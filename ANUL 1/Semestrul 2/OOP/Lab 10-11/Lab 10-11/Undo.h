#pragma once
#include "Medicament.h"
#include "MedicamentRepo.h"

class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
	int id;
	MedicamentRepo& rep;
public:
	UndoAdauga(MedicamentRepo& rep, int id) :rep{ rep }, id{ id } {}
	void doUndo() override {
		rep.delMedicamantRepo(id);
	}
};

class UndoSterge : public ActiuneUndo {
	Medicament medSters;
	MedicamentRepo& rep;
public:
	UndoSterge(MedicamentRepo& rep, Medicament& med) :rep{ rep }, medSters{ med } {}
	void doUndo() override {
		rep.store(medSters);
	}
};

class UndoModifica : public ActiuneUndo {
	int id;
	Medicament medVechi;
	MedicamentRepo& rep;
public:
	UndoModifica(MedicamentRepo& rep, Medicament& med, int id) :rep{ rep }, medVechi{ med }, id{ id } {}
	void doUndo() override {
		rep.modifyMedicamentRepo(id, medVechi);
	}
};