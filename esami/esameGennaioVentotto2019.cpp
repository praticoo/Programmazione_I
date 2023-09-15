#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice di stringhe A e due numeri short senza segno, k ed
s, e restituisca il valore booleano true se esiste almeno una riga di A contenente almeno k stringhe ognuna
contenente un numero di lettere maiuscole minore di s. */

//Esame 28 Gennaio 2019

bool esercizioDue(string **A, int n, unsigned short k, unsigned short s){
    for (int i=0; i<n; i++){
        unsigned short string = 0;
        for (int j=0; j<n; j++){
            unsigned short count = 0;
            for (int z=0; z<A[i][j].size(); z++){
                if (isupper(A[i][j][z])){
                     count ++;
                }
            }
            if (count < s){
                string ++;
            }
        }
        if (string >= k){
            return true;
        }
    }
    return false;
}


int main(){
    int n = 3;
string **A = new string *[n];
for (int i=0; i<n; i++){
    A[i] = new string [n];
     for (int j=0; j<n; j++){
         cin >> A[i][j];
     }
}

for (int i=0; i<n; i++){
     for (int j=0; j<n; j++){
         cout << A[i][j] << '\t';
     }
     cout << endl;
}

cout << esercizioDue(A, n, 2, 2);

}