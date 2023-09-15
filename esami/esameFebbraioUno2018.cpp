/* Un santone induista si trova nella regione indiana del Rajasthan, quest’ultima simulata con una matrice quadrata di boolean
in cui il valore true indica la presenza di un libro sacro. Scrivere un metodo che prenda in input una matrice di boolean e
restituisca il numero di libri raccolti dal santone che, partendo dal centro della regione, esegue un movimento casuale unitario
alla volta in una delle quattro direzioni prima che egli sia traviato dalle usanze oltre confine. */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Esame 1 / 02 / 2018

int esercizioUno(bool **B, int n){
int mid = n / 2;
//Il santone si trova in B[mid][mid];
int i = mid; 
int j = mid;
int r;
int count = 0; 
while ((i<n)&&(j<n)&&(i>=0)&&(j>=0)){
    cout  << "Partenza: B[" << i << "][" << j << "]: " << B[i][j] << endl;
    if (B[i][j]){
        B[i][j] = false;
        count ++;
    }
     r = rand () % 4;
     if (r==0){
        i++;
     }
     else if (r==1){
        i--;
     }
     else if (r==2){
        j++;
     }
     else if (r==3){
        j--;
     }
     //cout << count << endl;
     //cout << "B[" << i << "][" << j << "]:" << B[i][j] << endl;
 }
 //cout << endl;
return count;
}

int main(){
    srand(time (0));
    int n = 5;
    bool **B = new bool *[n];
    for (int i=0; i<n; i++){
        B[i] = new bool [n];
        for (int j=0; j<n; j++){
            B[i][j] = rand() % 2;
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << B[i][j] << '\t';
        }
      cout << endl;
    }

    cout << esercizioUno(B, n);

}