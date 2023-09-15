#include <iostream>
using namespace std;
/*31.Scrivere un metodo che prenda in input una matrice M di puntatori a double di dimensione n × m e
due interi a e b e restituisca un array unidimensionale di booleani di lunghezza 2m tale che l’elemento
dell’array di posizione 2i contiene True se e solo se la media dei soli elementi della colonna i-esima di M
compresi tra a e b(estremi inclusi) è maggiore di (a+b)/2. Gli elementi dell’array di indice dispari devono
essere inizializzati a False. NB: Si presti attenzione ai numeri mancanti! */
bool *MarryTrentaUno(double ***M, int n, int m, int a, int b){
    bool *Risultato=new bool [2*m];
    for (int i=0; i<(2*m); i++){
            Risultato[i]=false;
    }
    int incremento=0;
    for (int j=0; j<m; j++){
        double SommaElementi=0;
        double media=0;
        for (int i=0; i<n; i++){
            if ((M[i][j])&&(M[i][j][0]>=a)&&(M[i][j][0]<=b)){
                cout<<"Elemento in esame: "<<M[i][j][0]<<endl;
                SommaElementi=M[i][j][0]+SommaElementi;
                media++; 
            }
        }
        cout<<"Somma Elementi: "<<SommaElementi<<endl;
        cout<<"Elementi per media: "<<media<<endl;
        if ((SommaElementi/media)>((double)(a+b)/2)){
            if (incremento%2==0){
            Risultato[incremento]=true;
            incremento++;
           //cout<<"Incremento: "<<incremento<<endl;
            }
            else{
                Risultato[incremento+1]=true;
                incremento=incremento+2;
               // cout<<"Incremento: "<<incremento<<endl;
            }
            //else {
              //  if (Risultato[j+1]!=1){
                //    cout<<"["<<j<<"]"<<endl;
                //Risultato[j+1]=new bool (true);
               // }
                //else{
                  //  cout<<"ciao"<<endl;
                    //Risultato[j+2]=true;
                //}

            //}
            //if ((j==m)){
              //      cout<<"Yes!"<<endl;
                   // Risultato [j+2]=true;
                //}
        }
    }
    return Risultato;

}
int main(){
    int n=3;
    int m=4;
    double ***M =new double **[n];
    for (int i=0; i<n; i++){
    M[i]=new double *[m];
    for (int j=0; j<m; j++){
        M[i][j]=new double;
        cin>>*M[i][j];
    }
    }
for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
       cout<<*M[i][j]<<'\t';
    }
    cout<<endl;
    }
int MM=8;
bool *Risultato=new bool [MM];
Risultato=MarryTrentaUno(M, n, m, 2, 3);
for (int i=0; i<MM; i++){
cout<<Risultato[i]<<'\t';
}
}
