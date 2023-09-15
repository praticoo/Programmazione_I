#include <iostream>
using namespace std;
/*9.Scrivere un metodo che prenda in input un parametro formale matrice quadrata Q di interi ed un
double w, e restituisca un valore booleano true se esiste almeno una colonna della matrice Q tale che il
rapporto tra la somma degli elementi della colonna stessa e la somma degli elementi della diagonale
principale di Q sia maggiore di w.*/
bool MarryNove(int **Q, int n, double w){
int contenitoreDS=0;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        if (i==j){
            contenitoreDS=Q[i][j]+contenitoreDS;
        }
    }
}
cout<<"Somma Diagonale Principale: "<<contenitoreDS<<endl;
int contenitoreSC;
for (int j=0; j<n; j++){
    contenitoreSC=0; 
    for (int i=0; i<n; i++){
       contenitoreSC=Q[i][j]+contenitoreSC;
       if ((j==n-1)&&(((double)contenitoreSC/contenitoreDS)>w)){
           double rapporto=(double)contenitoreSC/contenitoreDS;
           cout<<"Rapporto maggiore di w: "<<contenitoreSC<<" / "<<contenitoreDS<<" = "<<rapporto<<endl;
           return true;
           break;
       }
    }
}
return false;
} 

int main(){
int n=3;
double w=1.1;
int s=1;
int **Q=new int *[n];
for (int i=0; i<n; i++){
    Q[i]=new int [n];
    for (int j=0; j<n; j++){
        Q[i][j]=s++;
    }
}    
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<Q[i][j]<<'\t';
    }
    cout<<endl;
}    
cout<<"Risultato: "<<MarryNove(Q, n, w);
}