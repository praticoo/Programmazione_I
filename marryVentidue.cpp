#include <iostream>
using namespace std;
/*22.Scrivere un metodo che prenda in input una matrice quadrata Q di stringhe e restituisca il valore
booleano true se la stringa piu lunga della diagonale principale di Q contiene un numero di vocali minore
della stringa piu corta della diagonale stessa. NB: Si assuma che le stringhe della diagonale principale
abbiano lunghezze differenti e sempre maggiori di zero. */
bool MarryVentidue(string **Q, int n){
string StringaPiuLunga;
string StringaPiuCorta;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        if ((i==j)&&(Q[i][j].size()>StringaPiuLunga.size())){
            StringaPiuLunga=Q[i][j];
            StringaPiuCorta=StringaPiuLunga;
        }
    }
}
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
if ((i==j)&&(Q[i][j].size()<StringaPiuCorta.size())){
            StringaPiuCorta=Q[i][j];
        }
    }
}
cout<<"Stringa piu lunga: "<<StringaPiuLunga<<endl;
cout<<"Stringa piu corta: "<<StringaPiuCorta<<endl;
int VocaliPl=0;
for (int i=0; i<StringaPiuLunga.size(); i++){
        if ((StringaPiuLunga[i]=='a')||(StringaPiuLunga[i]=='e')||(StringaPiuLunga[i]=='i')||(StringaPiuLunga[i]=='o')||(StringaPiuLunga[i]=='u')){
            VocaliPl++;
        }
}
cout<<"Vocali Stringa piu lunga: "<<VocaliPl<<endl;
int VocaliPc=0;
for (int i=0; i<StringaPiuCorta.size(); i++){
        if ((StringaPiuCorta[i]=='a')||(StringaPiuCorta[i]=='e')||(StringaPiuCorta[i]=='i')||(StringaPiuCorta[i]=='o')||(StringaPiuCorta[i]=='u')){
            VocaliPc++;
        }
}
cout<<"Vocali Stringa piu corta: "<<VocaliPc<<endl;
if (VocaliPl<VocaliPc){
    return true;
}
else {
    return false;
}
}
int main(){
    int n=3;
    string **Q=new string *[n];
    for (int i=0; i<n; i++){
           Q[i]=new string [n];
           for (int j=0; j<n; j++){
               cin>>Q[i][j];
           }
    }

     for (int i=0; i<n; i++){
           for (int j=0; j<n; j++){
               cout<<Q[i][j]<<'\t';
           }
           cout<<endl;
    }
    cout<<MarryVentidue(Q, n);
}