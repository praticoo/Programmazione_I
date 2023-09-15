#include <iostream>
using namespace std;
/*26.Scrivere un metodo che prenda in input una matrice quadrata Q di dimensioni n x n di puntatori a
stringhe e due short m e k e restituisca il valore booleano true se la diagonale secondaria di Q contiene
almeno m stringhe con un numero di vocali minore o uguale a k. NB: Si assuma m<=n. */
bool MarryVentisei(string ***Q, int n, short m, short k){
    int decremento=n-1;
    int ContaStringhe=0;
    for (int i=0; i<n; i++){
        int ContaVocali=0;
        for (int j=0; j<n; j++){
            if ((j==decremento)&&(Q[i][j])){
                decremento--;
                cout<<"Stringa Diagonale Secondaria: "<<Q[i][j][0]<<endl;
                for (int z=0; z<Q[i][j][0].size(); z++){
                    if ((Q[i][j][0][z]=='a')||(Q[i][j][0][z]=='e')||(Q[i][j][0][z]=='i')||(Q[i][j][0][z]=='o')|| (Q[i][j][0][z]=='u')){
                        ContaVocali++;
                    }
                }
                cout<<"Numero Vocali: "<<ContaVocali<<endl;
                if (ContaVocali<=k){
                    ContaStringhe++;
                }

            }
        }
    }
    cout<<"Numero Stringhe: "<<ContaStringhe<<endl;
    if (ContaStringhe>=m){
        return true;
    }
    return false;
}
int main(){
    int n=3;
    short m=2;
    short k=3;
    string ***Q=new string **[n];
    for (int i=0; i<n; i++){
        Q[i]=new string *[n];
        for (int j=0; j<n; j++){
            Q[i][j]=new string;
            cin>>*Q[i][j];
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<*Q[i][j]<<'\t';
        }
        cout<<endl;
    }
cout<<MarryVentisei(Q, n, m, k);
}