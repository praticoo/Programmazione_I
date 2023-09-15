#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <typeinfo>
#include <climits>

using namespace std;

#define DIM 50

//Esame di Laboratorio 15 / 02 / 2019 B

class A {
private : 
int x;

public :
A (int m) {
    this -> x = m;
}

virtual double const v (int a) = 0;

virtual ostream& put(ostream& os) {
    os << typeid(*this).name() << ", x=" << x;
    return os;
}

};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
int *ptr;
int l;

public :
B (int z, int y) : A (z) {
    this -> l = y;
    this -> ptr = new int [y];
    for (int i=0; i<y; i++) {
        ptr[i] = rand() % (100 - 1 + 1) + 1;
     }
}

double const v(int a) {
   return (double const)(1*1000) / (sum(a) + 1);
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << ", ptr=[";
    for (int i=0; i<l; i++) {
        os << ptr[i] << " ";
    }
    os << "], v(50)=" << v(50);
    return os;
}

 int& operator[](int i) {
    return ptr[i % l];
} 

protected :
int const sum (int t) {
    int somma = 0;
    for (int i=0; i<l; i++) {
        if (ptr[i] <= t) {
            somma += ptr[i];
        }
    }
    return somma;
}

};

template <typename T>
class C : public A {
private :
T k;

public :
C (int n) :  A(n) {
    if (typeid(T) == typeid(int)) {
        k = 2*n;
    }
    else {
        k = log (1 + (sin(n) * sin(n)));
    }
}

double const v (int r) {
    return g(r);
}

T const g (T w) {
    return k * (w + 1);
}

virtual ostream& put(ostream& os) {
    A :: put(os);
    os << ", k=" << k << ", v(50)=" << v(50);
    return os;
}

};
 
int main() {
    srand ( 111222333 );
A *vett [DIM ] ;
for ( int i =0; i<DIM; i++) {
int n=1+rand ( )%10;
switch ( rand ()%3) {
case 0 :
vett [ i ]= new B( n , rand ()%10 + 1 ) ;
break ;
case 1 :
vett [ i ]= new C<int >(n) ;
break ;
case 2 :
vett [ i ]= new C<double>(n) ;
}
}

cout << "PRIMO PUNTO" << endl;
cout << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "SECONDO PUNTO" << endl;
cout << endl;
double min = INT_MAX;
double max = INT_MIN;
double media = 0.0;
int count = 0;
for (int i=0; i<DIM; i++) {
    if (vett[i] -> v(50)) {
        if (vett[i] -> v(50) > max) {
            max = vett[i] -> v(50);
        }
        if (vett[i] -> v(50) < min) {
            min = vett[i] -> v(50);
        }
    }
    if (typeid(C<double>) == typeid(*vett[i])) {
        media += ((C<double>*)(vett[i])) -> g(5);
        count ++;
    }
}

cout << "Min = " << min << endl;
cout << "Max = " << max << endl;
cout << "Media = " << media / count << endl;


cout << endl << "TERZO PUNTO" << endl;
cout << endl;

cout << "*vett[40] = " << *vett[40] << endl;
cout << "((B*)vett[40])->operator[](40) = " << ((B*)vett[40])->operator[](40) << endl;
((B*)vett[40])->operator[](40) = 888;
cout << "Nuovo ((B*)vett[40])->operator[](40) = " << ((B*)vett[40])->operator[](40) << endl;
cout << "Nuovo *vett[40] = " << *vett[40];

}