/* Scrivere un metodo che prenda come parametri formali una matrice A di stringhe ed uno short w, e
restituisca in output un bool che indichi se esiste una riga di A in cui siano presenti almeno due
stringhe consecutive in cui i primi w caratteri della prima stringa siano uguali agli ultimi w caratteri
della seconda stringa (nello stesso ordine). */

//Per w caratteri SUBSTR(INIZIO, FINE)

//Esame 08 / 03 /2018 - Esercizio Due

#include <iostream>
using namespace std;

bool esercizioDue(string**A, int n, short w){
  for (int i=0; i<n; i++){
    short count = 0; 
    for (int j=0; j<n-1; j++){
        if ((A[i][j].size()>=w)&&(A[i][j+1].size()>=w)&&(A[i][j].substr(0, w)) == A[i][j+1].substr(A[i][j+1].size()-w, A[i][j+1].size())){
            count ++;
            cout << "1: " << A[i][j].substr(0, w) << endl;
            cout << "2: " << A[i][j+1].substr(A[i][j+1].size()-w, A[i][j+1].size()) << endl;
        }
    }
    if (count >= 1){
        return true;
    }
  }
  return false;
}

int main(){
    int n = 4;
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

    cout << esercizioDue(A, n, 3);
}