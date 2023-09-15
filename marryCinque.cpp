#include <iostream>
using namespace std;
/*5.Scrivere un metodo che prenda come parametri formali una matrice A n×m di long ed un long x, e
restituisca in output l’indice della colonna di A con il maggior numero di occorrenze di x. */
int MarryCinque(long **A, int n, int m, long x){
      int IColonna;             //indice da tornare
      int Momentanea=0;           //numero max di occorrenze 
      int Occorrenza;              //occorrenze per colonna 
      for (int j=0; j<m; j++){
          Occorrenza=0;
          for (int i=0; i<n; i++){
              if (A[i][j]==x){
                 Occorrenza++;
              }
              if (Occorrenza>Momentanea){
                  Momentanea=Occorrenza;
                  IColonna=j;
              }
          }
      }
      cout<<"Colonna in cui "<<x<<" si ripete piu' volte: "<<endl;
      return IColonna; 
}
int main(){
    int n=3;
    int m=4;
    //int PerRiempireMatrice=1001;
    long x=1002;
    long **A=new long *[n];
    for (int i=0; i<n; i++){
        A[i]=new long [m];
        for (int j=0; j<m; j++){
            //A[i][j]=PerRiempireMatrice++;
            cin>>A[i][j];
        }
    }
    
     for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
cout<<MarryCinque(A, n, m, x);
}