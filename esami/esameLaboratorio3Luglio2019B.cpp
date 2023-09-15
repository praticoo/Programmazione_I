#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <typeinfo>
#include <climits>

using namespace std;
#define DIM 50

//Esame di Laboratorio 3 Luglio 2019 B

class A {
private :
char *s;
short len;

public :
A (short m) {
    this -> len = m;
    this -> s = new char [len];
    for (int i=0; i<len; i++) {
        s[i] = rand() % ('z' - 'a' + 1) + 'a'; 
    }
}

virtual double elab (short a) = 0;

short getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", s= ";
    for (int i=0; i<len; i++) {
        os << s[i];
    }
    os << ", ";
    return os;
}

protected :
char get (short i) {
    return s[i % len];
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

double elab (short a) {
    int C = 0;
    int V = 0;
    for (int i=0; i<getLen(); i++) {
        if  ( (get(i) != 'a' && get(i) != 'e' && get(i) != 'i' && get(i) != 'o' && get(i) != 'u' &&
        get(i) != 'A' && get(i) != 'E' && get(i) != 'I' && get(i) != 'O' && get(i) != 'U' ) ) {
            C ++;
        }
        else {
            V ++;
        }
    }
    return (double) V / (C + 1);
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << "p=" << p << ", elab(3)=" << elab(3);
    return os;
}

B* operator++ (int) {
    p++;
    return this;
}

protected :

bool test() {
    for (int i=0; i<4; i++) {
        if (get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u' ||
        get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U' ) {
            return true;
        }
    }
    return false;
}
};

class C : public A {
private :
char x;

public :
C (short n, char c) : A (n) {
    this -> x = c;
}

double elab (short r) {
    int caratteri = 0;
    for (int i=r % getLen(); i<getLen(); i++) {
        if (get(i) >= x) {
            caratteri ++;
        }
    }
return (double)caratteri / getLen();
}

string g (char c) {
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
A *vett[DIM];
for ( int i =0; i<DIM; i++) {
short n=1+rand ( )% 10;
if ( rand ()%2==0)
vett [ i ]= new B( n , rand ()%10 + 1 ) ;
else
vett [ i ]= new C ( n , ( char ) ( rand ( )% ( ( int ) 'z' - ( int ) 'a' + 1 ) + ( int ) 'a' ) ) ;
}

cout << "PUNTO UNO" << endl;
cout << endl;

for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "SECONDO PUNTO" << endl;
cout << endl;

double media = 0.0;
string concat = "";
for (int i=0; i<DIM; i++) {
    if (vett[i] -> elab(3)) {
        media += vett[i] -> elab(3);
    }
    if (typeid(C) == typeid(*vett[i])) {
        concat += (((C*) vett[i]) -> g('h'));
    }
}

cout << "Media = " << media / DIM << endl;
cout << "Concat = " << concat << endl;

cout << endl << "TERZO PUNTO" << endl;
cout << endl;

cout << "*vett[48] = " << *vett[48] << endl;
cout << "*((*(B*)vett[48])++) = " << *((*(B*)vett[48])++) << endl;


}