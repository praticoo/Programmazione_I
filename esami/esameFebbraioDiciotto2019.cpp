#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice di puntatori a stringhe M e due numeri short senza
segno, k ed s, e restituisca il numero di colonne contenenti almeno k stringhe con un numero di lettere vocali
minore di s */

//Esame 18 / 02 / 2019

int esercizioDue (string ***M, int n, unsigned short k, unsigned short s){
    int Colonna = 0; 
    for (int j=0; j<n; j++){
        int Stringa = 0;
        for (int i=0; i<n; i++){
            int count = 0;
            if (M[i][j]){
                for (int z=0; z<M[i][j][0].size(); z++){
                    if ((M[i][j][0][z] == 'A')||(M[i][j][0][z] == 'E')||(M[i][j][0][z] == 'I')||(M[i][j][0][z] == 'O')||(M[i][j][0][z] == 'U')||
                    (M[i][j][0][z] == 'a')||(M[i][j][0][z] == 'e')||(M[i][j][0][z] == 'i')||(M[i][j][0][z] == 'o')||(M[i][j][0][z] == 'u')){
                        count ++;
                    }
                }
                if (count < s){
                    Stringa ++;
                }
            }
        }
        if (Stringa >= k){
                Colonna ++;
            }
    }
    return Colonna;
}

int main(){
    int n = 3;
    string ***M = new string **[n];
    for (int i=0; i<n; i++){
        M[i] = new string *[n];
        for (int j=0; j<n; j++){
            M[i][j] = new string;
            cin >> M[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << M[i][j][0] << '\t';
        }
      cout << endl;
    }

    cout << esercizioDue(M, n, 1, 2);

}