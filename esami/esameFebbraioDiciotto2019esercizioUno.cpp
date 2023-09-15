#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice A di numeri interi e due double w e v, e restituisca il
valore booleano true se esiste almeno una colonna di A in cui la media dei suoi elementi `e compresa tra w e
v. NB: Si assuma che w ≤ v. */

//Esame 18 / 02 / 2019

bool esercizioUno(int **A, int n, double w, double v){
for (int j=0; j<n; j++){
    double somma = 0;
    for (int i=0; i<n; i++){
          somma += A[i][j];
    }
    cout << somma / (double) n << endl;
    if (((somma / (double) n)>= w) && ((somma / (double) n) <= v)) {
        return true;
    }
}
return false;
}

int main(){
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
cout << esercizioUno(A, n, 6.1, 7.4);
}