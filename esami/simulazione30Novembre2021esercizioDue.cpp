#include <iostream>
using namespace std;

/* Scrivere una funzione che prende come parametro una matrice A di dimensione N x M di stringhe e restituisca una stringa che contenga tutte le 
vocali delle stringhe nelle posizioni A[i][j] tali che A[i][j] è piu lunga di A[j%N][i%M] di almeno i + j unità */

//Simulazione 30 / 11 / 21

string esercizioDue (string **A, int n, int m) {
    string Risultato = "";
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //cout << "El : " << (A[i%n][j%m].size())+i+j << endl;
            cout << "[j%n]: " << j%n << endl;
            cout << "[i%m]: " << i%m << endl;
            cout << "Dimensione " << A[i][j] << ": "<< A[i][j].size() << endl;
            cout << "e' maggiore a " << A[j%n][i%m].size()+i+j << "?" << endl;
             if (A[i][j].size()>=(A[j%n][i%m].size())+i+j){                    //almeno >=
                    for (int z=0; z<A[i][j].size(); z++){
                        if ((A[i][j][z]=='a')||(A[i][j][z]=='e')||(A[i][j][z]=='i')||(A[i][j][z]=='o')||(A[i][j][z]=='u')||(A[i][j][z]=='A')||
                            (A[i][j][z]=='E')||(A[i][j][z]=='I')||(A[i][j][z]=='O')||(A[i][j][z]=='U')){
                            Risultato = Risultato + A[i][j][z];
                            cout << "Risultato : " << Risultato << endl;
                        }
                    }
             }
        }
    }
    return Risultato;
}

int main() {
int n = 2;
int m = 3;
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

cout << esercizioDue(A, n, m);
}