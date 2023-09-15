#include <iostream>
using namespace std;
/*25.Scrivere un metodo che prenda in input una matrice di interi M di dimensioni nx m, uno short k ed
un double x, e restituisca il valore booleano true se esiste almeno una colonna in M contenente
esattamente k coppie di elementi adiacenti tali che il rapporto tra il primo elemento ed il secondo elemento
di ogni coppia sia minore di x. NB: Si assuma k <= n - 1 e si presti attenzione alle divisioni per zero! */
bool MarryVentiCinque(int **M, int n, int m, short k, double x){
for (int j=0; j<m; j++){
    int CoppieAccettate=0; 
    for (int i=0; i<n-1; i++){
        if ((M[i+1][j]!=0)&&((double)M[i][j]/M[i+1][j]<x)){
            cout<<"Primo Elemento: "<<M[i][j]<<endl;
            cout<<"Secondo Elemento: "<<M[i+1][j]<<endl;
            cout<<"Rapporto: "<<(double)M[i][j]/M[i+1][j]<<endl;
            CoppieAccettate++;
            cout<<"Coppia: "<<CoppieAccettate<<endl;
        }
    }
     if (CoppieAccettate==k){
        return true;
    }
}
return false;
}
int main(){
    int n=3;
    int m=4;
    int a=5;
    int **M=new int *[n];
    for (int i=0; i<n; i++){
        M[i]=new int [m];
        for (int j=0; j<m; j++){
            cin>>M[i][j];
            //M[i][j]=a++;
            //cout<<M[i][j]<<'\t';
        }
        //cout<<endl;
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<M[i][j]<<'\t';
        }
        cout<<endl;
    }
    short k=2;
    double x=1.1;
    cout<<MarryVentiCinque(M, n, m, k, x);


}