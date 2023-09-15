#include <iostream>
using namespace std;
/*15.Scrivere un metodo che prenda in input tre matrice A, B e C di boolean con le stesse dimensioni, e
restituisca un boolean che indichi se una diagonale in A, soprastante la diagonale principale, è presente
anche in B e C (nella stessa posizione e con la stessa sequenza di valori!).*/
bool MarryQuindici(bool **A, bool **B, bool **C, int n){
int incremento=0;
int a=0; 
for (int i=0; i<n-1; i++){
    for (int j=1; j<n; j++){
          if ((i==a)&&(j==(i+1))&&(A[i][j]==B[i][j])&&(A[i][j]==C[i][j])&&(B[i][j]==C[i][j])){
              incremento++;
              a++;
              cout<<"["<<i<<"] ["<<j<<"]"<<endl;
              cout<<A[i][j]<<endl;
              cout<<"Incremento: "<<incremento<<endl;
          }
    }
    if (incremento==n-1){
              cout<<"Diagonale soprastante la diagonale principale identica in tutte e tre le matrici!"<<endl;
              return true;
          }
}
return false;
}
int main(){
int n=4; 
cout<<"Array Booleano A: "<<endl;
bool **A=new bool *[n];
for (int i=0; i<n; i++){
    A[i]=new bool [n];
    for (int j=0; j<n; j++){
        if (i%2==0){
            A[i][j]=0;
        }
        else {
            A[i][j]=1;
        }
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<A[i][j]<<'\t';
}
cout<<endl;
}

bool **B=new bool *[n];
for (int i=0; i<n; i++){
    B[i]=new bool [n];
    for (int j=0; j<n; j++){
        if (i%2==0){
            B[i][j]=0;
        }
        else {
            B[i][j]=1;
        }
    }
}
cout<<"Array Booleano B: "<<endl;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<B[i][j]<<'\t';
}
cout<<endl;
}

bool **C=new bool *[n];
for (int i=0; i<n; i++){
    C[i]=new bool [n];
    for (int j=0; j<n; j++){
        if (i%2==0){
            C[i][j]=0;
        }
        else {
            C[i][j]=1;
        }
    }
}
cout<<"Array Booleano C: "<<endl;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<C[i][j]<<'\t';
}
cout<<endl;
}
cout<<MarryQuindici(A, B, C, 4);
}