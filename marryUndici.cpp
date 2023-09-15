//Per generare numeri naturali compresi tra a e b, possiamo usare la seguente espressione:
//int a=2; 
//int b=11;
//srand(time(0));
//cout<<rand()%(b-a+1)+a;
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*11.Scrivere un metodo che prenda come parametri formali una matrice quadrata A n × n di puntatori ad int
e restituisca in output un bool che indichi se la somma degli elementi puntati dalla diagonale sottostante la
diagonale secondaria è divisibile per n.*/
bool MarryUndici(int ***A, int n){
int decremento=n-1;
int somma=0;
for (int i=1; i<n; i++){
    for (int j=1; j<n; j++){
        if(j==decremento&&(A[i][j])){           
           somma=*A[i][j]+somma;
           decremento=decremento--;
        }
    }
}
cout<<"Somma Diagonale sottostante alla secondaria: "<<somma<<endl;
if (somma%n==0){
    cout<<"Risultato rapporto: "<<(double)somma/n<<endl;
    return true;
}
else{
    cout<<"Risultato rapporto: "<<(double)somma/n<<endl;
    return false;
}
}
int main(){
    int n=4;
    int ***A= new int **[n];
    srand(time(0));                                             //randomicità ogni compilazione
    for (int i=0; i<n; i++){
           A[i]=new int *[n];
         for (int j=0; j<n; j++){
             A[i][j]=new int(rand()%(20-1+1)+1);                 //numeri randomici tra 1 e 20
             cout<<*A[i][j]<<'\t';
         }  
         cout<<endl;
    }
    cout<<MarryUndici(A, n);
} 