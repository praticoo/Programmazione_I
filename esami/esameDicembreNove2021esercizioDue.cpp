/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice A di puntatori a stringhe ed un array B di caratteri.
Il metodo operi sulle stringhe delle colonne di indice dispari di A depurandole delle vocali eventualmente presenti in B. */

#include <iostream>
using namespace std;

//Esame 9 Dicembre 2021

string ***esercizioDue(string ***A, int n, char *b){
    for (int j=1; j<n; j++){
        for (int i=0; i<n; i++){
            if (j%2!=0){
                if (A[i][j]){
                    for (int z=0; z<n; z++){
                        for (int s=0; s<A[i][j][0].size(); s++){
                            while ((A[i][j][0][s] == b[z])&&((b[z] == 'a')||(b[z] == 'e')||(b[z] == 'i')||(b[z] == 'o')||(b[z] == 'U')||(b[z] == 'u')||
                            (b[z] == 'A')||(b[z] == 'E')||(b[z] == 'I')||(b[z] == 'O'))){
                                    A[i][j][0][s] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return A;
}

int main(){
    int n = 4;
    string ***A = new string **[n];
    for (int i=0; i<n; i++){
        A[i] = new string *[n];
        for (int j=0; j<n; j++){
            A[i][j] = new string;
            cin >> A[i][j][0];
        }
    }
for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << A[i][j][0] << '\t';
        }
      cout << endl;
    }

    char *b = new char [n];
    for (int i=0; i<n; i++){
        cin >> b[i];
    }

    for (int i=0; i<n; i++){
        cout << b[i] << '\t'; 
    }
    cout << endl;

    string ***Risultato = new string **[n];
    Risultato = esercizioDue(A, n, b);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << Risultato[i][j][0] << '\t';
        } 
        cout << endl;
    }
}