#include <climits>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <typeinfo>

using namespace std;
#define DIM 50

//Esame di Laboratorio 29 / 04 / 19 - B

class A {
private :
int *vec;
short len;

public :
A (short m, int a, int b) {
    this -> len = m; 
    this -> vec = new int [len];
    for (int i=0; i<m; i++) {
        vec[i] = rand() % (b - a + 1) + a;
    }
}

virtual double foo (short a) = 0;

short getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", vec=[";
    for (int i=0; i<len; i++) {
        os << vec[i] << " ";
    }
    os << "], ";
    return os;
}

int& operator[](int i) {
    return vec[i % len];
}

protected : 
int get(short i) {
    return vec[i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private : 
int p;

public :
B (short m, int x, int y) : A(m, x, y){
    this -> p = A :: get(rand() % A :: getLen());
}

double foo(short a) {
    return prod(a) / p;
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << "p=" << p << ", foo(3)=" << foo(3);
    return os;
}

protected :
int prod(short s) {
    int prodotto = 1;
    for (int i = s % A :: getLen(); i< A :: getLen(); i++) {
        prodotto *= A :: get(i);
    }
    return prodotto;
}
};

template <typename T>
class C : public A {
private :
T x;

public :
C (short n, int a, int b) : A (n, a, b) {
    if (typeid(T) == typeid(short)) {
        x = n;
    }
    else {
        x = log (1 + (sin(n) * sin(n)));
    }
}

double foo (short r) {
    return g(r);
}

T g(T k) {
    return 2 * x * (k + 1);
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << "x=" << x << ", foo(3)=" << foo(3);
    return os;
}
};

int main() {
A * vett [DIM ] ;
for ( int i =0; i<DIM; i++) {
short n=1+rand ( )%10;
switch ( rand ()%3) {
case 0 :
vett [ i ]= new B( n , rand ()%5 + 1 , rand ()%10 + 5 ) ;
break ;
case 1 :
vett [ i ]= new C<double>(n , rand ()%5 + 1 , rand ()%10 + 5 ) ;
break ;
case 2 :
vett [ i ]= new C<short>(n , rand ()%5 + 1 , rand ()%10 + 5 ) ;
}
}

cout << "PUNTO UNO " << endl;
cout << endl;
double max = INT_MIN;
double media = 0.0;
int count = 0;
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
    if (vett[i] -> foo(3) > max) {
        max = vett[i] -> foo(3);
    }
    if (typeid(*vett[i]) == typeid(C<double>)) {
        media += ((C<double>*)vett[i]) -> g(5);
        count ++;
    }
}

cout << endl << "PUNTO DUE" << endl;
cout << endl;
cout << "max = " << max << endl;
cout << "media = " << media / count << endl;

cout << endl << "PUNTO TRE" << endl;
cout << endl;
cout << "*vett[43] : " << *vett[40] << endl;
(*vett[40])[3] = 4;
cout << "*vett[43] : " << *vett[40] << endl;

}