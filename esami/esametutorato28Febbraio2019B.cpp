#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;

#define DIM 50

//Esame di Laboratorio 28 / 02 / 2019 B

class A {
private:
char *ptr;
short len;

public:
A (short m, char c){
    this -> len = m;
    this -> ptr = new char [len];
    for (int i=0; i<len; i++){
        ptr[i] = rand() % (c - 'a' + 1) + 'a';
    }
}

virtual string elab (short a, char c) = 0;

short getLen() {
    return len;
}

virtual ostream& put(ostream& os) {
    //os << typeid(*this).name() << " ptr=[";
    cout << "ptr=[";
    for (int i=0; i<len; i++) {
        os << ptr[i] << " ";
    }
    os << "], ";
    return os;
}

//all'interno delle parentesi un indice, allora usiamo int o short
char& operator[](short c){
   return ptr [c % len];
}

protected:

char get (short i) {
    return ptr [i % len];
}

};

ostream& operator<< (ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
    private :
    double x;

    public:
    B (short m, double y, char c) : A (m, c) {
        this -> x = y;
    }

    double foo (short s) {
        return ((sin (this -> x + s)) / (log (this -> x + s)));
    }

    string elab (short a, char c) {
        string risultato = "";
        for (int i=0; i<getLen(); i++) {
            if (abs( get(i) - c )<= a) {
                risultato += get(i);
            }
        }
        return risultato;
    }

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "x=" << x << ", elab(5,z)=" << elab (5, 'z') << endl;
    return os;
}

};

template <typename T>
class C : public A {
private:
T y;

public:
C (short n, double k, char c) : A (n, c) {
    if (typeid(T) == typeid(short)){
        this -> y = round (100 *k);
    }
    else {
        this -> y = k;
    }
}

string elab (short a, char c) {
    string risultato = "";
    if (getLen() >= a){
        for (int i=0; i < a; i++){
            risultato += c;
        }
    }
    else {
        for (int i=0; i<getLen(); i++){
            risultato += get(i);
        }
    }
    return risultato;
}

double g(short w) {
    return sin (w + this -> y);
}

virtual ostream& put(ostream& os) {
    A :: put (os);
    os << "y=" << y << ", elab(5,z)=" << elab (5, 'z') << endl;
    return os;
}
};

int main() {
srand(111222333);
A *vett[DIM];
for(int i=0; i<DIM; i++) {
        short n=1 + rand() % 10;
        switch(rand() % 3) {
            case 0:
                vett[i]= new B(n, (double) rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a' );
                break;
            case 1:
                vett[i]= new C<double>(n, (double)rand() / RAND_MAX, rand()%('z' - 'a' + 1) + 'a');
                break;
            case 2:
                vett[i]= new C<short>(n, (double) rand() / RAND_MAX, rand()%('z' - 'a' + 1) + 'a');
        }
    }

cout << "PUNTO UNO" << endl;
for (int i=0; i<DIM; i++){
    cout << i << ")" ;
    if (typeid(*vett[i]) == typeid(B)){
         cout << "B ";
    }
    else if (typeid(*vett[i]) == typeid(C<short>)){
         cout << "C<short> ";
    }
    else {
        cout << "C<double> ";
    }
  cout << *vett[i] << endl;
}

/* si calcoli la media dei valori foo(5) per tutti gli oggetti di tipo B, e la media dei valori g(5) per tutti gli
oggetti di tipo C<short>; */
cout << endl << "PUNTO DUE" << endl;
double media = 0.0;
double mediaDue = 0.0;
int count = 0;
int countDue = 0;
for (int i=0; i<DIM; i++){
    if (typeid(*vett[i]) == typeid(B)){
        media += ((B*)vett[i]) -> foo(5);
        count ++;
    }
    if (typeid(*vett[i]) == typeid(C<short>)){
        mediaDue += ((C<short>*)vett[i]) -> g(5);
        countDue ++;
    }
} 

cout << "avg(foo(5)= " << media / count << ", avg(g(5))= "<< mediaDue / countDue << endl;

cout << endl << "PUNTO TRE" << endl;
cout << (*vett[0]) << endl;
(*vett[0])[0] = '*';
cout << *vett[0] << endl;
}