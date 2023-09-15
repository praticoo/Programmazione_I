#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <typeinfo>
#include <string>

using namespace std;

#define DIM 30

//Esame di Laboratorio 14 Dicembre 2018 

class A {
protected :
double *ptr;
short len;

public :
A (short n) {
    len = n;
    ptr = new double [n];
    for (int i=0; i<len; i++) {
        ptr[i] = rand() / (double) RAND_MAX;
    }
}

virtual double const foo (short a) = 0;

virtual ostream& put(ostream& os) {
    os << "ptr=[";
    for (int i=0; i<len; i++) {
        os << ptr[i] << " ";
    }
    os << "], ";
    return os;
}

double& operator[](int i) {
      return ptr[i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private : 
double alpha;

public :
B (short m, double d) : A (m) {
    this -> alpha = d;
}

double extract (short s) {
    double media = ( ptr[s % len] + alpha ) / 2;
    return media;
}

double const foo (short b) {
    return log (1 + extract(b));
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "alpha=" << alpha << ", foo(5)=" << foo(5);
    return os;
}

};

template <typename T>
class C : public A {
private : 
T x;

public :
C (short n) : A (n) {
    if (typeid(T) == typeid(short)) {
        this -> x = g(n); 
    }
    else {
        this -> x = log (1 + n);
    }
}

double const foo (short r) {
    return g (r * x);
}

T const g (T k) {
    return 3 * k;
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "x=" << x << ", foo(5)=" << foo(5) << ", g(5)=" << g(5);
    return os;
}

};

int main() {
srand (328832748);
A *vett[DIM];
for ( int i =0; i<DIM; i++) {
short n=1+rand ( )%5;
switch ( rand ()%3) {
case 0 : vett [i]= new B( n , n / 100.0 ) ; break ;
case 1 : vett [ i ]= new C<double>(n ) ; break ;
case 2 : vett [i]= new C<int>(n ) ;
}
}

cout << "PRIMO PUNTO" << endl;

for (int i=0; i<DIM; i++) {
    cout << i << ")" ;
    if (typeid(*vett[i]) == typeid(B)) {
        cout << "B, ";
    }
    else if (typeid(*vett[i]) == typeid(C<double>)) {
        cout << "C<double>, ";
    }
    else {
        cout << "C<int>, ";
    }
    cout << *vett[i] << endl;
}

cout << endl << "SECONDO PUNTO " << endl;
cout << endl;
double MaX = 0.0;
double somma = 0.0;
for (int i=0; i<DIM; i++) {
if (vett[i] -> foo(5) > MaX) {
    MaX = vett[i] -> foo(5);
}
if (typeid(*vett[i]) == typeid(C<double>)) {
    if (((C<double>*)vett[i]) -> g(5)) {
    somma += ((C<double>*)vett[i]) -> g(5);
    }
}
}

cout << "Max = " << MaX << endl;
cout << "Somma = " << somma << endl;

cout << endl << "TERZO PUNTO" << endl;
cout << endl;
cout << "*vett[29] = " << *vett[29] << endl;
cout << "(*vett[29])[3] = " << (*vett[29])[3] << endl;
(*vett[29])[3] = 104;
cout << "Cambio di valore, (*vett[29])[3] = " << (*vett[29])[3] << endl; 
cout << "*vett[29] = " << *vett[29] << endl;
}