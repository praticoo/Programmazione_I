#include <iostream>
using namespace std;

/* [Esercizio 8] Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni n × m, uno
short k ed uno short w, e restituisca true se la matrice contiene almeno w colonne che contengono almeno una sequenza di interi
monotona crescente di lunghezza maggiore o uguale a k.

Help : Una sequenza non vuota di interi si dice monotona crescente se ogni numero della sequenza è (strettamente) maggiore del precedente, 
similmente si dice monotona decrescente se ogni numero della sequenza è (strettamente) minore del precedente. */

bool esercizioOtto (int **A, int n, int m, short k, short w){
    bool Risultato = false;
    int Colonne = 0;
    for (int j=0; j<m; j++){
        int lunghezza = 1;
        for (int i=0; i<n-1; i++){
            //cout << "A[i][j]: " << A[i][j] << endl;
            //cout << "A[" << i << "][" << j << "]: " << A[i][j] << endl;
            if (A[i][j] < A[i+1][j]){
                cout << "A[" << i << "][" << j << "]: " << A[i][j] << endl;
                cout << "A[" << i+1 << "][" << j << "]: " << A[i+1][j] << endl;
                lunghezza ++;
                cout << "Incremento Lunghezza: " << lunghezza << endl;
            }
            else {
                lunghezza = 1;
                cout <<"-"<< A[i][j] << endl;
            }
            if (lunghezza >= k){
                cout << "Lunghezza : " << lunghezza << endl;
                Colonne ++;
                cout << "Incremento Colonna : " << Colonne <<endl;
                break;
            }
           
        }
            if (Colonne >= w){
        Risultato = true;
    }
}
    return Risultato;

    }


int main(){
int n = 4;
int m = 3;
int **A = new int *[n];
for (int i = 0; i < n; i++){
        A[i] = new int [m];
    for (int j=0; j < m; j++){
            cin >> A[i][j];
    }
}

for (int i = 0; i < n; i++){
    for (int j=0; j < m; j++){
            cout << A[i][j] << '\t';
    }
        cout << endl;
}

short k = 3;
short w = 2;

cout << esercizioOtto(A, n, m, k, w);

}