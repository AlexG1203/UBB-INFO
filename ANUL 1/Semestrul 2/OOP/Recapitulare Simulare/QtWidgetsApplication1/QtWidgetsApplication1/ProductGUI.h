#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class ProductGUI : public QWidget {
public:
	ProductGUI() {
		initGUI();
        loadData();
        initConnect();
	}
private:
    QListWidget* lst = new QListWidget;
    QPushButton* btnExit = new QPushButton{ "&Exit" };
    QPushButton* btnAdd = new QPushButton{ "&Adauga" };
    QLineEdit* txtNume = new QLineEdit;
    QLineEdit* txtTip = new QLineEdit;
    QLineEdit* txtPret = new QLineEdit;

    void initConnect() {
        QObject::connect(btnExit, &QPushButton::clicked, [&]() {
            qDebug() << "Exit buton apasat";
            QMessageBox::information(nullptr, "Info", "Exit buton apasat");
            close();
            });
        QObject::connect(btnAdd, &QPushButton::clicked, [&]() {
            auto nume = txtNume->text();
            auto tip = txtTip->text();
            auto pret = txtPret->text();
            qDebug() << "Nume" << nume << "Tip" << tip << "Pret" << pret;
            loadData();
            });
    }

    void loadData() {
        lst->clear();
        vector<string> allProducts = { "prod1","prod2" ,"prod3" ,"prod4","prod11","prod12" ,"prod13" ,"prod14" };
        for (const auto& numeProd : allProducts) {
            lst->addItem(QString::fromStdString(numeProd));
        }
    }

	void initGUI() {

    QHBoxLayout* lyMain = new QHBoxLayout{};
    setLayout(lyMain);

    lyMain->addWidget(lst);

    auto stgLy = new QVBoxLayout;

    auto formLy = new QFormLayout;
    formLy->addRow("Nume", txtNume);
    formLy->addRow("Tip", txtTip);
    formLy->addRow("Pret", txtPret);
    stgLy->addLayout(formLy);

    auto lyBtn = new QHBoxLayout{};
    lyBtn->addWidget(btnAdd);
    lyBtn->addWidget(new QPushButton{ "&Sterge" });
    lyBtn->addWidget(new QPushButton{ "&Modifica" });
    lyBtn->addWidget(btnExit);
    stgLy->addLayout(lyBtn);

    lyMain->addLayout(stgLy);
	}
};