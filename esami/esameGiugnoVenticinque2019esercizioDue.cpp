/* Scrivere un metodo che prenda in input una matrice quadrata Q di dimensioni n × n di puntatori a stringhe e due short m e k
e restituisca il valore booleano true se la diagonale secondaria di Q contiene almeno m stringhe con un numero di vocali minore
o uguale a k. NB: Si assuma m ≤ n. */
#include <iostream>
using namespace std;

//Esame 25 / 06 / 2019

bool esercizioDue(string ***Q, int n, short m, short k){
    int j = n-1; int string = 0;
    for (int i=0; i<n; i++){
        int count = 0;
        if (Q[i][j]){
            cout << "Stringa D. Sec. :" << Q[i][j][0] << endl;
        for (int z=0; z<Q[i][j][0].size(); z++){
              if ((Q[i][j][0][z] == 'A')||(Q[i][j][0][z] == 'E')||(Q[i][j][0][z] == 'I')||(Q[i][j][0][z] == 'O')||(Q[i][j][0][z] == 'U')||
                  (Q[i][j][0][z] == 'a')||(Q[i][j][0][z] == 'e')||(Q[i][j][0][z] == 'i')||(Q[i][j][0][z] == 'o')||(Q[i][j][0][z] == 'u')){
                    count ++;
                  }
        }
        if (count <= k){
            string ++;
        }
        j--;
        }
        if (string >= m){
            return true;
        }
    }
    return false;
}

int main(){
    int n = 3;
    string ***Q = new string**[n];
    for (int i=0; i<n; i++){
        Q[i] = new string *[n];
        for (int j=0; j<n; j++){
            Q[i][j] = new string;
            cin >> Q[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << Q[i][j][0] << '\t';
        }
      cout << endl;
    }
cout << esercizioDue(Q, n, 2, 3);
}


