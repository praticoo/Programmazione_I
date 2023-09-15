#include <iostream>
#include <typeinfo>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>

using namespace std;
#define DIM 50

//Esame di Laboratorio 8 Febbraio 2022 - Compito A

class A {
private :
double *vec;
short len;

public :
A (short w, double a, double b) {
    this -> len = w;
    this -> vec = new double [len];
    for (int i=0; i<len; i++) {
        vec[i] = a + ((double)rand() / RAND_MAX) * (b - a + 1);
    }
}

virtual bool test (short a) = 0;

virtual ostream& put (ostream& os) {
    os << typeid(*this).name() << " [";
    for (int i=0; i<len; i++) {
        os << vec[i] << " ";
    }
    os << "]";
    return os;
}

double& operator[](int i) {
    return vec[i % len];
}

protected :
double select (double x) {
    double media = 0.0;
    int count = 0;
    for (int i=0; i<len; i++) {
        if (vec[i] <= x) {
            media += vec[i];
            count ++;
        }
    }
    //if (count != 0) {
    return media / count;
    //}
    //else {
      //  return 0;
    //}
}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B : public A {
    private :
    short p;

    public :
    B (short m, short a, short b) : A(m, a, b) {
        this -> p = rand() % (-b + a + 1) - a;
    }

    bool test (short a) {
        if (p >= a) {
        return true;
        }
      return false;
    }

    virtual ostream& put (ostream& os) {
        A :: put(os);
        os << "p=" << p;
        return os;
    }
};

template <typename T>
class C : public A {
    private :
    T alpha;

    public :
    C (short n, double x, double y) : A (n, x, y) {
        if (typeid(T) == typeid(short)) {
            this -> alpha = n;
        }
        else {
            this -> alpha = -y + ((double)rand() / RAND_MAX) * (-x + y + 1);
        }
    }

    bool test (short r) {
       if ((g(r) / alpha) >= 1) {
        return true;
       }
       return false;
    }
    
    double g(double k) {
        return A :: select(k) * 2;
    }

    virtual ostream& put (ostream& os) {
        A :: put(os);
        os << "alpha=" << alpha;
        return os;
    }

};


int main() {
    srand(11223367);
    A*vec[DIM];

  for(unsigned short i=0; i<DIM; i++){
    short r = rand()%3;
    if(r==0) //
      vec[i] = new C<double>(rand()%5+5, 
			    rand()%5+5 + rand()/(RAND_MAX*1.0), 
			    rand()%10+10 + rand()/(RAND_MAX*1.0));
    else if(r==1)
      vec[i] = new C<short>(rand()%5+5, 
			    rand()%5+5 + rand()/(RAND_MAX*1.0), 
			    rand()%10+10 + rand()/(RAND_MAX*1.0));
    else // B       
      vec[i] = new B(rand()%5+5, rand()%5+5, rand()%15+10);
  }

  cout << "PUNTO UNO" << endl;
  cout << endl;
  double max = INT_MIN;
  int count = 0;
  for (int i=0; i<DIM; i++) {
    cout << i << ")" << *vec[i] << endl;
     if (typeid(C<double>) == typeid(*vec[i])) {
        if (((C<double>*)vec[i]) -> g(12) > max) {
            max = (((C<double>*)vec[i]) -> g(12));
        }
     }
     if (vec[i] -> test(12) == true) {
        count ++;
     }
  }

  cout << endl << "PUNTO DUE" << endl;
  cout << endl;
  cout << "max(g(12))=" << max << endl;
  cout << "count(test(12)==true)=" << count << endl;

  cout << endl << "PUNTO TRE" << endl;
  cout << endl;
  cout << "(*vec[2])[2]=" << (*vec[2])[2] << endl; 

}