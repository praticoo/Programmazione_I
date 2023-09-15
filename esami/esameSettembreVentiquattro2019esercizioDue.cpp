#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice di stringhe S di dimensioni n × m, uno short k, ed una
stringa w. Il metodo restituisca il valore booleano true se esiste almeno una riga in S tale che la stringa w
sia sottostringa di un numero di stringhe della riga stessa che sia minore o uguale a k. */

//Esame 24 Settembre 2019

bool esercizioDue(string **S, int n, int m, short k, string w){
    for (int i=0; i<n; i++){
        int count = 0; int conta = 0;
        for (int j=0; j<m; j++){
            if (S[i][j].find(w) != string :: npos){
                count ++;
            }
             if (S[i][j].size() <= k){
                conta ++;
             }
        }
        cout << count << endl;
        cout << conta << endl;
        if (count == conta){
            return true;
        }
    }
    return false;
}

int main(){
int n = 3;
int m = 4;
string **S = new string *[n];
for (int i=0; i<n; i++){
    S[i] = new string [m];
    for (int j=0; j<m; j++){
        cin >> S[i][j];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout << S[i][j] << '\t';
    }
    cout << endl;
}

cout << esercizioDue(S, n, m, 5, "ia");
}