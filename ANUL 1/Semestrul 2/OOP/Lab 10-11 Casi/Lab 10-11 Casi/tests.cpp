#include "tests.h"
//#include "Medicament.h"
#include <assert.h>
#include <iostream>
#include <string>

void Tests::runAllTests()
{
	testDomain();
	testRepo();
	testValidate();
	testService();
	testMyVector();
	testReteta();
}

void Tests::testDomain()
{
	Medicament medicament1("Nurofen", 10.0, "dada", "dadada");
	assert(medicament1.getDenumire() == "Nurofen");
	assert(medicament1.getProducator() == "dada");
	assert(medicament1.getSubstantaActiva() == "dadada");
	assert(10.0 - medicament1.getPret() < 0.0001);
	printf("Teste domeniu trecute cu succes!\n");
}

void Tests::testRepo() {
	MedicamentRepo repo;
	Medicament medicament1("Nurofen", 10.0, "dada", "dadada");
	repo.addRepo(medicament1);
	assert(repo.sizeRepo() == 1);
	Medicament medicament2("Ibuprofen", 20.0, "ada", "adsad");
	repo.addRepo(medicament2);
	assert(repo.sizeRepo() == 2);
	repo.deleteRepo("Nurofen");
	assert(repo.sizeRepo() == 1);
	Medicament medicament3("Ibuprofen", 15.5, "dada", "dasdas");
	try {
		repo.addRepo(medicament3);
		assert(false);
	}
	catch (RepoException exception) {
		assert(exception.what() == "Medicament existent!\n");
	}
	try {
		repo.deleteRepo("Nurofen");
		assert(false);
	}
	catch (RepoException exception) {
		assert(exception.what() == "Medicament inexistent!\n");
	}
	Medicament medicament4("Ibuprofen", 12.2, "daa", "dsadjklsa");
	repo.modifyRepo(medicament4);
	assert(repo.sizeRepo() == 1);
	Medicament foundMedicament = repo.searchRepo("Ibuprofen");
	assert(foundMedicament.getDenumire() == "Ibuprofen");
	assert(foundMedicament.getPret() - 12.2 < 0.0001);
	assert(foundMedicament.getProducator() == "daa");
	assert(foundMedicament.getSubstantaActiva() == "dsadjklsa");
	try {
		repo.modifyRepo(medicament1);
		assert(false);
	}
	catch (RepoException exception) {
		assert(exception.what() == "Medicament inexistent!\n");
	}
	vector<Medicament> medicamente = repo.getAllRepo();
	assert(medicamente.size() == 1);
	try {
		repo.searchRepo("Strepsils");
	}
	catch (RepoException exception) {
		assert(exception.what() == "Medicament inexistent!\n");
	}
	printf("Teste repository trecute cu succes!\n");
}


void Tests::testValidate() {
	Medicament mValid("Nurofen", 12.2, "dada", "adasd");
	MedicamentValidator validator;
	try {
		validator.validate(mValid);
		assert(true);
	}
	catch (ValidateException exc) {
		assert(false);
	}
	Medicament mInvalid("", -2.2, "", "ada");
	try {
		validator.validate(mInvalid);
		assert(false);
	}
	catch (ValidateException exception) {
		assert(exception.what() == "denumire invalida!\npret invalid!\nproducator invalid!\n");
	}
}

int cmpFDenumire(Medicament med1, Medicament med2) {
	return med1.getDenumire() < med2.getDenumire();
}

void Tests::testService()
{
	MedicamentRepo repo;
	MedicamentValidator validator;
	Reteta reteta;
	MedicamentService service(repo, validator, reteta);
	service.addMedicament("Nurofen", 10.0, "dada", "asdsa");
	assert(service.nrMedicamente() == 1);
	try {
		service.addMedicament("", 10.0, "dasd", "kdkjsjf");
		assert(false);
	}
	catch (ValidateException exc) {
		assert(exc.what() == "denumire invalida!\n");
	}
	assert(service.nrMedicamente() == 1);
	try {
		service.stergeMedicament("ada");
		assert(false);
	}
	catch (RepoException exc) {
		assert(exc.what() == "Medicament inexistent!\n");
	}
	service.stergeMedicament("Nurofen");
	assert(service.nrMedicamente() == 0);
	service.addMedicament("Nurofen", 10.0, "dada", "asdsa");
	service.modificaMedicament("Nurofen", 12.2, "kjlfd", "ndsal");
	assert(service.nrMedicamente() == 1);
	Medicament medicamentFind = service.searchMedicament("Nurofen");
	assert(medicamentFind.getDenumire() == "Nurofen");
	assert(abs(12.2 - medicamentFind.getPret()) < 0.001);
	assert(medicamentFind.getProducator() == "kjlfd");
	assert(medicamentFind.getSubstantaActiva() == "ndsal");
	vector<Medicament> medicamente = service.getAllMedicamente();
	assert(medicamente.size() == 1);
	service.addMedicament("Strepsils", 12.2, "adsad", "sajdsa");
	vector<Medicament> filteredMedsPret = service.filterMedicamentePret(12.2);
	assert(filteredMedsPret.size() == 2);
	vector<Medicament> filteredMedsSubstanta = service.filterMedicamenteSubstantaActiva("sajdsa");
	std::cout << filteredMedsSubstanta.size();
	assert(filteredMedsSubstanta.size() == 1);
	vector<Medicament> sortedMeds = service.sortMedicamente(cmpFDenumire);
	assert(sortedMeds.size() == 2);
	assert(sortedMeds[0].getDenumire() == "Nurofen");
	std::cout << "Teste service trecute cu succes!\n";
	service.genereazaReteta(50);
	assert(service.getSizeReteta() == 50);
}

MyVector testCopyIterate(MyVector v) {
	double totalPrice = 0;
	for (auto el : v) {
		totalPrice += el.getPret();
	}
	Medicament m{ "total",totalPrice, "tt", "tt" };
	v.add(m);
	return v;
}

void addMedicamente(MyVector& v, int nr) {
	for (int i = 0; i < nr; i++) {
		Medicament m{ std::to_string(i) + "_denumire", i + 10.0, std::to_string(i) + "_producator", std::to_string(i) + "_subst" };
		v.add(m);
	}
}

void testCreateCopyAssign() {
	MyVector v;//default constructor
	addMedicamente(v, 100);
	assert(v.size() == 100);
	assert(v.get(50).getDenumire() == "50_denumire");

	MyVector v2{ v };//constructor de copiere
	assert(v2.size() == 100);
	assert(v2.get(50).getDenumire() == "50_denumire");

	MyVector v3;//default constructor
	v3 = v;//operator=   assignment
	assert(v3.size() == 100);
	assert(v3.get(50).getDenumire() == "50_denumire");

	auto v4 = testCopyIterate(v3);
	assert(v4.size() == 101);
	assert(v4.get(50).getDenumire() == "50_denumire");
}

void testMoveConstrAssgnment() {
	std::vector<MyVector> v;
	//adaugam un vector care este o variabila temporara
	//se va apela move constructor
	v.push_back(MyVector{});

	//inseram, la fel se apeleaza move costructor de la vectorul nostru
	v.insert(v.begin(), MyVector{});

	assert(v.size() == 2);

	MyVector v2;
	addMedicamente(v2, 50);

	v2 = MyVector{};//move assignment

	assert(v2.size() == 0);

}

void Tests::testMyVector()
{
	testCreateCopyAssign();
	testMoveConstrAssgnment();
	std::cout << "Teste MyVector trecute cu succes!\n";
}

void Tests::testReteta()
{
	Reteta reteta;
	Medicament m1("Nurofen", 20.0, "ada", "ada");
	reteta.add(m1);
	assert(reteta.size() == 1);
	Medicament m2("Strepsils", 11.11, "aasa", "sad");
	reteta.add(m2);
	assert(reteta.size() == 2);
	vector<Medicament> all = reteta.getAll();
	assert(all.size() == 2);
	reteta.clear();
	assert(reteta.size() == 0);
	std::cout << "Teste Reteta trecute cu succes!\n";
}
