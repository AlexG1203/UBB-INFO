#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qmessagebox.h>
#include "Medicament.h"
#include "MedicamentStore.h"
#include "Reteta.h"
#include "FilteredMedsGUI.h"
#include "RetetaGUI.h"
#include "TabelGUI.h"

using std::vector;
using std::string;

class GUI : public QWidget {
public:
	GUI(MedicamentStore& service) : service{ service } {
		initGUI();
		initConnect();
		loadData();
		loadDynamicButtons();
	}

	void addMedGUI();
	void delMedGUI();
	void modificaMedGUI();

private:
	MedicamentStore& service;
	QVBoxLayout* lyStanga = new QVBoxLayout{};
	QListWidget* list = new QListWidget{};
	QPushButton* btnSortDenumire = new QPushButton{ "Sortare denumire" };
	QPushButton* btnSortProducator = new QPushButton{ "Sortare producator" };
	QPushButton* btnFiltruPret = new QPushButton{ "Filtrare Pret" };
	QLineEdit* linieFiltarePret = new QLineEdit;
	QPushButton* btnAdd = new QPushButton("Adauga");
	QPushButton* btnSterge = new QPushButton("Sterge");
	QPushButton* btnModifica = new QPushButton("Modifica");
	QPushButton* btnUndo = new QPushButton("Undo");
	QPushButton* btnExit = new QPushButton("Exit");
	QPushButton* btnAddToReteta = new QPushButton("Adauga la reteta");
	QPushButton* btnClearReteta = new QPushButton("Goleste reteta");
	QPushButton* btnShowReteta = new QPushButton("Afiseaza reteta");
	QLineEdit* lineID = new QLineEdit;
	QLineEdit* lineDenumire = new QLineEdit;
	QLineEdit* linePret = new QLineEdit;
	QLineEdit* lineProducator = new QLineEdit;
	QLineEdit* lineSubstanta = new QLineEdit;
	QHBoxLayout* lyDynamicButtons = new QHBoxLayout{};
	vector<QPushButton*> allDynamicButtons;

	void initGUI();
	void initConnect();
	void loadData();
	void loadData(vector<Medicament> meds);
	void loadDynamicButtons();
};