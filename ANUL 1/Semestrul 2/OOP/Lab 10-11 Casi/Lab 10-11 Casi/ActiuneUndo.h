#include "MedicamentRepo.h"
class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() {};
};

class UndoAdauga : public ActiuneUndo {
private:
	Medicament medAdaugat;
	MedicamentRepo& repo;
public:
	UndoAdauga(Medicament& med, MedicamentRepo& rep) : medAdaugat{ med }, repo{ rep } {}
	void doUndo() override {
		repo.deleteRepo(medAdaugat.getDenumire());
	}
};

class UndoSterge : public ActiuneUndo {
private:
	Medicament medSters;
	MedicamentRepo& repo;
public:
	UndoSterge(Medicament& medSters, MedicamentRepo& repo) : medSters{ medSters }, repo{ repo } {};
	void doUndo()override {
		repo.addRepo(medSters);
	}
};

class UndoModifica : public ActiuneUndo {
private:
	Medicament medInitial;
	MedicamentRepo& repo;
public:
	UndoModifica(Medicament& medInitial, MedicamentRepo& repo) :medInitial{ medInitial }, repo{ repo } {};
	void doUndo()override {
		repo.modifyRepo(medInitial);
	}
};
