#include <iostream>
using namespace std;

/* [Esercizio 16]
Scrivere un metodo che prenda in input una matrice S di puntatori a stringhe di dimensione n × m ed un array B di short
di dimensione m e che restituisca uno short che rappresenti l’indice della riga in S con il maggior numero di stringhe aventi
lunghezza minore o uguale del corrispondente numero nello array B (NB: in pratica la lunghezza della stringa di indici (i,j) va
confrontata con il numero di indice j in B). */

short esercizioSedici (string ***S, int n, int m, short *B) {
    short Risultato = 0;
    short Contatore = 0;
    short Indice = -1;
    for (int j=0; j<m; j++){
        Contatore = 0;
        for (int i=0; i<n; i++){
            if ((S[i][j][0].size())<=B[j]){
                 cout << "S[i][j][0].size()=" << S[i][j][0].size() << endl;
                 //cout << "S[i][j][0].size() - 1=" << S[i][j][0].size() - 1 << endl;
                 cout << "S[i][j][0]=" << S[i][j][0] << endl;
                 cout << "B[j]=" << B[j] << endl;
                 Contatore ++;
            }
        }
        if (Contatore > Risultato){
            cout << "Colonna: " << j << endl;
            Risultato = Contatore;
            Indice = j;
        }
    }
    if (Indice == -1){
         cout << "NOTHING!" << endl;
         return (short)NULL;
    }
    else {
    cout << "Colonna: " ;
    return Indice;
    }
}

int main(){
int n = 3;
int m = 4;
string ***S = new string **[n];
for (int i=0; i<n; i++){
    S[i] = new string *[m];
    for (int j=0; j<m; j++){
        S[i][j] = new string;
        cin >> *S[i][j];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout << *S[i][j] << '\t';
    }
    cout << endl;
}

short *B = new short [m];
for (int i=0; i < m; i++){
    cin >> B[i];
}

for (int i=0; i < m; i++){
   cout << B[i] << '\t';
}
cout << endl;

cout << esercizioSedici(S, n, m, B) << endl;
}