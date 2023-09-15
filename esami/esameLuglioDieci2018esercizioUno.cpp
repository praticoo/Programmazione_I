/* Scrivere un metodo che prenda come parametri formali una matrice quadrata A n×n di puntatori a
char e restituisca in output un bool che indichi se esiste una colonna in A identica alla diagonale
principale di A. */

//Esame 10 / 07 / 2018

#include <iostream>
using namespace std;

bool esercizioUno(char ***A, int n){
    char *diag = new char [n];
    for (int j=0; j<n; j++){
        for (int i=0; i<n; i++){
            if ((A[i][j])&&(i==j)){
                diag[i] = A[i][j][0];
            }
        }
    }

    for (int j=0; j<n; j++){
        int count = 0; 
        for (int i=0; i<n; i++){
            if (A[i][j]&&(A[i][j][0] == diag[i])){
                cout << "El: " << A[i][j][0] << endl;
                cout << "El Diag: " << diag[i] << endl;
                count ++;
            }
        }
        if (count == n){
            return true;
        }
    }
    return false;
}

int main(){
    int n = 3;
    char ***A = new char **[n];
    for (int i=0; i<n; i++){
        A[i] = new char *[n];
        for (int j=0; j<n; j++){
            A[i][j] = new char;
            cin >> A[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << A[i][j][0] << '\t';
        }
        cout << endl;
    }

    cout << esercizioUno(A, n);
}