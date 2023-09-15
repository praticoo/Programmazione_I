#include <iostream>
#include <ctime>
using namespace std;

/* Scrivere una funzione che prenda in input una matrice S di dimensione n × n di puntatori a stringhe, una matrice B di booleani
di dimensione n × n e restituisca una stringa ottenuta concatenando i caratteri di indici pari delle stringhe di S che si trovano
in corrispondenza di valori di B che sono identici nella corrispettiva trasposta BT. */

//Per Trasposta invertire righe con colonne

//Esame 14 / 02 / 2022

bool** trasposta(bool **B, int n){
    bool **Trasposta = new bool *[n];
       for (int i=0; i<n; i++){
        Trasposta[i] = new bool [n];
        for (int j=0; j<n; j++){
            Trasposta[i][j] = B[j][i];
        }
       }
       return Trasposta;
}

string esercizioUno(string ***S, int n, bool** B){
    bool **BT = new bool *[n];
    BT = trasposta(B, n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << BT[i][j] << '\t';
        }
        cout << endl;
    }
    string Risultato = "";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if ((S[i][j])&&(BT[i][j] == B[i][j])){
                for (int z=0; z<S[i][j][0].size(); z++){
                  if ((z%2 == 0)){
                        Risultato += S[i][j][0][z];
                  }
                }
            }
        }
    }
    return Risultato;
}

int main(){
srand(time(0));
int n=3;

string ***S = new string **[n];
for (int i=0; i<n; i++){
    S[i] = new string *[n];
    for (int j=0; j<n; j++){
        S[i][j] = new string;
        cin >> S[i][j][0];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout << S[i][j][0] << '\t';
    }
    cout << endl;
}

bool **b = new bool *[n];
for (int i=0; i<n; i++){
     b[i] = new bool [n];
    for (int j=0; j<n; j++){
         b[i][j] = rand() % 2;
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
         cout << b[i][j] << '\t';
    }
    cout << endl;
}

//cout << endl;

cout << esercizioUno(S, n, b);

/*bool **T= new bool *[n];
T = trasposta(b, n);
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout << T[i][j] << '\t';
    }
    cout << endl;
}*/

}