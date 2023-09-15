#include <iostream>
using namespace std;
/* 29.Scrivere un metodo che prenda in input una matrice quadrata A di numeri interi ed un double w, e
restituisca il valore booleano true se il rapporto tra il minimo ed il massimo valore della diagonale
secondaria di A e' minore o uguale a w. */
bool MarryVentiNove(int **A, int n, double w){
int Elpiupiccolo=0;
int Elpiugrande=0;
int decremento=n-1;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        if (j==decremento){
            decremento--;
        if (A[i][j]>Elpiugrande){
            Elpiugrande=A[i][j];
            Elpiupiccolo=Elpiugrande;
            
        }
        }
    }
}
decremento=n-1;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        if (j==decremento){
            decremento--;
            if (A[i][j]<Elpiupiccolo){
                Elpiupiccolo=A[i][j];
            }
        }
    }
}
cout<<"Elemento min Diagonale Secondaria: "<<Elpiupiccolo<<endl;
cout<<"Elemento max Diagonale Secondaria: "<<Elpiugrande<<endl;
double rapporto;
if (Elpiugrande!=0){
rapporto=(double)Elpiupiccolo/Elpiugrande;}
else{
rapporto=0;
}
cout<<"Rapporto: "<<rapporto<<endl;
if (rapporto<=w){
    return true;
}
else {
    return false;
}
}
int main(){
    int n=3;
    int **A=new int *[n];
    for (int i=0; i<n; i++){
        A[i]=new int [n];
        for (int j=0; j<n; j++){
           cin>>A[i][j];
        }
    }

     for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
           cout<<A[i][j]<<'\t';
        }
        cout<<endl;
    }
cout<<MarryVentiNove(A, n, 2.3);
}