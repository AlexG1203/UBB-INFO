#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qtablewidget.h>
#include "device.h"
#include "Service.h"
#include <vector>

class GUI : public QWidget {
public:
	GUI(Serv& service) : service{ service } {
		initGUI();
		initConnect();
		loadData(service.getList());
	}
private:
	Serv& service;
	QHBoxLayout* lyStanga = new QHBoxLayout{};
	QListWidget* list = new QListWidget{};

	QLineEdit* linieModel = new QLineEdit;
	QLineEdit* linieAn = new QLineEdit;

	QPushButton* btnSortModel = new QPushButton("Sortare Model");
	QPushButton* btnSortAn = new QPushButton("Sortare An");
	QPushButton* btnNesortat = new QPushButton("Nesortat");

	void initGUI();
	void initConnect();
	void loadData(vector<Device> dev);
};