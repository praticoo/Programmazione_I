#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input un parametro formale matrice quadrata Q di interi ed un double w,
e restituisca un valore booleano true se esiste almeno una colonna della matrice Q tale che il rapporto tra
la somma degli elementi della colonna stessa e la somma degli elementi della diagonale secondaria di Q sia
maggiore di w. */

//ESAME ESERCIZIO UNO 3 Settembre 2019

bool esameTreSettembreUno (int **Q, int n, double w){
int b = n;
double diag = 0; 
for (int i=0; i<n; i++){
    if (b>=n-i-1){
          b--;
          diag += Q[i][b];
    }
}

cout << "Diagonale Secondaria :" << diag << endl;

for (int i=0; i<n; i++){
    double rap = 0; 
    double somma = 0; 
    for (int j=0; j<n; j++){
         somma += Q[i][j];
    }
    cout << "Somma :" << somma << endl;
    rap = somma / diag;
    cout << "Rapporto: " << rap << endl;
    if (rap > w){
        return true;
    }
}
return false;
}

int main(){
    int incremento = 3;
    int n = 3;
    int **Q = new int *[n];
    for (int i=0; i<n; i++){
        Q[i] = new int [n];
        for (int j=0; j<n; j++){
            Q[i][j] = incremento++;
            cout << Q[i][j] << '\t';
        }
        cout << endl;
    }

    double w = 1.1;
cout << esameTreSettembreUno(Q, n, w);
}