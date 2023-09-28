#include "Repo.h"
#include <qdebug.h>

void Repo::loadFromFile()
{
	std::ifstream in(fName);
	if (!in.is_open()) {
		throw std::exception("error open file!\n");
	}
	while (!in.eof()) {
		int id;
		string nume;
		string tip;
		double pret;
		string line;
		std::getline(in, line);
		id = std::stoi(line);

		std::getline(in, line);
		nume = line;

		std::getline(in, line);
		tip = line;

		std::getline(in, line);
		pret = stoi(line);

		Produs pr{ id, nume, tip, pret };
		list.push_back(pr);
	}
	in.close();
}

void Repo::writeToFile()
{
	std::ofstream out(fName);
	if (!out.is_open()) {
		throw std::exception("error open file!\n");
	}
	for (auto pr : list) {
		if (pr.getID() == list.at(list.size() - 1).getID())
			out << pr.getID() << '\n' << pr.getNume() << '\n' << pr.getTip() << '\n' << pr.getPret();
		else out << pr.getID() << '\n' << pr.getNume() << '\n' << pr.getTip() << '\n' << pr.getPret() << '\n';
	}
	out.close();
}

void Repo::store(Produs& tractor)
{
	int id = tractor.getID();
	auto it = std::find_if(list.begin(), list.end(), [&](Produs& tr) {
		return tr.getID() == id;
		});
	if (it != list.end()) {
		throw std::exception("Produs existent!\n");
	}
	list.push_back(tractor);
	writeToFile();
}

Produs& Repo::search(int id)
{
	auto it = std::find_if(list.begin(), list.end(), [&](Produs& tr) {
		return tr.getID() == id;
		});
	if (it == list.end()) {
		throw std::exception("Produs inexistent!\n");
	}
	return *it;
}

size_t Repo::size()
{
	return list.size();
}

vector<Produs> Repo::getAll()
{
	return list;
}