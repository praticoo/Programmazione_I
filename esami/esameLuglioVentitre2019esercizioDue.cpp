#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice quadrata Q di stringhe e restituisca il valore booleano true se la stringa piu
lunga della diagonale principale di Q contiene un numero di vocali minore della stringa pi`u corta della diagonale stessa. NB: Si
assuma che le stringhe della diagonale principale abbiano lunghezze differenti e sempre maggiori di zero. */

//Esame 23 / 07 / 2019

bool esercizioDue (string **Q, int n){
    string lunga = ""; string corta = Q[0][0];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i == j){
                if (Q[i][j].size() > lunga.size()){
                    lunga = Q[i][j];
                    
                }
                else {
                    cout << corta << endl;
                    if (Q[i][j].size() < corta.size()){
                        corta = Q[i][j];
                    }
                }
            }
        }
    }

    cout << "Stringa Lunga: " << lunga << endl;
    cout << "Stringa Corta: " << corta << endl;
    
    int l = 0;   int c = 0;
    for (int i=0; i<lunga.size(); i++){
        if ((lunga[i] == 'a')||(lunga[i] == 'e')||(lunga[i] == 'i')||(lunga[i] == 'o')||(lunga[i] == 'u')||(lunga[i] == 'A')||(lunga[i] == 'E')||
            (lunga[i] == 'I')||(lunga[i] == 'O')||(lunga[i] == 'U')){
                l++;
            }
    }
    for (int i=0; i<corta.size(); i++){
        if ((corta[i] == 'a')||(corta[i] == 'e')||(corta[i] == 'i')||(corta[i] == 'o')||(corta[i] == 'u')||(corta[i] == 'A')||(corta[i] == 'E')||
            (corta[i] == 'I')||(corta[i] == 'O')||(corta[i] == 'U')){
                c++;
            }
    }

    if (l < c){
        return true;
    }
return false;
}

int main(){
    int n = 3;
    string **Q  = new string *[n];
    for (int i=0; i<n; i++){
        Q[i] = new string [n];
        for (int j=0; j<n; j++){
            cin >> Q[i][j];
        }
    }

for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << Q[i][j] << '\t';
        }
       cout << endl; 
    }

cout << esercizioDue(Q, n);

}