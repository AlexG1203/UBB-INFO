#pragma once
#include "Service.h"
#include "qwidget.h"
#include <qboxlayout.h>
#include "qlabel.h"
#include "MyTableModel.h"
#include <qtableview.h>
#include <qformlayout.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qcombobox.h>
#include <qpainter.h>
#include <QMouseEvent>

class GUI : public QWidget {
private:
	Service& service;
	void initGUI();

	int nrRoti = 0;

	QHBoxLayout* mainLy = new QHBoxLayout;
	QHBoxLayout* lyStanga = new QHBoxLayout;
	QTableView* tableView = new QTableView;
	QHBoxLayout* lyDesen = new QHBoxLayout;
	MyTableModel* model = new MyTableModel{ service };
	QVBoxLayout* lyDreapta = new QVBoxLayout;
	QFormLayout* formLayout = new QFormLayout;
	QLineEdit* idLineEdit = new QLineEdit;
	QLineEdit* denumireLineEdit = new QLineEdit;
	QLineEdit* tipLineEdit = new QLineEdit;
	QLineEdit* nrRotiLineEdit = new QLineEdit;
	QHBoxLayout* btnLy = new QHBoxLayout;
	QPushButton* btnAdd = new QPushButton{ "Adauga" };
	QComboBox* comboBox = new QComboBox;


public:
	GUI(Service& service) : service{ service } {
		initGUI();
	}
	
};