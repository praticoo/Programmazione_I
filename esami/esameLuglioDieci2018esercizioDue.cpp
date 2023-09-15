#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda come parametri formali una matrice A di stringhe ed un intero k, e
restituisca in output una copia di A in cui tutte le stringhe della colonna k-esima siano state epurate
dalle lettere non italiane. */

//Esame 10 / 07 / 2018

string **esercizioDue(string**A, int n, int k){
    for(int i=0; i<n; i++){
        for (int z=0; z<A[i][k].size(); z++){
            if ((A[i][k][z]=='x')||(A[i][k][z]=='y')||(A[i][k][z]=='j')||(A[i][k][z]=='w')||(A[i][k][z]=='k')
            ||(A[i][k][z]=='X')||(A[i][k][z]=='Y')||(A[i][k][z]=='J')||(A[i][k][z]=='W')||(A[i][k][z]=='K')){
                A[i][k][z] = 0;
            }
        }
    }
    return A;
}

int main(){
    int n = 3;
    int k = 1;
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

    string **Risultato = new string *[n];
    Risultato = esercizioDue(A, n, k);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << Risultato [i][j] << '\t';
        }
        cout << endl;
    }
}