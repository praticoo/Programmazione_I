#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <typeinfo>

using namespace std;
#define DIM 7

//Esame di Laboratorio 4 / 07 / 2022

template <typename T>
class AbstractRandomGenerator {
protected :
int num_values;
int tossed;
T accumulated_value;
T value;
T* values;

public :
AbstractRandomGenerator (T value, int num_values, T* input_values) : value (value), num_values(num_values), accumulated_value(value), tossed(0) {
    values = new T [num_values];
    for (int i=0; i<num_values; i++) {
        values[i] = input_values[i];
    }
}

virtual T toss () {
    value = values [rand() % num_values];
    tossed ++;
    accumulated_value += value;
    return value;
}

T getValue() {
    return value;
}

int getTossed() {
    return tossed;
}


virtual void nudge() = 0;

virtual ostream& put(ostream& os) {
    os << ", values={";
    for (int i=0; i<num_values; i++) {
        os << values[i] << " ";
    }
    os << "}, value=" << value << ", accumulated_value=" << accumulated_value << ", tossed=" << tossed;
    return os;
}

};

template <typename T>
ostream& operator<<(ostream& os, AbstractRandomGenerator<T>& obj) {
    return obj.put(os);
}

class Dice : public AbstractRandomGenerator<int> {
private :
int doubles;

public :
Dice () : AbstractRandomGenerator<int>(1, 6, values = new int[6]{1, 2, 3, 4, 5, 6} ), doubles(0) {}

void nudge() {
    value += rand() % (1 + 1 + 1) + 1;
    if (value > 6) {
        value = 6;
    }
    if (value < 1) {
        value = 1;
    }
}

int toss() {
    int val = value;
    int Stoss = AbstractRandomGenerator<int> :: toss();
    if (val == Stoss) {
        doubles ++;
    }
    return value;
}

double getDoubleRate() {
    return double(doubles) / tossed;
}

ostream& put (ostream& os) {
    os << typeid(this).name();
    AbstractRandomGenerator<int> :: put(os);
    return os;
}
};

class Coin : public AbstractRandomGenerator<string> {
private :
int nudge_prob;

public :
Coin (int nudge_prob) : AbstractRandomGenerator<string>("H", 2, values = new string [2]{"H", "T"}), nudge_prob(nudge_prob) {}

void nudge() {
    int casuale = rand() % ((nudge_prob - 1) + 1);
    if (casuale == 0) {
        if (value == "H") {
            value = "T";
        }
        else {
            value = "H";
        }
    }
}

ostream& put (ostream& os) {
    os << typeid(this).name();
    AbstractRandomGenerator<string> :: put(os);
    return os;
}
};

int main() {
    	srand(424242);
    AbstractRandomGenerator<int>* vec1[DIM];
    AbstractRandomGenerator<string>* vec2[DIM];

	for(int i=0; i<DIM; i++) {
		vec1[i] = new Dice();
		vec2[i] = new Coin(rand()%10+1);
	}

    for(int i=0; i<100; i++) {
         vec1[rand()%DIM]->toss();
		 vec2[rand()%DIM]->toss();
         if(rand()%5==0) {
            vec1[rand()%DIM]->nudge();
			vec2[rand()%DIM]->nudge();
		 }
    }

    cout << "PRIMO PUNTO" << endl;

    for (int i=0; i<DIM; i++) {
        cout << i + 1 << ")" << "Class=" << *vec1[i] << endl; 
        cout << i + 1 << ")" << "Class=" << *vec2[i] << endl;
    }

    cout << endl << "PUNTO DUE" << endl;
    cout << endl;
    int min = INT_MAX;
    double max = INT_MIN;
    for (int i=0; i<DIM; i++) {
        if (vec2[i] -> getTossed() < min) {
            min = vec2[i] -> getTossed();
        }
        if (typeid(*vec1[i]) == typeid(Dice)) {
            if (((Dice*)vec1[i]) -> getDoubleRate() > max) {
                max = ((Dice*)vec1[i]) -> getDoubleRate();
            }
        }
    }
    cout << "min tossed = " << min << endl;

    cout << endl << "PUNTO TRE" << endl;
    cout << endl;
    cout << "max double rate = " << max;
}







































/*
template <typename T>
class AbstractRandomGenerator {
protected :
int num_values;
int tossed;
T accumulated_value;
T value;
T* values;

public :

AbstractRandomGenerator(T value, int num_values, T *input_values) {
			this->value = value;
			this->num_values = num_values;
			this->values = new T[num_values];
			accumulated_value = value;
			tossed = 0;
			for(int i=0; i<num_values; i++) {
				this->values[i] = input_values[i];
			}
		}

virtual T toss() {
    value = values[rand() % num_values];
    tossed ++;
    accumulated_value += value;
    return value;
}

T getValue() {
    return value;
}

int getTossed() {
    return tossed;
}

virtual void nudge() = 0;

virtual ostream& put (ostream& os) {
    os << ", values={";
    for (int i=0; i<num_values; i++) {
        os << values[i] << " ";
    }
    os << "}, value=" << value << ", accumulated_value=" << accumulated_value << ", tossed=" << tossed;
    return os;
}

};

template <typename T>
ostream& operator<<(ostream& os, AbstractRandomGenerator<T>& obj) {
    return obj.put(os);
}

class Dice : public AbstractRandomGenerator<int> {
private :
int doubles;

public :
Dice() : AbstractRandomGenerator<int> ( 1, 6, values = new int [6] {1, 2, 3, 4, 5, 6 } ), doubles(0) {}

void nudge () {
    value = rand() % (1 + 1 + 1) - 1;
    if (value > 6) {
        value = 6;
    }
    if (value < 1) {
        value = 1;
    } 
}*/
/*
 int toss() {
			int previous_value = value;
			int value = AbstractRandomGenerator<int>::toss();
			if(value==previous_value) {
				doubles++;
			}

			return value;
		}*/
/*
 int toss() {
    //int Stoss = AbstractRandomGenerator<int>::toss();
    int val = value;
    int Stoss = AbstractRandomGenerator<int>::toss();

    if (Stoss == val) {
        //cout << val << endl;
        //cout << value << endl;
        doubles ++;
    }
    return value;
} 

double getDoubleRate() {
    return double(doubles) / tossed;
}

virtual ostream& put (ostream& os) {
    os << typeid(this).name();
    AbstractRandomGenerator :: put(os);
    return os;
}

};

class Coin : public AbstractRandomGenerator<string> {
private : 
int nudge_prob;

public :
Coin (int nudge_prob) : AbstractRandomGenerator<string> ("H", 2, values = new string [2] {"H", "T"}), nudge_prob(nudge_prob) {}

void nudge() {
    int casuale = rand() % ((nudge_prob - 1) + 1);
    if (casuale == 0) {
        if (value == "H") {
            value = "T";
        }
        else {
            value = "H";
        }
    }
}

 virtual ostream& put (ostream& os) {
    os << typeid(this).name();
    AbstractRandomGenerator :: put(os);
    return os;
}
};

int main() {

    AbstractRandomGenerator<int> **vec1 = new AbstractRandomGenerator<int>*[DIM];
	AbstractRandomGenerator<string> **vec2 = new AbstractRandomGenerator<string>*[DIM];

    srand(424242);

	for(int i=0; i<DIM; i++) {
		vec1[i] = new Dice();
		vec2[i] = new Coin(rand()%10+1);
	}

    for(int i=0; i<100; i++) {
         vec1[rand()%DIM]->toss();
		 vec2[rand()%DIM]->toss();
         if(rand()%5==0) {
            vec1[rand()%DIM]->nudge();
			vec2[rand()%DIM]->nudge();
		 }
    }

cout << "PUNTO UNO" << endl;

    for (int i=0; i<DIM; i++) {
        cout << i + 1 << ")Class=" << *vec1[i] << endl;
        cout << i + 1 << ")Class=" << *vec2[i] << endl;
    }

cout << endl << "PUNTO DUE " << endl;
cout << endl;

int min = INT_MAX;
double max = INT_MIN;
for (int i=0; i<DIM; i++) {
    if (vec2[i] -> getTossed() < min) {
        min = vec2[i] -> getTossed();
    } 
}

cout << "min tossed = " << min << endl;
/*
/* for (int i=0; i<DIM; i++) {
//if (typeid(*vec1[i]) == typeid(Dice)) {
           if (((Dice*)vec1[i]) -> getDoubleRate() > max) {
                max = ((Dice*)vec1[i]) -> getDoubleRate();
           }
  //  }
}
cout << "max double rate = " << max;

} */
/*
double max_double_rate= 0;
    for (int i=0; i<DIM; i++) {
		double double_rate = ((Dice*)vec1[i])->getDoubleRate();
        if (double_rate > max_double_rate) {
            max_double_rate = double_rate;
        }
    }

    cout << "max double rate = "<<max_double_rate<<endl;
} 
*/


