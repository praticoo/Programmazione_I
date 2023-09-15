#include <iostream>
#include <cmath>
using namespace std;
/*23.Scrivere un metodo che prenda in input un parametro formale matrice K di double di dimensioni n
x m e due interi a e b, e restituisca un array A di short di dimensione m, in cui l'elemento A[i] e' calcolato
come il numero di elementi della colonna i-esima di K tali che, approssimati all'intero più vicino, siano
compresi tra a e b (inclusi). NB: si assuma a < b. */
short *MarryVentiTre(double **K, int n, int m, int a, int b){
    short *A=new short [m];
    for (int j=0; j<m; j++){
        short contatore=0;
        for (int i=0; i<n; i++){
            if((round(K[i][j])>a)&&(round(K[i][j])<b)){
                cout<<"["<<i<<"]["<<j<<"]: "<<K[i][j]<<endl;
                contatore++;
            }
        }
        A[j]=contatore;
    }
    return A;
}

int main(){
    int n=3;
    int m=4;
    double z=1.2;
    double **K=new double *[n];
    for (int i=0; i<n; i++){
        K[i]=new double [m];
        for (int j=0; j<m; j++){
            K[i][j]=z++;
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<K[i][j]<<'\t';
        }
        cout<<endl;
    }

    short *arr=new short [m];
    arr=MarryVentiTre(K, n, m , 1, 8);
    for (int i=0; i<m; i++){
        cout<<arr[i]<<'\t';
    }
    
    
}