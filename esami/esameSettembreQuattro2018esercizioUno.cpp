#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda come parametri formali una matrice A n×m di long ed un long x, e
restituisca in output l’indice della colonna di A con il maggior numero di occorrenze di x. */

//ESAME 4 Settembre 2018 - Esercizio Uno

int esercizioUno(long **A, int n, int m, long x){
    int conta;
    int risultato = -1;
    int occorrenze = 0; 
    for (int j=0; j<m; j++){
        conta = 0; 
        for (int i=0; i<n; i++){
             if (A[i][j] == x){
                 conta ++;
             }
        }
        if (conta > occorrenze){
            occorrenze = conta;
            risultato = j;
        }
    }
    if (risultato >= 0){
    cout << "Colonna con piu' occorrenze : ";
    return risultato;}
    else {
        cout << "Nessuna Occorrenza!" << endl;
        return -1;
    }
}

int main(){
    int n = 3;
    int m = 4;
    long **A = new long *[n];
    for (int i=0; i<n; i++){
        A[i] = new long [m];
        for (int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << A[i][j] << '\t';
        }
      cout << endl;
    }

    cout << esercizioUno(A, n, m, 2);
}