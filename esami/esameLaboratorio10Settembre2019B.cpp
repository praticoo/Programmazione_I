#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
#include <string>
#include <climits>

using namespace std;

#define DIM 50

//Esame di Laboratorio 10 Settembre 2019 B

class A {
private :
double *arr;
short len;

public : 
A (short m) {
    this -> len = m; 
    this -> arr = new double [len];
    for (int i=0; i<len; i++) {
        arr[i] = rand() / (double)RAND_MAX;
    }
}

virtual double f (short a) = 0;

short getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", arr=[";
    for (int i=0; i<len; i++) {
        os << arr[i] << " ";
    }
    os << "], ";
    return os;
}

double operator()(int i1, int i2) {
    double somma = 0.0;
    for (int i=i1; i<=i2; i++) {
        somma += get(i);
    }
    return somma;
}

protected : 
double get (short i) {
    return arr[i % len];
}

};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
double p;

public :
B (short m) : A (m) {
    double media = 0.0;
    for (int i=0; i<getLen(); i++) {
        media += get(i);
    }
    this -> p = media / getLen();
}

double f (short a) {
    return (log(foo(a, 2*a))) / p;
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "p=" << p << ", f(3)=" << f(3);
    return os;
}

protected :
double foo (short s, int k) {
    double somma = 0.0;
    for (int i=s % getLen(); i<getLen(); i++) {
        somma += get(i);
    }
    return somma * k;
}
};

template <class T>
class C : public A {
private : 
T x;

public :
C (short n) : A (n) {
    if (typeid(T) == typeid(short)) {
        this -> x = n;
    }
    else {
        this -> x = log (1 + (sin(n)* sin(n)));
    }
}

double f (short r) {
    return g(r);
}

T g (T k) {
    return 2 * x * (k + 1);
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "x=" << x << ", f(3)=" << f(3);
    return os;
}

};
 
int main() {
    srand (111222333);
    A* vett[DIM];
for (int i=0; i<DIM; i++) {
short n=1+rand() % 10;
switch (rand() % 3) {
case 0 :
vett[i]= new B(n) ;
break ;
case 1 :
vett[i]= new C<double>(n) ;
break ;
case 2 :
vett[i]= new C<short>(n) ;
}
}

cout << "PUNTO UNO" << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "PUNTO DUE" << endl;
cout << endl;
double MaX = INT_MIN;
double media = 0.0;
int count = 0; 
for (int i=0; i<DIM; i++) {
    if (vett[i] -> f(3) > MaX) {
        MaX = vett[i] -> f(3);
    }
    if (typeid(*vett[i]) == typeid(C<double>)) {
        media += ((C<double>*)vett[i]) -> g(5);
        count ++;
    }
}
cout << "Max = " << MaX << endl;
cout << "Media = " << media / count << endl;

cout << endl << "TERZO PUNTO" << endl;
cout << endl;
cout << "*vett[48] = " << *vett[48] << endl;
cout << "(*vett[48])(0,2) = " << (*vett[48])(0,2) << endl; 

}
 