#include <iostream>
using namespace std; 

/* Scrivere un metodo che prenda in input una matrice V di stringhe contenente verbi italiani
all’infinito, e restituisca la percentuale dei verbi della prima coniugazione. */
 
//Percentuale: (numero verbi Totale * numero verbi prima coniugazione) / 100

// Esame 20 / 12 / 17

double esercizioDue (string **V, int n, int m){
    int contatore = 0;
    cout << "Verbi Prima Coniugazione Trovati :" << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if ((V[i][j][(V[i][j].size())-3]=='a')&&(V[i][j][(V[i][j].size())-2]=='r')&&(V[i][j][(V[i][j].size())-1]=='e')){
                cout << V[i][j] << endl;
                contatore ++;
            }
        }
    }
    double Percentuale = (double)(contatore * (n * m)) / 100;
    cout << "Percentuale Verbi Prima Coniugazione : " ;
    return Percentuale;
}

int main(){
    int n = 3;
    int m = 4;
    string **V = new string *[n];
    for (int i=0; i<n; i++){
        V[i] = new string [m];
        for (int j=0; j<m; j++){
            cin >> V[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << V[i][j] << '\t';
        }
      cout << endl;
    }

    cout << esercizioDue (V, n, m) << "%";
}