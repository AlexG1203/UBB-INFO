#include "Reteta.h"

void Reteta::add(Medicament& medicament)
{
	v.push_back(medicament);
}

void Reteta::clear()
{
	v.clear();
}

size_t Reteta::size()
{
	return v.size();
}

vector<Medicament> Reteta::getAll()
{
	return v;
}
