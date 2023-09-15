#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice A di stringhe di dimensioni n × m ed una matrice B di puntatori a
stringhe di dimensioni m × l. Il metodo restituisca un vettore di booleani C di dimensione l in cui cj = true se e solo se `e
possibile trovare almeno una stringa, nella colonna j −esima di B (sia bkj ), la quale sia sottostringa della corrispondente stringa
presente nella riga j − esima di A (sia ajk). Si assuma n ≥ l. NB: si presti attenzione alle stringhe mancanti in B. */

//Esame 30 / 11 / 21 

bool *esercizioDue(string **A, int n, int m, string ***B, int l){
    bool *C = new bool [l];
    for (int j=0; j<l; j++){
        for (int i=0; i<m; i++){
            if (B[i][j]){
                if (A[j][i].find(B[i][j][0]) != string :: npos){
                    C[j] = true;
                    break;
                }
            }
        }
        if (C[j] != true){
            C[j] = false;
        }
    }
    return C;
}

int main(){
    int m = 2;
    int l = 3;
    int n = 4;
    string **A = new string *[n];
    for (int i=0; i<n; i++){
        A[i] = new string [m];
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

    string ***B = new string **[m];
    for (int i=0; i<m; i++){
        B[i] = new string *[l];
        for (int j=0; j<l; j++){
            B[i][j] = new string;
            cin >> B[i][j][0];
        }
    }

     for (int i=0; i<m; i++){
        for (int j=0; j<l; j++){
            cout << B[i][j][0] << '\t';
        }
      cout << endl;
    }

    bool *C = new bool [l];
    C = esercizioDue(A, n, m, B, l);
    for (int i=0; i<l; i++){
        cout << C[i] << '\t';
    }
}