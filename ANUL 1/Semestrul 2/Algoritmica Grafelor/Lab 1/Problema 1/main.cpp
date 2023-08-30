#include <iostream>
#include <fstream>
using namespace std;
ifstream in("../fisier.in");

int mat_a[100][100],mat_i[100][100];

int main() {
    int nr_nod,m1,m2;
    in>>nr_nod;
    /*
    while (in>>m1 && in>>m2){
        mat_a[m1][m2] = mat_a[m2][m1] = 1;
    }
    cout<<"Matricea de adiacenta:\n";
    for(int i = 1; i <= nr_nod; i++){
        cout<<endl;
        for (int j = 1; j <= nr_nod; j++) {
            cout<<mat_a[i][j]<<" ";
        }
    }*/
    cout<<endl<<endl;
    cout<<"Lista de adiacenta:\n";

    for(int i = 1; i <= nr_nod; i++)
    {
        cout<<i<<"::";
        for(int j = 1; j <= nr_nod; j++){
            if(mat_a[i][j] == 1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int c = 1;
    while (in>>m1 && in>>m2){
        if(m1 != 0)
            mat_i[m1][c] = 1;
        if(m2 != 0)
            mat_i[m2][c] = 1;
        c++;
    }

    cout<<"Matricea de incidenta:\n";
    for(int i = 1; i <= nr_nod; i++){
        cout<<endl;
        for (int j = 1; j <= nr_nod; j++) {
            cout<<mat_i[i][j]<<" ";
        }
    }
    return 0;
}
