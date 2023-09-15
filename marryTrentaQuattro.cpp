#include <iostream>
using namespace std;
/* 34.Scrivere un metodo che prenda in input una matrice di puntatori a stringhe S di dimensioni n×m,
una stringa x ed un array di double W di dimensione m; il metodo restituisca un array di bool R di
dimensione m tale che l’i-esimo elemento di R sarà true se e solo se il rapporto tra il numero di stringhe
della i-esima colonna di S delle quali x è sottostringa ed il numero n è minore o uguale dello i-esimo
elemento di W. NB: Si presti attenzione alle stringhe mancanti! */
bool *MarryTrentaQuattro(string ***S, int n, int m, string x, double *W){
    bool *R=new bool [m];         //risultato da ritornare
    for (int j=0; j<m; j++){
        double NStringhe=0;
        for (int i=0; i<n; i++){
            cout<<"Stringa in esaame: "<<S[i][j][0]<<endl;
            if ((S[i][j])&&(S[i][j][0].find(x)!=string::npos)){
                cout<<"Stringa: "<<S[i][j][0]<<endl;
                NStringhe++;
            }
        }
        cout<<"Numero Sottostringhe: "<<NStringhe<<endl;
        double rapporto=(NStringhe/(double)n);
        cout<<"Rapporto: "<<rapporto<<endl;
        if (rapporto<=W[j]){
            cout<<"Elemento Array: "<<W[j]<<endl;
            R[j]=true;
        }
        else 
        R[j]=false;
    }
    return R;
}
int main(){
    int n=3;
    int m=4;
    string ***S=new string **[n];
    for (int i=0; i<n; i++){
        S[i]=new string *[m];
        for (int j=0; j<m; j++){
            S[i][j]=new string;
            cin>>*S[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<*S[i][j]<<'\t';
        }
        cout<<endl;
    }

    double *W=new double [m];
    for (int i=0; i<m; i++){
        cin>>W[i];
    }
    for (int i=0; i<m; i++){
        cout<<W[i]<<'\t';
    }
    cout<<endl;

bool *R=new bool[m];
R=MarryTrentaQuattro(S, n, m, "ri", W);
for (int i=0; i<m; i++){
    cout<<R[i]<<'\t';
}

}