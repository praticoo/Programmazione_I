/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice di puntatori a stringhe di dimensioni n × m ed uno
short p (si assuma p < n). Il metodo restituisca il numero di colonne aventi il seguente requisito: la colonna contiene almeno
p stringhe le quali risultano composte esclusivamente da caratteri appartenenti agli insiemi {’0’, ’1’, . . . ,’9’} e {’A’, . . . , ’Z’}.
Esempi: ”ABCD” (ok!), ”AB4ER2” (ok!), ”1261” (ok!), ”aGHTY34T5bPT” (NO!). */

#include <iostream>
using namespace std;

//Esame 24 / 01 / 2O22 - COMPITO B

// p < n
int esercizioDue(string ***P, int n, int m, short p){
    int colonna = 0; 
for (int j=0; j<m; j++){
    int stringa = 0;
    for (int i=0; i<n; i++){
        if (P[i][j]){
            int count = 0;
        for (int z=0; z<P[i][j][0].size(); z++){
            if ((P[i][j][0][z] == '0')||(P[i][j][0][z] == '1')||(P[i][j][0][z] == '2')||(P[i][j][0][z] == '3')||(P[i][j][0][z] == '4')||
            (P[i][j][0][z] == '5')||(P[i][j][0][z] == '6')||(P[i][j][0][z] == '7')||(P[i][j][0][z] == '8')||(P[i][j][0][z] == '9')||
            ((P[i][j][0][z] >= 65)&&(P[i][j][0][z] <= 90))){
                count ++;
                //cout << P[i][j][0][z] << endl;
            }
            else {
                cout << P[i][j][0][z] << endl;
                break;
            }
        }
        if (count == P[i][j][0].size()){
            stringa ++;
        }
        }
    }
    if (stringa >= p){
        colonna ++;
    }

}
return colonna;
}

int main (){
    int n = 3;
    int m = 4;
    string ***P = new string **[n];
    for (int i=0; i<n; i++){
        P[i] = new string *[n];
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

    cout << esercizioDue(P, n, m, 2);
}