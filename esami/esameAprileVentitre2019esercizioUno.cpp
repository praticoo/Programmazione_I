#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda in input una matrice quadrata M di short e restituisca il valore booleano true se M `e una matrice
triangolare inferiore o superiore. */

//Esame 23 / 04 / 2019

bool esercizioUno(short **M, int n){
    int countUno = 0;
    int occorrenze = 0;
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            //if (i!=j){
                occorrenze ++;
                //cout << M[i][j] << endl;
                if (M[i][j] == 0){
                    countUno ++;
                //}
            }
        }
    }

    if ((countUno > 0) && (countUno == occorrenze)){
        return true;
    }
    
    occorrenze = 0;
    int countDue = 0;
    for (int i=0; i<n; i++){
        for (int j=1+i; j<n; j++){
            occorrenze ++;
            //cout << M[i][j] << endl;
            if (M[i][j] == 0){
                countDue ++;
            }
        }
    }

    if ((countDue > 0) && (countDue == occorrenze)){
        return true;
    }
    return false;
}

int main(){
int n = 4;
short **M = new short*[n];
for (int i=0; i<n; i++){
    M[i] = new short[n];
    for (int j=0; j<n; j++){
        cin >> M[i][j];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout << M[i][j] << '\t';
    }
    cout << endl;
}

cout << esercizioUno(M, n);

}