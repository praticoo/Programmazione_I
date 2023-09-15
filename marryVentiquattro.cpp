#include <iostream>
using namespace std;
/*24.Scrivere un metodo che prenda in input una matrice di stringhe S di dimensioni nxm, uno short k,
ed una stringa w. Il metodo restituisca il valore booleano true se esiste almeno una riga in P tale che
la stringa w sia sottostringa di un numero di stringhe della riga stessa che sia minore o uguale a k. */
bool MarryVentiquattro(string **S, int n, int m, short k, string w){
     for (int i=0; i<n; i++){
         short contatore=0;
         for (int j=0; j<m; j++){
             if (S[i][j].find(w)!=string::npos){
                 contatore++;
             }
         }
         if ((contatore>0)&&(contatore<=k)){
             cout<<"Riga: "<<i<<endl;
             return true;
         }
     }
     return false;
}

int main(){
int n=3;
int m=4;
string **S=new string *[n];
for (int i=0; i<n; i++){
S[i]=new string [m];
for (int j=0; j<m; j++){
    cin>>S[i][j];
}
}
for (int i=0; i<n; i++){
for (int j=0; j<m; j++){
    cout<<S[i][j]<<'\t';
}
cout<<endl;
}
string w = "ri";
cout<<MarryVentiquattro(S, n, m, 2, w);
}