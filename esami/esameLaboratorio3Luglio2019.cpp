#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

#define DIM 50

//Esame di Laboratorio 3 Luglio 2019

class A {
private :
int *arr;
short len;

public :
A (short m, int a, int b) {
    this -> len = m;
    this -> arr = new int [m];
    for (int i=0; i<len; i++) {
        arr[i] = rand() % (b - a + 1) + a;
    }
}

virtual double func (short i) = 0;

short getLen() {
    return len;
}

virtual ostream& put (ostream& os) {
    os << typeid(*this).name() << ", arr=[";
    for (int i=0; i<len; i++) {
        os << arr[i] << " ";
    }
    os << "], ";
    return os;
}

int& operator[] (short i) {
    return arr[i % len];
}

protected :
double get (short i) {
    return arr [i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
double p;

public :
B (short m, int y, int z, double x) : A (m, y, z) {
    this -> p = x;
}

double func (short i) {
    int max  = INT_MIN;
    int min = INT_MAX;

    for (int i=0; i<getLen(); i++) {
         if (get(i) > max) {
            max = get(i);
         }
         if (get(i) < min) {
            min = get(i);
         }
    }
    return (double)min / max;
} 

virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "p=" << p << ", func(3)=" << func(3);
    return os;
}
};

class C : public A {
private : 
char t;

public : 
C (short n, char c, int a, int b) : A (n, a, b) {
    this -> t = c;
}

double func (short i) {
    double media = 0.0;
    for (int i=0; i<getLen(); i++) {
        media += get(i);
    }
    return media / getLen();
}

string g (char c, short k) {
    string tc = "";
    for (int i=0; i<k; i++) {
        tc += this -> t;
        tc += c;
    }
    return tc;
}

virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "t=" << t << ", func(3)=" << func(3);
    return os;
}
};

int main() {
  srand (111222333);
  A* vett[DIM];
for ( int i =0; i<DIM; i ++){
short n=1+rand ()% 10;
if ( rand ()%2==0)
vett [ i ]= new B( n , rand ()%5+1, rand ()%11+10, ( double ) rand ( ) / (RAND_MAX) ) ;
else
vett [ i ]= new C( n , ( char ) ( rand ()%( 'z' - 'a' + 1 ) + 'a' ) , rand ()%5+1, rand ()%11+10);
}

cout << "PRIMO PUNTO" << endl;
cout << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "SECONDO PUNTO" << endl;
cout << endl;
double media = 0.0;
for (int i=0; i<DIM; i++) {
    if (vett[i] -> func(3)) {
        media += vett[i] -> func(3);
    }
}

cout << "Media = " << media << endl;

int count = 0; 
for (int i=0; i<DIM; i++) {
    if (typeid(*vett[i]) == typeid(C) && count < 4) {
        cout << "((C*)vett[" << i << "]) -> g('h',2) = " << ((C*)vett[i]) -> g('h', 2) << endl;
        count ++;
        if (count == 3) {
            break;
        }
    }
}

cout << endl << "TERZO PUNTO" << endl;
cout << endl;
cout << *vett[48] << endl;
cout << (*vett[48])[3] << endl;
(*vett[48])[3] = 69;
cout << (*vett[48])[3] << endl;
cout << *vett[48] << endl;
}