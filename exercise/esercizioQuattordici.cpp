#include <iostream>
using namespace std;

/* [Esercizio 14]
Scrivere un metodo che preveda un parametro formale array monodimensionale S di n puntatori a stringhe, ed inoltre una
matrice C di caratteri distinti ed uno short k, e restituisca un array di n puntatori a stringhe in cui il generico elemento di
indice i contiene un puntatore alla i-esima stringa in S solo se questa contiene almeno k caratteri in C, altrimenti nullptr. */

string **esercizioQuattordici(string **S, char **C, int n, short k){
    string **Risultato = new string *[n];
    short count;
    for (int i=0; i<n; i++){
        count = 0; 
        cout << "Stringa in Esame :" << S[i][0] << endl;
        cout << "Corrispettiva Locazione di Memoria :" << S[i] << endl; 
        for (int s=0; s<S[i][0].size(); s++){
            for (int z=0; z<n; z++){
                for (int r=0; r<n; r++){
                    if (S[i][0][s] == C[z][r]){
                        count ++;
                    }
                }
            }
        }
        if (count >= k){
              //cout << S[i][0] << endl;
              Risultato[i] = S[i]; 
            }
            else {
                Risultato[i] = nullptr;                                   //nullptr perchè devo tornare puntatore
            }                                                                    //sennò per puntare direttamente al valore mettevo null
    }
        return Risultato;
    }

int main(){
    int n = 3;
    string **S =new string *[n];
    for (int i=0; i<n; i++){
        S[i] = new string;
        cin >> S[i][0];
    }

    for (int i=0; i<n; i++){
        cout << S[i][0] << '\t';
    }
    cout << endl;
    
    cout << "Matrice C di caratteri distinti : " << endl;
    char **C = new char *[n];
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

    short k = 2;

string **Risultato = new string *[n];
Risultato = esercizioQuattordici (S, C, n, k);
    for (int i=0; i<n; i++){
         cout << Risultato[i] << '\t';
    }

}
