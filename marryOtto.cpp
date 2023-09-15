#include <iostream>
using namespace std;
/*8.Scrivere un metodo che prenda in input una matrice quadrata di puntatori a stringhe Q ed una stringa s. Il
metodo restituisca il valore booleano true se e solo se il numero di stringhe che contengono s, presenti nella
diagonale principale di Q, e maggiore del numero di stringhe che contengono s presenti nella diagonale
secondaria di Q. */
bool MarryOtto(string ***Q, int n, string s){
    int SPrincipale=0;
    int SSecondaria=0;
    int Incremento=n-1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(j==Incremento){
                if ((Q[i][j])&&(*Q[i][j]==s)){
                    SSecondaria++;
                }
            }
            if (i==j){
                if((Q[i][j])&&(*Q[i][j]==s)){
                    SPrincipale++;
                }
            }
        }
    }
    if (SPrincipale>SSecondaria){
        return true;
    }
    else {
        return false;
    }

}
int main(){
    int n=3;
    string ***Q=new string **[n];
    for (int i=0; i<n; i++){
        Q[i]=new string *[n];
        for (int j=0; j<n; j++){
            Q[i][j]=new string();
            cin>>Q[i][j][0];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<Q[i][j][0]<<'\t';
        }
        cout<<endl;
    }
cout<<MarryOtto(Q, n, "giallo");
}
