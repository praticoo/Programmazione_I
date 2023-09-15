#include <iostream>
using namespace std;

/* [Esercizio 3] Scrivere un metodo che prenda in input tre parametri formali: una matrice di stringhe S di dimensioni n×m,
un array di caratteri C che contiene elementi distinti, ed un float w. Il metodo restituisca true se esiste almeno una riga o una
colonna della matrice tale che la percentuale di caratteri di C presenti in essa `e maggiore di w. */

bool esercizioTre(string **S, int n, int m, char *C, int dimC, float w){
    for (int i=0; i < n; i++){
        double count = 0; 
        for (int j=0; j < m; j++){
            for (int z=0; z<S[i][j].size();z++){
                for (int s=0; s<dimC; s++){
                    if (S[i][j][z]==C[s]){
                        cout << S[i][j] << endl;
                        cout << S[i][j][z] << " = " << C[s] << endl;
                        count ++;
                    }
                }
            }
        }
        double media = (count * n) / 100;
        cout << "Media Riga : " << media << endl;
        if (media > w){
            return true;
            break;
        }

    }

    for (int j=0; j < m; j++){
        double count = 0; 
        for (int i=0; i < n; i++){
            for (int z=0; z<S[i][j].size();z++){
                for (int s=0; s<dimC; s++){
                    if (S[i][j][z]==C[s]){
                        cout << S[i][j] << endl;
                        cout << S[i][j][z] << " = " << C[s] << endl;
                        count ++;
                    }
                }
            }
        }
        double media = (count * m) / 100;
        cout << "Media Colonna : " << media << endl;
        if (media > w){
            return true;
            break;
        }

    }
    return false;

}

int main(){
int n = 2;
int m = 4;
string **S = new string *[n];
for (int i=0; i<n; i++){
    S[i] = new string [m];
    for (int j=0; j < m; j++){
        cin >> S[i][j];
    }
}

for (int i=0; i<n; i++){
    for (int j=0; j < m; j++){
        cout << S[i][j] << '\t';
    }
    cout << endl;
}

int dimC = 5;
char *C = new char [dimC];
for (int i=0; i < dimC; i++){
    cin >> C[i];
}
for (int i=0; i < dimC; i++){
    cout << C[i] << '\t';
}
cout << endl; 
cout << esercizioTre(S, n, m, C, dimC, 0.3);


}