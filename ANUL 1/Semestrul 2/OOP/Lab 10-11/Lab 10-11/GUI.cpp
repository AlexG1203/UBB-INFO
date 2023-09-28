#include "GUI.h"

void GUI::initGUI() {
	QHBoxLayout* lyMain = new QHBoxLayout{};
	setLayout(lyMain);

	//adauga chenrarul unde se afla medicamentele
	lyMain->addLayout(lyStanga);
	lyStanga->addWidget(list);

	lyStanga->addLayout(lyDynamicButtons);

	//adauga butoane in partea cu chenarul principal
	QHBoxLayout* lySortButtons = new QHBoxLayout{};
	lyStanga->addLayout(lySortButtons);
	lySortButtons->addWidget(btnSortDenumire);
	lySortButtons->addWidget(btnSortProducator);

	QHBoxLayout* lyFilterButtons = new QHBoxLayout{};
	lyStanga->addLayout(lyFilterButtons);
	lyFilterButtons->addWidget(btnFiltruPret);

	//adauga linie in care se poate scrie in partea cu chenarul principal 
	QHBoxLayout* lyFilterLines = new QHBoxLayout{};
	lyStanga->addLayout(lyFilterLines);
	linieFiltarePret->setPlaceholderText("Pret Filtru");
	lyFilterLines->addWidget(linieFiltarePret);

	//Creeaza partea dreapta
	QVBoxLayout* lyVertical = new QVBoxLayout{};
	lyMain->addLayout(lyVertical);

	//Creaza linie in care se poate scrie in partea dreapta
	auto formLy = new QFormLayout;
	formLy->addRow("ID", lineID);
	formLy->addRow("Denumire", lineDenumire);
	formLy->addRow("Pret", linePret);
	formLy->addRow("Producator", lineProducator);
	formLy->addRow("Substanta activa", lineSubstanta);
	lyVertical->addLayout(formLy);

	auto lyButtons = new QHBoxLayout;
	lyVertical->addLayout(lyButtons);

	//Adauga butoane in partea dreapta
	lyButtons->addWidget(btnAdd);
	lyButtons->addWidget(btnSterge);
	lyButtons->addWidget(btnModifica);
	lyButtons->addWidget(btnUndo);
	lyButtons->addWidget(btnExit);

	auto lyBtnsReteta = new QHBoxLayout;
	lyVertical->addLayout(lyBtnsReteta);
	lyBtnsReteta->addWidget(btnAddToReteta);
	lyBtnsReteta->addWidget(btnClearReteta);
	lyBtnsReteta->addWidget(btnShowReteta);

}

void GUI::loadData() {
	list->clear();
	vector<Medicament> allMeds = service.getAll();
	for (const auto& med : allMeds) {
		list->addItem(QString::fromStdString(med.getDenumire()));
	}
}

void GUI::loadData(vector<Medicament> meds) {
	list->clear();
	for (const auto& med : meds) {
		list->addItem(QString::fromStdString(med.getDenumire()));
	}
}

void GUI::initConnect() {
	QObject::connect(btnExit, &QPushButton::clicked, [&]() {
		this->close();
		});

	QObject::connect(btnAdd, &QPushButton::clicked, [&]() {
		addMedGUI();
		});

	QObject::connect(btnSterge, &QPushButton::clicked, [&]() {
		delMedGUI();
		});

	QObject::connect(btnModifica, &QPushButton::clicked, [&]() {
		modificaMedGUI();
		});

	QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {
		auto sel = list->selectedItems();
		if (sel.isEmpty()) {
			lineID->setText("");
			lineDenumire->setText("");
			linePret->setText("");
			lineProducator->setText("");
			lineSubstanta->setText("");
		}
		else {
			auto selectedItem = sel.at(0);
			auto med = service.srcMedicamentDenumire(selectedItem->text().toStdString());
			lineID->setText(QString::number(med.getID()));
			lineDenumire->setText(selectedItem->text());
			linePret->setText(QString::number(med.getPret()));
			lineProducator->setText(QString::fromStdString(med.getProducator()));
			lineSubstanta->setText(QString::fromStdString(med.getSubstanta()));
		}
		});

	QObject::connect(btnSortDenumire, &QPushButton::clicked, [&]() {
		loadData(service.sortDenumire());
		});

	QObject::connect(btnSortProducator, &QPushButton::clicked, [&]() {
		loadData(service.sortProducator());
		});

	QObject::connect(btnFiltruPret, &QPushButton::clicked, [&]() {
		if (linieFiltarePret->text() == "") {
			QMessageBox::information(nullptr, "Info", "Introduceti un pret");
		}
		else {
			int filterPrice = linieFiltarePret->text().toInt();
			auto filteredMeds = service.pretFilter(filterPrice);
			TabelGUI* tabelMedsGUI = new TabelGUI{ filteredMeds };
			tabelMedsGUI->show();
		}
		});

	QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
		try {
			service.undo();
			loadData();
		}
		catch (std::exception e) {
			qDebug() << "Nu se mai poate face undo!";
		}
		});

	QObject::connect(btnAddToReteta, &QPushButton::clicked, [&]() {
		try {
			auto denumire = lineDenumire->text().toStdString();
			service.adauga_reteta(denumire);
		}
		catch (std::exception e) {
			qDebug() << "Eroare!";
		}
		});

	QObject::connect(btnShowReteta, &QPushButton::clicked, [&]() {
		vector<Medicament> retetaMeds = service.getAll_reteta();
		RetetaGUI* reteta = new RetetaGUI{ retetaMeds };
		reteta->show();
		});

	QObject::connect(btnClearReteta, &QPushButton::clicked, [&]() {
		try {
			service.goleste_reteta();
		}
		catch (std::exception e) {
			qDebug() << "Eroare!";
		}
		});
}

void GUI::addMedGUI() {
	try {
		int id = std::stod(lineID->text().toStdString());
		string denumire = lineDenumire->text().toStdString();
		int pret = std::stod(linePret->text().toStdString());
		string producator = lineProducator->text().toStdString();
		string substanta = lineSubstanta->text().toStdString();
		service.addMedicament(id, denumire, pret, producator, substanta);
		list->addItem(QString::fromStdString(denumire));
		lineID->clear();
		lineDenumire->clear();
		linePret->clear();
		lineProducator->clear();
		lineSubstanta->clear();
	}
	catch (ValidateException e) {
		qDebug() << "Medicament invalid!";
	}
	catch (std::exception e) {
		qDebug() << "Medicament invalid!";
	}
}

void GUI::delMedGUI() {
	try {
		auto id = lineID->text().toInt();
		service.delMedicament(id);
		loadData();
	}
	catch (exception e) {
		qDebug() << "Nu se poate sterge!";
	}
}

void GUI::modificaMedGUI() {
	try {
		int id = std::stod(lineID->text().toStdString());
		string denumire = lineDenumire->text().toStdString();
		double pret = linePret->text().toDouble();
		string producator = lineProducator->text().toStdString();
		string substanta = lineSubstanta->text().toStdString();
		service.modifyMedicament(id, denumire, pret, producator, substanta);
		loadData();
		lineID->clear();
		lineDenumire->clear();
		linePret->clear();
		lineProducator->clear();
		lineSubstanta->clear();
	}
	catch (ValidateException e) {
		qDebug() << "Medicament invalid!";
	}
	catch (std::exception e) {
		qDebug() << "Medicament invalid!";
	}
}

void GUI::loadDynamicButtons() {
	std::map<string, vector<Medicament>> map = service.creeazaRaport();
	for (auto& pair : map) {
		auto btn = new QPushButton{ QString::fromStdString(pair.first) };
		lyDynamicButtons->addWidget(btn);
		QObject::connect(btn, &QPushButton::clicked, [btn, pair]() {
			QMessageBox::information(nullptr, "Info", QString::number(pair.second.size()));
			delete btn;
			});
	}
}