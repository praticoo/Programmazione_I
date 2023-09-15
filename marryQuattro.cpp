#include <iostream>
using namespace std;
/*4.Scrivere un metodo che prenda in input una matrice di puntatori a stringhe P di dimensioni n*m, due short a
e b, ed una stringa s. Il metodo restituisca il valore booleano true se esiste almeno una colonna in P tale
che la stringa s sia sottostringa di un numero compreso tra a e b (inclusi) di stringhe della colonna
stessa. PS: Si assuma 0 < a b < n */
bool MarryQuattro(string ***P, int n, int m, short a, short b, string s){
    for (int j=0; j<m; j++){
       int ContaStringhe=0;
       for (int i=0; i<n; i++){
           if ((P[i][j])&&(P[i][j][0].find(s)!=string::npos)){
               ContaStringhe++;
           }
           if ((a<=ContaStringhe)&&(ContaStringhe<=b)){
               cout<<"Colonna: "<<j<<endl;
               return true;
               break;
           }
       }
    }
           return false;
 }
           
int main(){
int n=4;
int m=3;
short a=1;
short b=3;
string s="ia";
string ***P=new string **[n];
for (int i=0; i<n; i++){
     P[i]=new string *[m];
    for (int j=0; j<m; j++){
        P[i][j]=new string;
        cin>>*P[i][j];
      
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout<<P[i][j][0]<<'\t';
    }
    cout<<endl;
}
cout<<MarryQuattro(P, n, m, a, b, s );
 }