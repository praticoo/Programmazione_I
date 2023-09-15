#include <iostream>
#include <climits>
#include <typeinfo>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

#define DIM 50

//Esame di Laboratorio 15 Febbraio 2019 - A

class A {
private :
double *w;
short len;

public : 
A (short m) {
    this -> len = m;
    this -> w = new double [len];
    for (int i=0; i<len; i++) {
        w[i] = rand() / (double)RAND_MAX;
    }
 }

virtual double const foo (short a) = 0;

short const getLen() {
    return len;
}

virtual ostream& put (ostream& os) {
    os << typeid(*this).name() << ", w=[";
    for (int i=0; i<getLen(); i++) {
        os << w[i] << " ";
    }
    os << "] , ";
    return os;
}

double& operator[] (short i) {
    return w [i % len];
}

protected :
double const get (short i) {
    return w[i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
int p;

public : 
B (short m, int x) : A (m) {
    this -> p = x;
}

double const foo (short a) {
    return sum (a) / p;
}

virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "p=" << p << ", foo(3)=" << foo(3); 
    return os;
}

protected :
double const sum (short s) {
    double somma = 0;
    for (short i=s%getLen(); i<getLen(); i++) {
        somma += get(i);
    }
    return somma;
}
};


template <class T>
class C : public A {
private :
T x;

public :
C (short n) : A (n) {
    if (typeid(T) == typeid(short)) {
        x = n;
    }
    else {
        x = log(1 + (sin(n)*sin(n)));
    }
}

double const foo (short r) {
    return g(r);
}

T const g (T k) {
    return 2 * x * (k + 1);
}

virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "x=" << x << ", foo(3)=" << foo(3); 
    return os;
}
};

int main() {
srand (111222333);
A* vett[DIM];
for (int i=0; i<DIM; i++) {
short n = 1 + rand() % 10;
switch(rand() % 3) {
case 0 :
vett[i]= new B(n, rand() % 10 + 1 );
break;
case 1 :
vett[i]= new C<double>(n);
break;
case 2 :
vett[i]= new C<short>(n);
}
}

cout << "PRIMO PUNTO" << endl;
cout << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")";
    cout << *vett[i] << endl;
}

cout << endl << "SECONDO PUNTO" << endl;
cout << endl;

double MaX = INT_MIN;
double media = 0.0;
int count = 0; 
for (int i = 0; i<DIM; i++) {
    if (vett[i] -> foo(3) > MaX) {
        MaX = vett[i] -> foo(3);
    }
    if (typeid(*vett[i]) == typeid(C<double>)) {
        media += (((C<double>*)vett[i]) -> g(5));
        count ++;
    }
}

cout << "Massimo Valore di foo(3) = " << MaX << endl;
cout << "Media dei valori g(5), tipo C<double> = " << media / count << endl;

cout << endl << "TERZO PUNTO" << endl;
cout << endl;
cout << "*vett[49] = " << *vett[49] << endl;
cout << "(*vett[49])[3] = " << (*vett[49])[3] << endl;
cout << "*vett[48] = " << *vett[48] << endl;
(*vett[48])[2] = 8.8;
cout << "Nuovo *vett[48] = " << *vett[48] << endl;

}