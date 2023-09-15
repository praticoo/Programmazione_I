#include <iostream>
using namespace std;

/* [Esercizio 15]
Scrivere un metodo che preveda due parametri formali: una matrice A di stringhe ed una matrice B di short, entrambe di
dimensioni n×m. Il metodo restituisca uno array di n puntatori a stringhe nel quale il generico elemento di indice i sarà uguale
alla concatenazione delle sole stringhe della riga i-esima di A che hanno lunghezza pari o maggiore del corrispondente numero
in B. */

string **esercizioQuindici (string **A, short **B, int n, int m){
                string **Risultato = new string *[n];
                for (int i=0; i<n; i++){
                    Risultato[i] = new string;                                      //qui si
                    string vuota = "";
                    for (int j=0; j<m; j++){
                        if (A[i][j].size() >= B[i][j]){
                            vuota = vuota + A[i][j]; 
                        }
                    }
                    Risultato[i][0] = vuota;
                    //cout << Risultato[i][0]<<endl;
                }
            return Risultato;
}

int main(){
    int n = 3;
    int m = 4;
    string **A = new string *[n];
    for (int i=0; i<n; i++){
        A[i] = new string [m];
        for (int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << A[i][j] << '\t';
        }
       cout << endl;               
    }

    short **B = new short *[n];
    for (int i=0; i<n; i++){
        B[i] = new short [m];
        for (int j=0; j<m; j++){
            cin >> B[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << B[i][j] << '\t';
        }
        cout << endl;
    }
string **Risultato = new string *[n];
Risultato = esercizioQuindici (A, B, n, m);
   for (int i=0; i<n; i++){
       //Risultato[i] = new string;                          qui non metterlo per stampare array di puntatori
       cout << *Risultato[i] << '\t'; 
   }    
}