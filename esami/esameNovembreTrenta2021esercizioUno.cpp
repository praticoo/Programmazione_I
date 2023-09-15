#include <iostream>
using namespace std;

/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice quadrata S di dimensioni n × n di puntatori a interi
senza segno, un double w ed uno short k (si assuma k < n). Il metodo restituisca il valore booleano true se esistono almeno k
colonne in S che soddisfano il seguente requisito: la media aritmetica degli elementi della colonna stessa sia minore o uguale a
w. NB: si presti attenzione ai numeri mancanti.. */

//Esame 30 / 11 / 2021

bool esercizioUno(unsigned int ***S, int n, double w, short k){
    int colonna = 0; 
    for (int j=0; j<n; j++){
        double media = 0.0;
        double somma = 0.0;
        for (int i=0; i<n; i++){
            if (S[i][j]){
                somma += S[i][j][0];
                cout << "El: " << S[i][j][0] << endl;
            }
        }
        if ((somma / n) <= w){
            cout << somma / n << endl;
            colonna ++;
        }

        if (colonna >= k){
            return true;
        }
    }
    return false;
}

void printMatrixPtr(unsigned int*** M, int n) {
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

    unsigned int ***A = new unsigned int**[n];
    for (int i=0; i<n; i++){
        A[i] = new unsigned int *[n];
        for (int j=0; j<n; j++){
              A[i][j] = new unsigned int;
        }
    }
    A[0][0] = new unsigned int(3);
    A[0][1] = NULL;
    A[0][2] = new unsigned int (2);
    A[1][0] = new unsigned int(4);
    A[1][1] = new unsigned int(5);
    A[1][2] = NULL;
    A[2][0]= new unsigned int (5);
    A[2][1] = NULL;
    A[2][2] = new unsigned int(1);

    printMatrixPtr(A, n);
    
    cout << esercizioUno(A, n, 4.5, 2);
    
}