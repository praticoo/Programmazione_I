#include <iostream>
using namespace std;
/* 36.Scrivere un metodo che prenda in input una matrice di stringhe di dimensioni n×m, due stringhe x
e y e due short k e w; il metodo restituisca la percentuale di colonne della matrice che contengono
almeno k stringhe contenenti almeno w caratteri presenti sia in x che in y. NB: si assuma, per
semplicità, che ognuna delle stringhe della matrice non che le stringhe x e y non contengano lo stesso
carattere più di una volta. */
double MarryTrentaSei(string **Matrice, int n, int m, string x, string y, short k, short w){
    double NColonne=0;
    for (int j=0; j<m; j++){
        int KStringhe=0;
        for (int i=0; i<n; i++){
            int NCaratteri=0;
            int NCaratteri2=0;
            for (int z=0; z<Matrice[i][j].size(); z++){
                cout<<"Stringa in esame: "<<Matrice[i][j]<<endl;
                 for (int xx=0; xx<x.size(); xx++){
                    if (Matrice[i][j][z]==x[xx]){
                        cout<<"Carattere Stringa: "<<Matrice[i][j][z]<<endl;
                        cout<<"Carattere identico: "<<x[xx]<<endl;
                        NCaratteri++;
                    }
                 }
                 cout<<"Caratteri contenuti nella stringa X: "<<NCaratteri<<endl;
                 for (int yy=0; yy<y.size(); yy++){
                    if (Matrice[i][j][z]==y[yy]){
                        cout<<"Carattere Stringa: "<<Matrice[i][j][z]<<endl;
                        cout<<"Carattere identico: "<<y[yy]<<endl;
                        NCaratteri2++;
                    }
                 }
                 cout<<"Caratteri contenuti nella stringa Y: "<<NCaratteri2<<endl;

            }
            if ((NCaratteri>=w)&&(NCaratteri2>=w)){
                     KStringhe++;
                 }
        }
        cout<<"Numero Stringhe: "<<KStringhe<<endl;
        if (KStringhe>=k){
            NColonne++;
        }
    cout<<"Colonne: "<<NColonne<<endl;
    }
    return (NColonne / m)/100;

}
int main(){
int n=2;
int m=3;
string **Matrice=new string*[n];
for (int i=0; i<n; i++){
    Matrice[i]=new string [m];
    for (int j=0; j<m; j++){
        cin>>Matrice[i][j];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        cout<<Matrice[i][j]<<'\t';
    }
    cout<<endl;
}
cout<<MarryTrentaSei(Matrice, n, m, "caso", "albero", 2, 2);
//( numero colonne valide / numero colonne ) / 100

}