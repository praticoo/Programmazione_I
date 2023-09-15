#include <iostream>
#include <typeinfo>
#include <climits>
#include <cstdlib>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

#define DIM 50

//Esame di Laboratorio 28 Febbraio 2019 C

class A {
private :
char *base;
short len;

public :
A (short m) {
    this -> len = m;
    this -> base = new char [len];
    for (int i=0; i<len; i++) {
        base[i] = rand() % ('z' - 'a' + 1) + 'a';
    }
}

virtual string extract (short x) = 0;

short getLen() {
    return len;
}

virtual ostream& put (ostream& os) {
    os << ": base=[";
    for (int i=0; i<len; i++) {
        os << base[i] << " ";
    }
    os << "], ";
    return os;
}
 
protected :

char get (short i) {
    return base [i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
string str;
double k;

public : 
B (short m, double p) : A (m) {
    this -> k = p;
    for (int i=0; i<getLen(); i++) {
        if ( (get(i) == 'a') || (get(i) == 'e') || (get(i) == 'i') || (get(i) == 'o') || (get(i) == 'u') || 
        (get(i) == 'A') || (get(i) == 'E') || (get(i) == 'I') || (get(i) == 'O') || (get(i) == 'U') ) {
            this -> str += get(i);
        }
    }
}

double foo(short s) {
    return sin (k + s) / log (s + 1);
}

string extract (short x) {
    string stringa = "";
    for (int i=0; i<x; i++) {
        stringa += get(rand() % getLen());
    }    
    return stringa;
}

virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "str=" << str << ", k=" << k << ", extract(3)=" << extract(3);
    return os;
}
};

class C : public A {
private : 
int y;

public :
C (short n, int k) : A (n) {
    this -> y = k;
}

string extract (short x) {
    string contenitore = "";
    string stringa = "";
    short count = 0;
            for (int i=0; i<getLen(); i++) {
                 if ( (get(i) != 'a') && (get(i) != 'e') && (get(i) != 'i') && (get(i) != 'o') && (get(i) != 'u') && 
                 (get(i) != 'A') && (get(i) != 'E') && (get(i) != 'I') && (get(i) != 'O') && (get(i) != 'U') ) {
                    count ++;
                    contenitore += get(i);
                 }
            }
            if (count <= x) {
                for (int i=0; i<contenitore.size(); i++) {
                    stringa += contenitore[i];
                }
            }
            else {
                for (int i=0; i<x; i++) {
                    stringa += contenitore[i];
                }
            }
    return stringa;
}

short g(short w) {
    return sin(w + y);
}


virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "y=" << y << ", extract(3)=" << extract(3);
    return os;
}

C* operator++(int) {
    y ++;
    return this;
}
};

int main () {
A*vett[DIM] ;
for ( int i =0; i<DIM; i ++){
short n=10+rand()%10;
switch (rand()%2){
case 0 :
vett[i]= new C( n , rand()%20 + 1 ) ;
break ;
case 1 :
vett[i]= new B( n , rand () / ( double ) RAND_MAX) ;
break ;
}
}

cout << "PRIMO PUNTO" << endl;
cout << endl;

for (int i=0; i<DIM; i++) {
    cout << i << ")";
    if (typeid(B) == typeid(*vett[i])) {
        cout << "B";
    }
    else {
        cout << "C";
    }
    cout << *vett[i] << endl;
}

cout << endl << "SECONDO PUNTO" << endl;
cout << endl;

double mediaUno = 0.0;
double mediaDue = 0.0;
for (int i=0; i<DIM; i++) {
    if (typeid(B) == typeid(*vett[i])){
    mediaUno += ((B*)(vett[i])) -> foo(5);
    }
    else {
    mediaDue += ((C*)(vett[i])) -> g(5);
    }
}

cout << "Media = " << ( mediaUno + mediaDue ) / DIM << endl;

cout << endl << "TERZO PUNTO" << endl;
cout << endl;
cout << "*vett[40] = C" << *vett[40] << endl;
cout << "(*((*(C*)(vett[40])))++) C= " << (*((*(C*)(vett[40])))++);

}