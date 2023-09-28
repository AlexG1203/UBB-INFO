#include "GUI.h"

void GUI::initGUI() {
	QHBoxLayout* lyMain = new QHBoxLayout{};
	setLayout(lyMain);

	lyMain->addLayout(lyStanga);
	lyStanga->addWidget(list);

	QVBoxLayout* lyVertical = new QVBoxLayout{};
	lyMain->addLayout(lyVertical);

	auto formLy = new QFormLayout;
	formLy->addRow("Locatie", lineLocatie);
	formLy->addRow("Data", linieData);
	formLy->addRow("Intensitate", lineIntensitate);
	formLy->addRow("Adancime",lineAdancime);
	lyVertical->addLayout(formLy);

	auto lyButtons = new QHBoxLayout;
	lyVertical->addLayout(lyButtons);

	lyButtons->addWidget(btnAdd);
}

void GUI::loadData(vector<Cutremur> cut) {
	list->clear();
	for (auto& c : cut) {
		list->addItem(QString::fromStdString(c.getLocatie()));
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(c.getLocatie()));
		item->setData(Qt::UserRole, QString::fromStdString(c.getLocatie()));
		if (c.getIntensitate() < 3) {
			item->setData(Qt::BackgroundRole, QBrush{ Qt::gray,Qt::SolidPattern });
		}
	}
}

void GUI::initConnect() {
	QObject::connect(btnAdd, &QPushButton::clicked, [&]() {

		});
}