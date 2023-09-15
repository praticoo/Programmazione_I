#include <iostream>
using namespace std;
/* 32.Scrivere un metodo che prenda in input una matrice quadrata di puntatori a stringhe e due caratteri
c1 e c2. Calcolare O1 come numero di occorrenze del carattere c1 che figurano nella diagonale principale.
CalcolareO2 come numero di occorrenze del carattere c2 che che figurano nella secondaria. Restituire il
rapportoO1/O2. NB: si faccia attenzione alle stringhe mancante */
double MarryTrentaDue(string ***Matrice, int n, char c1, char c2){
    double O1=0;
    double O2=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if ((i==j)&&(Matrice[i][j])){
                 cout<<"Stringa: "<<Matrice[i][j][0]<<endl;
                for (int z=0; z<Matrice[i][j][0].size(); z++){
                  if (Matrice[i][j][0][z]==c1){
                      cout<<"Carattere: "<<Matrice[i][j][0][z]<<endl;
                      O1++;
                  }
                }
            }
        }
    }
        int decremento=n-1;
        for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if ((j==decremento)&&(Matrice[i][j])){
                cout<<"Stringa: "<<Matrice[i][j][0]<<endl;
                decremento--;
                for (int z=0; z<Matrice[i][j][0].size(); z++){
                  if (Matrice[i][j][0][z]==c2){
                      cout<<"Carattere: "<<Matrice[i][j][0][z]<<endl;
                      O2++;
                  }
                }
            }
        }
    }
    double rapporto;
    if (O2!=0){
    rapporto=O1/O2;
    return rapporto;}
    else{
    rapporto=0;
    return rapporto;
    }

}
int main(){
    int n=3;
    string ***Matrice=new string **[n];
    for (int i=0; i<n; i++){
        Matrice[i]=new string *[n];
        for (int j=0; j<n; j++){
         Matrice[i][j]=new string;
         cin>>Matrice[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
         cout<<Matrice[i][j][0]<<'\t';
        }
        cout<<endl;
    }
    cout<<MarryTrentaDue(Matrice, n, 'c', 'a');
}
