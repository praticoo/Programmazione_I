#include <iostream>
using namespace std;
/* 7.Scrivere un metodo che prenda in input un parametro formale matrice A di puntatori ad interi di
dimensione nxm, due double d1 e d2 ed uno short s, e restituisca il numero di colonne di A nelle quali
esistano almeno s coppie di elementi contigui (ES: A[1][1] e A[2][1]) tali che il rapporto tra il primo ed il
secondo elemento sia compreso tra d1 e d2. NB: Si assuma a priori che s<=n-1 e che d1 < d2. Si presti
attenzione ai numeri "mancanti"nella matrice A. */
int MarrySette(int ***A, int n, int m, double d1, double d2, short s){
    int NColonne=0;
    double rapporto;
    for (int j=0; j<m; j++){
        int coppia=0;
        for (int i=0; i<n-1; i++){
           if ((A[i][j])&&(A[i+1][j])){
               cout<<"Primo Elemento: "<<A[i][j][0]<<endl;
               cout<<"Secondo Elemento: "<<A[i+1][j][0]<<endl;
               if (A[i+1][j][0]!=0){
                rapporto=(double)A[i][j][0]/A[i+1][j][0];}
               else {
                    rapporto=0;
               }
               cout<<"Rapporto: "<<rapporto<<endl;
               if ((rapporto>d1)&&(rapporto<d2)){
                   coppia++;
               }
               cout<<"Coppia: "<<coppia<<endl;
           }
        }
        if (coppia>=s){
            NColonne++;
        }
    }
    cout<<"Numero Colonne: ";
    return NColonne;
}
int main(){
    int n=3;
    int m=4;
    int ***A=new int **[n];
    for (int i=0; i<n; i++){
        A[i]=new int *[m];
        for (int j=0; j<m; j++){
            A[i][j]=new int;
            cin>>A[i][j][0];
        }
    }

     for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<A[i][j][0]<<'\t';
        }
        cout<<endl;
    }
    cout<<MarrySette(A, n, m, 0.8, 4.5, 1);
}