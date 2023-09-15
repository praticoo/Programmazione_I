#include <iostream>
using namespace std;
/* 30.Scrivere un metodo che prenda in input una matrice di stringhe A e due numeri short senza segno,
k ed s, e restituisca il valore booleano true se esiste almeno una riga di A contenente almeno k stringhe
ognuna contenente un numero di lettere maiuscole minore di s. */
bool MarryTrenta(string **A, int n, unsigned short k, unsigned short s){
    for (int i=0; i<n; i++){
        int KStringhe=0;
        for (int j=0; j<n; j++){
            int NLetMaiuscole=0;
             for (int z=0; z<A[i][j].size(); z++){
                 cout<<"Stringa: "<<A[i][j]<<endl;
                 if ((A[i][j][z]>=65)&&(A[i][j][z]<=90)){
                     cout<<"Lettera Maiscuola: "<<A[i][j][z]<<endl;
                      NLetMaiuscole++;
                 }
             }
             cout<<"Lettere Maiuscole: "<<NLetMaiuscole<<endl;
             if (NLetMaiuscole<s){
                 KStringhe++;
             }
             cout<<"Numero Stringhe: "<<KStringhe<<endl;
             if (KStringhe>=k){
                 return true;
                 break;
             }
        }
    }
    return false;
}
int main(){
    int n=3;
    string **A=new string *[n];
    for (int i=0; i<n; i++){
        A[i]=new string [n];
        for (int j=0; j<n; j++){
            cin>>A[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<A[i][j]<<'\t';
        }
        cout<<endl;
    }   
    cout<<MarryTrenta(A, n, 2, 3);

    //string ciao="CiAO";
    //for (int i=0; i<ciao.size();i++){
        //if ((ciao[i]>=0x41)&&(ciao[i]<=0x5a)){
          //   cout<<"Yes!"<<endl;
        //}
        //if ((ciao[i]>=0101)&&(ciao[i]<=0132)){
          //   cout<<"Yes!"<<endl;
        //}
        //if ((ciao[i]>=65)&&(ciao[i]<=90)){
          //   cout<<"Yes!"<<endl;
        //}
    //}
}