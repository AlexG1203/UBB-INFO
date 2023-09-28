#pragma once
#include <utility>

#include "service.h"
#include "QWidget"
#include "MODEL.h"
#include "QTableView"
#include "Qt"
#include "QPushButton"
#include "QLineEdit"
#include "QLabel"
#include "QLayout"
#include <qformlayout.h>

using namespace std;

class GUI : public QWidget {
private:
    Service& service;
    void initGUI();
    void loadData(vector<Student> list);
    void initConnect();
	QHBoxLayout* mainLy = new QHBoxLayout;
	QHBoxLayout* lyStanga = new QHBoxLayout;
	QTableView* tableView = new QTableView;
	MyTableModel* model = new MyTableModel{ service };
	QVBoxLayout* lyDreapta = new QVBoxLayout;
	QFormLayout* formLayout = new QFormLayout;
	QHBoxLayout* btnLy = new QHBoxLayout;
	QPushButton* btnDel = new QPushButton{ "Sterge" };
	QPushButton* btnIntinerire = new QPushButton{ "Intinerire" };
	QPushButton* btnImbatranire = new QPushButton{ "Imbatranire" };
public:
	GUI(Service& service) : service{ service } {
		initGUI();
		loadData(service.sort_lista());
		initConnect();
	}
};