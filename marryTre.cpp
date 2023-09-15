#include <iostream>
using namespace std;
/*3.Scrivere un metodo che prenda in input un parametro formale matrice A di interi di dimensioni
nxn ed un double w, e restituisca un valore booleano true se esiste almeno una colonna della matrice A per
cui il rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della
diagonale secondaria di A sia maggiore di w. */
bool MarryTre(int **A, int n, double w){
    int SDsecondaria=0; 
    int decremento=n-1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if ((j==decremento)){ 
            decremento--;
            SDsecondaria=A[i][j]+SDsecondaria;
    }}
    }
    cout<<"Somma Elementi Diagonale Secondaria: "<<SDsecondaria<<endl;
    for (int j=0; j<n; j++){
        int SommaColonna=0;
        for (int i=0; i<n; i++){
             SommaColonna=A[i][j]+SommaColonna;
             if (((double)SommaColonna/SDsecondaria)>w){
                 cout<<"Somma Colonna: "<<SommaColonna<<endl;
                 cout<<"Colonna: "<<j<<endl;
                 cout<<"Rapporto maggiore: "<<(double)SommaColonna/SDsecondaria<<endl;
                 return true;
                 break;
             }
        }
    }
    return false;
}
int main(){
    int n=3;
    int incremento=1;
    int **A=new int *[n];
    for (int i=0; i<n; i++){
        A[i]=new int [n];
        for (int j=0; j<n; j++){
            A[i][j]=incremento++;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<A[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<MarryTre(A, n, 1.1);
}