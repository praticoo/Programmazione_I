#include <iostream>
using namespace std;

//Esame 18 / 06 / 2018

int esercizioDue(string *A, int n){
    int l = 0; string u;
    for (int i=0; i<n; i++){
        if (A[i].size()>l){
            l = A[i].size();
            u = A[i];
        }
    }

    int Ris = 1;
    for (int z=0; z<(u.size()-1); z++){
        for (int s=1+z; s<u.size(); s++){
            cout << u << endl;
            if (u[z] == u[s]){
                cout << u[z] << endl;
                Ris ++;
                break;
            }
        }

    }
    return Ris;
}

int main(){
    int n = 4;
    string *A = new string [n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }

    for (int i=0; i<n; i++){
        cout << A[i] << '\t';
    }

    cout << esercizioDue(A, n);
}