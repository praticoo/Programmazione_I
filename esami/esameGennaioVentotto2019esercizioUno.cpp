#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice quadrata A di numeri interi ed un double w, e restituisca
il valore booleano true se il rapporto tra il minimo ed il massimo valore della diagonale secondaria di A `e
minore o uguale a w. */

//Esame 28 Gennaio 2019 - Esercizio Uno

bool esercizioUno (int **A, int n, double w){
    int b = n; int min = INT_MAX; int max = 0; 
    for (int i=0; i<n; i++){
            if (b == n-i){
                b--;
                if (A[i][b] >= max){
                    max = A[i][b];
                }
                if (A[i][b] <= min){
                    min = A[i][b];
                }
            }
        }
        cout << "Valore massimo : " << max << endl;
        cout << "Valore minimo : " << min << endl;
        if (((double)min/max) >= w){
            cout << "Rapporto : " << min / max << endl;
            return true;
        }
        return false;
    }

    int main () {
        int n = 3;
        int **A = new int *[n];
        for (int i=0; i<n; i++){
            A[i] = new int [n];
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

        cout << esercizioUno (A, n, 0.4);
    }
