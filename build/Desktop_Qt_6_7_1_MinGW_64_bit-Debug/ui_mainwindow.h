/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *ownerNameEdit;
    QLineEdit *carModelEdit;
    QLineEdit *plateNumberEdit;
    QPushButton *registerButton;
    QListWidget *carListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 50, 160, 214));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ownerNameEdit = new QLineEdit(verticalLayoutWidget);
        ownerNameEdit->setObjectName("ownerNameEdit");

        verticalLayout->addWidget(ownerNameEdit);

        carModelEdit = new QLineEdit(verticalLayoutWidget);
        carModelEdit->setObjectName("carModelEdit");

        verticalLayout->addWidget(carModelEdit);

        plateNumberEdit = new QLineEdit(verticalLayoutWidget);
        plateNumberEdit->setObjectName("plateNumberEdit");

        verticalLayout->addWidget(plateNumberEdit);

        registerButton = new QPushButton(verticalLayoutWidget);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);

        carListWidget = new QListWidget(verticalLayoutWidget);
        carListWidget->setObjectName("carListWidget");

        verticalLayout->addWidget(carListWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ownerNameEdit->setText(QString());
        ownerNameEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Owner", nullptr));
        carModelEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Car Model", nullptr));
        plateNumberEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        registerButton->setText(QCoreApplication::translate("MainWindow", "Add Car", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
