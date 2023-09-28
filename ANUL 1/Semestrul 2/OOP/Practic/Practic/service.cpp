#pragma once
#include "Service.h"
#include "algorithm"

vector<Student> Service::sort_lista() {
    vector<Student> rez = repo.get_all();
    sort(rez.begin(), rez.end(), [](Student& m1, Student& m2) {
        return m1.getVarsta() < m2.getVarsta();
        });

    return rez;
}

void Service::remove_srv(int nrMAtricol) {
    string nume;
    for (auto& s : get_all_srv())
        if (nrMAtricol == s.getNrMatricol())
            nume = s.getNume();
    int k = 0;
    for (auto& m : get_all_srv())
        if (m.getNume() == nume)
            k++;
    if (k > 1)
        repo.remove(nrMAtricol);
}

vector<string> Service::getAllTypes()
{
    vector<string> allTypes;
    for (auto pr : repo.get_all()) {
        string tip = pr.getFacultate();
        auto it = std::find_if(allTypes.begin(), allTypes.end(), [&](string t) {
            return tip == t;
            });
        if (it == allTypes.end()) {
            allTypes.push_back(tip);
        }
    }
    return allTypes;
}

void Service::Intinerire(int nrMAtricol) {
    int varsta;
    for (auto& s : get_all_srv()) {
        s.getVarsta() + 1;
    }
}