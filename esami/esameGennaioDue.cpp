#include <iostream>
using namespace std;
/*Scrivere un metodo in linguaggio C++ che prenda in imput una matrice di puntatori a stringhe 
di dimensioni n x m, e tre short k, r ed s (si assuma r < s e k < n). Il metodo restituisca il 
numero di colonne aventi il seguente requisito: la colonna contiene almeno k stringhe palindrome 
che abbiano lunghezza r <= l <= s. NB: una stringa si dice palindroma quando si legge allo stesso 
modo da destra e da sinistra (esempio: "abckcba" oppure "trert").*/
bool CheckPalindroma(string s){
    string vuota="";
    for (int i=0; i<s.size(); i++){
        vuota = s[i] + vuota;
    }
    return vuota==s;
}
int EsameGennaioDue(string ***Matrice, int n, int m, short k, short r, short s){
    int NColonne=0;
    for (int j=0; j<m; j++){
        int KStringhe=0;
        for (int i=0; i<n; i++){
            if ((Matrice[i][j])&&(CheckPalindroma(Matrice[i][j][0])==true)&&(Matrice[i][j][0].size()>=r)&&(Matrice[i][j][0].size()<=s)){
                cout<<"Stringa Palindroma esaminata: "<<Matrice[i][j][0]<<endl;
                KStringhe++;
            }
        }
        cout<<"Numero Stringhe: "<<KStringhe<<endl;
        if (KStringhe>=k){
            NColonne++;
        }
    }
    cout<<"Colonne: ";
    return NColonne;
}
int main(){
int n=3;
int m=4;
string ***Matrice=new string **[n];
for (int i=0; i<n; i++){
    Matrice[i]=new string *[m];
    for (int j=0; j<m; j++){
        Matrice [i][j]=new string;
        cin>>*Matrice[i][j];
    }
}
for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout<<*Matrice[i][j]<<'\t';
    }
    cout<<endl;
}
cout<<EsameGennaioDue(Matrice, n, m, 2, 4, 6);
}
