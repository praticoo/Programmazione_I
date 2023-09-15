#include <iostream>
using namespace std;

/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice di puntatori a stringhe di dimensioni n × m, e tre short
k, r ed s (si assuma r < s e k < n). Il metodo restituisca il numero di colonne aventi il seguente requisito: la colonna contiene
almeno k stringhe palindrome che abbiano lunghezza r ≤ l ≤ s. NB: una stringa si dice palindroma quando si legge allo stesso
modo da destra e da sinistra (esempio: ”abckcba” oppure ”trert”). */

//Esame 24 / 01 / 2022 - COMPITO A 

bool CheckPalindroma(string stringa){
    string vuota = "";
    for (int i=0; i<stringa.size(); i++){
        vuota = stringa[i] + vuota;
    }
    //cout << vuota << endl;
    return vuota == stringa;
}

int esercizioDue(string ***P, int n, int m, short k, short r, short s){
    int Risultato = 0;
    for (int j=0; j<m; j++){
        short palindroma = 0;
        for (int i=0; i<n; i++){
            if ((P[i][j]) && (CheckPalindroma(P[i][j][0]) == true) && (P[i][j][0].size() >= r) && (P[i][j][0].size() <= s)) {
                palindroma ++;
            }
        }
        if (palindroma >= k){
            Risultato ++;
        }
    }
    return Risultato;
}

int main(){
    int n = 3;
    int m = 4;
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

cout << esercizioDue(P, n, m, 2, 4, 6);
}