#include "GUI.h"

void GUI::initGUI() {
	QHBoxLayout* lyMain = new QHBoxLayout{};
	setLayout(lyMain);

	lyMain->addLayout(lyStanga);
	lyStanga->addWidget(list);
	//lyMain->addWidget(list);

	lyStanga->addLayout(lyDynamicButtons);

	QHBoxLayout* lySortButtons = new QHBoxLayout{};
	lyStanga->addLayout(lySortButtons);
	lySortButtons->addWidget(btnSortDenumire);
	lySortButtons->addWidget(btnSortProducator);

	QHBoxLayout* lyFilterButtons = new QHBoxLayout{};
	lyStanga->addLayout(lyFilterButtons);
	lyFilterButtons->addWidget(btnFilterPret);
	lyFilterButtons->addWidget(btnFilterSubstantaActiva);

	QHBoxLayout* lyFilterLines = new QHBoxLayout{};
	lyStanga->addLayout(lyFilterLines);
	linePretFiltru->setPlaceholderText("Pret Filtru");
	lineSubstantaFiltru->setPlaceholderText("Substanta Filtru");
	lyFilterLines->addWidget(linePretFiltru);
	lyFilterLines->addWidget(lineSubstantaFiltru);

	QVBoxLayout* lyVertical = new QVBoxLayout{};
	lyMain->addLayout(lyVertical);

	auto formLy = new QFormLayout;
	formLy->addRow("Denumire", lineDenumire);
	formLy->addRow("Pret", linePret);
	formLy->addRow("Producator", lineProducator);
	formLy->addRow("Substanta activa", lineSubstanta);
	lyVertical->addLayout(formLy);

	auto lyButtons = new QHBoxLayout;
	lyVertical->addLayout(lyButtons);

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

void GUI::addMedGUI() {
	try {
		string denumire = lineDenumire->text().toStdString();
		double pret = std::stod(linePret->text().toStdString());
		string producator = lineProducator->text().toStdString();
		string substanta = lineSubstanta->text().toStdString();
		service.addMedicament(denumire, pret, producator, substanta);
		list->addItem(QString::fromStdString(denumire));
		lineDenumire->clear();
		linePret->clear();
		lineProducator->clear();
		lineSubstanta->clear();
	}
	catch (RepoException e) {
		qDebug() << e.what();
	}
	catch (ValidateException e) {
		qDebug() << e.what();
	}
	catch (std::exception e) {
		qDebug() << e.what();
	}
}

void GUI::delMedGUI() {
	try {
		auto denumire = lineDenumire->text();
		service.stergeMedicament(denumire.toStdString());
		loadData();
	}
	catch (RepoException e) {
		qDebug() << e.what();
	}
}

void GUI::modificaMedGUI() {
	try {
		string denumire = lineDenumire->text().toStdString();
		double pret = linePret->text().toDouble();
		string producator = lineProducator->text().toStdString();
		string substanta = lineSubstanta->text().toStdString();
		service.modificaMedicament(denumire, pret, producator, substanta);
		loadData();
		lineDenumire->clear();
		linePret->clear();
		lineProducator->clear();
		lineSubstanta->clear();
	}
	catch (RepoException e) {
		qDebug() << e.what();
	}
	catch (ValidateException e) {
		qDebug() << e.what();
	}
	catch (std::exception e) {
		qDebug() << e.what();
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
			lineDenumire->setText("");
			linePret->setText("");
			lineProducator->setText("");
			lineSubstanta->setText("");
		}
		else {
			auto selectedItem = sel.at(0);
			auto med = service.searchMedicament(selectedItem->text().toStdString());
			lineDenumire->setText(selectedItem->text());
			linePret->setText(QString::number(med.getPret()));
			lineProducator->setText(QString::fromStdString(med.getProducator()));
			lineSubstanta->setText(QString::fromStdString(med.getSubstantaActiva()));
		}
		});

	QObject::connect(btnSortDenumire, &QPushButton::clicked, [&]() {
		loadData(service.sortMedicamenteDenumire());
		});

	QObject::connect(btnSortProducator, &QPushButton::clicked, [&]() {
		loadData(service.sortMedicamenteProducator());
		});

	QObject::connect(btnFilterPret, &QPushButton::clicked, [&]() {
		if (linePretFiltru->text() == "") {
			QMessageBox::information(nullptr, "Info", "Introduceti un pret");
		}
		else {
			try {
				double filterPrice = linePretFiltru->text().toDouble();
				auto filteredMeds = service.filterMedicamentePret(filterPrice);
				FilteredMedsGUI* filteredMedsGUI = new FilteredMedsGUI{ filteredMeds };
				filteredMedsGUI->show();
			}
			catch (std::exception e) {
				qDebug() << e.what();
			}

		}
		});

	QObject::connect(btnFilterSubstantaActiva, &QPushButton::clicked, [&]() {
		if (lineSubstantaFiltru->text() == "") {
			QMessageBox::information(nullptr, "Info", "Introduceti o substanta activa");
		}
		else {
			try {
				auto filterSubstanta = lineSubstantaFiltru->text().toStdString();
				auto filteredMeds = service.filterMedicamenteSubstantaActiva(filterSubstanta);
				FilteredMedsGUI* filteredMedsGUI = new FilteredMedsGUI{ filteredMeds };
				filteredMedsGUI->show();
			}
			catch (std::exception e) {
				qDebug() << e.what();
			}

		}
		});
	QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
		try {
			service.undo();
			loadData();
		}
		catch (std::exception e) {
			qDebug() << e.what();
		}
		});

	QObject::connect(btnAddToReteta, &QPushButton::clicked, [&]() {
		try {
			auto denumire = lineDenumire->text().toStdString();
			service.adaugaToReteta(denumire);
		}
		catch (RepoException e) {
			qDebug() << e.what();
		}
		});
	QObject::connect(btnShowReteta, &QPushButton::clicked, [&]() {
		vector<Medicament> retetaMeds = service.getAllReteta();
		RetetaGUI* reteta = new RetetaGUI{ retetaMeds };
		reteta->show();
		});
}

void GUI::loadData() {
	list->clear();
	vector<Medicament> allMeds = service.getAllMedicamente();
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