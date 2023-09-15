#include <typeinfo>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

//Esame di Laboratorio 26 / 07 / 2019 B

#define DIM 50

class A {
private :
int *vec;
short len;

public:
A (short m, int a, int b) {
    this -> len = m; 
    this -> vec = new int [len];
    for (int i=0; i<len; i++){
        vec[i] = rand() % (b - a + 1) + a;
    }
}

virtual double foo (short a) = 0;

short getLen() {
    return len;
}

virtual ostream& put (ostream& os) {
    os << typeid(*this).name() << ", vec=[";
    for (int i=0; i<len; i++) {
        os << vec[i] << " ";
    }
    os << "], ";
    return os;
}

int operator()(int i1, int i2) {
      int somma = 0;
       for (int i=i1; i<len && i<=i2; i++) {
             somma += vec[i];
       }
   return somma;
}

protected:
int get (short i) {
    return vec [i % len];
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private:
int p;

public:
B (short m, int x, int y) : A (m, x, y) {
p = get (rand() % getLen());
}

double foo(short a) {
    return ((prod(a)) / p ); 
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "p=" << p << ", foo(3)=" << foo(3);
    return os;
}

protected:
int prod (short s) {
    int prodotto = 1;
    for (int i=s; i<getLen(); i++) {
        prodotto *= get(i);
    }
    return prodotto;
}
};

template <typename T>
class C : public A {
private :
T x;

public:
C (short n, int a, int b) : A (n, a, b) {
    if (typeid(T) == typeid(short)){
        this -> x = n;
    }
    else {
        this -> x = log(1 + (sin(n) * sin(n)));
    }
}

double foo(short r) {
    return g(r);
}

T g(T k) {
    return 2 * x * (k + 1);
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "x=" << x << ", foo(3)=" << foo(3);
    return os;
}
};

int main() {
srand(111222333);
A *vett[DIM];
for (int i = 0; i < DIM; i++) {
        short n = 1 + rand() % 10;
        switch (rand() % 3) {
        case 0:
            vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 1:
            vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 2:
            vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
        }
    }
cout << "PRIMO PUNTO" << endl;
for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vett[i] << endl;
}

/* si calcoli il massimo valore foo(3) per tutti gli oggetti della collezione e la media dei valori g(5) per 
tutti gli oggetti di tipo C<double>; */
cout << endl << "SECONDO PUNTO" << endl;
double somma = 0;
double count = 0; 
double max = INT_MIN;
for (int i=0; i<DIM; i++) {
    if (typeid(*vett[i]) == typeid(C<double>)){
           count ++;
           somma += ((C<double>*)vett[i]) -> g(5); 
    }
    if ((vett[i] -> foo(3)) > max) {
          max = (vett[i]) -> foo(3);
    }
} 
cout << "Max = " << max << ", Avg =  " << somma / count << endl;

/* si implementi l’overloading dello operatore membro “()” per la classe A e lo si utilizzi nel main. La
funzione di overloading dovra' prevedere due argomenti interi i1 e i2 e restituire la somma di tutti gli
elementi presenti in vec, dall’indice i1 all’indice i2. */
cout << endl << "TERZO PUNTO" << endl;
cout << "*vett[10] = "<< *vett[10] << endl;
cout << "*vett[10](4,8) = "<< (*vett[10])(4,8) << endl;

}