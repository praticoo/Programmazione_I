/* Scrivere un metodo in linguaggio C++ che prenda in input una matrice A di puntatori a stringhe, un array B di caratteri
ed uno short k. Il metodo operi sulla matrice A depurando le stringhe delle righe di indice pari di un numero k di caratteri
selezionati casualmente dall’array B. */

#include <iostream>
#include <ctime>
using namespace std;

//Esame 9 / 12 / 21 DAD

string ***esercizioDue(string ***A, int n, char *B, short k){
    char *C = new char [k];
    srand(time(0));
    for (int f=0; f<k; f++){
        int i = rand() % n;
        C[f] = B[i];
    }

    for (int f=0; f<k; f++){
       cout << C[f] <<'\t';
    }
    cout << endl;


    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (A[i][j]){
                for (int z=0; z<A[i][j][0].size(); z++){
                    if (z%2 == 0){
                        for (int f=0; f<k; f++){
                            if (A[i][j][0][z] == C[f]){
                                A[i][j][0][z] = 0;
                            }
                
                    }
                    }
                }
            }
        }
    }
    return A;
}

int main(){
    int n = 3;
    string ***A = new string **[n];
    for (int i=0; i<n; i++){
        A[i] = new string *[n];
        for (int j=0; j<n; j++){
            A[i][j] = new string;
            cin >> A[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << A[i][j][0] << '\t';
        }
      cout << endl;
    }

    char *B = new char[n];
    for (int i=0; i<n; i++){
        cin >> B[i];
    }

    cout << endl;
    
    for (int i=0; i<n; i++){
        cout << B[i] << '\t';
    }
cout << endl;
string ***Risultato = new string**[n];
Risultato =  esercizioDue(A, n, B, 2);
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
         cout << Risultato[i][j][0] << '\t';
    }
    cout << endl;
}

//srand(time(0));
  //  int z = rand() % ((n-1) - 0 + 1) + 0 ;
    //cout << B[z] << endl;
}

