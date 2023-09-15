#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata A di puntatori a double. Il metodo restituisca
una matrice B la cui diagonale secondaria sia costituita dagli elementi della colonna di A la cui media aritmetica risulti maggiore
tra tutte le colonne di A; inoltre gli elementi di B non appartenenti alla diagonale secondaria siano numeri pseudo-casuali
0 ≤ r ≤ 1 (tranne gli elementi che risultano nullptr in A!). */

//Esame 24 / 01 / 2022 - COMPITO C

double ***esercizioUno(double ***A, int n){
    srand(time(0));
    double media_max = 0.0; int variabile = 0;
    for (int j=0; j<n; j++){
        double somma = 0.0;
        for (int i=0; i<n; i++){
            if (A[i][j]){
                somma = somma + A[i][j][0];
            }
        }
        if ((somma / n) > media_max){
            media_max = (somma / n);
            variabile = j;
        }
    }

    double *d_sec = new double [n];
    for (int i=0; i<n; i++){
        d_sec[i] = A[i][variabile][0];
    }
    
    cout << endl;
    for (int i=0; i<n; i++){
        cout << d_sec[i] << '\t';
    }
    cout << endl;

    int b = n - 1;

    double ***R = new double **[n];
    for (int i=0; i<n; i++){
        R[i] = new double *[n];
        for (int j=0; j<n; j++){
            R[i][j] = new double;
            if (j == b){
                R[i][j][0] = d_sec[i];
            }
            else {
                if (A[i][j]){
                    R[i][j][0] = rand() / (double) RAND_MAX; 
                }
                else {
                    R[i][j] = A[i][j];
                }
            }
        }
        b--;
    }
return R;
}

void printMatrixPtr(double*** M, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(M[i][j])
                cout << *M[i][j] << " ";
            else
                cout << "* "; 
        }
        cout << endl;
    }
}

int main(){
    int n = 3;

    double ***A = new double **[n];
    for (int i=0; i<n; i++){
        A[i] = new double *[n];
        for (int j=0; j<n; j++){
              A[i][j] = new double;
        }
    }
    A[0][0] = new double (3.2);
    A[0][1] = NULL;
    A[0][2] = new double (2.8);
    A[1][0] = new double (4.5);
    A[1][1] = new double (5.3);
    A[1][2] = NULL;
    A[2][0]= new double (5.6);
    A[2][1] = new double (6.2);
    A[2][2] = new double (1.2);

    printMatrixPtr(A, n);
    
    double ***R = esercizioUno(A, n);
   
    printMatrixPtr(R, n);
    
}