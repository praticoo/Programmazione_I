#include <iostream>
using namespace std;

/* [Esercizio 18]
Scrivere un metodo che preveda un parametro formale matrice A di double di dimensioni n × k ed un array B di interi di
dimensione n, e restituisca l’indice della colonna in A che contiene il maggior numero di elementi tali che l’approssimazione
dell’elemento stesso al numero intero piu' vicino sia uguale al corrispondente elemento intero in B (NB: in pratica il generico
elemento di indice (i,j) va confrontato con l’elemento in B di indice i). */

int esercizioDiciotto (double **A, int n, int k, int *B){
    int Indice = -1;
    int IndiceMax = 0;
    for (int j=0; j<k; j++){
        int Contatore = 0; 
        for (int i=0; i<n; i++){
            if ((int)A[i][j] == B[i]){
                 Contatore ++;
            }
        }
        if (Contatore > IndiceMax){
            IndiceMax = Contatore;
            Indice = j;
        }
    }
if (Indice == -1){
    cout << "NOTHING!" << endl;
    return -1;
}
else {
    cout << "Indice Colonna con il maggior numero di elementi tali che l'approssimazione dell'elemento stesso al numero piu' vicino sia uguale al corrispondente elemento intero in B: " ;
return Indice;
}
}


int main(){
int n = 3;
int k = 4;
double **A = new double *[n];
for (int i=0; i<n; i++){
    A[i] = new double [k];
    for (int j=0; j<k; j++){
        cin >> A[i][j];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<k; j++){
        cout << A[i][j] << '\t';
    }
   cout << endl;
}

int *B = new int [n];
for (int i=0; i<n; i++){
    cin >> B[i];
}

for (int i=0; i<n; i++){
    cout << B[i] << '\t';
}
cout << endl;

cout << esercizioDiciotto(A, n, k, B);
}
