#pragma once
#include <QAbstractTableModel>
#include "Produs.h"
#include <vector>
using std::vector;

class MyTableModel : public QAbstractTableModel
{
private:
	vector<Produs> list;
	Service& service;
	string tip;
public:
	MyTableModel(Service& service) :service{ service } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override {
		return list.size();
	};
	int columnCount(const QModelIndex& parent = QModelIndex()) const override {
		return 5;
	};
	QVariant data(const QModelIndex& index, int role) const override {
		if (role == Qt::DisplayRole) {
			auto currentRow = index.row();
			if (index.column() == 0) {
				return QString::number(list[currentRow].getID());
			}
			else if (index.column() == 1) {
				return QString::fromStdString(list[currentRow].getNume());
			}
			else if (index.column() == 2) {
				return QString::fromStdString(list[currentRow].getTip());
			}
			else if (index.column() == 3) {
				return QString::number(list[currentRow].getPret());
			}
			else if (index.column() == 4) {
				//return QString::number(service.filterTip(list[currentRow].getTip()).size());
				return QString::number(service.getVoc(list[currentRow].getNume()));
			}
		}
		
		return QVariant();
	};
	void setData(vector<Produs> list) {
		this->list = list;
		emit layoutChanged();
	};
	void setData(vector<Produs> list, string tip) {
		this->list = list;
		this->tip = tip;
		emit layoutChanged();
	};
};