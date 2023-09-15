#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <typeinfo>
using namespace std;

#define DIM 50

//Esame di Laboratorio 15 / 02 / 2019 D

class A {
private :
int *ptr;
short len;

public:
A (short m, short k){
    this -> len = m;
    this -> ptr = new int [m];
    for (int i=0; i<m; i++){
        ptr[i] = rand() % k + 1; 
    }
}

virtual double const f() = 0;

int get (short i){
    return ptr [i % len];
}

short getLen(){
    return len;
}

virtual ostream& put(ostream& os){
    os << typeid(*this).name() << ", ptr= [";
    for (int i=0; i<len; i++){
        os << ptr[i] << " "; 
    }
os << "],";
return os;
}

int& operator[](int i){
    return ptr[i % len];
}

};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A {
private:
double p;

public:
B (short m, short k, double y) : A (m, k){
    this -> p = y;
}

double const f(){
    int somma = 0;
    for (int i=0; i<getLen(); i++){
         if (get(i) % 2 == 0){
            somma += get(i);
         }
    }

    return somma / this -> p;
}

virtual ostream& put(ostream& os){
    A :: put(os);
os << " p=" << p << ", f()=" << f() << endl;
return os;
}
};

class C : public A {
private :
char x;

public:
C (short n, short k, char c) : A (n, k){
    this -> x = c;
}

double const f(){
    double count = 0; 
    double somma = 0;
    for (int i=0; i<getLen(); i++){
        if (get(i) % 2 != 0){
            somma += get(i);
            count ++;
        }
    }

    if (count == 0){
        return 0;
    }
    else {
        return somma / count;
    }
}

string const g(char c) {
    string xc = "";
    xc += this -> x;
    xc += c;
    return xc;
}

virtual ostream& put(ostream& os){
    A :: put(os);
os << " x=" << x << ", f()=" << f() << endl;
return os;
}
};

int main () {
srand(111222333);
A *vett[DIM];

for (int i = 0; i < DIM; i++) {
	short n = 1 + rand() % 10;
	short m = 1 + rand() % 8;
	if (rand() % 2 == 0)
		vett[i] = new B(n, m, rand() / (double)RAND_MAX + 0.05);
	else
		vett[i] = new C(n, m, (char)(rand() % ('z' - 'a' + 1) + 'a'));
}  

cout << "PUNTO UNO" << endl;
 
for (int i=0; i<DIM; i++){
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "PUNTO DUE" << endl;

double media = 0;
string concatenazione = "";
for (int i=0; i<DIM; i++){
           media += vett[i] -> f();
           if (typeid(*vett[i]) == typeid(C)){
            concatenazione += ((C*)vett[i]) -> g('h');
           }
}
cout << "Avg(f())= "<< media / DIM << ", concat=" << concatenazione << endl;

cout << endl << "PUNTO TRE" << endl;

cout << "vett[5]=" << (*vett[5])[0] << endl;
(*vett[5])[0] = -1;
cout << "vett[5]=" << (*vett[5])[0] << endl;

}