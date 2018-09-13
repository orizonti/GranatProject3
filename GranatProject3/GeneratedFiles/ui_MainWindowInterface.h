/********************************************************************************
** Form generated from reading UI file 'MainWindowInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWINTERFACE_H
#define UI_MAINWINDOWINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowInterface
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *ButShowNormal;
    QGroupBox *groupBox;

    void setupUi(QWidget *MainWindowInterface)
    {
        if (MainWindowInterface->objectName().isEmpty())
            MainWindowInterface->setObjectName(QStringLiteral("MainWindowInterface"));
        MainWindowInterface->resize(1233, 936);
        gridLayout_2 = new QGridLayout(MainWindowInterface);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        ButShowNormal = new QPushButton(MainWindowInterface);
        ButShowNormal->setObjectName(QStringLiteral("ButShowNormal"));

        gridLayout_2->addWidget(ButShowNormal, 1, 0, 1, 1);

        groupBox = new QGroupBox(MainWindowInterface);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QLatin1String("QGroupBox\n"
"{\n"
"border: 2px solid line black;\n"
"}"));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(MainWindowInterface);

        QMetaObject::connectSlotsByName(MainWindowInterface);
    } // setupUi

    void retranslateUi(QWidget *MainWindowInterface)
    {
        MainWindowInterface->setWindowTitle(QApplication::translate("MainWindowInterface", "MainWindowInterface", Q_NULLPTR));
        ButShowNormal->setText(QApplication::translate("MainWindowInterface", "ShowNormal", Q_NULLPTR));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowInterface: public Ui_MainWindowInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWINTERFACE_H
