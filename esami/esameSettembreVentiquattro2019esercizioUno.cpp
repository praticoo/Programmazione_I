#include <iostream>
#include <cmath>
using namespace std;

/* Scrivere un metodo che prenda in input un parametro formale matrice K di double di dimensioni n × m e
due interi a e b, e restituisca un array A di short di dimensione m, in cui l’elemento A[i] `e calcolato come
il numero di elementi della colonna i−esima di K tali che, approssimati all’intero pi`u vicino, siano compresi
tra a e b (inclusi). NB: si assuma a < b. */

//Esame 24 / 09 / 2019

short* esercizioUno(double **K, int n, int m, int a, int b){
    short *A = new short [m];
    for (int j=0; j<m; j++){
        short count = 0; 
        for (int i=0; i<n; i++){
        int variabile = round (K[i][j]);
        if (variabile >= a && variabile <= b){
            count ++;
        }
        }
        A[j] = count;
    }
    return A;
}

int main(){
    int n = 3;
    int m = 4;
    double** A = new double *[n];
    for (int i=0; i<n; i++){
        A[i] = new double [m];
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

short *K = new short [m];
K = esercizioUno(A, n, m, 2, 3);
for (int i=0; i<m; i++){
    cout << K[i] << '\t';
}
}