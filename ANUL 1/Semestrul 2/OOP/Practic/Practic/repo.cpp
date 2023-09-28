#pragma once
#include <sstream>
#include "repo.h"
#include "fstream"
#include "algorithm"
#include <cassert> 

void Repo::loadFromFile() {
    std::ifstream in(fName);
    if (!in.is_open()) {
        throw std::exception("error open file!\n");
    }
    while (!in.eof()) {
        int nrMAtricol;
        string nume;
        int varsta;
        string facultate;
        
        string line;
        std::getline(in, line);
        nrMAtricol = std::stoi(line);

        std::getline(in, line);
        nume = line;

        std::getline(in, line);
        varsta = stoi(line);

        std::getline(in, line);
        facultate = line;

        Student s{ nrMAtricol, nume, varsta, facultate };
        list.push_back(s);
    }
    in.close();
}


void Repo::save_to_file(vector<Student> lst) {
    ofstream g("input.txt");
    for (auto& s : lst) {
        g << s.getNrMatricol() << "," << s.getNume() << "," << s.getVarsta() << "," << s.getFacultate() << endl;
    }
    g.close();
}


void Repo::writeToFile()
{
    std::ofstream out(fName);
    if (!out.is_open()) {
        throw std::exception("error open file!\n");
    }
    for (auto s : list) {
        if (s.getNrMatricol() == list.at(list.size() - 1).getNrMatricol())
            out << s.getNrMatricol() << "," << s.getNume() << "," << s.getVarsta() << "," << s.getFacultate() << endl;
        else  out << s.getNrMatricol() << "," << s.getNume() << "," << s.getVarsta() << "," << s.getFacultate() << endl;
    }
    out.close();
}

void Repo::remove(int nrMAtricol) {
    int i = 0;
    for (auto& s : list) {
        if (s.getNrMatricol() == nrMAtricol) {
            list.erase(list.begin() + i);
        }
        i++;
    }
    save_to_file(get_all());
}