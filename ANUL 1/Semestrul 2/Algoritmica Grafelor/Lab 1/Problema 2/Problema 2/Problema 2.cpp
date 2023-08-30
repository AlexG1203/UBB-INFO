#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("in.txt");

int matriceAdiacenta[100][100], degree[100], matriceDrumuri[100][100], visited[100];

void dfs(int start, int n) {
    visited[start] = 1;
    for (int i = 1; i <= n; i++) {
        if (matriceAdiacenta[start][i] == 1 && visited[i] == 0)
        {
            dfs(i, n);
        }
    }
}

int main()
{
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> matriceAdiacenta[i][j];

    cout << "a. sa se determine nodurile izolate dintr-un graf\n";
    int nrNoduriIzolate = 0;
    for (int i = 1; i <= n; i++)
    {
        bool izolat = true;
        for (int j = 1; j <= n; j++)
        {
            if (matriceAdiacenta[i][j] == 1) izolat = false;
        }
        if (izolat)
        {
            cout << "Nodul " << i << " este izolat\n";
            nrNoduriIzolate++;
        }

    }
    if (nrNoduriIzolate == 0)
        cout << "Nu exista noduri izolate!\n";


    cout << "b. sa se determine daca graful este regular\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            if (matriceAdiacenta[i][j] == 1)
            {
                degree[i]++;
                degree[j]++;
            }
    }
    for (int i = 1; i <= n; i++)
        cout << "Gradul lui " << i << " este " << degree[i] << "\n";
    bool isRegular = true;
    for (int i = 2; i <= n; i++)
        if (degree[i] != degree[1]) isRegular = false;
    if (isRegular)
        cout << "Graful este regular\n";
    else
        cout << "Graful nu este regular\n";

    cout << "\nc. pentru graful reprezentat cu matricea de adiacenta sa se determine matricea distantelor";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (matriceAdiacenta[i][j] == 0 && i != j)
                matriceDrumuri[i][j] = INT_MAX;
            else matriceDrumuri[i][j] = matriceAdiacenta[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (matriceDrumuri[i][k] != INT_MAX && matriceDrumuri[k][j] != INT_MAX) {
                    if (matriceDrumuri[i][j] > matriceDrumuri[i][k] + matriceDrumuri[k][j]) {
                        matriceDrumuri[i][j] = matriceDrumuri[i][k] + matriceDrumuri[k][j];
                    }
                }
            }
        }
    }
    cout << "\nMatricea drumurilor este :\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matriceDrumuri[i][j] != INT_MAX)
                cout << matriceDrumuri[i][j] << ' ';
            else cout << "x ";
        }
        cout << endl;
    }

    cout << "\nd. pentru graful reprezentat cu o matrice de adiacenta sa se determine daca este conex\n";

    dfs(1, n);
    bool isConex = true;
    for (int i = 1; i <= n; i++) {
        cout << visited[i] << ' ';
        if (visited[i] == 0) isConex = false;
    }
    if (isConex)
        cout << "\nGraful este conex\n";
    else cout << "\nGraful nu este conex\n";

    return 0;
}