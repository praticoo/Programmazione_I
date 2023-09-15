#include <iostream>
using namespace std;

/* [Esercizio 12] Scrivere un metodo che preveda un parametro formale matrice quadrata di stringhe di dimensioni n × n,
uno short k ed una stringa s, e restituisca un array di n puntatori a stringhe in cui il generico elemento di indice i contiene la
i-esima stringa della diagonale secondaria se questa ha lunghezza maggiore o uguale a k e inizia con la stringa s, altrimenti la
corrispondente stringa della diagonale principale. 

string **esercizioDodici (string **Q, int n, short k, string s){
    string **Risultato = new string *[n];
    int a = n - 1;
    for (int i=0; i<n; i++){
        Risultato [i] = new string [n];
        for (int j=0; j<n; j++){
            if (j==a){
                a--;
                //cout << "a:" << a << endl;
                if ((Q[i][j].size()>=k)&&(Q[i][j].find(s)!=string::npos)){
                    cout << "?" << Q[i][j].find(s) << endl;
                    cout << "-" << Q[i][j] << endl;
                    *Risultato[i] = Q[i][j];
                }
                else {
                    cout << "+" << Q[i][j] << endl;
                    *Risultato[i] = Q[i][i];
                }

            }
        }
    }
    return Risultato;
}
*/

string **esercizioDodici (string **Q, int n, short k, string s){
    string **Risultato = new string *[n];
    int a = n - 1;
    int uguale = 0;
    cout << "Dimensione della stringa s: " << s.size() << endl;
    for (int i=0; i<n; i++){
        Risultato [i] = new string [n];
        for (int j=0; j<n; j++){
            if (j==a){
                a--;
                //cout << "a:" << a << endl;
                if ((Q[i][j].size()>=k)){
                    uguale = 0;
                    for (int z=0; z<s.size(); z++){
                       if (Q[i][j][z] == s[z] ){
                          cout << "Q[" << i << "][" << j  << "][" << z << "]: " << Q[i][j][z] << endl;
                          cout << "s[" << z << "]: " << s[z] << endl;
                          uguale ++;
                       }
                    }
                    if (uguale == s.size()){
                    //cout << "?" << Q[i][j].find(s) << endl;
                    cout << "-" << Q[i][j] << endl;
                    *Risultato[i] = Q[i][j];
                    }
                    else {
                    cout << "+" << Q[i][j] << endl;
                    *Risultato[i] = Q[i][i];
                }
                }

            }
        }
    }
    return Risultato;
}
int main(){
    int n = 3;
    string **Q = new string *[n];
    for (int i=0; i<n; i++){
            Q[i] = new string [n];
        for (int j=0; j<n; j++){
                cin >> Q[i][j];
        }
    }


     for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
                cout << Q[i][j] << '\t';
        }
      cout << endl;
    }

    short k = 2;
    string s = "re";
    cout << "Risultato: " << endl;
    string **Risultato = new string *[n];
    Risultato = esercizioDodici(Q, n, k, s);
    for (int i=0; i<n; i++){
       // Risultato[i] = new string [n];
        cout << *Risultato[i] << '\t';
    }

}


