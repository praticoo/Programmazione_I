#include <iostream>
#include <cmath>
using namespace std;

/*
Scrivere una funzione che prenda come parametri formali un array tridimensionale A di puntatori a interi di dimensione n * n *n (un cubo) e 
uno short q. Sia m_a la media dei valori contenuti nella diagonale principale del cubo. La funzione restituisca il numero di elementi in A 
che puntino ad un qualche valore a tale che |a - m_a| <= q.
*/

//Esame 14 Aprile 2022 - Esercizio Uno

int esercizioUno(int ****A, int n, short q){
    double media = 0;
    double principale = 0;
    double c = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int z=0; z<n; z++){
                if ((A[i][j][z])&&(i==j)&&(j==z)&&(i==z)){
                   principale += A[i][j][z][0];
                   c++;
                }

            }
        }
    }
    int conta = 0; 
    if (c>0) {media = principale / c;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int z=0; z<n; z++){
                if ((A[i][j][z])&&((abs(A[i][j][z][0]-media))<=q)){
                   conta++;
                }

            }
        }
    }
    }
    return conta;
}



int main(){
int n=3;
int ****M= new int ***[n];
for (int i=0; i<n; i++){
    M[i]= new int **[n];
    for (int j=0; j<n; j++){
        M[i][j]=new int *[n];
        for (int z=0; z<n; z++){
            M[i][j][z] = new int [n];
        }
    }
} 
int count=1;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        for (int z=0; z<n; z++){
            M[i][j][z][0]=count;
            count ++;
            cout<< "C[" << i << "][" << j << "][" << z << "]: " <<M[i][j][z][0]<<" ";
        }
        cout<<endl;
    }
}

cout << esercizioUno(M, n, 1);
}