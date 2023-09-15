#include <iostream>
#include <cmath>
#include <cstdlib>
#include <typeinfo> //per il tipo
using namespace std;

//ESAME DI LABORATORIO 24 / 06 / 2021

/*RIPASSO
+ sta per public, - per private, # per protected
metodi da implementare nelle nuvolette, alcune funzioni da non implementare perchè definite banali, ad esempio le funzioni get ritornano la
variabile privata (getLen, return len)
Primo passo : Implementare Classi A B C
Secondo passo : Fare primo, secondo e terzo punto
Per primo punto : Overloading dell' operatore <<
Bisogna stampare il count { 1, 2..50) } , il tipo, la stampa del vettore, il valore di y della classe C, foo(3) della classe C
Se il tipo è della classe C
Per la classe B, stampare count, tipo, vettore, il valore di p, e foo(3)
La parte della stampa del vettore possiamo farla direttamente nella classe A
Cominciamo ad implementare nella classe public A
*/

// Definiamo la dimensione del vettore
#define DIM 50
class A
{
private:
    double *vec;
    short len;

public:
    A(short w, double a, double b)
    {
        this->len = w;
        this->vec = new double[len];
        for (int i = 0; i < len; i++)
        {
            vec[i] = a + ((double)rand() / RAND_MAX) * (b - a + 1);         //elementi double compresi tra a e b, IMPORTANTE!
        }
    }

    short getLen()
    {
        return len;
    }

    // Le funzioni virtual si pongono = 0 perchè sarà inizializzata successivamente
    virtual double foo(short a) = 0;

    /*Punto Uno:
    Creo una funzione virtual, deve tornare un ostream&, la chiamiamo put, come parametri formali prende in input un ostream& che chiamiamo os.
    Visto che la classe è virtual facciamo l'operatore al di fuori della classe.
    */
    virtual ostream &put(ostream &os)
    {
        // prima cosa dobbiamo stampare il tipo
        // all'interno di typeid dobbiamo deferenziare la classe corrente
        os << typeid(*this).name() << ", vec= [";
        // poi stampiamo tutti i valori, servendoci di un ciclo for
        for (short i = 0; i < len; i++)
        {
            os << vec[i] << " ";
        }
        os << "], ";
        return os;
    }
//Su public della classe A implementiamo il terzo punto
//elementi vettore sono double allora torniamo double
double& operator[](int i){
    return vec[i % len];
} 

protected:
    double get(short i)
    {
        return vec[i % len];
    }
};

ostream &operator<<(ostream &os, A &obj)
{ // qui in input prendiamo pure un oggetto A& che mi serve, che chiamiamo obj
    return obj.put(os);
}

class B : public A
{
private:
    int p;

public:
    B(short m, short x, short y) : A(m, x, y)
    {
        p = rand() % (100 * y - 10 * x + 1) + 10 * x;
    }

    double foo(short a)
    {
        return log(prod(a, a / 2.0));
    }

protected:
    double prod(short s, double v)
    {
        double somma = 0.0;
        for (short i = s; i < getLen(); i++)
        {
            somma += get(i);
        }
        return v * somma;
    }

    // continuo il primo punto, mi serve la classe B
    virtual ostream &put(ostream &os)
    {
        A ::put(os);
        os << "p= " << p << ", foo(3)=" << foo(3);
        return os;
    }
};

template <typename T> // o class T
class C : public A
{
private:
    T y;

public:
    C(short n, double x, double y) : A(n, x, y)
    {
        if (typeid(T) == typeid(short))
        { // possiamo mettere pure typeid(this -> y)
            this->y = n;
        }
        else
        {
            this->y = 1 + (cos(n) * cos(n));
        }
    }

    double foo(short r)
    {
        return g(r);
    }

    double g(double k)
    {
        return (2.0 * y) * (k + 1);                    //visto che deve tornare double, per sicurezza mettiamo il .0
    }

    // per completare primo punto facciamo la stessa cosa della classe B
    virtual ostream &put(ostream &os)
    {
        A ::put(os); // questo identico
        os << "y= " << y << ", foo(3)=" << foo(3);
        return os;
    }
};

int main(){
    //per indentare il codice usare la combinazione : Alt + Maiuscolo + F
    A *vett[DIM]; // per inizializzare vettore della classe A, di dimensione DIM
    // adesso stampiamo il primo punto, il main lo troviamo nel pdf che ci danno
    srand(111222333);
    for (int i = 0; i < DIM; i++)
    {
        short n = 5 + rand() % 5;
        switch (rand() % 3)
        {
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

cout << "PUNTO 1" << endl;

    for (int i=0; i<DIM; i++){
        cout << i << ")"<< *vett[i] << endl;
    }

cout << "PUNTO 2" << endl;

//Per trovare il valore massimo ci serviamo di un ulteriore variabile che inizializziamo con il valore minimo
double max = -1;
double somma_g = 0;
int count = 0;
for (int i=0; i<DIM; i++){
       if(vett[i] -> foo(3) > max){
        //così per trovare il massimo
        max = vett[i] -> foo(3);
       }
       if (typeid(*vett[i]) == typeid(C<double>)){
        somma_g += ((C<double>*)vett[i]) -> g(0.5);
        count++;
       }
}

cout << "Max = " << max << ", avg = " << somma_g / count;

cout << endl;

cout << "PUNTO TRE" << endl;
cout << *vett[10] << endl;
cout << "(*vett[10])[0] = " << (*vett[10])[0] << endl;
(*vett[10])[0] = 4.5;
cout << "(*vett[10])[0] = " << (*vett[10])[0] << endl;
}