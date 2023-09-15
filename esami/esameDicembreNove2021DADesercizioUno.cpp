#include <iostream>
using namespace std;

/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata di puntatori a interi, un double z ed un double
w (si assuma w > z) e restituisca la media aritmetica di tutti gli elementi della diagonale principale e della diagonale secondaria
che risultino compresi tra z e w (inclusi). */

//Esame 9 / 12 / 21 DAD

double esercizioUno(int ***M, int n, double z, double w){
    int CountUno = 0; int sommaUno = 0;
    for (int i=0; i<n; i++){
        if (M[i][i] && M[i][i][0] >= z && M[i][i][0] <= w){
        sommaUno += M[i][i][0];
        CountUno ++;
        }
    }

    int CountDue = 0; int sommaDue = 0;
    int b = n - 1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (M[i][j] && b == j && M[i][j][0] >= z && M[i][j][0] <= w){
                CountDue ++;
                sommaDue += M[i][j][0];
            }
         }
         b--;
    }

    int somma = sommaUno + sommaDue;
    int count = CountUno + CountDue;
    //cout << count << endl;
    //cout << somma << endl;
    return ((double)(somma)) / count; 
}

int main(){
    int n = 3;
    int ***M = new int **[n];
    for (int i=0; i<n; i++){
        M[i] = new int *[n];
        for (int j=0; j<n; j++){
            M[i][j] = new int;
            cin >> M[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << M[i][j][0] << '\t';
        }
        cout << endl;
    }

    cout << esercizioUno(M, n, 1.2, 3.4);
}