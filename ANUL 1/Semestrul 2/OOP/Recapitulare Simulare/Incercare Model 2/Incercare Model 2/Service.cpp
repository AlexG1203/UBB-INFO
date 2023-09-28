#include "Service.h"

vector<Device> Serv::sorteazaCresc() {
	vector<Device> sortat = repo.getList();
	sort(sortat.begin(), sortat.end(), [&](Device& j1, Device& j2) {
		return j1.getPret() < j2.getPret();
		});
	return sortat;
}