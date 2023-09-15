#include <iostream>
using namespace std;

/* Scrivere un metodo che prenda come parametro formale un array A di stringhe (tutte di lunghezza
dispari), e restituisca in output la massima lunghezza delle stringhe palindrome contenute al centro
delle stringhe di A. */

/*bool CheckPalindroma(string stringa){
    string vuota = "";
    for (int i=0; i<stringa.size(); i++){
        vuota = stringa[i] + vuota;
    }
    if (vuota == stringa){
        return true;
    }
    return false;
}*/

//Esame 25 / 09 / 2018

int esercizioDue(string *A, int n){
    int l_max = 0;
    int centro;
    for (int i=0; i<n; i++){
            centro = 1;
        int mid = A[i].size()/2;
        for (int j=1; j<mid; j++){
            //cout << "A[" << i << "][" << mid + j << "]: "<< A[i][mid+j] << endl;
        	//cout << "A[" << i << "][" << mid - j << "]: " << A[i][mid-j] << endl;
            if (A[i][mid - j] == A[i][mid + j]){
                 centro = centro + 2;
            }
        } 
        if (centro > l_max){
            l_max = centro;
        }
    }
    return l_max;
}

int main(){
    int n=3;
    string *A = new string [n];
    for (int i=0; i<n; i++){
            cin >> A[i];
        }

    for (int i=0; i<n; i++){
            cout << A[i]<< '\t';
    }
    cout << endl;

cout << esercizioDue(A, n);
}