#include <iostream>
using namespace std;
/* 33.Scrivere un metodo che prenda in input una matrice quadrata A di puntatori ad interi e restituisca
un double calcolato come il rapporto tra la somma degli elementi della diagonale principale di A e la
somma degli elementi della diagonale secondaria di A stessa. NB: Si presti attenzione ai numeri mancanti! */
double MarryTrentaTre(int ***A, int n){
    double SommaElPrincipali=0;
    double SommaElSecondari=0;
    int decremento=n-1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if ((i==j)&&(A[i][j])){
                SommaElPrincipali=SommaElPrincipali+A[i][j][0];
            }
            if ((j==decremento)&&(A[i][j])){
                decremento--;
                SommaElSecondari=SommaElSecondari+A[i][j][0];
            }
        }
    }
cout<<"Somma Elementi Diagonale Principale: "<<SommaElPrincipali<<endl;
cout<<"Somma Elementi Diagonale Secondaria: "<<SommaElSecondari<<endl;
double rapporto;
if (SommaElSecondari!=0){
      rapporto=SommaElPrincipali/SommaElSecondari;
      //cout<<"Rapporto: "<<rapporto<<endl;
      return rapporto;
}
else {
    rapporto=0;
    return rapporto;
}
}
int main(){
    int n=3;
    int ***A=new int **[n];
    for (int i=0; i<n; i++){
        A[i]=new int *[n];
        for (int j=0; j<n; j++){
            A[i][j]=new int;
            cin>>*A[i][j];
        }
    }

for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
           cout<<*A[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<MarryTrentaTre(A, n)<<endl;
}