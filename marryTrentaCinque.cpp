#include <iostream>
#include <cmath>
using namespace std;
/* 35.Scrivere un metodo che prenda in input una matrice Q di puntatori a int di dimensione n × m e due
float a e b e restituisca un array di float di dimensione m tale che lo i-esimo elemento dello array contiene la
media dei soli elementi della colonna i-esima compresi tra a e b (estremi inclusi). Nel confronto tra interi e
numeri in virgola mobile si consideri l’arrotondamento di questi ultimi al numero intero più prossimo ad essi.
NB: Si presti attenzione ai numeri mancanti! */
float *MarryTrentaCinque(int ***Q, int n, int m, float a, float b){
    float *Risultato= new float [m];
    for (int j=0; j<m; j++){
        int NElementi=0;
        float SommaElementi=0;
        for (int i=0; i<n; i++){
            if ((Q[i][j])&&(Q[i][j][0]>=round(a))&&(Q[i][j][0]<=round (b))){
                cout<<"Elemento in esame: "<<Q[i][j][0]<<endl;
                SommaElementi=Q[i][j][0]+SommaElementi;
                NElementi++;
            }
        }
        cout<<"Somma elementi: "<<SommaElementi<<endl;
        cout<<"Numero elementi: "<<NElementi<<endl;
        if ((NElementi!=0)){
        float media=SommaElementi/NElementi;
        cout<<"Media: "<<media<<endl;
        Risultato[j]=media;}
        else {
            Risultato[j]=0;
        }
    }
return Risultato;
}
int main(){
    int n=3;
    int m=4;
    int ***Q=new int **[n];
    for (int i=0; i<n; i++){
        Q[i]=new int *[m];
        for (int j=0; j<m; j++){
            Q[i][j]=new int;
            cin>>*Q[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<*Q[i][j]<<'\t';
        }
        cout<<endl;
    }
float *Risultato=new float [m];
Risultato=MarryTrentaCinque(Q, n, m, 1.3, 7.2);
for (int i=0; i<m; i++){
    cout<<Risultato[i]<<'\t';
}
}