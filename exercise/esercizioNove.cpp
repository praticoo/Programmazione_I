#include <iostream>

using namespace std;

/* [Esercizio 9] Scrivere un metodo che prenda in input un parametro formale A matrice di stringhe di dimensione n × m,
ed una stringa s. Il metodo restituisca true se esistono almeno due stringhe in A che contengono la stringa s e che abbiano
differenti indici di riga e di colonna. */

bool esercizioNove(string **A, int n, int m, string s){
    bool Risultato;
    int Contatore = 0; 
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if ((A[i][j].find(s) != string::npos) && (i != j)){
                Contatore ++;
                if (Contatore >= 2){
                    Risultato = true;
                    if (Risultato==true){
                    cout << "Ci sono almeno due stringhe in A che contengono la stringa " << s << "." << endl;
                    return true;
                    break;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int n = 3;
    int m = 3;
    string **A = new string *[n];
    for (int i=0; i<n; i++){
        A[i] = new string [n];
        for (int j=0; j<n; j++){
            cin >> A[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << A[i][j] << '\t';
        }
      cout << endl;
    }
    string s = "ao";
    cout << esercizioNove(A, n, m, s);
}
