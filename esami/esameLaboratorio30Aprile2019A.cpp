#include <iostream>
#include <cstring>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;
#define DIM 50
// Esame di Laboratorio 30 / 04 / 19 - A

class A
{
private:
    char *str;
    short len;

public:
    A(short m, string source)
    {
        this->len = m;
        this->str = new char[m];
        for (int i = 0; i < len; i++)
        {
            str[i] = source[rand() % source.size()];
        }
    }

    virtual char func(short i) = 0;

    short getLen()
    {
        return len;
    }

    virtual ostream &put(ostream &os)
    {
        os << typeid(*this).name() << ", str = ";
        for (int i = 0; i < len; i++)
        {
            os << str[i];
        }
        os << " , ";
        return os;
    }

    string operator()(int i1, int i2) {
        string sotto = "";
        for (int i=i1; i<=i2; i++) {
            sotto += str[i];
        }
        return sotto;
    }

    char& operator[](int i) {
        return str[i % len];
    }

protected:
    char get(short i)
    {
        return str[i % len];
    }
};

ostream &operator<<(ostream &os, A &obj)
{
    return obj.put(os);
}

class B : public A
{
private:
    short p;

public:
    B(short m, string source) : A(m, source)
    {
        short vocali = 0;
        for (int i = 0; i < getLen(); i++)
        {
            if (get(i) == 'a' || get(i) == 'e' || get(i) == 'i' || get(i) == 'o' || get(i) == 'u' ||
                get(i) == 'A' || get(i) == 'E' || get(i) == 'I' || get(i) == 'O' || get(i) == 'U')
            {
                vocali++;
            }
        }
        this->p = vocali + 1;
    }

    char func(short i)
    {
        for (int j = i; j < getLen(); j++)
        {
            if (get(j) != 'a' && get(j) != 'e' && get(j) != 'i' && get(j) != 'o' && get(j) != 'u' && get(j) != 'A' &&
                get(j) != 'E' && get(j) != 'I' && get(j) != 'O' && get(j) != 'U')
            {
                return get(j);
            }
        }
        return 'X';
    }

    virtual ostream &put(ostream &os)
    {
        A ::put(os);
        os << "p=" << p << ", func(3)=" << func(3);
        return os;
    }

    B* operator++() {
        ++p;
        return this;
    }

    B* operator--() {
        --p;
        return this;
    }

     B* operator++(int) {
        p++;
        return this;
    }

    B* operator--(int) {
        p--;
        return this;
    }
};

class C : public A
{
private:
    char x;

public:
    C(short n, string source, char y) : A(n, source), x(y) {}

    char func(short i)
    {
        for (int j = i; j < getLen(); j++)
        {
            if (get(j) > x)
            {
                return get(j);
            }
        }
        return x;
    }

    string g(char c)
    {
        string xstrc = "";
        xstrc += x;
        for (int i = 0; i < getLen(); i++)
        {
            xstrc += get(i);
        }
        xstrc += c;
        return xstrc;
    }

    virtual ostream &put(ostream &os)
    {
        A ::put(os);
        os << "x=" << x << ", func(3)=" << func(3);
        return os;
    }
};

int main()
{
    srand(111222333);
    A * vett[DIM];
    string S = "supercalifragilistichespiralidoso" ;
    for (int i = 0; i < DIM; i++)
    {
        short n = 3 + rand() % 10;
        if(rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a' ));
    }

    cout << "PUNTO UNO" << endl;
    cout << endl;
    string concat = "";
    for (int i=0; i<DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
        if (typeid(C) == typeid(*vett[i])) {
            concat += ((C*)vett[i]) -> g('h'); 
        }
    }

    cout << endl << "SECONDO PUNTO" << endl;
    cout << endl;
    cout << "concat = " << concat << endl;

    cout << endl << "TERZO PUNTO" << endl;
    cout << endl;
    cout << "*vett[43] : " << *vett[43] << endl;
    cout << "(*vett[43])(2, 5) : " << (*vett[43])(2,5) << endl;

    cout << endl << "Operatore Parentesi Quadre : " << endl;
    cout << endl;

    cout << "(*vett[43])[2] : " << (*vett[43])[2] << endl;
    (*vett[43])[2] = 'A';
    cout << "(*vett[43]) : " << *vett[43] << endl;
    
    cout << endl << "Operatore ++ PreFisso e PostFisso" << endl;
    cout << endl;
    cout << "*(++(*((B*)vett[43]))) : " << *(++(*((B*)vett[43]))) << endl;
    cout << "*vett[47] : " << *vett[47] << endl;
    cout << "*((*(B*)vett[47])++) : " << *((*(B*)vett[47])++) << endl;

    cout << endl << "Operatore -- PreFisso e PostFisso" << endl;
    cout << endl,
    cout << "*(--(*((B*)vett[43]))) : " << *(--(*((B*)vett[43]))) << endl;
    cout << "*((*(B*)vett[47])--) : " << *((*(B*)vett[47])--) << endl;

}