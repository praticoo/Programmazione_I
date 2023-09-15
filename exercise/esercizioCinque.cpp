/* [Esercizio 5] Scrivere un metodo che prenda in input un parametro formale array A di interi di dimensioni n×m di elementi
distinti ed un array B di double di dimensioni k × n, e restituisca un array di n interi nel quale lo i-esimo elemento sia uguale
alla media aritmetica degli elementi presenti sia nella riga i-esima di A che nella colonna i-esima di B. NB: per decidere se un
elemento int della matrice A `e uguale ad un elemento double della matrice B si calcoli l’approssimazione all’intero pi`u vicino di
quest’ultimo. */

#include <iostream>
using namespace std;

int *esercizioCinque(int **A, int n, int m, double **B, int k){
    int *Risultato = new int [n];
    int *MediaRiga = new int [n];
    double *MediaColonna = new double [n];
    int sommaRiga;
    double sommaColonna;
    for (int i=0; i<n; i++){
        sommaRiga = 0;
        for (int j=0; j<m; j++){
             sommaRiga += A[i][j];
        }
        MediaRiga[i] = sommaRiga;
        cout << "Somma Riga: " << MediaRiga[i] << endl;
    }

    for (int i=0; i<n; i++){
        sommaColonna = 0;
        for (int j=0; j<k; j++){
             sommaColonna += B[j][i];
        }
        MediaColonna[i] = sommaColonna;
        cout << "Somma Colonna : "<< MediaColonna[i] << endl;
    }

    for (int i=0; i<n; i++){
        Risultato[i] = (MediaRiga[i] + MediaColonna[i]) / (m*2);
    }

return Risultato;
}

int main(){
    int n = 3;
    int m = 4;
    int k = 4;
    int incremento = 2;

    int **A = new int *[n];
    for (int i=0; i<n; i++){
        A[i] = new int [m];
        for (int j=0; j<m; j++){
            A[i][j] = incremento++;
            cout << A[i][j] << '\t';
        }
       cout << endl; 
    }

    cout << endl;
    
    double plus = 0.3;
    double **B = new double *[k];
    for (int i=0; i<k; i++){
        B[i] = new double [n];
        for (int j=0; j<n; j++){
            B[i][j] = plus++;
            cout << B[i][j] << '\t';
        }
       cout << endl; 
    }
    
    cout << endl;

    int *Risultato = new int [n];
    Risultato = esercizioCinque(A, n, m, B, k);
    for (int i=0; i<n; i++){
        cout << Risultato[i] << '\t';
    }
}