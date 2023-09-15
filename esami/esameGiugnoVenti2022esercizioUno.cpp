#include <iostream>
using namespace std;

/* Scrivere una funzione in C++ che prenda in input una matrice tridimensionale di puntatori a booleani A di dimensione m * n * g, un intero
senza segno l e restituisca una matrice di interi dimensione m * n il cui elemento di indici (i, j) contenga il numero di sottosequenze di 
elementi contigui nel vertice indicizzato di A[i][j] che abbiano valori pari a true e siano di lunghezza esattamente pari a l. 
NB. si presti attenzione ai puntatori NULL. */

//Esame 20 / 06 / 2022 

/* int **esercizioUno(bool****A, int m, int n, int g, unsigned int l){
    int **R = new int *[m];
    for (int i=0; i<m; i++){
 R[i] = new int [n];
 for (int j=0; j<n; j++){
    R[i][j] = 0;
 }
 }
    for (int z=0; z<g; z++){
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                    int ContaSequenze = 0;
                    if (A[i][j][z][0] == true && A[i][j]){
                        int ContaColonna = 0;
                        int ContaRiga = 0;
                        for (int s=i; s<m; s++){
                            if (A[s][j][z] && A[s][j][z][0] == true){
                                 ContaColonna ++;
                            }
                            else {
                                ContaColonna = 0;
                            }
                            if (ContaColonna == l){
                                ContaSequenze ++;
                            }
                        }
                        for (int x=j; x<n; x++){
                            if (A[i][x][z] && A[i][x][z][0] == true){
                                 ContaRiga ++;
                                 if (ContaRiga == l){
                                    ContaSequenze ++;
                                 }
                            }
                            else {
                                ContaRiga = 0;
                            }

                        }
                    }
                    R[i][j] += ContaSequenze; 
                }
            }

        }
        return R;
    }*/

    int **esercizioUno(bool****A, int m, int n, int g, unsigned int l){
    int **R = new int *[m];
    for (int i=0; i<m; i++){
 R[i] = new int [n];
 for (int j=0; j<n; j++){
    R[i][j] = 0;
 }
 }
    for (int z=0; z<g; z++){
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                    int ContaSequenze = 0;
                    if (A[i][j][z][0] == true && A[i][j]){
                        int ContaColonna = 0;
                        int ContaRiga = 0;
                        int ContaRigaSinistra = 0;
                        int ContaColonnaAlto = 0;
                        for (int c=i; c>=0; c--){
                            if ( A[c][j][z] && A[c][j][z][0] == true){
                                 ContaColonnaAlto ++;
                            }
                            else {
                                ContaColonnaAlto = 0;
                                break;
                            }
                            if (ContaColonnaAlto == l){
                                ContaSequenze ++;
                            }
                        }
                        for (int s=i; s<m; s++){
                            if (A[s][j][z] && A[s][j][z][0] == true){
                                 ContaColonna ++;
                            }
                            else {
                                ContaColonna = 0;
                                break;
                            }
                            if (ContaColonna == l){
                                ContaSequenze ++;
                            }
                        }
                        for (int x=j; x<n; x++){
                            if (A[i][x][z] && A[i][x][z][0] == true){
                                 ContaRiga ++;
                                 if (ContaRiga == l){
                                    ContaSequenze ++;
                                 }
                            }
                            else {
                                ContaRiga = 0;
                                break;
                            }

                        }
                        for (int m=j; m>=0; m--){
                            if (A[i][m][z] && A[i][m][z][0] == true){
                                 ContaRigaSinistra ++;
                                 if (ContaRigaSinistra == l){
                                    ContaSequenze ++;
                                 }
                            }
                            else {
                                ContaRigaSinistra = 0;
                                break;
                            }

                        }
                    }
                    R[i][j] += ContaSequenze; 
                }
            }

        }
        return R;
    }
int main(){
    int m = 4;
    int n = 3;
    int g = 2;
    bool ****A = new bool ***[m];
    for (int i=0; i<m; i++){
        A[i] = new bool **[n];
        for (int j=0; j<n; j++){
            A[i][j] = new bool *[g];
            for(int z=0; z<g; z++){
                A[i][j][z] = new bool;
                cin >> A[i][j][z][0];
            }
        }
    }

for(int z=0; z<g; z++){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
                cout << A[i][j][z][0] << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }

int **R = new int *[m];
R = esercizioUno(A, m, n, g, 3);
for (int i=0; i<m; i++){
    for (int j=0; j<n; j++){
        cout << R[i][j] << '\t';
    }
    cout << endl;
}
}