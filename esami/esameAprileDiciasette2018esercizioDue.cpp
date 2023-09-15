#include<iostream>
using namespace std;

/* Due stringhe si dicono c-equivalenti se esse risultano uguali dopo aver eliminato da ambedue tutte le
occorrenze del carattere c. Scrivere un metodo che prenda in input una matrice A di puntatori a
stringhe ed un carattere c, e restituisca un boolean che indichi se esistono in A due stringhe
c-equivalenti */

//Esame 17 / 04 /18 

bool esercizioDue(string***A, int n, char c){
    string *Arr = new string [n*n];
    int s = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (A[i][j]){
            for (int z=0; z<A[i][j][0].size(); z++){
                cout << A[i][j][0][z] << endl;
                  while (A[i][j][0][z] == c){
                    //cout << A[i][j][0][z] << endl;
                       //cout << (A[i][j][0]).erase(z, 1) << endl;
                      (A[i][j][0]).erase(z, 1);
                     // while (A[i][j][0][z]==c){
                       // A[i][j][0].erase(z,1);
                      //}
                  }
            }
            Arr[s] = A[i][j][0];
            s++; 
          }
        }
    }
    /*for (int i=0; i<(n*n); i++){
        cout << Arr[i]<< '\t';}
        cout << endl; */
   int count = 1;
   for (int i=0; i<n; i++){
    //cout << count << endl;
    for (int j=0; j<n; j++){
        //int s = count;
        for (int s=count; s<(n*n); s++){
            //cout << A[i][j][0] << endl;
            //cout << Arr[s] << endl;
            if ((A[i][j])&&(A[i][j][0] == Arr[s])){
                return true;
            }
        }
        count ++;
    }
   }
    return false;
    /*for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (A[i][j]){
            for (int z=0; z<A[i][j][0].size(); z++){
                  if (A[i][j][0][z] == c){
                    //cout << A[i][j][0][z] << endl;
                      //cout << (A[i][j][0]).erase(z, 1) << endl;;
                      (A[i][j][0]).erase(z, 1);
                  }
            }
          }
        }
    }*/

    /*for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << A[i][j][0] << '\t';
        }cout << endl;
            }*/

    /*for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if ((A[i][j])&&(A[i][j][0]==A[i][j+1][0])){
                cout << A[i][j][0] << endl;
                cout << A[i][j+1][0] << endl;
                return true;
        }
     }
    }
    
    for (int j=0; j<n; j++){
        for (int i=0; i<n-1; i++){
            if ((A[i][j])&&(A[i][j][0]==A[i+1][j][0])){
                cout << A[i][j][0] << endl;
                cout << A[i][j+1][0] << endl;
                return true;
        }
     }
    }*/
    /*for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int z=0; z<n; z++){
                for (int s=0; s<n; s++){
                     cout << A[i][j][0] << endl;
                     cout << A[z][s][0] << endl;
                     if (A[i][j][0]!=A[i][j][0]){
                     if (A[i][j][0]==A[z][s][0]){
                        return true;
                     }}
                }
            }
        }
    }*/

    /*for (int s=0; s<n*n; s++){
    for (int i=0; i<n; i++){
        for (int j=1; j<n; j++){
            cout << "-" << A[i][j][0] << endl;
            cout << "--"<< C[0] << endl;
            if (A[i][j][0] == C[s]){
                return true;
            }}
        }
    }*/

    return false;
}
int main(){
    int n = 3;
    string ***A = new string **[n];
    for (int i=0; i<n; i++){
        A[i] = new string *[n];
        for (int j=0; j<n; j++){
             A[i][j] = new string [n];
             cin >> A[i][j][0];
        }
    }

for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
             cout << A[i][j][0] << '\t';
        }
      cout << endl;
    }

    cout << esercizioDue(A, n, 'c');

}
