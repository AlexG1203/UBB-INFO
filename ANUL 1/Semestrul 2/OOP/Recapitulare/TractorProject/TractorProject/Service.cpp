#include "Service.h"
#include <algorithm>

vector<Tractor> Service::filterTip(string tip)
{
	vector<Tractor> filtered;
	for (auto tr : repo.getAll()) {
		if (tr.getTip() == tip) {
			filtered.push_back(tr);
		}
	}
	return filtered;
}

vector<Tractor> Service::sortAll()
{
	vector<Tractor> sortedList = repo.getAll();
	std::sort(sortedList.begin(), sortedList.end(), [&](const Tractor& tr1, const Tractor& tr2) {
		return tr1.getDenumire() < tr2.getDenumire();
		});
	return sortedList;
}

void Service::store(int id, string denumire, string tip, int nrRoti)
{
	Tractor tr{ id, denumire, tip, nrRoti };
	repo.store(tr);
}

void Service::modifica(int id, string denumire, string tip, int nrRoti)
{
	Tractor tr{ id, denumire, tip, nrRoti };
	repo.modifica(tr);
}

vector<string> Service::getAllTypes()
{
	vector<string> allTypes;
	for (auto tr : repo.getAll()) {
		string tip = tr.getTip();
		auto it = std::find_if(allTypes.begin(), allTypes.end(), [&](string t) {
			return tip == t;
			});
		if (it == allTypes.end()) {
			allTypes.push_back(tip);
		}
	}
	return allTypes;
}
