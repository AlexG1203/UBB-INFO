#pragma once
#include <qwidget.h>
#include "Medicament.h"
#include <vector>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qtablewidget.h>
#include <qlayout.h>
#include <qtablewidget.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qheaderview.h>

class TabelGUI : public QWidget {
public:
	TabelGUI(std::vector<Medicament> tabelMeds) {
		initGUI();
		loadTabelMeds(tabelMeds);
	};
private:
	QListWidget* list = new QListWidget{};
	QTableWidget* listW = new QTableWidget{};
	QLabel* recomW = new QLabel;
	void initGUI() {
		auto lyMain = new QHBoxLayout{};
		this->setLayout(lyMain);
		listW->setColumnCount(1);
		listW->setMinimumHeight(350);
		listW->setMaximumWidth(210);
		lyMain->addWidget(listW);
		lyMain->addWidget(recomW);
	};
	void loadTabelMeds(std::vector<Medicament> meds) {
		list->clear();
		listW->setRowCount(meds.size());
		int pos = 0;
		for (auto& med : meds) {
			QTableWidgetItem* item;

			item = new QTableWidgetItem;
			item->setText(QString::fromStdString(med.getDenumire()));
			listW->setItem(pos, 0, item);
			++pos;
		}
	}
};