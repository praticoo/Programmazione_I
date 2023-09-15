#include <iostream>
using namespace std;

/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice di puntatori ad interi di dimensioni n × m, due interi
positivi a e b ed uno short s (si assuma a < b ed s < n). Il metodo restituisca una copia della matrice in cui ogni numero di una
singola colonna della matrice di origine che risulti presente almeno s volte nella colonna stessa sia sostituito, nella corrispondente
colonna della matrice copia, con un numero pseudo-casuale negativo appartenente all’intervallo [−b, −a] (tranne gli elementi
che risultano nullptr nella matrice originale!) */

//Compito 24 / 01 / 2022 - COMPITO A 

// ( a < b ) (s < n )
int ***esercizioUno(int ***M, int n, int m, int a, int b, short s){
    int ***copia = new int **[n]; 
    for (int i=0; i<n; i++){
        copia[i] = new int *[m];
        for (int j=0; j<m; j++){
            copia[i][j] = new int;
            if (M[i][j]){
            copia[i][j][0] = M[i][j][0]; }
            else{
                copia[i][j] = M[i][j];
            }
        }
    }

short uguale = -1;
    for (int j=0; j<m; j++){
        for (int i=0; i<n-1; i++){
            int count = 1;
            for (int b=i+1; b<n; b++){
                if (copia[i][j] && copia[b][j]){
                if (copia[i][j][0] == copia[b][j][0]){
                    count ++;
                    uguale = M[i][j][0];
                }
              }
            }
            if (count >= s){
                /*for (int u=0; u<n; u++){
                    if ((copia[u][j])&&(copia[u][j][0] == uguale)){
                        copia[u][j][0] = rand() % ((b-a+1)+a)*(-1);
                    }
                }*/
                if ((copia[i][j])){
                        copia[i][j][0] = rand() % ((b-a+1)+a)*(-1);
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

    int ***copia = new int **[n];
    copia = esercizioUno(A, n, m, 2, 10, 2);
    for (int i=0; i<n; i++){
        //copia [i] = new int *[m];
        for (int j=0; j<m; j++){
            cout << copia[i][j][0] << '\t';
        }
        cout << endl;
    }

}