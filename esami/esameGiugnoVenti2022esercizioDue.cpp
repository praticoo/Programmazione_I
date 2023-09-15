#include <iostream>
using namespace std;

/* Scrivere una funzione in C++ che prenda in input una matrice di puntatori a stringa A di dimensione n x m e un intero senza segno s, e 
restituisca un vettori di interi di lunghezza n il cui i-esimo elemento conti il numero di stringhe della riga i-esima di A che siano di
lunghezza al più pari ad s e non siano duplicate nella stessa riga. NB : si presti attenzione ai puntatori NULL! */

//Esame 20 / 06 / 2022 

int *esercizioDue(string ***A, int n, int m, unsigned int s){
int *R = new int [n];
int count;
for (int i=0; i<n; i++){
     int countDue;
    for (int j=0; j<m; j++){
        if (A[i][j]){
            if (A[i][j][0].size() >= s){
               string mom = A[i][j][0];
               count = 0; 
               for (int z = 0; z < m; z++){
                if ((z!=j) && (A[i][z][0] != mom) && A[i][z]){
                    count ++;
                }
               }
               if (count == (m - 1)){
                countDue ++;
               }
            } 
        }
    }
   R[i] = countDue;  
    countDue = 0;
}
return R;
}

int main(){
    int n = 3;
    int m = 4;
    string ***A = new string **[n];
    for (int i=0; i<n; i++){
        A[i] = new string *[m];
        for (int j=0; j<m; j++){
            A[i][j] = new string;
            cin >> A[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << A[i][j][0] << '\t';
        }
        cout << endl;
    }
    int *R = new int [n];
    R = esercizioDue(A, n, m, 4);
    for (int i=0; i<n; i++){
        cout << R[i] << '\t';
    }
}