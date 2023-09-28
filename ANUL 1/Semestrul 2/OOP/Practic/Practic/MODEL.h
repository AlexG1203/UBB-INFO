#pragma once
#include <QAbstractTableModel>
#include "domain.h"
#include <vector>
using std::vector;

class MyTableModel :public QAbstractTableModel {
private:
	vector<Student> list;
	Service& service;
	string facultate;
public:
	MyTableModel(Service& service) :service{ service } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return list.size();
	};
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 4;
	};
	QVariant data(const QModelIndex& index, int role) const override {
		if (role == Qt::DisplayRole) {
			auto currentRow = index.row();
			if (index.column() == 0) {
				return QString::number(list[currentRow].getNrMatricol());
			}
			else if (index.column() == 1) {
				return QString::fromStdString(list[currentRow].getNume());
			}
			else if (index.column() == 2) {
				return QString::number(list[currentRow].getVarsta());
			}
			else if (index.column() == 3) {
				return QString::fromStdString(list[currentRow].getFacultate());
			}
		}
		return QVariant();
	};
	void setData(vector<Student> list) {
		this->list = list;
		emit layoutChanged();
	};
	void setData(vector<Student> list, string tip) {
		this->list = list;
		this->facultate = facultate;
		emit layoutChanged();
	};
};