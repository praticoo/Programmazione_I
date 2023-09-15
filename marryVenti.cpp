#include <iostream>
using namespace std;
/*20.Scrivere un metodo che prenda in input una matrice di puntatori a stringhe S di dimensione n*m,
una stringa s1 ed uno short k, e restituisca la percentuale di stringhe, tra quelle presenti nelle prime
k colonne di S, che siano piu lunghe di s1. NB: si assuma k<=m. */
double MarryVenti(string ***S, int n, int m, string s1, short k){
    double Percentuale=0;
    double StringheLunghe=0;
    double Stringhe;
    for (int j=0; j<=k; j++){
        for (int i=0; i<n; i++){
            if (S[i][j]){
            Stringhe++;
            if ((S[i][j][0].size()>s1.size())){
                StringheLunghe++;
            }
            }
        }
    }
    cout<<"Numero Stringhe Lunghe: "<<StringheLunghe<<endl;
    cout<<"Numero Stringhe: "<<Stringhe<<endl;
return (StringheLunghe/Stringhe)/100;
}
int main(){
    int n=3; 
    int m=4;
    short k=1;
    string ***S=new string **[n];
    for (int i=0; i<n; i++){
        S[i]=new string *[n];
        for (int j=0; j<n; j++){
            S[i][j]=new string;
            cin>>*S[i][j];
        }
    }

for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<*S[i][j]<<'\t';
        }
        cout<<endl;
    }
cout<<MarryVenti(S, n, m, "vita", k);
}