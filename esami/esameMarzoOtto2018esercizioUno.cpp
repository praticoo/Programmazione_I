#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda come parametri formali una matrice quadrata A n×n di puntatori ad
int e restituisca in output un bool che indichi se la somma degli elementi puntati dalla diagonale
sottostante la diagonale secondaria è divisibile per n. */ 

//Esame 8 / 03 / 2018

bool esercizioUno(int ***A, int n){
    int j = n - 1;
    int somma = 0; 
    for (int i=1; i<n; i++){
        if (A[i][j]){
            cout << "El :" << A[i][j][0] << endl;
            somma += A[i][j][0];
            j--;
         }
    }
    cout << "Somma :" << somma << endl;
    if (somma % n == 0){
        return true;
    }
    else {
        return false;
    }
}

//Modulo unicamente con INT, con DOUBLE o FLOAT castare ad INT per evitare errore.

int main(){
    int n = 4;
    int ***A = new int **[n];
    for (int i=0; i<n; i++){
        A[i] = new int *[n];
        for (int j=0; j<n; j++){
            A[i][j] = new int;
            cin >> A[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << A[i][j][0] << '\t';
        }
      cout << endl;
    }

    cout << esercizioUno(A, n) << endl;
}