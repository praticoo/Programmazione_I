#include <iostream>
using namespace std;

//Esame 18 / 06 / 2018

int *esercizioUno(int **A, int n, int *B){
    int *C = new int [n];
        /*for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                for (int z=0; z<n; z++){
                cout << A[i][j] << endl;
                cout << B[z] << endl;
                if (A[i][j] == B[z]){
                    C[z] = B[z];
                    cout << "-" << C[z] << endl;
                }
            }
        }
    }*/
    for (int z=0; z<n; z++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout << A[i][j] << endl;
                cout << B[z] << endl;
                if (A[i][j] == B[z]){
                    C[z] = B[z];
                    cout << "-" << C[z] << endl;
                }
            }
        }
        if (C[z] != B[z]){
            C[z] = 0;
        }
       
    }
    return C;
}

int main(){
int n = 3;
int **A = new int *[n];
for (int i=0; i<n; i++){
    A[i] = new int[n];
for (int j=0; j<n; j++){
    cin >> A[i][j];
}    
}

for (int i=0; i<n; i++){
for (int j=0; j<n; j++){
   cout << A[i][j] << '\t';
}    
cout << endl;
}

int *B = new int [n];
for (int i=0; i<n; i++){
    cin >> B[i];
}

for (int i=0; i<n; i++){
 cout << B[i] << '\t';
}

cout << endl;

int *C = new int [n];
C = esercizioUno(A, n, B);
for (int i=0; i<n; i++){
    cout << C[i] << '\t';
}



}