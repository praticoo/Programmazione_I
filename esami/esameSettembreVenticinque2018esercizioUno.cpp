#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda come parametro formale una matrice A n×m di puntatori ad intero, e
restituisca in output un bool che indichi se esistono due elementi in A che puntano allo stesso valore
intero (anche in locazioni differenti). */

//Esame 25 / 09 / 2018

bool esercizioUno(int ***A, int n, int m){
    int *b = new int [n*m];
    int z = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            b[z] = A[i][j][0];
            z++;
        }
    }

  /*for (int s=0; s<(n*m); s++){
    cout << b[s] << '\t';
  }*/

  int count = 1;
  for (int i=0; i<n; i++){
    for (int j=0; j<m; j++){
        for (int s=count; s<n*m; s++){
            cout << "El Matrice: "<< A[i][j][0] << endl;
            cout << "El Array: "<< b[s] << endl;
             if (A[i][j][0] == b[s]){
                return true;
             }
        }
      count ++;
    }
  }

  /*for (int i=0; i<n*m; i++){
    int uno = b[i];
    for (int j=i+1; j<n*m; j++){
        int due = b[j];
        cout << "Uno: " << uno << endl;
        cout << "Due: " << due << endl;
        if (uno == due){
            return true;
        }
    }
  } */ 
  return false;
}

int main(){
    int n=3;
    int m=4;
    int ***A = new int **[n];
    for (int i=0; i<n; i++){
        A[i] = new int *[m];
        for (int j=0; j<m; j++){
            A[i][j] = new int;
            cin >> A[i][j][0];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << A[i][j][0] << '\t';
        }
        cout << endl;
    }

    cout << esercizioUno(A, n, m);
}