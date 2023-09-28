#include "Service.h"
#include <algorithm>

vector<Produs> Service::filterTip(string tip)
{
	vector<Produs> filtered;
	for (auto pr : repo.getAll()) {
		if (pr.getTip() == tip) {
			filtered.push_back(pr);
		}
	}
	return filtered;
}

vector<Produs> Service::sortAll()
{
	vector<Produs> sortedList = repo.getAll();
	std::sort(sortedList.begin(), sortedList.end(), [&](Produs& tr1, Produs& tr2) {
		return tr1.getPret() < tr2.getPret();
		});
	return sortedList;
}

void Service::store(int id, string nume, string tip, double pret)
{
	Produs tr{ id, nume, tip, pret };
	repo.store(tr);
}

vector<string> Service::getAllTypes()
{
	vector<string> allTypes;
	for (auto pr : repo.getAll()) {
		string tip = pr.getTip();
		auto it = std::find_if(allTypes.begin(), allTypes.end(), [&](string t) {
			return tip == t;
			});
		if (it == allTypes.end()) {
			allTypes.push_back(tip);
		}
	}
	return allTypes;
}

int Service::getVoc(string nume) {
	int ct = 0;
	for (auto pr : repo.getAll()) {
		if (pr.getNume() == nume) {
			int length = nume.length();
			char* char_array = new char[length + 1];
			strcpy(char_array, nume.c_str());
			for (int i = 0; i < length; i++) {
				if (strchr("aeiouAEIOU", char_array[i]))
					ct++;
			}
		}
	}
	return ct;
}