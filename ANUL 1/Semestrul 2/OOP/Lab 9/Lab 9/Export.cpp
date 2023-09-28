#include "Export.h"
#include<fstream>
void exportToCSV(string fileName, const vector<Medicament>& all) {
	ofstream out(fileName, ios::trunc);
	if (!out.is_open()) {
		//throw RepositoryExceptions("Cannot open the file " + fileName);
	}

	for (const auto& product : all) {
		out << product.getID() << "," << product.getDenumire() << "," << product.getPret() << "," << product.getProducator() << "," << product.getSubstanta() << endl;
	}
	out.close();
}