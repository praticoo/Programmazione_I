#include <iostream>
using namespace std;

/* [Esercizio 13] Scrivere un metodo che preveda due parametri formali matrici di interi, A e B di dimensioni k × n ed
n × k rispettivamente, e restituisca uno array monodimensionale di k elementi double in cui lo i-esimo elemento sia uguale alla
differenza tra la media aritmetica degli elementi della riga i-esima di A ed il minimo valore degli elementi della colonna i-esima
di B. */

double *esercizioTredici (int **A, int **B, int n, int k){
    double *Risultato = new double [k];
        double differenza = 0;
        for (int i=0; i<k; i++){
            double media = 0;
            double minore = 100;
            for (int j=0; j<n; j++){
                 cout << "A[i][j]" << A[i][j] << endl;
                 media = A[i][j] + media;
                 if (B[j][i]<minore){
                     minore = B[j][i];
                 }
            }
            cout << "Minore :" << minore << endl;
            media = media / n;
            cout << "Media :" << media << endl;
            differenza = media - minore;
             cout << "Differenza :" << differenza << endl;
             Risultato[i] = differenza;
        }
    return Risultato;
}

int main(){
int k = 3;
int n = 4;
int **A = new int *[k];
for (int i=0; i<k; i++){
    A[i] = new int [n];
    for (int j=0; j<n; j++){
        cin >> A[i][j];
    }
}

for (int i=0; i<k; i++){
    for (int j=0; j<n; j++){
        cout << A[i][j] << '\t';
    }
    cout << endl;
}

int **B = new int *[n];
for (int i=0; i<n; i++){
    B[i] = new int [k];
    for (int j=0; j<k; j++){
        cin >> B[i][j];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<k; j++){
        cout << B[i][j] << '\t';
    }
    cout << endl;
}

double *Risultato = new double [k];
Risultato = esercizioTredici(A, B, n, k);
for (int i=0; i<k; i++){
    cout << Risultato[i] << '\t';
}

}