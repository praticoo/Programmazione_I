#include <iostream>
using namespace std;
/*18.Scrivere un metodo che prenda in input una matrice di puntatori a stringhe M e due numeri short
senza segno, k ed s, e restituisca il numero di colonne contenenti almeno k stringhe con un numero di lettere
vocali minore di s. */
int MarryDiciotto(string ***M, int n, unsigned short k, unsigned short s){
    int NColonne=0;
    for (int j=0; j<n; j++){
        int KStringhe=0;
        for (int i=0; i<n; i++){
            if (M[i][j]){
                cout<<"Stringa in esame: "<<M[i][j][0]<<endl;
                int Vocali=0;
                for (int z=0; z<M[i][j][0].size(); z++){
                   cout<<"Carattere in esame: "<<M[i][j][0][z]<<endl;
                   if ((M[i][j][0][z]=='a')||(M[i][j][0][z]=='e')||(M[i][j][0][z]=='i')||(M[i][j][0][z]=='o')||(M[i][j][0][z]=='u')){
                        Vocali++;
                   }
                }
                cout<<"Numero Vocali: "<<Vocali<<endl;
                if (Vocali<s){
                    KStringhe++;
                }
            }
        }
        cout<<"Numero Stringhe: "<<KStringhe<<endl;
        if (KStringhe>=k){
            NColonne++;
        }
    }
    cout<<"Numero Colonne: ";
    return NColonne;
}
int main(){
int n=3;
unsigned short k=2;
unsigned short s=3;
string ***M=new string **[n];
for (int i=0; i<n; i++){
    M[i]=new string *[n];
    for (int j=0; j<n; j++){
        M[i][j]=new string;
        cin>>M[i][j][0];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout<<M[i][j][0]<<'\t';
    }
    cout<<endl;
}
cout<<MarryDiciotto(M, n, k, s);
}