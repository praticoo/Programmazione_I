#include <iostream>
using namespace std; 

/* Due stringhe si dicono sorelle se hanno lo stesso numero di vocali. Scrivere un metodo che prenda in input una matrice A di
puntatori a stringhe, e restituisca un boolean che indichi se esiste una colonna di A in cui sono puntate almeno due stringhe
sorelle. */

//Esame 01 / 02 / 2018

bool esercizioDue(string ***A, int n){
        for (int j=0; j<n; j++){
        for (int d=0; d<n-1; d++){
        for (int i=0; i<n-1; i++){
            int CountUno = 0;
            int CountDue = 0;
            if (&A[i][j][0]!=&A[d+1][j][0]){
            //cout << A[i][j][0] << endl;
            //cout << A[d+1][j][0] << endl;
            if (A[i][j] && A[d+1][j]){
                for (int z=0; z<A[i][j][0].size(); z++){
                    if ((A[i][j][0][z] == 'A')||(A[i][j][0][z] == 'E')||(A[i][j][0][z] == 'I')||(A[i][j][0][z] == 'O')||(A[i][j][0][z] == 'U')||
                    (A[i][j][0][z] == 'a')||(A[i][j][0][z] == 'e')||(A[i][j][0][z] == 'i')||(A[i][j][0][z] == 'o')||(A[i][j][0][z] == 'u')){
                        CountUno ++;
                    }    
                    
                }
                for (int s=0; s<A[d+1][j][0].size(); s++){
                    if ((A[d+1][j][0][s] == 'A')||(A[d+1][j][0][s] == 'E')||(A[d+1][j][0][s] == 'I')||(A[d+1][j][0][s] == 'O')||(A[d+1][j][0][s] == 'U')||
                    (A[d+1][j][0][s] == 'a')||(A[d+1][j][0][s] == 'e')||(A[d+1][j][0][s] == 'i')||(A[d+1][j][0][s] == 'o')||(A[d+1][j][0][s] == 'u')){
                        CountDue ++;
                    }
                }
            }
            
            if ((CountUno>0)&&(CountUno == CountDue)){
                return true;
            }}
        }}
    }
    /*for (int j=0; j<n; j++){
        for (int i=0; i<n-1; i++){
            int CountUno = 0;
            int CountDue = 0;
            cout << A[i][j][0] << endl;
            cout << A[i+1][j][0] << endl;
            if (A[i][j] && A[i+1][j]){
                for (int z=0; z<A[i][j][0].size(); z++){
                    if ((A[i][j][0][z] == 'A')||(A[i][j][0][z] == 'E')||(A[i][j][0][z] == 'I')||(A[i][j][0][z] == 'O')||(A[i][j][0][z] == 'U')||
                    (A[i][j][0][z] == 'a')||(A[i][j][0][z] == 'e')||(A[i][j][0][z] == 'i')||(A[i][j][0][z] == 'o')||(A[i][j][0][z] == 'u')){
                        CountUno ++;
                    }    
                    
                }
                for (int s=0; s<A[i+1][j][0].size(); s++){
                    if ((A[i+1][j][0][s] == 'A')||(A[i+1][j][0][s] == 'E')||(A[i+1][j][0][s] == 'I')||(A[i+1][j][0][s] == 'O')||(A[i+1][j][0][s] == 'U')||
                    (A[i+1][j][0][s] == 'a')||(A[i+1][j][0][s] == 'e')||(A[i+1][j][0][s] == 'i')||(A[i+1][j][0][s] == 'o')||(A[i+1][j][0][s] == 'u')){
                        CountDue ++;
                    }
                }
            }
            if ((CountUno>0)&&(CountUno == CountDue)){
                return true;
            }
        }
    }*/
    return false;
}

int main(){
    int n=3; 
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
cout << esercizioDue(A, n);
}