#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qtablewidget.h>
#include <qbrush.h>
#include "Repo.h"
#include "Service.h"
#include "cutremur.h"
#include <vector>


class GUI : public QWidget {
public:
	GUI(Serv& service) : service{ service } {
		initGUI();
		initConnect();
		loadData(service.getList());
	}

	void AddCutGUI();

private:
	Serv& service;
	QHBoxLayout* lyStanga = new QHBoxLayout{};
	QListWidget* list = new QListWidget{};

	QLineEdit* lineLocatie = new QLineEdit;
	QLineEdit* linieData = new QLineEdit;
	QLineEdit* lineIntensitate = new QLineEdit;
	QLineEdit* lineAdancime = new QLineEdit;

	QPushButton* btnAdd = new QPushButton("Adauga cutremur");

	void initGUI();
	void initConnect();
	void loadData(vector<Cutremur> c);
};