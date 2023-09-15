#include <iostream>
using namespace std;
/*14.Scrivere un metodo che prenda come parametri formali una matrice A di stringhe ed un intero k, e restituisca 
in output una copia di A in cui tutte le stringhe della colonna k-esima siano state epurate dalle lettere non italiane.*/ 
string **MarryQuattordici(string **A, int n, int k){
    string **Copia=new string *[n];
    for (int i=0; i<n; i++){
        Copia[i]=new string [n];
        for (int j=0; j<n; j++){
              Copia[i][j]=A[i][j];
        }
    }
    for (int j=0; j<n; j++){
        //Copia[j]=new string [n];
        //Copia[j]=new string [n];
        for (int i=0; i<n; i++){
            //Copia[i]=new string [n];
          if (j==k){
              for (int z=0; z<A[i][j].size(); z++){
                  //cout<<"Carattere: "<<A[i][j][z]<<endl;
                  //cout<<"Stringa in esame: "<<A[i][j]<<endl;
                  if ((A[i][j][z]=='j')||(A[i][j][z]=='x')||(A[i][j][z]=='y')||(A[i][j][z]=='w')||(A[i][j][z]=='k')){
                      //cout<<"Caratteri Stranieri: "<<A[i][j][z]<<endl;
                      A[i][j][z]=0;             //Con NULL da errore, usare 0 
                      Copia[i][j][z]=A[i][j][z];
                  }
                  else{
                      //cout<<"Caratteri non stranieri: "<<A[i][j][z]<<endl;
                      Copia[i][j][z]=A[i][j][z];
                  }
                  Copia[i][j]=A[i][j];
              }
          }
        }
    }
    return Copia;

}

int main(){
int n=3;
int k=2;
string **A=new string *[n];
for (int i=0; i<n; i++){
    A[i]=new string [n];
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
string **Copia=new string *[n];
//Copia=MarryQuattordici(A, 3, 2);
for (int i=0; i<n; i++){
    Copia[i]=new string [n];
    for (int j=0; j<n; j++){
        Copia=MarryQuattordici(A, 3, 2);
        cout<<Copia[i][j]<<'\t';
    }
    cout<<endl;
}
}