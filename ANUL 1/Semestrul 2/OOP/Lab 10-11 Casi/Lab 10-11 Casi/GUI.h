#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>
#include "Medicament.h"
#include "MedicamentService.h"
#include <QtWidgets/qmessagebox.h>
#include "FilteredMedsGUI.h"
#include "RetetaGUI.h"

using std::vector;
using std::string;

class GUI : public QWidget {
public:
	GUI(MedicamentService& service) : service{ service } {
		initGUI();
		loadData();
		initConnect();
		loadDynamicButtons();
	}

	void addMedGUI();
	void delMedGUI();
	void modificaMedGUI();

private:
	MedicamentService& service;
	QVBoxLayout* lyStanga = new QVBoxLayout{};
	QListWidget* list = new QListWidget{};
	QPushButton* btnSortDenumire = new QPushButton("Sort denumire");
	QPushButton* btnSortProducator = new QPushButton("Sort producator");
	QPushButton* btnFilterPret = new QPushButton("Filtru pret");
	QPushButton* btnFilterSubstantaActiva = new QPushButton("Filtru substanta activa");
	QLineEdit* linePretFiltru = new QLineEdit;
	QLineEdit* lineSubstantaFiltru = new QLineEdit;
	QPushButton* btnAdd = new QPushButton("Adauga");
	QPushButton* btnSterge = new QPushButton("Sterge");
	QPushButton* btnModifica = new QPushButton("Modifica");
	QPushButton* btnUndo = new QPushButton("Undo");
	QPushButton* btnExit = new QPushButton("Exit");
	QPushButton* btnAddToReteta = new QPushButton("Adauga la reteta");
	QPushButton* btnClearReteta = new QPushButton("Goleste reteta");
	QPushButton* btnShowReteta = new QPushButton("Afiseaza reteta");
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