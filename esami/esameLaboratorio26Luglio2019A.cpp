#include <iostream>
#include <typeinfo>
#include <climits>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;
#define DIM 50

//Esame di Laboratorio 26 / 07 / 2019 - A

class A {
private :
char *str;
short len;

public :
A (short m, string source) {
    this -> len = m;
    this -> str = new char [len];
    for (int i=0; i<len; i++) {
        str[i] = source[rand() % source.size()]; 
    }
}

virtual char func (short i) = 0;

short getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", str = ";
    for (int i=0; i<getLen(); i++) {
        os << str[i];
    }
    os << " , ";
    return os;
}

string operator()(int i1, int i2) {
    string stringa = "";
    for (int i=i1; i<=i2; i++) {
         stringa += str[i];
    }
    return stringa;
}

protected : 
char get (short i) {
    return str [i % len]; 
}

};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
short p;

public : 
B (short m, string source) : A (m, source) {
    short vocali = 0;
    for (int i=0; i<getLen(); i++) {
        if ( (get(i) == 'a') || (get(i) == 'e') || (get(i) == 'i') || (get(i) == 'o') || (get(i) == 'u') ||
        (get(i) == 'A') || (get(i) == 'E') || (get(i) == 'I') || (get(i) == 'O') || (get(i) == 'U') ) {
            vocali = vocali + 1;
        }
    }
    this -> p = (1 + vocali);
}

char func (short i) {
    char consonante;
    if (i < getLen()) {
    for (int j=i; j<getLen(); j++) {
        if ( (get(i) != 'a') && (get(i) != 'e') && (get(i) != 'i') && (get(i) != 'o') && (get(i) != 'u') &&
        (get(i) != 'A') && (get(i) != 'E') && (get(i) != 'I') && (get(i) != 'O') && (get(i) != 'U') ) {
            consonante = get(i);
            break;
        }
        else {
            consonante = 'X';
        }
    }
    }
    else {
        consonante = 'X';
    }
    return consonante;
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << "p=" << p << ", func(3)=" << func(3);
    return os;
}

};

class C : public A {
private :
char x;

public : 
C (short n, string source, char y) : A (n, source) {
    this -> x = y;
}

char func (short i) {
    char consonante;
    if (i<getLen()){
    for (int j=i; j<getLen(); j++) {
        if ( (get(i) != 'a') && (get(i) != 'e') && (get(i) != 'i') && (get(i) != 'o') && (get(i) != 'u') &&
        (get(i) != 'A') && (get(i) != 'E') && (get(i) != 'I') && (get(i) != 'O') && (get(i) != 'U') && (get(i) > x)) {
            consonante = get(i);
            break;
        }
        else {
            consonante = x;
        }
    }
    }
    else {
        consonante = x;
    }
    return consonante;
}

string g (char c) {
    string risultato = "";
    risultato += x;
    for (int i=0; i<getLen(); i++) {
        risultato += get(i);
    }
    risultato += c;
    return risultato;
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << "x=" << x << ", func(3)=" << func(3);
    return os;
}

};
 
int main() {
srand (111222333);
A* vett[DIM] ;
string S= "supercalifragilistichespiralidoso" ;
for ( int i =0; i<DIM; i ++){
short n=3+rand() % 10;
if ( rand () % 2 == 0)
vett[i]= new B(n, S) ;
else
vett[i]= new C(n ,S , (char)(rand() % ('z' - 'a' + 1)+ 'a'));
}

cout << "PUNTO UNO" << endl;
cout << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "PUNTO DUE" << endl;
cout << endl;
string concat = "";
for (int i=0; i<DIM; i++) {
    if (typeid(*vett[i]) == typeid(C)) {
         concat += ((C*)vett[i]) -> g('h');
    }
}
cout << "Concatenazione g('h') = " << concat << endl;

cout << endl << "TERZO PUNTO" << endl;
cout << endl;
cout << "*vett[49] = "<< *vett[49] << endl;
cout << "(*vett[49])(2,4) = " << (*vett[49])(2,4) << endl;
}