#include "GUI.h"
#include "qmessagebox.h"

void GUI::initGUI() {
	this->setLayout(mainLy);
	tableView->setModel(model);
	tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	tableView->setSizeAdjustPolicy(QAbstractItemView::AdjustToContents);
	tableView->setMaximumHeight(200);
	mainLy->addLayout(lyStanga);
	lyStanga->addWidget(tableView);
	mainLy->addLayout(lyDreapta);
	lyDreapta->addLayout(formLayout);
	lyDreapta->addLayout(btnLy);
	btnLy->addWidget(btnDel);
	btnLy->addWidget(btnIntinerire);
	btnLy->addWidget(btnImbatranire);
}

void GUI::loadData(vector<Student> list)
{
	vector<string> allTypes = service.getAllTypes();
	for (auto tip : allTypes) {
		model->setData(list, tip);
	}
	repaint();
}

void GUI::initConnect() {
	QObject::connect(btnDel, &QPushButton::clicked, [this] {
		auto row = tableView->selectionModel()->selectedIndexes().at(0).row();
		auto id = tableView->model()->data(tableView->model()->index(row, 0), Qt::DisplayRole).toInt();
		service.remove_srv(id);
		this->repaint();
		});
	QObject::connect(btnIntinerire, &QPushButton::clicked, [&] {
		auto lst = service.get_all_srv();
		for (int i = 0; i < lst.size(); i++) {
			int c = lst[i].getVarsta();
			c = c + 1;
		}
		});
}