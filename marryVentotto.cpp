#include <iostream>
using namespace std;
/*28.Scrivere un metodo che prenda come parametro formale un array A di stringhe (tutte di lunghezza dispari),
e restituisca in output la massima lunghezza delle stringhe palindrome contenute al centro delle stringhe di A.*/
/*bool CheckPalindroma(string StringArray){
    string Vuota="";
    for (int i=0; i<StringArray.size(); i++){
         Vuota=StringArray[i]+Vuota;
    }
    return Vuota==StringArray;
}*/
int MarryVentotto(string *A, int n){
    int lunghezza = 0;
    int centro;
    for (int i=0; i<n; i++){
        centro = 1;
        int mid = A[i].size() / 2;
        for (int j=1; j<mid; j++){
            if (A[i][mid - j]  == A[i][mid + j]){
                centro += 2;
            }
        }
        if (centro > lunghezza){
            lunghezza = centro;
        }
    }
    return lunghezza;
}
int main(){
    int n = 3;
    string *A = new string [n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }

    for (int i=0; i<n; i++){
        cout << A[i] << '\t';
    }

    cout << MarryVentotto(A, n);
}