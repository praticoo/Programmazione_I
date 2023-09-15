#include <iostream>
using namespace std;

/* [Esercizio 4] Scrivere un metodo che prenda in input due parametri formali: una matrice A di dimensioni n × m ed una
matrice B di dimensioni k × n entrambe di interi positivi. Il metodo restituisca un array C di double di dimensione n nel quale
lo i-esimo elemento dello array C sia uguale al rapporto tra la somma degli elementi della riga i-esima di A e il prodotto degli
elementi della colonna i-esima di B. */

long double *esercizioQuattro(unsigned int **A, int n, int m, unsigned int **B, int k){
    long double *C = new long double [n];
    long double *sum = new long double [n];
    long double *mult = new long double [n];
    for (int i=0; i<n; i++){
        long double somma = 0; 
        for (int j=0; j<m; j++){
        somma += A[i][j];
        cout << "Somma : " << somma << endl;
        }
        sum[i] = somma;
    }

for (int i=0; i<n; i++){
        long double prodotto = 1; 
        for (int z=0; z<k; z++){
               prodotto *= B[z][i];
               cout << "Prodotto : " << prodotto << endl;
           }
        mult[i] = prodotto;
    }

    for (int i=0; i<n; i++){
        cout << "Rapporto "<< sum[i] << " : " << mult[i] << " = " << sum[i] / mult[i] << endl;
        C[i] = sum[i] / mult[i];
    }
    return C;
}

int main(){
int n = 3;
int m = 4;
int incremento = 2;
unsigned int **A = new unsigned int *[n]; 
for (int i=0; i<n; i++){
    A[i] = new unsigned int [m];
    for (int j=0; j<m; j++){
        A[i][j] = incremento ++ ;
        cout << A[i][j] << '\t';
    }
  cout << endl;
}

cout << endl;

int k = 4;
incremento = 1;
unsigned int **B = new unsigned int *[k]; 
for (int i=0; i<k; i++){
    B[i] = new unsigned int [n];
    for (int j=0; j<n; j++){
        B[i][j] = incremento ++ ;
        cout << B[i][j] << '\t';
    }
  cout << endl;
}

cout << endl; 

long double *C = new long double [n];
C = esercizioQuattro(A , n, m, B, k);
for (int i=0; i<n; i++){
    cout << C[i] << '\t';
}
}