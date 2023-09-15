#include <iostream>
#include <string>
#include <climits>
#include <cstdlib>
#include <typeinfo>
#include <cmath>

using namespace std;
#define DIM 50

//Esame di Laboratorio 8 Febbraio 2022 - Compito B

class A {
private :
char* str;
short len;

public :
A (short w, char c1, char c2) {
    this -> len = w;
    this -> str = new char [len];
    for (int i=0; i<len; i++) {
        str[i] = rand() % (c2 - c1 + 1) + c1;
    }
}

virtual short f(short k) = 0;

virtual ostream& put (ostream& os) {
    os << " str=";
    for (int i=0; i<len; i++) {
        os << str[i];
    }
    os << ", ";
    return os;
}

string operator() (int i1, int i2) {
    string sotto = "";
    for (int i=i1; i<=i2; i++) {
        sotto += str[i];
    }
    return sotto;
}

protected :
string extract (short k) {
    string stringa = "";
    if (k >= len) {
        for (int i=0; i<len; i++) {
            stringa += str[i];
        }
    }
    else {
        for (int i=len-1; i>=len - k; i--) {
            stringa = str[i] + stringa;
        }
    }
    return stringa;
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
private :
char z;

public :
B (short m, char c1, char c2) : A (m, c1, c2) {
    string stringa = extract (m / 2 + 1);
    this -> z = stringa [rand() % stringa.size()];
}

short f (short k) {
    string stringa = extract(k);
    short count = 0;
    for (int i=0; i<stringa.size(); i++) {
        if (stringa[i] <= z) {
            count ++;
        }
    }
    return count;
}

virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "z=" << z;
    return os;
}
};

template <class T>
class C : public A {
private :
T ss;

public :
C (short w, char c1, char c2) : A (w, c1, c2) {
    if (typeid(T) == typeid(string)) {
        string stringa = extract ((w/2)+1);
        for (int i=0; i<stringa.size(); i++) {
            ss += stringa[i];
        }
    }
    else {
        ss = w;
    }
}

short f (short k) {
    string stringa = extract(k);
    short valore = 0;
    for (int i=0; i<stringa.size(); i++) {
        if (stringa[i] >= 'A' && stringa[i] <= 'Z') {
             valore = 1;
             break;
        }
    } 
    return valore;
}

T foo (short x) {
    T r = ss;
    for (int i=1; i<x; i++) {
        r += ss;
    }
    return r;
}

virtual ostream& put (ostream& os) {
    A :: put(os);
    os << "ss=" << ss;
    return os;
}
};

int main() {
srand(12345678);
A *vec[DIM];                                
for(unsigned int i=0; i<DIM; i++){
    int r = rand(); 
    if(r%3==0) // B 
      vec[i] = new B(rand()%10+5, '0', '9');
    else if(r%3==1)
      vec[i] = new C<string>(rand()%10+5, 'a', 'z');
    else
      vec[i] = new C<short>(rand()%20+10, 'A', 'Z');
  }

  cout << "PUNTO UNO" << endl;
  int somma = 0;
        for (int i=0; i<DIM; i++) {
            cout << i << ")";
            if (typeid(*vec[i]) == typeid(B)) {
                cout << "B";
            }
            else if (typeid(*vec[i]) == typeid(C<short>)) {
                cout << "C<short>";
            }
            else {
                cout << "C<string>";
            }
            cout << *vec[i] << endl;
        }

    cout << "PUNTO DUE" << endl;
    short count = 0;
    for (int i=0; i<DIM; i++) {
        if ((vec[i] -> f(5) >= 4)) {
                    count ++;
                }
                if (typeid(*vec[i]) == typeid(C<short>)) {
                    somma += ((C<short>*)(vec[i])) -> foo(3);
            }
    }
    cout << "count(f(5)<=4)=" << count << endl;
    cout << "sum(foo(3))=" << somma << endl;

    cout << "PUNTO TRE" << endl;
    cout << *vec[9] << endl;
    cout << (*vec[9])(0,3) << endl;
}




