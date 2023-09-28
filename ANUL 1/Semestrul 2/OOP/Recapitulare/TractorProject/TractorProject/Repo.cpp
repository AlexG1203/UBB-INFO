#include "Repo.h"
#include <qdebug.h>

void Repo::loadFromFile() {
	std::ifstream in(fName);
	if (!in.is_open()) {
		throw std::exception("error open file!\n");
	}
	while (!in.eof()) {
		int id;
		string denumire;
		string tip;
		int nrRoti;
		string line;
		std::getline(in, line);
		id = std::stoi(line);
		std::getline(in, line);
		denumire = line;
		std::getline(in, line);
		tip = line;
		std::getline(in, line);
		nrRoti = stoi(line);
		Tractor tr{ id,denumire,tip,nrRoti };
		list.push_back(tr);
	}
	in.close();
}

void Repo::writeToFile() {
	std::ofstream out(fName);
	if (!out.is_open()) {
		throw std::exception("error open file!\n");
	}
	for (auto tr : list) {
		if (tr.getID() == list.at(list.size() - 1).getID())
			out << tr.getID() << "\n" << tr.getDenumire() << "\n" << tr.getTip() << "\n" << tr.getNrRoti();
		else
			out << tr.getID() << "\n" << tr.getDenumire() << "\n" << tr.getTip() << "\n" << tr.getNrRoti() << "\n";
	}
	out.close();
}

void Repo::store(const Tractor& tractor) {
	int id = tractor.getID();
	auto it = std::find_if(list.begin(), list.end(), [&](const Tractor& tr) {
		return id == tr.getID();
		});
	if (it != list.end()) {
		throw std::exception("Tractor existent!\n");
	}
	list.push_back(tractor);
	writeToFile();
}

void Repo::deleteRepo(int id)
{
	auto it = std::find_if(list.begin(), list.end(), [&](const Tractor& tr) {
		return tr.getID() == id;
		});
	if (it == list.end()) {
		throw(std::exception("Tractor inexistent!\n"));
	}
	list.erase(it);
	writeToFile();
}

void Repo::modifica(const Tractor& tractor)
{
	int id = tractor.getID();
	auto it = std::find_if(list.begin(), list.end(), [&](const Tractor& tr) {
		return tr.getID() == id;
		});
	if (it == list.end()) {
		throw std::exception("Tractor inexistent!\n");
	}
	*it = tractor;

	writeToFile();
}

Tractor& Repo::search(int id)
{
	auto it = std::find_if(list.begin(), list.end(), [&](const Tractor& tr) {
		return tr.getID() == id;
		});
	if (it == list.end()) {
		throw std::exception("Tractor inexistent!\n");
	}
	return *it;
}

size_t Repo::size()
{
	return list.size();
}

vector<Tractor> Repo::getAll()
{
	return list;
}