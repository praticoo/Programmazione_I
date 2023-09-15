#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input tre matrici A, B e C di boolean con le stesse dimensioni, e
restituisca un boolean che indichi se una diagonale in A, soprastante la diagonale principale, è
presente anche in B e C (nella stessa posizione e con la stessa sequenza di valori!). */

//Esame 17 / 04 /2018

bool esercizioUno(bool **A, bool **B, bool **C, int n){
    int i=0; 
    bool *R = new bool [n-1];
    for (int j=1; j<n; j++){
        R[i] = A[i][j];
        i++;
    }
    cout << endl;
    for (int i=0; i<n-1; i++){
        cout << R[i] << '\t';
    }
    cout << endl;

    i=0; int count = 0;                              //i o la scrivo senza int oppure cambio valore 
    for (int j=1; j<n; j++){
        if ((R[i] == B[i][j])&&(R[i] == C[i][j])){
            //cout << R[i] << endl;
            //cout << B[i][j] << endl;
            //cout << C[i][j] << endl;
            count ++;
        }
        i++;
    }
    cout << "Conta : " << count << endl;
    if (count == n-1){
        return true;
    }
    return false;
}

int main(){
    int n = 3;
    bool **A = new bool *[n];
    for (int i=0; i<n; i++){
        A[i] = new bool [n];
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

    bool **B = new bool *[n];
    for (int i=0; i<n; i++){
        B[i] = new bool [n];
        for (int j=0; j<n; j++){
            cin >> B[i][j];
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << B[i][j] << '\t';
        }
        cout << endl;
    }

    bool **C = new bool *[n];
    for (int i=0; i<n; i++){
        C[i] = new bool [n];
        for (int j=0; j<n; j++){
            cin >> C[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << C[i][j] << '\t';
        }
        cout << endl;
    }

    cout << esercizioUno(A, B, C, n);
}