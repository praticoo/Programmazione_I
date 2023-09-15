//string s1="gaeciaono";
//string s2="ciao";
//if (s1.find(s2)!=string::npos){                         per trovare sottostringa!
//cout<<"true";
//}
#include <iostream>
#include <cstdlib>
#include <iomanip>                  //es. per setw()
using namespace std;
/*10.Scrivere un metodo che prenda in input tre parametri formali: una matrice di puntatori a stringhe
A di dimensioni nxm, uno short k ed una stringa s. Il metodo restituisca un array di bool di dimensione n in
cui il singolo elemento di indice i assume valore true se la stringa s e' sottostringa di almeno k stringhe della
riga i-esima della matrice A.*/
bool *MarryDieci(string ***A, int n, int m, short k, string s){
    bool *ABool=new bool[n];
    for (int i=0; i<n; i++){
        int ContaSottoStringhe=0;
        for (int j=0; j<m; j++){
            if ((A[i][j])&&(A[i][j][0].find(s)!=string::npos)){
                ContaSottoStringhe++;
            }
            if (ContaSottoStringhe>=k){
                ABool[i]=true;
            }
            else{
                ABool[i]=false;
            }
        }
    }
    return ABool;
} 
int main(){
int n=3;
int m=4;
string ***A=new string **[n];
for (int i=0; i<n; i++){
       A[i]=new string *[m];
       for (int j=0; j<m; j++){
           A[i][j]=new string;
           cin>>*A[i][j];
       }

 }

for (int i=0; i<n; i++){
       for (int j=0; j<m; j++){
           cout<<*A[i][j]<<'\t';
       }
       cout<<endl;
 }
 string s="ri";
 cout<<"Array Di Bool: "<<endl;
 bool *ABool=new bool [n];
 ABool=MarryDieci(A, n, m, 2, s);
 for (int i=0; i<n; i++){
 cout<<ABool[i]<<'\t';
 }
}