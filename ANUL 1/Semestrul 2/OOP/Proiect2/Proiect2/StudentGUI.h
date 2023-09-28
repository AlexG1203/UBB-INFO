#pragma once
#include <qapplication.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qpushbutton.h>
#include <qtableview.h>
#include <qslider.h>
#include "Service.h"
#include <qmessagebox.h>
#include "MyTableModel.h"
class StudentGUI : public QWidget
{
public:
	StudentGUI(Service& serv) : serv{ serv } {
		initGUI();
		reloadList();
		connectSignalSlots();
	};
private:
	Service& serv;
	void initGUI();
	void connectSignalSlots();
	void reloadList();
	QPushButton* btnDec = new QPushButton{ "&Intinerire" };
	QPushButton* btnInc = new QPushButton{ "&Imbatranire" };
	QPushButton* btnDelete = new QPushButton{ "&Delete button" };
	QPushButton* btnUndo = new QPushButton{ "&Undo Button" };
	QSlider* slider = new QSlider;
	QTableView* tabel;
	TableViewModel* model;
};

