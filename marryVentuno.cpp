#include <iostream>
#include <cmath>
using namespace std;
/*21.Scrivere un metodo che prenda in input una matrice di double D ed un intero a, e restituisca il
valore booleano true se esiste almeno una colonna in D nella quale la somma di una qualsiasi coppia di
elementi adiacenti, approssimata all'intero piu vicino, sia uguale ad a.  */
bool MarryVentuno(double **D, int n, int a){
for (int j=0; j<n; j++){
    for (int i=0; i<n-1; i++){
        cout<<"1: "<<D[i][j]<<endl;
        cout<<"2: "<<D[i+1][j]<<endl;
         double sommaElContigui=(D[i][j])+(D[i+1][j]);
         cout<<"1+2: "<<sommaElContigui<<endl;
         if (round(sommaElContigui)==a){
             cout<<"Colonna: "<<j<<endl;
             cout<<"Coppia Trovata!"<<endl;
             return true;
         }
    }
}
return false;
}
int main(){
int n=3;
double a=1.1;
double **D=new double *[n];
for (int i=0; i<n; i++){
D[i]=new double [n];
for (int j=0; j<n; j++){
    D[i][j]=a++;
}
}
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<D[i][j]<<'\t';
    }
    cout<<endl;
}
cout<<MarryVentuno(D, n, 15);
}