#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda come parametro formale un cubo (array tridimensionale) C di
stringhe, e restituisca in output una stringa contenente tutte le desinenze di due caratteri delle
stringhe sulla faccia superiore del cubo C. */

//Esame 4 / 09 / 2018 - Esercizio Due

string esercizioDue(string ***C, int n){
    string risultato = "";
    int i = 0;
    for (int j=0; j<n; j++){
        for (int z=0; z<n; z++){
             risultato += C[i][j][z][C[i][j][z].size()-2];
             risultato += C[i][j][z][C[i][j][z].size()-1];
        }
    }
    return risultato;
}

int main(){
int n = 3;
string ***M= new string **[n];
for (int i=0; i<n; i++){
    M[i]= new string *[n];
    for (int j=0; j<n; j++){
        M[i][j]=new string [n];
    }
} 

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        for (int z=0; z<n; z++){
            cin >> M[i][j][z];}
    }

cout << endl;
    for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        for (int z=0; z<n; z++){
            cout<< "C[" << i << "][" << j << "][" << z << "]: " <<M[i][j][z]<<" ";
        }
        cout<<endl;
    }
    cout << endl;
}


}

cout << esercizioDue(M, n);
}
