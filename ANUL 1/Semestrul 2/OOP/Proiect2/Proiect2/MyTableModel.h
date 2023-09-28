#pragma once
#include "Domain.h"
#include "Service.h"
#include <QAbstractTableModel>
#include <QModelIndex>
#include <qbrush.h>

class TableViewModel : public QAbstractTableModel {
private:
	Service& serv;
	int nr;
public:
	TableViewModel(Service& srv, int nr) : serv{ srv }, nr{ nr } {};

	int rowCount(const QModelIndex& parent) const override;

	int columnCount(const QModelIndex& parent) const override;

	QVariant data(const QModelIndex& index, int role) const override;

	QVariant headerData(int section, Qt::Orientation, int role) const override;

	void setSongs();

	Qt::ItemFlags flags(const QModelIndex&) const override {
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
	}

	void setNumber(int nr);
};