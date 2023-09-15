#include <iostream>
using namespace std;
/*19.Scrivere un metodo che prenda in input una matrice quadrata M di short e restituisca il valore
booleano true se M e' una matrice triangolare inferiore o superiore. */
bool CheckMatriceTriangolareSuperiore(short **M, int n){
for (int i=1; i<n; i++){
    for (int j=0; j<i; j++){
        if ((M[i][j]==0)){
            //cout<<"["<<i<<"]["<<j<<"] :"<<M[i][j]<<endl;
        }
        else{
            //cout<<"["<<i<<"]["<<j<<"] :"<<M[i][j]<<endl;
            return false;
            break;
        }
    }
}
return true;
}

bool CheckMatriceTriangolareInferiore(short **M, int n){
for (int i=0; i<n-1; i++){
    for (int j=i+1; j<n; j++){
        if ((M[i][j]==0)){
            cout<<"["<<i<<"]["<<j<<"] :"<<M[i][j]<<endl;
        }
        else{
            cout<<"["<<i<<"]["<<j<<"] :"<<M[i][j]<<endl;
            return false;
            break;
        }
    }
}
return true;
}

int main(){
    int n=4;
    short **M=new short *[n];
    for (int i=0; i<n; i++){
        M[i]=new short [n];
        for (int j=0; j<n; j++){
            cin>>M[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout<<M[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<"Matrice Triangolare Superiore: "<<CheckMatriceTriangolareSuperiore(M, n)<<endl;
    cout<<"Matrice Triangolare Inferiore: "<<CheckMatriceTriangolareInferiore(M, n)<<endl;
}