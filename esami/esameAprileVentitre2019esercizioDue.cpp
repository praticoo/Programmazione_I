#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice di puntatori a stringhe S di dimensione n× m, una stringa s1 ed uno short
k, e restituisca la percentuale di stringhe, tra quelle presenti nelle prime k colonne di S, che siano pi`u lunghe di s1. NB: si
assuma k ≤ m. */

//Esame 23 / 04 / 2019

double esercizioDue(string ***S, int n, int m, string s1, short k){
    double count = 0;
    for (int j=0; j<k; j++){
        for (int i=0; i<n; i++){
            if (S[i][j]){
                cout << S[i][j] << endl;
                if (S[i][j][0].size() > s1.size()){
                    count ++;
                }
            }
        }
    }
    if (count > 0){
        return count *(double)(n*k) / (double) 100;
    }
    else {
        return 0;
    }
}

int main (){
    int n = 3;
    int m = 4;
    string ***S = new string **[n];
    for (int i=0; i<n; i++){
        S[i] = new string *[m];
        for (int j=0; j<m; j++){
            S[i][j] = new string;
            cin >> S[i][j][0];
        }
    }

     for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << S[i][j][0] << '\t';
        }
      cout << endl;
    }

cout << esercizioDue(S, n, m, "ciao", 2);
}