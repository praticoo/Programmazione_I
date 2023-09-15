#include <iostream>
using namespace std;
/*13.Scrivere un metodo che prenda come parametri formali una matrice quadrata A n×n di puntatori a char
e restituisca in output un bool che indichi se esiste una colonna in A identica alla diagonale principale di A.*/
bool MarryTredici(char ***A, int n){
    for (int j=0; j<n; j++){
        int Contatore=0;
        int u=0;
        int d=0;
        for (int i=0; i<n; i++){
            if ((A[i][j])&&(A[u][d])&&(A[i][j][0]==A[u][d][0])){
                Contatore++;
                u++;
                d++;
            }
            if (Contatore==n){
                cout<<"Colonna: "<<j<<endl;
                return true;
                break;
            }
        }
    }
    return false;
}
int main(){
int n=3;
char ***A=new char **[n];
for (int i=0; i<n; i++){
A[i]=new char *[n];
for (int j=0; j<n; j++){
    A[i][j]=new char;
    cin>>A[i][j];
}
}

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<A[i][j]<<'\t';
    }
    cout<<endl;
}
cout<<MarryTredici(A, n);
}

