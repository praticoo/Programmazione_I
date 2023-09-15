#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

/* Scrivere una funzione che prenda come parametri formali un array A di puntatori a stringhe di lunghezza n e una reference a intero m e 
restituisca il numero di coppie ordinate (a,b) di stringhe di uguale lunghezza in A tali che contenga almeno m elementi nelle sue posizioni pari 
che esistano in b in posizioni dispari. La funzione ponga infine in m la lunghezza media delle stringhe in A, opportunatamente arrotondata al 
numero intero più vicino. */

//Esame 14 Aprile 2022 - Esercizio Due

int esercizioDue (string **A, int n, int &m) {
    int coppia = 0; 
      for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            int count = 0;
             if ((A[i])&&(A[j])&&(A[i][0].size()==A[j][0].size())){
                for (int x=0; x<A[i][0].size(); x+=2){
                   for (int y=1; y<A[j][0].size(); y+=2){
                       if (A[i][0][x] == A[j][0][y]){
                           //cout << "A[" << i << "[0]:" << A[i][0] << "+" <<  A[i][0][x] << endl;
                           //cout << "++" << A[j][0] << "+" << A[j][0][y] << endl;
                           count ++;
                       }
                   }
                }
                 if (count >= m){
             coppia = coppia + 1;
          }
          }
        }
      }

      for (int i=n-1; i>0; i--){
        for (int j=i-1; j>=0; j--){
            int count = 0;
             if ((A[i])&&(A[j])&&(A[i][0].size()==A[j][0].size())){
                for (int x=0; x<A[i][0].size(); x+=2){
                   for (int y=1; y<A[j][0].size(); y+=2){
                       if (A[i][0][x] == A[j][0][y]){
                           //cout << "-" << A[i][0] << "-" <<  A[i][0][x] << endl;
                           //cout << "--" << A[j][0] << "-" << A[j][0][y] << endl;
                           count ++;
                       }
                   }
                }
                 if (count >= m){
             coppia = coppia + 1;
          }
          }
        }
      }
      
      double somma = 0; 
      double conta = 0;
      double media = 0; 
      for (int i=0; i<n; i++){
          if (A[i]){
          somma += A[i][0].size();
          conta ++;
      }
   }  
   if (conta > 0){
   media = somma / conta;}
   m = round(media);
   cout << "Media Lunghezza Stringhe : " << m << endl;
   return coppia;
}

int main (){
    int n = 5;
    string **A = new string *[n];
    for (int i=0; i<n; i++){
        A[i] = new string;
        cin >> A[i][0];
    }

    for (int i=0; i<n; i=i+1){
        cout << A[i][0] << '\t';
    }
    
    cout << endl; 

    int m = 2;                             
    cout << esercizioDue(A, n, m);                  
}