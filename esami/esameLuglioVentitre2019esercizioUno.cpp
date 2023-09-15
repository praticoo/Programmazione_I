#include <iostream>
#include <cmath>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice di double D ed un intero a, e restituisca il valore booleano true se esiste
almeno una colonna in D nella quale la somma di una qualsiasi coppia di elementi adiacenti, approssimata all’intero pi`u vicino,
sia uguale ad a. */

//Esame 23 / 07 / 2019

bool esercizioUno(double **D, int n, int a){
    for (int j=0; j<n; j++){
        for (int i=0; i<n-1; i++){
            //cout << D[i][j] << endl;
            //cout << D[i+1][j] << endl;
            //cout << "Somma: " << round(D[i][j]+D[i+1][j]) << endl;
            if (round(D[i][j]+D[i+1][j]) == a){
                  return true;
            }
        }
    }
    return false;
}

int main(){
    int n = 3;
    double **D = new double *[n];
    for (int i=0; i<n; i++){
        D[i] = new double [n];
        for (int j=0; j<n; j++){
             cin >> D[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
             cout << D[i][j] << '\t';
        }
      cout << endl;
    }

cout << esercizioUno(D, n, 4);
}
