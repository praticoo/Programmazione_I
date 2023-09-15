#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

#define DIM 10

//Esame di Laboratorio 08 / 02 / 22 - Turno 1

class AbstractRandomVec {
protected :
int *vec;
int num;

public :
AbstractRandomVec (int n, int min, int max) {
    num = n;
    vec = new int [num];
    for (int i=0; i<num; i++) {
        vec[i] = rand() % (max - min + 1) + min;
    }
}

virtual int count() = 0;

int *get(int i) {
    if (i >= num || i < 0 ) {
        return nullptr ; 
    }
    else {
        return (vec + i);                                //addizione sui puntatori, facendo + i, per tornare puntatore corretto
    }
}

int numel() {
    return num;
}

//mean == media
float mean() {
    float somma = 0; 
    for (int i=0; i<numel(); i++) {
            somma += vec[i];
    }
    return somma / num;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", num=" << num << ", vec=[";
    for (int i=0; i<num; i++) {
        os << vec[i] << " ";
    }
    os << "], ";
    return os;
}
 
};

ostream& operator<<(ostream& os, AbstractRandomVec& obj) {
    return obj.put(os);
}

class TernaryVec : public AbstractRandomVec {
public :
TernaryVec (int n) : AbstractRandomVec (n, 0, 2) {}

int count() {
int contatore = 0;
    for (int i=0; i<numel(); i++) {
        //posso usare vec perche è protetta stavolta, non privata
        if (vec[i] != 0) {
            contatore ++;
        }
    }
    return contatore;
}

virtual ostream& put(ostream& os) {
    AbstractRandomVec :: put(os);
    return os;
}
};
#include <ctime>
class MultVec : public AbstractRandomVec {
    private :
    double midpoint;

    public:
    MultVec (int n, int min, int max, int mul) : AbstractRandomVec (n, min, max) {
        //num = n;             già fatto nel costruttore della Classe A 
        for (int i=0; i<n; i++){
            //srand(time (0));
            int m = rand() % (max - min + 1) + min;
            if (m % mul == 0){
            vec[i] = m;
            }
            else {
                i--;
            }
        }
        this -> midpoint = (double)(min + max) / 2;
    }

    int count() {
           int elMaggiori = 0;
           for (int i=0; i < num; i++) {
            if ((double)vec[i] > midpoint) {
                elMaggiori ++;
            }
           }
           return elMaggiori;
    }

    int CountEven() {
        int contaPari = 0;
        for (int i=0; i<numel(); i++) {
            if (vec[i] % 2 == 0) {
                contaPari ++;
            }
        }
        return contaPari;
    }

    virtual ostream& put(ostream& os) {
    AbstractRandomVec :: put(os);
    os << "midpoint=" << midpoint;
    return os;
}
};




int main() {
 srand(424242);

    AbstractRandomVec* vett[DIM];

    for(int i=0; i<DIM; i++) {
        int n=5+rand()%5;
        int m=5+rand()%5;
        int min = rand()%10 + 5;
        int max = min + rand()%20;

        switch(rand()%2) {
            case 0: {
                vett[i]= new TernaryVec(n);
                break;
            }
            case 1: {
                vett[i]= new MultVec(n, min, max, m);
            }
        }
    } 
    
    cout << "PRIMO PUNTO" << endl;

    for (int i=0; i<DIM; i++) {
         cout << i << ") Class=" << *vett[i] << endl;
    }

cout << endl << "SECONDO PUNTO" << endl;
int max = INT_MIN;
int media = 0;
int count = 0;
for (int i=0; i<DIM; i++){
    if ((vett[i] -> count()) > max) {
        max = vett[i] -> count();
    }
    if (typeid(*vett[i]) == typeid(MultVec)) {
          media += ((MultVec*)vett[i]) -> CountEven();
          count ++;
    }
}

cout << "max count(): "<< max << endl;

cout << endl << "TERZO PUNTO" << endl;

cout << "mean CountEven(): " << media / count << endl;
}