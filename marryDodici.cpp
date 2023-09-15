//string.erase(pos_iniziale, posti)
/*int main(){
string uno="gatto";
string due="toga";
int w=3;
cout<<uno.erase(w, uno.size())<<endl;
cout<<due.erase(0, due.size()-w)<<endl;
if (uno==due){
    cout<<"Yes!"<<endl;
}
else{
    cout<<"No!"<<endl;
}
*/


//cout<<uno.erase(w,uno.size())<<endl;

//cout<<due.erase(0,due.size()-w)<<endl;
/*if (uno==due){
    cout<<"Yes!"<<endl;
}*/

//}
#include <iostream>
//#include <iomanip>
using namespace std;
/*12.Scrivere un metodo che prenda come parametri formali una matrice A di stringhe ed uno short w, e
restituisca in output un bool che indichi se esiste una riga di A in cui siano presenti almeno due stringhe
consecutive in cui i primi w caratteri della prima stringa siano uguali agli ultimi w caratteri della
seconda stringa (nello stesso ordine). */
bool MarryDodici(string **A, int n, short w){
    for (int i=0; i<n; i++){
        int Contatore=0;
        for (int j=0; j<n-1; j++){
            //cout<<"1: "<<A[i][j].substr(0,w)<<endl;
            //cout<<"2: "<<A[i][j+1].substr(A[i][j+1].size()-w)<<endl;
            if ((A[i][j].size()>=w)&&(A[i][j+1].size()>=w)&&(A[i][j].substr(0,w))==(A[i][j+1].substr(A[i][j+1].size()-w))){
               cout<<"Primi w caratteri della prima stringa: "<<A[i][j].substr(0,w)<<endl;
               cout<<"Ultimi w caratteri della seconda stringa: "<<A[i][j+1].substr(A[i][j+1].size()-w)<<endl;
               Contatore++;
            }
            if (Contatore>=2){
                cout<<"Caratteri congruenti"<<endl;
                return true;
                break;
            }
        }
    }
    
    return false;
}

int main(){
/*int n=3;
int s=3;
int z=3;
cout<<n++<<endl;                                //incrementa dopo!
cout<<s+1<<endl;
cout<<++z;*/

int n=3;
int w=3;
string **A= new string *[n];
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
cout<<MarryDodici(A, n, w);


/*string s1="caio";                                               
string s2="sambuca";
string s3;
int w=2;
cout<<s1.substr(0,w)<<endl;
cout<<s2.substr(s2.size()-w)<<endl;
if (s1.substr(0,w)==s2.substr(s2.size()-w)){
    cout<<"Si!"<<endl;
}
else {
    cout<<"No!"<<endl;
}
cout<<s1[0]<<endl;
cout<<s1[1]<<endl;
cout<<s2[s2.size()-2]<<endl;
cout<<s2[s2.size()-1]<<endl;
if ((s1[0]==s2[s2.size()-2])&&(s1[1]==s2[s2.size()-1])){
    cout<<"Yes!"<<endl;
}
else{
    cout<<"No!"<<endl;
}*/

}