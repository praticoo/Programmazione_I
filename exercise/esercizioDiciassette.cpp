#include <iostream>
using namespace std;

/* [Esercizio 17]
Scrivere un metodo che prenda un parametro formale matrice di stringhe S di dimensione n × m e due array di caratteri C
e D di egual dimensione n e restituisca un array di short nel quale il generico elemento di posto i contiene il numero di stringhe
che iniziano con il carattere di C avente indice i e finiscono con il carattere in D avente indice i. */

short *esercizioDiciassette(string **S, int n, int m, char *C, char *D){
    short *ArrayR = new short [m];
    for (int i=0; i < n; i++){
        short Contatore = 0;
        for (int j=0; j < m; j++){
            for (int z=0; z < S[i][j].size(); z++){
                if ((S[i][j][0]==C[i])&&(S[i][j][S[i][j].size()-1]==D[i])){
                    cout << S[i][j][0] << "=" << C[i] << endl;
                    cout << S[i][j][S[i][j].size()-1] << "=" << D[i] << endl;
                    Contatore++;
                    break;
                }
            }
        }
        ArrayR[i] = Contatore;
    }
    return ArrayR;
}

int main(){
    int n = 2;
    int m = 3;
    string **S = new string *[n];
    for (int i=0; i < n; i++){
        S[i] = new string [m];
        for (int j=0; j < m; j++){
            cin >> S[i][j];
        }
    }
  for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            cout << S[i][j] << '\t';
        }
        cout << endl;
    }

    char *C =new char [n];
    for (int i=0; i<n; i++){
        cin >> C[i];
    }

    for (int i=0; i<n; i++){
        cout << C[i] << '\t';
    }
cout << endl;
    char *D =new char [n];
    for (int i=0; i<n; i++){
        cin >> D[i];
    }

    for (int i=0; i<n; i++){
        cout << D[i] << '\t';
    }
cout << endl;
    short *Nuovo = new short [n];
    Nuovo = esercizioDiciassette(S, n, m, C, D);
    for (int i=0; i < n; i++){
        cout << Nuovo [i] << '\t';
    }
}