#include "GUI.h"

void GUI :: initGUI() {
	QHBoxLayout* lyMain = new QHBoxLayout{};
	setLayout(lyMain);

	lyMain->addLayout(lyStanga);
	lyStanga->addWidget(list);


	QVBoxLayout* lyVertical = new QVBoxLayout{};
	lyMain->addLayout(lyVertical);

	auto formLy = new QFormLayout;
	formLy->addRow("Model", linieModel);
	formLy->addRow("An", linieAn);
	lyVertical->addLayout(formLy);

	
	auto lyButtons = new QHBoxLayout;
	lyVertical->addLayout(lyButtons);

	lyButtons->addWidget(btnSortModel);
	lyButtons->addWidget(btnSortAn);
	lyButtons->addWidget(btnNesortat);

}

void GUI::loadData(vector<Device> devs) {
	list->clear();
	for (auto& dev : devs) {
		list->addItem(QString::fromStdString(dev.getTip()));
	}
}

void GUI::initConnect() {
	QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {
		auto sel = list->selectedItems();
		if (sel.isEmpty()) {
			linieModel->setText("");
			linieAn->setText("");
		}
		else {
			auto selectedItem = sel.at(0);
			Device dev = list->selectedItems()[0]->data(Qt::UserRole).value<Device>();
			linieModel->setText(QString::fromStdString(dev.getModel()));
			linieAn->setText(QString::fromStdString(std::to_string(dev.getAn())));
		}
		});

	QObject::connect(btnSortAn, &QPushButton::clicked, [&]() {
		vector<Device> vct = service.sorteazaCresc();
		loadData(vct);
		});

	QObject::connect(btnNesortat, &QPushButton::clicked, [&]() {
		auto fereastra = new QWidget;
		QHBoxLayout* lyStangaf = new QHBoxLayout{};
		fereastra->show();
		QHBoxLayout* lyMain = new QHBoxLayout{};
		setLayout(lyMain);

		lyMain->addLayout(lyStangaf);
		lyStangaf->addWidget(fereastra);


		QVBoxLayout* lyVertical = new QVBoxLayout{};
		lyMain->addLayout(lyVertical);
		});
}