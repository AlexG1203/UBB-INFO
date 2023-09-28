#include "GUI.h"
#include "qmessagebox.h"

void GUI::initGUI()
{
	this->setLayout(mainLy);
	tableView->setModel(model);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSizeAdjustPolicy(QAbstractItemView::AdjustToContents);
	tableView->setMaximumHeight(200);
	mainLy->addLayout(lyStanga);
	lyStanga->addWidget(tableView);

	formLayout->addRow(tr("&ID:"), idLineEdit);
	formLayout->addRow(tr("&Nume:"), numeLineEdit);
	formLayout->addRow(tr("&Tip:"), tipLineEdit);
	formLayout->addRow(tr("&Pret:"), pretLineEdit);
	mainLy->addLayout(lyDreapta);
	lyDreapta->addLayout(formLayout);
	lyDreapta->addLayout(btnLy);
	//lyDreapta->addWidget(comboBox);
	lyDreapta->addWidget(slider);
	slider->setRange(0, 100);
	slider->setValue(0);
	btnLy->addWidget(btnAdd);
}

void GUI::loadData(vector<Produs> list)
{
	vector<string> allTypes = service.getAllTypes();
	//comboBox->clear();
	for (auto tip : allTypes) {
		//comboBox->addItem(QString::fromStdString(tip));
		model->setData(list, tip);
	}
	//string tip = comboBox->currentText().toStdString();
	repaint();
}

void GUI::initConnect(){
	QObject::connect(btnAdd, &QPushButton::clicked, [&] {
		double pret = pretLineEdit->text().toDouble();
		if (numeLineEdit->text() == "" || (pret < 1 || pret > 100)) {
			QMessageBox::warning(this, tr("Warning"), tr("Date invalide!"));
		}
		else {
			try {
				int id = idLineEdit->text().toInt();
				string nume = numeLineEdit->text().toStdString();
				string tip = tipLineEdit->text().toStdString();
				service.store(id, nume, tip, pret);
				loadData(service.sortAll());
			}
			catch (std::exception& e) {
				QMessageBox::warning(this, tr("Warning"),
					tr(e.what()));
			}
		}
		});
	QObject::connect(slider, &QSlider::valueChanged, [this](int value) {
		qDebug() << slider->value();
		// Verificarea daca modelul este valid
		if (tableView->model()) {
			// Parcurgerea tuturor randurilor tabelului
			for (int row = 0; row < tableView->model()->rowCount(); ++row) {
				// Obtinerea valorii din coloana "Pret"
				double price = tableView->model()->data(tableView->model()->index(row, 3)).toDouble();

				// Setarea culorii de fundal in functie de valoarea slider-ului
				if (price <= value) {
					tableView->setStyleSheet("QTableView::item { background-color: red; }");
				}
				else {
					tableView->setStyleSheet("");
				}
			}
		}
		});
}