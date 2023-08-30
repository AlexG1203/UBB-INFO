#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int NMAX = 1e3 + 5;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;

vector < int > graf[NMAX];
int cost[NMAX][NMAX], reziduri[NMAX][NMAX];
int viz[NMAX], pred[NMAX];

void citire() {
    int x, y, z;
    fin >> n >> m;
    for (int i = 1; i <= m; i++) {
        fin >> x >> y >> z;
        x++; y++;
        cost[x][y] += z;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
}

int bfs()
{
    //cout << "parcurgere\n";
    //memset(viz,0,sizeof(viz));
    for (int i = 0; i <= n; i++)
        viz[i] = 0;
    queue < int > noduri;
    noduri.push(1);
    viz[1] = 1;
    while (!noduri.empty()) {
        //nod curent
        int nc = noduri.front();
        //cout << "nod_curent: " << nc << " | ";
        //in cazul in care nodul curent este
        //chiar nodul destinatie pe care dorim sa-l atingem
        //nu mai are rost sa-l vizitam, asa ca continuam
        //algoritmul

        //if(nc==n)continue;
        //cout << "nod_vecini: ";
        //incepem sa vizitam vecinii
        for (int i = 0; i < graf[nc].size() && nc != n; i++) {
            //nod vecin
            int nv = graf[nc][i];
            //in cazul in care fluxul pe care il avem pe muchie este atins
            //adica nu mai putem sa trecem ceva prin flux , nu ne dorim sa-l parcurgem
            //asa ca ne continuam aventura in gasirea fluxului maxim
            if (reziduri[nc][nv] == cost[nc][nv] || viz[nv] == 1)continue;
            //clasic
            //cout << nv << " ";
            viz[nv] = 1;
            noduri.push(nv);
            //ne dorim ca acest algoritm sa salveze si drumul inapoi
            //asa ca plasam cate o bucatica din noduri in vectorul nostru
            pred[nv] = nc;
        }
        //cout << '\n';

        //eliminam nodul din lista
        noduri.pop();
    }
    //returnam viz[n] deoarece
    //dorim sa stim daca am reusit
    //sa atingem nodul n adica nodul destinatie
    //cu parcurgerea bfs pe care am facut-o
    return viz[n];
}

int edmonds_karp() {
    //cum ziceam si in functia de bfs
    //atat timp cat putem sa ajungem la nodul nostru
    //algoritmul continua parcurgerea
    int noduri, fminim, flux;
    flux = 0;
    while (bfs() == 1) {
        //refacem traseul invers
        for (int i = 0; i < graf[n].size(); i++)
        {
            int nc = graf[n][i];
            //in cazul in care vecinul este full
            //pe muchie , nu putem sa-l luam in calcul
            //pentru transport
            if (cost[nc][n] == reziduri[nc][n] || viz[nc] == 0)
                continue;
            pred[n] = nc;
            fminim = 550000005;
            for (noduri = n; noduri != 1; noduri = pred[noduri]) {
                fminim = min(fminim, cost[pred[noduri]][noduri] - reziduri[pred[noduri]][noduri]);
            }
            if (fminim == 0)
                continue;
            for (noduri = n; noduri != 1; noduri = pred[noduri]) {
                reziduri[pred[noduri]][noduri] += fminim;
                reziduri[noduri][pred[noduri]] -= fminim;
            }
            flux += fminim;
        }
    }
    return flux;
}

int main()
{
    citire();
    fout << edmonds_karp();
    return 0;
}