/* [Esercizio 11] Scrivere un metodo che preveda un parametro formale matrice di char di dimensione n × m ed un ulteriore
parametro intero a, e restituisca il valore booleano true se esiste almeno una riga o una colonna che contiene almeno a caratteri
che siano tutti minuscoli o tutti maiuscoli e che abbiano posizioni adiacenti. NB: Si assuma che la matrice contenga solo caratteri
corrispondenti alle lettere dell’alfabeto. */
#include <iostream>
// funzioni che operano sui singoli caratteri. Per usare queste funzioni dobbiamo includere cctype:
#include <cctype>
using namespace std;
bool esercizioUndici(char **Matrice, int n, int m, int a){
    int minuscoli;
    int maiuscoli;
    for (int i=0; i<n; i++){
        minuscoli = 0; 
        maiuscoli = 0;
        for (int j=0; j<m; j++){
            if (Matrice[i][j]==tolower(Matrice[i][j])){
                minuscoli++;
            }
            else {
                minuscoli = 0;
            }
            if (Matrice[i][j]==toupper(Matrice[i][j])){
                maiuscoli ++;
            }
            else {
                maiuscoli = 0; 
            }
            if ((maiuscoli == a)||(minuscoli == a)){
                cout << "Riga maiuscole: "<< maiuscoli << endl;
                cout << "Riga minuscole: " << minuscoli << endl;
                return true;
                break;
            }
        }
    }

    for (int i=0; i<m; i++){
        minuscoli = 0; 
        maiuscoli = 0;
        for (int j=0; j<n; j++){
            if (Matrice[j][i]==tolower(Matrice[j][i])){
                minuscoli++;
            }
            else {
                minuscoli = 0;
            }
            if (Matrice[j][i]==toupper(Matrice[j][i])){
                maiuscoli ++;
            }
            else {
                maiuscoli = 0; 
            }
            if ((maiuscoli == a)||(minuscoli == a)){
                cout << "Colonna maiuscole: "<< maiuscoli << endl;
                cout << "Colonna minuscole: " << minuscoli << endl;
                return true;
                break;
            }
        }
    }
    return false;
}

int main(){
    int n = 3;
    int m = 4;
    int a = 3;
    char **Matrice = new char *[n];
    for (int i=0; i<n; i++){
        Matrice[i] = new char [m];
        for (int j=0; j<m; j++){
            cin >> Matrice[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << Matrice[i][j] << '\t';
        }
        cout << endl;
    }

    cout << esercizioUndici(Matrice, n, m, a);
}