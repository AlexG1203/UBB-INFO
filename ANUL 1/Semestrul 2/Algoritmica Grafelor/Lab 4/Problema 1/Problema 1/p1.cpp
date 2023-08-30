#include<iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<int> cod;

struct nod {
    int val;
    int pre;
    bool frunza = true;
    bool in_graf = true;
};

nod v[100001];

nod get_min_frunza()
{
    nod aux;
    aux.val = 100001;
    for (int i = 0; i < n; i++)
        if (v[i].in_graf && v[i].frunza && i < aux.val)
            aux = v[i];
    return aux;
}

void codare_puff()
{
    while (cod.size() < n - 1)
    {
        nod aux = get_min_frunza();
        cod.push_back(aux.pre);
        v[aux.pre].frunza = true;
        v[aux.val].in_graf = false;
        for (int i = 0; i < n; i++)
            if (v[i].in_graf && v[i].pre == aux.pre)
            {
                v[aux.pre].frunza = false;
                break;
            }
    }
}


int main(int argc, char** argv)
{
    ifstream f("input.txt");

    f >> n;
    for (int i = 0; i < n; i++)
    {
        f >> v[i].pre;
        v[i].val = i;
        if (v[i].pre != -1)
            v[v[i].pre].frunza = false;
        else
            v[i].frunza = false;
    }

    codare_puff();

    ofstream g("output.txt");

    g << cod.size() << endl;
    for (int i = 0; i < cod.size(); i++)
        g << cod[i] << " ";

    return 0;
}