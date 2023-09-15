#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <typeinfo>
#include <climits>

using namespace std;
#define DIM 50

//Esame di Laboratorio 15 Febbraio 2019 C

class A {
private :
char *str;
short len;

public :
A (short m) {
    this -> len = m;
    this -> str = new char [len];
    for (int i=0; i<len; i++) {
        str[i] = rand() % ('z' - 'a' + 1) + 'a';
    }
}

double const virtual elab (short a) = 0;

short const getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", w=";
    for (int i=0; i<len; i++) {
        os << str[i];
    }
    os << ", ";
    return os;
}
 
protected :
char const get (short i) {
    return str[i % len];
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

double const elab(short a) {
    double somma = 0.0;
short *array = map();
for (int i=0; i<getLen(); i++) {
    somma += array[i];
}
return somma / p;
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << "p=" << p << ", elab(3)=" << elab(3);
    return os;
}

B* operator++(int) {
    p++;
    return this;
}

protected :
short *const map() {
short *array = new short [getLen()];
for (int i=0; i<getLen(); i++) {
    if ((get(i) != 'a') && (get(i) != 'e') && (get(i) != 'i') && (get(i) != 'o') && (get(i) != 'u') &&
    (get(i) != 'A') && (get(i) != 'E') && (get(i) != 'I') && (get(i) != 'O') && (get(i) != 'U') ) {
        array[i] = 1;
    }
    else {
        array[i] = 0;
    }
}
return array;
}
};

class C : public A {
private :
char x;

public :
C (short n, char c) : A(n) {
    this -> x = c;
}

double const elab (short r) {
    double count = 0.0;
    for (int i=0; i<getLen(); i++) {
        if (get(i) >= x) {
            count ++;
        }
    }
    return count / getLen();
}

string const g (char c) {
    string xc = "";
    xc += x;
    xc += c;
    return xc;
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << "x=" << x << ", elab(3)=" << elab(3);
    return os;
}

};

int main() {
srand ( 111222333 );
A * vett [DIM ] ;
for ( int i =0; i<DIM; i++) {
short n=1+rand ( )%10;
if ( rand ()%2==0)
vett [ i ]= new B( n , rand ()%10 + 1 ) ;
else
vett [ i ]= new C( n , ( char ) ( rand ()%( 'z' - 'a' + 1 ) + 'a' ) ) ;
}

cout << "PRIMO PUNTO " << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "SECONDO PUNTO"  << endl;
cout << endl;
double media = 0.0;
string concat = "";
for (int i=0; i<DIM; i++) {
    if (vett[i] -> elab(3)) {
    media += (vett[i]) -> elab(3);
    }
    if (typeid(*vett[i]) == typeid(C)) {
        concat += ((C*)vett[i]) -> g('h');
    }
}

cout << "Media = " << media / DIM << endl;
cout << "Concatenazione = " << concat << endl;

cout << endl << "TERZO PUNTO " << endl;
cout << endl;
cout << "*vett[46] = " << *vett[46] << endl;
cout << "(*((*(B*)vett[46]))++) = " << (*((*(B*)vett[46]))++) << endl;

}