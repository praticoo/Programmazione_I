#include <iostream>
using namespace std;
/*17.Scrivere un metodo che prenda in input una matrice A di numeri interi e due double w e v, e
restituisca il valore booleano true se esiste almeno una colonna di A in cui la media dei suoi elementi e
compresa tra w e v. NB: Si assuma che w <=v. */ 
bool MarryDiciasette (int **A, int n, double w, double v){
      for (int j=0; j<n; j++){
          int SommaCol=0;
          double MediaCol=0;
          for (int i=0; i<n; i++){
                    SommaCol=A[i][j]+SommaCol;
                    cout<<"Somma Colonna: "<<SommaCol<<endl;
                if (i==n-1){
                    MediaCol=(double)SommaCol/n;
                if ((w<MediaCol)&&(MediaCol<v)){
                    cout<<"Colonna: "<<j<<endl;
                    cout<<"Media Colonna: "<<MediaCol<<endl;
                    return true;
                    break;
                }
            }
          }
      }
      return false;
}
int main(){
int n=3;
int a=1;
int **A=new int *[n];
for (int i=0; i<n; i++){
    A[i]=new int [n];
    for (int j=0; j<n; j++){
        cin>>A[i][j];
        //cout<<A[i][j]<<'\t';
    }
    //cout<<endl;
}
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<A[i][j]<<'\t';}
        cout<<endl;}
cout<<MarryDiciasette(A,n,5.1,5.7);
}