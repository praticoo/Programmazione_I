#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;
#define DIM 10

//Esame di Laboratorio 24 / 02 / 2022

template <typename T>
class AbstractVec {
private :
T **data;      //int **arr = new int *[DIM]

public :
AbstractVec (int max_size) : max_size(max_size), read_index(0), write_index(0) {
    this -> data = new T *[max_size];
    for (int i=0; i<max_size; i++) {
        data[i] = nullptr;
    }
}

virtual T* next() = 0;

virtual bool insert (T x) = 0;

int len() {
    int non_nulli = 0;
    for (int i=0; i<max_size; i++) {
        if (data[i]) {
            non_nulli ++;
        }
    }
    return non_nulli;
}

void shuffle() {
    for (int i=0; i<max_size; i++) {
        if (data[i]) {
            T* tmp = nullptr;
            int index = 0;
            while (tmp == nullptr || tmp == data[i]) {
                index = rand() % max_size;
                tmp = data[index];
            }
            data[index] = data[i];
            data[i] = tmp;
        }
    }
}

double mean() {
    double media = 0.0;
    int count = 0;
    for (int i=0; i<max_size; i++) {
        if (data[i]) {
        media += data[i][0];
        count ++;
        }  
    }
    return media / count;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", max size = " << max_size << ", vec=[";
    for (int i=0; i<max_size; i++) {
        if (data[i]) {
            os << data[i][0] << " ";
        }
        else {
           // os << "* ";
        }
    }
    os << "], len()=" << len() << ", mean()=" << mean();
    return os;
}

protected :
int max_size;
int read_index;
int write_index;

T* get (int index) {
    return data[index];
}

bool exists (int index) {
    if (data[index] != nullptr) {
        return true;
    }
    return false;
}

void set (int i, T x) {
    if (data[i]) {
    data[i][0] = x;
    }
    else {
        data[i] = new T(x);             //Risultato[i] = nullptr;                                   //nullptr perchè devo tornare puntatore
                                                                               //sennò per puntare direttamente al valore mettevo null
    }
}

};

template <class T>
ostream& operator<<(ostream& os, AbstractVec<T>& obj) {
    return obj.put(os);
}

template <typename T>
class PlainVec : public AbstractVec<T>{
public :
PlainVec(int max_size) : AbstractVec<T>(max_size) {}

T* next() {
    if (AbstractVec<T> :: read_index < AbstractVec<T> :: max_size) {
        AbstractVec<T> :: read_index ++;
        return AbstractVec<T> :: get(AbstractVec<T>::read_index);
    }
    else {
        return nullptr;
    }
}

bool insert (T x) {
    if (AbstractVec<T> :: write_index < AbstractVec<T> :: max_size) {
        AbstractVec<T> :: set (AbstractVec<T> :: write_index++, x);
        return true;
    }
    else {
        return false;
    }
}

};

template <typename T>
class CircularVec : public AbstractVec<T> {
public :
int cycles;

CircularVec (int max_size) : AbstractVec<T> (max_size), cycles(0) {}

T* next() {
    
    T* tmp = AbstractVec<T> :: get(AbstractVec<T> :: read_index++);
    if (AbstractVec<T> :: read_index == AbstractVec<T> :: max_size) {
        AbstractVec<T> :: read_index = 0;
        cycles ++;
    }
    return tmp;
}

bool insert(T x) {
    AbstractVec<T> :: set(AbstractVec<T> :: write_index++, x);
    if (AbstractVec<T> :: write_index == AbstractVec<T> :: max_size ) {
        AbstractVec<T> :: write_index = 0;
        cycles ++;
    }
    return true;
} 

int getCycles() {
    return cycles;
}

virtual ostream& put(ostream& os) {
    AbstractVec<T> :: put (os);
    os << ", cycles=" << cycles;
    return os;
}
};

int main() {
    srand(424242);
AbstractVec<int>* vec[DIM];
for(int i=0; i<DIM; i++) {
	int size = rand()%16+5;
	if(rand()%2){
		vec[i] = new PlainVec<int>(size);
	} else {
		vec[i] = new CircularVec<int>(size);
	}
}

for(int i=0; i<DIM*5; i++) {
	int x = rand()%100;
	vec[x%DIM]->insert(x);
}

for(int i=0; i<DIM; i++)
	vec[i]->shuffle();

    cout << "PUNTO UNO" << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")Class=" << *vec[i] << endl;
}

cout << endl << "PUNTO DUE" << endl;
cout << endl;
int min = INT_MAX;
double max = INT_MIN;
for (int i=0; i<DIM; i++) {
    if (vec[i] ->len() < min) {
        min = vec[i] -> len();
    }
    if (typeid(*vec[i]) == typeid(PlainVec<int>)) {
        if (((PlainVec<int>*)vec[i]) -> mean() > max) {
            max = vec[i] -> mean();
        }
    }
} 

cout << "Minimo len() : " << min << endl;

cout << endl << "PUNTO TRE " << endl;
cout << endl;
cout << "Massima mean() : " << max << endl;
}





/* template <typename T>
class AbstractVec {
private :
T** data;    //int **arr = new int *[DIM];

public :
AbstractVec (int max_size) : max_size(max_size), read_index(0), write_index(0) {
    this -> data = new T *[max_size];
    for (int i=0; i<max_size; i++) {
        data[i][0] = nullptr;
    }
 }

virtual T* next() = 0;

virtual bool insert (T x) = 0;

int len() {
    int non_nulli = 0;
    for (int i=0; i<max_size; i++) {
    if (data[i]) {
        non_nulli ++;
    }
    }
    return non_nulli;
}

void shuffle () {
    T *arr = new T [len()];
    for (int i=0; i<max_size; i++) {
        if (data[i]) {
            arr[i] = data[i][0];
        }
    }
    for (int i=0; i<max_size; i++) {
        if (data[i][0]) {
            data[i][0] = arr [rand() % len()];
        }
    }
}


protected :
int max_size;
int read_index;
int write_index;

T * get (int index) {
    return data[index];
}

bool exists (int index) {
    if (data[index] != nullptr) {
        return true;
    }
    else {
        return false;
    }
}

void set (int i, T x) {
    data[i] = data[x];
}

};

template <typename T>
class PlainVec : public AbstractVec<T> {
public :
PlainVec (int max_size) : AbstractVec<T>(max_size) {}

T* next() {
    if (AbstractVec<T>::read_index) {
        AbstractVec<T>::read_index ++;
        return get(AbstractVec<T>::read_index);
    }
    else {
        return nullptr;
    }
}

bool insert (T x) {
    if (AbstractVec<T>::write_index) {
        AbstractVec<T>::get(AbstractVec<T>::write_index) = x;
        AbstractVec<T>::write_index ++;
        return true;
    }
    else {
        return false;
    }
}
};
*/
/*
template <typename T>
class CircularVec : public AbstractVec<T> {
public :
int cycles;

CircularVec (int max_size) : AbstractVec<T> (max_size), cycles(0) {}

T* next() {
    read_index ++;
    if (read_index == max_size) {
        read_index = 0;
        cycles ++;
    }
    return data[read_index];
}

bool insert (T x) {
    data[wtite_index] = x;
    write_index ++;
    if (write_index == max_size) {
        write_index ++;
        cycles++;
    }
    return true;
}

int getCycles() {
    return cycles;
}
};
*/
/* int main() {
    srand(424242);
AbstractVec* vec[DIM];
for(int i=0; i<DIM; i++) {
	int size = rand()%16+5;
	if(rand()%2){
		vec[i] = new PlainVec<int>(size);
	} else {
		vec[i] = new CircularVec<int>(size);
	}
}

for(int i=0; i<DIM*5; i++) {
	int x = rand()%100;
	vec[x%DIM]->insert(x);
}

for(int i=0; i<DIM; i++)
	vec[i]->shuffle();
} */