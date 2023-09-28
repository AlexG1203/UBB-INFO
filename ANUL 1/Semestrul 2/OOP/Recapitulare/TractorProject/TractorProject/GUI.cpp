#include "GUI.h"

void GUI::initGUI() {
	this->setLayout(mainLy);
	tableView->setModel(model);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSizeAdjustPolicy(QAbstractItemView::AdjustToContents);
	tableView->setMaximumHeight(200);
	mainLy->addLayout(lyStanga);
	lyStanga->addWidget(tableView);
	lyStanga->addLayout(lyDesen);
	formLayout->addRow(tr("&Id:"), idLineEdit);
	formLayout->addRow(tr("&Denumire:"), denumireLineEdit);
	formLayout->addRow(tr("&Tip:"), tipLineEdit);
	formLayout->addRow(tr("&Numar roti:"), nrRotiLineEdit);
	mainLy->addLayout(lyDreapta);
	lyDreapta->addLayout(formLayout);
	lyDreapta->addLayout(btnLy);
	lyDreapta->addWidget(comboBox);
	btnLy->addWidget(btnAdd);
}