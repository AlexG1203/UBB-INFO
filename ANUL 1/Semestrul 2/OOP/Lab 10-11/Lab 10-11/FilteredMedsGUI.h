#pragma once
#include <qwidget.h>
#include "Medicament.h"
#include <vector>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlistwidget.h>

class FilteredMedsGUI : public QWidget {
public:
	FilteredMedsGUI(std::vector<Medicament> filteredMeds) {
		initGUI();
		loadFilteredMeds(filteredMeds);
	};
private:
	QListWidget* list = new QListWidget{};
	void initGUI() {
		auto lyMain = new QHBoxLayout{};
		this->setLayout(lyMain);
		lyMain->addWidget(list);
	};
	void loadFilteredMeds(std::vector<Medicament> meds) {
		list->clear();
		for (auto& med : meds) {
			list->addItem(new QListWidgetItem{ QString::fromStdString(med.getDenumire()) });
		}
	}
};