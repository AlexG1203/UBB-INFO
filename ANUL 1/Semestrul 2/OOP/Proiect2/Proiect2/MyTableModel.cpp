#include "MyTableModel.h"
#pragma once

int TableViewModel::rowCount(const QModelIndex&) const {
	return static_cast<int>(serv.getAllService().size());
}

int TableViewModel::columnCount(const QModelIndex&) const {
	return 4;
}

QVariant TableViewModel::data(const QModelIndex& parent, int role) const {
	const int row = parent.row();
	const int column = parent.column();

	if (role == Qt::BackgroundRole) {
		auto student = this->serv.getAllService()[parent.row()];
		if (student.getFacultate().compare("mate") == 0) {
			return QBrush(Qt::magenta);
		}
		if (student.getFacultate().compare("info") == 0) {
			return QBrush(Qt::blue);
		}
		if (student.getFacultate().compare("mate-info") == 0) {
			return QBrush(Qt::lightGray);
		}
		if (student.getFacultate().compare("ai") == 0) {
			return QBrush(Qt::green);
		}
	}

	if (role == Qt::DisplayRole) {
		auto student = serv.getAllService().at(row);
		if (column == 0) {
			return QString::number(student.getMatricol());
		}
		else if (column == 1) {
			return QString::fromStdString(student.getNume());
		}
		else if (column == 2) {
			return QString::fromStdString(student.getFacultate());
		}
		else if (column == 3) {
			return QString::number(student.getVarsta());
		}
	}

	return QVariant{};
}

QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return tr("NrMatricol");
			case 1:
				return tr("Nume");
			case 2:
				return tr("Facultate");
			case 3:
				return tr("Varsta");
			default:
				return QString("");
			}

		}
	}

	return QVariant{};
}

void TableViewModel::setSongs() {
	emit layoutChanged();
}

void TableViewModel::setNumber(int number) {
	this->nr = number;
}