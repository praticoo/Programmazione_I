#include <iostream>
using namespace std;
/*[Esercizio 2] Scrivere un metodo che prenda in input un parametro formale matrice M di dimensioni n × m di puntatori
a stringhe, e che restituisca true se esiste almeno una colonna in M che abbia un egual numero di stringhe palindrome di una
delle righe di M.*/
bool CheckPalindroma(string matriceFunzione){
    string vuota= "";
    for (int i=0; i<matriceFunzione.size(); i++){
        vuota= matriceFunzione[i]+vuota;
        //cout<<vuota<<endl;
    }
    return vuota==matriceFunzione;

}
bool esercizioDue(string ***M, int n, int m){
    int *palindroma=new int [n];               
    for (int i=0; i<n; i++){
        palindroma[i]=0;
        for (int j=0; j<m; j++){
           if((M[i][j])&&(CheckPalindroma(*M[i][j]))){
               palindroma[i]++;
           }
           
        }
    }
    for (int j=0; j<m; j++){
        int count=0; 
        for (int i=0; i<n; i++){
            if ((M[i][j])&&(CheckPalindroma(*M[i][j]))){
                count ++;
            }

        }
    
        for (int i=0; i<n; i++){
            if (count==palindroma[i]){
                return true;
            }
        }
    }
    return false;

}
int main(){
    //string uno="cane";
    //cout<<CheckPalindroma(uno);
    int n=3;
    int m=4;
    string ***M=new string **[n];
    for (int i=0; i<n; i++){
        M[i]=new string *[m];
        for (int j=0; j<m; j++){
            M[i][j]=new string;
            cin>>*M[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<*M[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<esercizioDue(M, n, m);
}

