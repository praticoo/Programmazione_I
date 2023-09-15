/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice di caratteri C, un array di stringhe S ed uno short
k. Il metodo restituisca una stringa composta da tutti i caratteri presenti in C che siano presenti in almeno k stringhe dell’array
S. */

#include <iostream>
using namespace std;

//Esame 24 / 01 / 22 - COMPITO C

string esercizioDue(char **C, int n, string *S, short k){
    string stringa = "";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            string m = "";  int stringhe = 0;
            for (int b=0; b<n; b++){
                int count = 0;
                for (int z=0; z<S[b].size(); z++){
                    if (C[i][j] == S[b][z]){
                        m=C[i][j];
                        //cout << m << endl;
                        count ++;
                    }
                }
                if (count > 0){
                    //cout << stringhe << endl;
                    stringhe ++;
                }
            }
            if (stringhe >= k){
            stringa = stringa + m;
           }
        }
    }
    return stringa;
}

int main(){
    int n = 3;
    char **C =new char *[n];
    for (int i=0; i<n; i++){
        C[i] = new char [n];
        for (int j=0; j<n; j++){
            cin >> C[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << C[i][j] << '\t';
        }
        cout << endl;
    }
    
    cout << endl;

    string *S = new string [n];
    for (int i=0; i<n; i++){
        cin >> S[i];
    }

    for (int i=0; i<n; i++){
        cout << S[i] << '\t';
    }
    cout << endl;

    cout << esercizioDue(C, n, S, 2);

}