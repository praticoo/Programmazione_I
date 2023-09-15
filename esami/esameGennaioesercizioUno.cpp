#include <iostream>
using namespace std;

/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice A di puntatori a interi di dimensioni n × m, uno short
k (si assuma k < n) e due interi a e b (si assuma a < b). Il metodo restituisca una copia della matrice A in cui ogni colonna
della matrice originale che contenga almeno una sequenza di elementi contigui che sia monotona non decrescente e di lunghezza
k, sia rimpiazzata (nella matrice copia) da una colonna di numeri pseudo-casuali nell’intervallo [a, b] (tranne gli elementi che
risultano nullptr nella matrice originale!). Esempio di sequenza monotona non decrescente: [1 2 3 3 7 8 12 15 15 18]. Altro
esempio: [2 3 4 7 9]. */

// ( k < n )      ( a < b )
int ***esercizioUno(int ***A, int n, int m, short k , int a, int b){
   int ***copia = new int **[n];
   for (int i=0; i<n; i++){
    copia[i] = new int *[m];
    for (int j=0; j<m; j++){
        copia[i][j] = new int;
        if(A[i][j]){
        copia[i][j][0] = A[i][j][0];
        }
        else {
            copia[i][j] = A[i][j];
        }
    }}

    for (int j=0; j<m; j++){
        int seq = 1;
        bool check = false;
        for (int i=0; i<n-1; i++){
            if (copia[i][j] && copia[i+1][j]){
              if (copia[i][j][0] <= copia[i+1][j][0]){
                  seq ++;
                  if (seq == k){
                    check = true;
                    break;
                  }
              }
              else {
                seq = 1;
              }
        }
        else {
            seq = 1;
        }
      }
      if (check == true){
        for (int i=0; i<n; i++){
            if (copia[i][j]){
            copia[i][j][0] = rand() % (b-a+1)+a;
            }
        }
      }
    }
   return copia;
}

int main(){
    int n = 3;
    int m = 4;
    int ***A = new int **[n];
    for (int i=0; i<n; i++){
        A[i] = new int *[m];
        for (int j=0; j<m; j++){
            A[i][j] = new int;
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

    int ***copia = new int **[n];
    copia = esercizioUno(A, n, m, 2, 3, 21);
    for (int i=0; i<n; i++){
        //copia [i] = new int *[m];
        for (int j=0; j<m; j++){
            cout << copia[i][j][0] << '\t';
        }
        cout << endl;
    }

}

