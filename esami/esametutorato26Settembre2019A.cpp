#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
#include <climits>

using namespace std;
#define DIM 50
//Class A, astratta perchè contiene metodo virtual che sarà inizializzato successivamente.
//Una classe ne può possedere anche più di uno.

//Esame di Laboratorio 26 / 09 / 2019 A
class A {
private:
char *str;
short len;

public:

 A(short m, string source){
    this -> len = m;                                         
    this -> str = new char [m];                                 
    string consonanti = "";                        
    int count = 0;                          
    for (int i=0; i<source.size(); i++){
    if ( source[i] == 'a' ||source[i] == 'e' ||source[i] == 'i' ||source[i] == 'o' ||source[i] == 'u' ||
    source[i] == 'A' ||source[i] == 'E' ||source[i] == 'I' ||source[i] == 'O' ||source[i] == 'U'){
            if (count < m){
                str[count ++] = source [i];
            }
    }
        else{
                consonanti += source [i];                                  
        }

    }
for (int i=0; i < consonanti.size(); i++){
    if (count < m){
    str[count++ ] = consonanti[i];  
    }
}

} 

virtual ostream& put (ostream& os){
os<<typeid(*this).name()<<", str= ";
for (int i=0; i<len; i++){
    os<<str[i]<<"";
}
os<<", ";
return os;
}

string operator()(int i1, int i2){
string sottostringa = "";
for (int i=i1; i<i2; i++){
    sottostringa += str[i];
}
    return sottostringa;
}


virtual string func(short k) = 0;

short getLen(){
    return len;
}

protected:
char get(short i){
    return str[i % len];
}
};

ostream& operator<<(ostream& os, A& obj){
return obj.put(os);
}

class B : public A{
private:
short q;

public:
B(short m, string source) : A(m, source){
this -> q = 1 + rand() % getLen();
}

string func(short k){
    string inversa = "";
    for (int i=0; i<getLen(); i++){
          inversa = get(i) + inversa;
    }
string sotto = "";
for (int i=0; i<k; i++){
sotto += inversa[i];
}
return sotto;
}

virtual ostream& put(ostream& os){
    A :: put(os);
    os << "q=" << q << ", func(3)=" << func(3);
    return os;
}
};

class C : public A{
private : 
char y;

public:
C (short n, string source, char y) : A(n, source){
    this -> y = y;
}

string func(short k){
    string stringa = "";
    for (int i=k; i < getLen(); i++){
      stringa = get(i) + stringa;
    }
    return stringa;
}

string g(char c){
    string s = "";
    for (int i=0; i<getLen(); i++){
       s += get(i);
    }
    return  this -> y + s + c;
}

virtual ostream& put(ostream& os){
    A :: put(os);
    os << "y=" << y << ", func(3)=" << func(3);
    return os;
}
};

int main(){
A *vett[DIM];
 srand(111222333);
    string S;
    short fa = 3;
    for (int i = 0; i < DIM; i++) {
        short n = 10 + rand() % 10;
        S = "";
        for (int k = 0; k < 20; k++)
            S += rand() % ('z' - 'a' + 1) + 'a';
        if (rand() % 2 == 0)
            vett[i] = new B(n, S);
        else            vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

cout << "PUNTO UNO" << endl;
for (int i=0; i<DIM; i++){
    cout << i << ")" << *vett[i] << endl;
}

cout << endl << "PUNTO DUE" << endl;
for (int i=DIM-1; i>=0; i--){
    if (typeid(*vett[i]) == typeid(C)){
        cout << "g('X')= " << ((C*)vett[i]) -> g('X') << endl;
        break;
    }
}


cout << endl << "PUNTO TRE" << endl;
cout << "*vett[5] = " << *vett[5] << endl;
cout << "vett[5](1,3) = " << (*vett[5])(1,3) << endl;
}

 
