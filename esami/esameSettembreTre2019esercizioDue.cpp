#include <iostream>
using namespace std; 

/* Scrivere un metodo che prenda in input una matrice di puntatori a stringhe P di dimensioni n×m, due short
a e b, ed una stringa s. Il metodo restituisca il valore booleano true se esiste almeno una colonna in P tale
che la stringa s sia sottostringa di un numero compreso tra a e b (inclusi) di stringhe della colonna stessa.
PS: Si assuma 0 < a ≤ b < n */

//Esame 3 Settembre 2019 - Esercizio 2

bool esercizioDue(string ***P, int n, int m, short a, short b, string s){
    for (int j=0; j<m; j++){
        int conta = 0; 
        for (int i=0; i<n; i++){
            if (P[i][j][0].find(s) != string :: npos){
                    conta++;
            }
        }
        if ((conta >= a) && (conta <=b)){
            return true;
        }
    }
    return false;
}

int main(){
    int n = 3;
    int m = 4;
    string s = "ic" ;
    string ***P = new string **[n];
    for (int i=0; i<n; i++){
        P[i] = new string *[m];
        for (int j=0; j<m; j++){
            P[i][j] = new string;
            cin >> P[i][j][0];
        } 
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << P[i][j][0] << '\t';
        } 
        cout << endl;
    }

    cout << esercizioDue(P, n, m, 1, 2, s);
}