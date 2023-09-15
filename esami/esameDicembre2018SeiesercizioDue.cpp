/* Scrivere un metodo che prenda in input tre parametri formali: una matrice di puntatori a stringhe A di
dimensioni n × m, uno short k ed una stringa s. Il metodo restituisca un array di bool di dimensione n in
cui il singolo elemento di indice i assume valore true se la stringa s `e sottostringa di almeno k stringhe della
riga i-esima della matrice A. */
#include <iostream>
using namespace std; 

//Esame 6 Dicembre 2018 - Esercizio Due

bool* esercizioUno(string ***A, int n, int m, short k, string s) {
    bool * Risultato = new bool [n];
    short cont;
    for (int i=0; i<n; i++){
        cont = 0;
        for (int j=0; j<m; j++){
            if ((A[i][j])&&(A[i][j][0].find(s) != string :: npos)){
                cont ++;
            }
        }
        if (cont >= k){
            Risultato[i] = true;
        }
        else {
            Risultato[i] = false;
        }
    }
    return Risultato;
}

int main(){
int n = 4;
int m = 3;
string ***A = new string **[n];
for (int i=0; i<n; i++){
    A[i] = new string *[m];
    for (int j=0; j<m; j++){
        A[i][j] = new string;
        cin >> A[i][j][0];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout << A[i][j][0] << '\t';
    }
  cout << endl;
}

cout << endl;

bool * Risultato = new bool [n];
Risultato = esercizioUno(A, n, m, 2, "ica");
for (int i=0; i<n; i++){
    cout << Risultato[i] << '\t';
}

}