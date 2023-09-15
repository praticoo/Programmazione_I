#include <iostream>
#include <climits>
#include <cstdlib>
#include <typeinfo>
#include <cmath>

using namespace std;
#define DIM 15

//Esame di Laboratorio 27 Aprile 2022 

class Wheel {
private :
int value;
int default_value;
int num_faces;

public :
Wheel (int initial_value, int num_faces) : value (initial_value), default_value (initial_value), num_faces (num_faces) {}

void rotate (int turns) {
    value = (value + turns) % num_faces; 
}

int getValue() {
    return value;
}

void reset() {
    value = default_value;
}

};

class AbstractSlotMachine {
protected : 
Wheel **wheels;
int num_wheels;
int prize;
int num_spins;
int num_wins;

public :
AbstractSlotMachine (int num_wheels, int num_faces) : prize (0), num_spins (0), num_wins (0), num_wheels (num_wheels) {
    wheels = new Wheel *[num_wheels];
    for (int i=0; i<num_wheels; i++) {
        wheels[i] = new Wheel (rand() % num_faces, num_faces);
    }
}

virtual int spin() = 0;

int getPrize() {
    return prize;
}

double getWinRate() {
    return (double)num_wins / num_spins; 
}

void reset() {
    for (int i=0; i<num_wheels; i++) {
        wheels[i] -> reset();
    }
}

virtual ostream& put(ostream& os) {
    os << ", num_wheels=" << num_wheels << ", prize=" << prize << ", num_spins=" << num_spins << ", num_wins=" <<num_wins<< ", winrate=" << getWinRate();
    return os;
}

};

ostream& operator<<(ostream& os, AbstractSlotMachine& obj) {
    return obj. put(os);
}

class ThreeWheelsSlotMachine : public AbstractSlotMachine {
private :
int num_max;

public:
ThreeWheelsSlotMachine () : AbstractSlotMachine (3, 6), num_max (0) {}

int spin() {
    num_spins ++;
    int valori[num_wheels];
    for (int i=0; i<num_wheels; i++){
        wheels[i] -> rotate (rand() % (10 - 3 + 1) + 3);
        valori[i] = wheels[i] -> getValue();
        prize += valori[i]; 
    }
    if (valori[0] == valori[1] && valori[0] == valori[2]){
        if (valori[0] == num_max){                         // 5 non num_max per risultare
            prize *= 2;
            num_max ++;
        }
          num_wins ++;
          int return_prize = prize;
          prize = 0;
          return return_prize;
    }
    else {
        return 0;
    }

    
}

int getNumMax() {
    return num_max;
}

   ostream& put(ostream& os) {
    os << "Class=" << typeid(this).name();
    AbstractSlotMachine :: put (os) << ", num_max=" << num_max;
    return os;
}
};

class TenWheelsSlotMachine : public AbstractSlotMachine {
public :
TenWheelsSlotMachine () : AbstractSlotMachine (5, 10) {}

int spin() {
    num_spins ++;
    int valori[num_wheels];
    int last_wheels = 0;
    for (int i=0; i<num_wheels; i++) {
       int num_turns = rand() % (10 - 3 + 1) + 3 + round(last_wheels / 3);
       last_wheels = num_turns;
       wheels[i] -> rotate(num_turns);
       valori[i] = wheels[i] -> getValue();
       prize += valori[i];
    }
    bool duplicati = false;
    for (int i=0; i<num_wheels; i++) {
       for (int j=i+1; j<num_wheels; j++) {
        if (valori[i] == valori[j]) {
            duplicati = true;
        }
       }
    }
   if (duplicati) {
    return 0;
   }
   else {
    num_wins ++;
    int return_prize = prize;
    prize = 0;
    return return_prize;
   }
}

virtual ostream& put(ostream& os) {
    os << "Class=" << typeid(this).name() << ", ";
    AbstractSlotMachine :: put (os);
    return os;
}

};


int main() {

    AbstractSlotMachine **vec = new AbstractSlotMachine*[DIM];

    srand(424242);

    for(int i=0; i<DIM; i++) {
        if(rand()%2){
            vec[i] = new ThreeWheelsSlotMachine();
        } else {
            vec[i] = new TenWheelsSlotMachine();
        }
    }

    for(int i=0; i<DIM*100; i++) {
         vec[rand()%DIM]->spin();
         if(rand()%5==0)
            vec[rand()%DIM]->reset();
    }

    cout << "PRIMO E SECONDO PUNTO" << endl;
    double MAX = INT_MIN;
    for (int i=0; i<DIM; i++){
        cout << i + 1 << ")" << *vec[i] << endl;
    }

    cout << "SECONDO PUNTO" << endl;
    for (int i=0; i<DIM; i++){
        if (vec[i] -> getWinRate() > MAX) {
            MAX = vec[i] -> getWinRate();
        }
    }
    cout << "max win rate = " << MAX << endl;

    cout << "TERZO PUNTO" << endl;
    double media = 0.0;
    int count = 0;
    for (int i=0; i<DIM; i++) {
        if (typeid(*vec[i]) == typeid(ThreeWheelsSlotMachine)) {
            media += ((ThreeWheelsSlotMachine*)vec[i]) -> getNumMax();
            count ++;
        }
    }
    
    cout << "mean num max = " << media / count << endl;

}






















/* class Wheel {
    private :
    int value;
    int default_value;
    int num_faces;
    
    public :
    Wheel (int initial_values, int num_faces) : value (initial_values), default_value (initial_values), num_faces (num_faces){}

    void rotate (int turns) {
        value = (value + turns) % num_faces;
    }

    int getValue() {
        return value;
    }

    void reset () {
        value = default_value;
    }
};

class AbstractSlotMachine {
protected :
Wheel **wheels;
int num_wheels;
int prize;
int num_spins;
int num_wins;

public :
AbstractSlotMachine (int num_wheels, int num_faces) : prize (0), num_spins (0), num_wins (0), num_wheels (num_wheels) { 
    wheels = new Wheel *[num_wheels];
    for (int i=0; i<num_wheels; i++) {
        wheels[i] = new Wheel (rand() % num_faces, num_faces);
    }
}

virtual int spin () = 0;

int getPrize() {
    return prize;
}

double getWinRate() {
    return (double)num_wins / num_spins;
}

void reset () {
    for (int i=0; i<num_wheels; i++) {
        wheels[i] -> reset();
    }
}

};

class ThreeWheelsSlotMachine : public AbstractSlotMachine {
private :
int num_max;

public :
ThreeWheelsSlotMachine () : AbstractSlotMachine (3, 6), num_max(0) {}

int spin() {
   num_spins ++;
   int vals[3];
   for (int i=0; i<num_wheels; i++) {
      wheels[i] -> rotate(rand() % ((10 - 3 + 1) + 3));
      vals[i] = wheels[i] -> getValue();
      prize += vals[i];
   }
   if (vals[0] == vals[1] && vals[0] == vals[2]) {
    if ( vals[0] == num_max ) {
        prize *= 2;
        num_max ++;
    }
    num_wins ++;
    int ret_prize = prize;
    prize = 0;
    return ret_prize;
   }
   else {
    return 0;
   }
}

int getNumMax() {
    return num_max;
}
};

class TenWheelsSlotMachine : public AbstractSlotMachine {
public :
TenWheelsSlotMachine () : AbstractSlotMachine (5, 10) {}

int spin() {
    num_spins ++;
    int last_turns = 0;
    int vals[10];
    for (int i=0; i<num_wheels; i++) {
        int num_turns = rand() % ((10- 3 + 1) + 3) + round(last_turns / 3);
        wheels[i] -> rotate(num_turns);
        vals[i] = wheels[i] -> getValue();
        prize += vals[i];
    }
    bool duplicates = false;
    for (int i=0; i<num_wheels; i++) {
        for (int j=i+1; j<num_wheels; j++) {
            if (vals[i] == vals[j]) {
                duplicates = true;
            }
        }
    }
    if (duplicates) {
        return 0;
    }
    else {
        num_wins ++;
        int return_prize = prize;
        prize = 0;
        return return_prize;
    }
}
};

int main() {

}
*/