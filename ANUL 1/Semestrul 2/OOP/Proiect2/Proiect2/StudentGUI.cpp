#include "StudentGUI.h"


void StudentGUI::initGUI() {
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);

	// impartim fereastra in 2 : 
	//lyleft : butoane 
	//lyright : tabel
	QVBoxLayout* lyLeft = new QVBoxLayout;
	lyLeft->addWidget(btnInc);
	lyLeft->addWidget(btnDec);
	lyLeft->addWidget(btnDelete);
	lyLeft->addWidget(btnUndo);

	// acum creez layout ul din dreapta pentru tabel
	QVBoxLayout* lyRight = new QVBoxLayout;
	tabel = new QTableView();
	model = new TableViewModel(serv, 50);
	tabel->setModel(model);
	tabel->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabel->setSelectionMode(QAbstractItemView::SingleSelection);
	tabel->setSizeAdjustPolicy(QAbstractItemView::AdjustToContents);


	lyRight->addWidget(tabel);

	lyMain->addLayout(lyLeft);
	lyMain->addLayout(lyRight);
}

void StudentGUI::reloadList() {
	model->setSongs();
}

void StudentGUI::connectSignalSlots() {

	QObject::connect(btnInc, &QPushButton::clicked, [&]() {
		//if (!tabel->selectionModel()->selectedIndexes().isEmpty()) {
			// continut qline id
			//auto selectedRow = tabel->selectionModel()->selectedIndexes().at(0).row();
			//auto celIndex = tabel->model()->index(selectedRow, 0);
			//auto selectedId = tabel->model()->data(celIndex, Qt::DisplayRole).toInt();

		serv.setAgeService(true);
		reloadList();
		//}
		});

	QObject::connect(btnDec, &QPushButton::clicked, [&]() {
		//if (!tabel->selectionModel()->selectedIndexes().isEmpty()) {
			// continut qline id
			//auto selectedRow = tabel->selectionModel()->selectedIndexes().at(0).row();
			//auto celIndex = tabel->model()->index(selectedRow, 0);
			//auto selectedId = tabel->model()->data(celIndex, Qt::DisplayRole).toInt();
		serv.setAgeService(false);
		reloadList();
		//}
		});

	QObject::connect(btnDelete, &QPushButton::clicked, [&]() {
		if (!tabel->selectionModel()->selectedIndexes().isEmpty()) {
			// continut qline id
			auto selectedRow = tabel->selectionModel()->selectedIndexes().at(0).row();
			auto celIndex = tabel->model()->index(selectedRow, 0);
			auto selectedId = tabel->model()->data(celIndex, Qt::DisplayRole).toInt();

			serv.deleteService(selectedId);
		}});

	QObject::connect(btnUndo, &QPushButton::clicked, [&]() {
		try { serv.undo(); }
		catch (std::exception& ex) {
			QMessageBox::warning(this, "Warning", QString::fromStdString("Nu exista undo-uri de facut"));
		}
		reloadList();
		});
}