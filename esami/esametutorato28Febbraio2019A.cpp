#include <iostream>
#include <cmath>
#include <typeinfo>
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;
#define DIM 50

//Esame di Laboratorio 28 Febbraio 2019 - A

class A {
private:
short *arr;
short len;

public:
A (short m) {
    this -> len = m;
    this -> arr = new short [len];
    for (int i=0; i<len; i++) {
        arr[i] = rand() % (10 - 1 + 1) + 1;
    }
}

virtual double f(short a) = 0;

short getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    os << "[" ;
    for (int i=0; i<len; i++) {
        os << arr[i] << " ";
    }
    os << "], ";
    return os;
}

protected:

short get (short i) {
    return arr [i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

template <typename T>
class B : public A{
private :
T x;

public:
double foo(short s) {
    return ((double)log (s) + sin (f(s)));
}

double f (short a) {
    double media = 0; 
    int count = 0;
     for (int i=a % getLen() ; i<getLen(); i++) {
        media += get(i);
        count ++;
     }
     return (double) media / count;
}

B (short m, char c) : A (m) {
    if (typeid(x) == typeid(char)) {
        x = c;
    }
    if (typeid(x)== typeid(string)){
        for (int i=0; i<m; i++) {
            x+=c;
        }
    }
} 


virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "x=" << x << ", f(3)=" << f(3);
    return os;
}
};

class C : public A {
private:
int y;

public:
C (short n, int k) : A (n) {
    this -> y = k;
} 

double f(short a) {
    short r = get(rand() % getLen());
    return ((double)(a + y)) / r;
}

short g (short w) {                                    //doveva essere double, il prof ha sbagliato
    return sin (w + y);
}

//visto che deve essere prefisso non dobbiamo mettere alcun valore sentinella all'interno della parentesi tonda, ad esempio un int
C* operator++() {
    ++y;
    return this;                //torniamo l'oggetto stesso
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "y=" << y << ", f(3)=" << f(3);
    return os;
}
};

int main() {
    srand(111222333);
    A *vett[DIM];

    for(int i=0; i<DIM; i++) {
        short n=1+rand()%10;
        switch(rand()%3) {
            case 0:
                vett[i]= new C(n, rand()%10 + 1);
                break;
            case 1:
                vett[i]= new B<string>(n, rand()%('z' - 'a' + 1) + 'a');
                break;
            case 2:
                vett[i]= new B<char>(n, rand()%('z' - 'a' + 1) + 'a');
        }
    }

cout << "PUNTO UNO" << endl;

    for (int i=0; i<DIM; i++) {
        cout << i << ")";
        if (typeid(*vett[i]) == typeid(B<char>)) {
            cout << "B<char> ";
        }
        else if (typeid(*vett[i]) == typeid(C)) {
            cout << "C ";
        }
        else {
            cout << "B<string> ";
        }
        cout << *vett[i] << endl;
    }

cout << "PUNTO DUE " << endl;

int max = INT_MIN;
double media = 0.0;
int count = 0;
for (int i=0; i<DIM; i++) {
    if (vett[i] -> f(3) > max) {
        max = vett[i] -> f(3);
    }
    if (typeid(*vett[i]) == typeid(C)) {
        media += ((C*)(vett[i])) -> g(5);
        count ++;
    } 
}

cout << "Max(f(3)) = " << max << ", avg(g(5)) = "<< media / count << endl;

cout << "TERZO PUNTO" << endl;

cout << "47)C "<< *vett[47] << endl;                //su GBD stampare il 48 ad esempio...
cout << *(++(*((C*)vett[47]))) << endl;

}
