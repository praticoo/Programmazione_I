#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <climits>

using namespace std;
#define DIM 50

//Esame di Laboratorio 29 / 04 / 19 - A

class A {
private :
double *ptr;
short len;

public :
A (short m) {
    this -> len = m;
    this -> ptr = new double [m];
    for (int i=0; i<len; i++) {
        ptr[i] = rand() / (double)RAND_MAX;
    } 
}

virtual double f (short i) = 0;

short getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", ptr=[ ";
    for (int i=0; i<getLen(); i++) {
        os << ptr[i] << " ";
    }
    os << "] , ";
    return os;
}

double& operator[](int i) {
    return ptr[i % len];
}

double operator() (int i1, int i2) {
    double somma = 0.0;
    for (int i=i1; i<=i2; i++) {
    somma += ptr[i];
    }
    return somma;
}

protected :
double get(short i) {
    return ptr[i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
int p;

public :
B (short m, int y) : A (m), p(y) {}

double f (short i) {
    double somma = 0.0;
    for (int j=0; j<A::getLen(); j++) {
        if (A::get(j) <= i) {
        somma += A::get(j);
        }
    }
    if (p!=0) {
    return somma / p;
    }
    else {
        return 0;
    }
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "p=" << p << ", f(3)=" << f(3);
    return os;
}

B* operator++() {
    ++p;
    return this;
}

B* operator++(int) {
    p++;
    return this;
}
};

class C : public A {
private :
char x;

public :
C (short n, char c) : A (n), x(c) {}

double f (short i) {
    double somma = 0.0;
    for (int j=0; j<A::getLen(); j++) {
        somma += A::get(j);
    }
    return get(i) / somma;
}

string g(char c) {
    string xc = "";
    xc += x;
    xc += c;
    return xc;
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "x=" << x << ", f(3)=" << f(3);
    return os;
}
};

int main() {
    srand ( 111222333 );
A * vett [DIM ] ;
for ( int i =0; i<DIM; i ++){
short n=1+rand ( )%10;
if ( rand ()%2==0)
vett [ i ]= new B( n , rand ( )%10 );
else
vett [ i ]= new C( n , ( char ) ( rand ()%( 'z' - 'a' + 1 ) + 'a' ) ) ;
}

cout << "PUNTO UNO" << endl;
double media = 0;
string concat = "";
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
    if (vett[i] -> f(3)) {
    media += vett[i] -> f(3);
    }
    if (typeid(C) == typeid(*vett[i])) {
        concat += ((C*)vett[i]) -> g('h');
    }

}

cout << endl << "PUNTO DUE" << endl;
cout << endl;
cout << "media : " << media / DIM << endl;
cout << "concatenazione : " << concat << endl;

cout << endl << "PUNTO TRE" << endl;
cout << endl;
cout << "*vett[42] : " << *vett[42] << endl;
(*vett[42])[3] = 0.888;
cout << "(*vett[42])[3] : " << (*vett[42])[3] << endl;
cout << "*vett[42] : " << *vett[42] << endl;
cout << "(*vett[42])(0, 2) : " << (*vett[42])(0, 2) << endl;
cout << "*(++(*((B*)vett[42]))) : " << *(++(*((B*)vett[42]))) << endl;
cout << "*((*(B*)vett[42])++) : "<< *((*(B*)vett[42])++) << endl;
}