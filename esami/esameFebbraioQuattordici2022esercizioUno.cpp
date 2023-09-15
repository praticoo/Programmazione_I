/* Scrivere una funzione che prenda in input una matrice A di dimensione m × n (si assuma m > n) di puntatori a double, uno
short k e un double q e restituisca il numero di sequenze di lunghezza k di media superiore a q che si trovano sulle diagonali
principali delle matrici quadrate di dimensione n × n contenute in A. */

//Esame 14 / 02 / 2022

#include <iostream>
using namespace std;

int esercizioUno(double ***A, int m, int n, short k, double q){
    int sequenza = 0;
    int conta = n; 
    int i = -1;
    while (conta != m+1){
      i++;
      int count = 0;
      double somma = 0; 
     for (int s=i; s<conta; s++){
        for (int j=0; j<n; j++){
         if (A[s][j]){
            if ((conta == n)&&(s == j)&&(count < k)){
               somma += A[s][j][0];
               //cout << "el. " << A[s][j][0] << endl;
               //cout << "S. " << somma << endl;
            }
            else if ((conta > n)&&(s == j + 1)&&(count < k)){
               somma += A[s][j][0];
               //cout << "el. " << A[s][j][0] << endl;
               // cout  << "S. "<< somma << endl;
            }
         }
         //cout << A[s][j] << '\t';

        }
        //cout << endl;
     }
     if (((double)somma / k) > q ){
      //cout << (double)somma / k << endl;
      sequenza ++;
     }
     conta++;
     //cout << endl;
    }
    return sequenza;
}

int main(){
int m = 4;
int n = 3;
double ***A = new double **[m];
for (int i=0; i<m; i++){
   A[i] = new double *[n];
   for (int j=0; j<n; j++){
      A[i][j] = new double;
      cin >> A[i][j][0];
   }
}

for (int i=0; i<m; i++){
   for (int j=0; j<n; j++){
      cout << A[i][j][0] << '\t';
   }
   cout << endl;
}

/*int conta = n; 
    int i = -1;
    while (conta != m+1){
      i++;
     for (int s=i; s<conta; s++){
        for (int j=0; j<n; j++){
         cout << A[s][j] << '\t';

        }
        cout << endl;
     }
     conta++;
     cout << endl;
    }*/

    cout << esercizioUno(A, m, n, 2, 1.2);
}

