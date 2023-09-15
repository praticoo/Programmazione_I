#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda come parametro formale una matrice quadrata M di n×n interi
positivi e restituisca un array A di n float in cui:
 minimo dei valori nella colonna i-esima di M, se i è pari;
 A[i] = media dei valori divisibili per 3 presenti nella riga i-esima di M, se i è dispari e non divisibile per 3,
 A[i−2]+A[i−1], altrimenti. */

// Esame - Esercizio Uno - 20 / 12 / 17

 float *esercizioUno(unsigned **M, int n){
     float *A = new float [n];
     int minimo;
     for (int i=0; i<n; i++){
         int media = 0;
         int contatore = 0;
         for (int j=0; j<n; j++){
                 minimo = INT_MAX;
                 for (int z=0; z<n; z++){
                    if (M[z][i]<minimo){
                        minimo = M[z][i];
                    }
                 }
             if (M[i][j] % 3 ==0){
                 cout <<"Valori divisibili per 3: "<< M[i][j] << endl;
                 media = M[i][j] + media;
                 contatore ++;
             }
         }
         cout << "Media: " << media << endl;
         cout << "Contatore: " << contatore << endl;
         if (i%2==0){
             A[i] = minimo; 
             cout << "Valore minimo: " << A[i] << endl;
         }
         else if ((i%3!=0)&&(i%2!=0)){
             A[i] = ((double)media / contatore);
             cout << "Media Valori divisibili per 3: " << A[i] << endl;
         }
         else {
             A[i] = A[i-2] + A[i-1];
             cout << "A[" << i-2<< "] + A[" << i-1 << "]: " << A[i] << endl;
         }
     }
     return A;

 }
 
 int main() {
     int n = 6;
     int a = 1;
     unsigned int **M = new unsigned int *[n];
     for (int i=0; i<n; i++){
         M[i] = new unsigned int [n];
         for (int j=0; j<n; j++){
             M[i][j] = a++;
             cout << M[i][j] << '\t';
         }
        cout << endl;
     }

     float *A = new float [n];
     A = esercizioUno(M, n);
     for (int i=0; i<n; i++){
         cout << A[i] << '\t';
     }
 }