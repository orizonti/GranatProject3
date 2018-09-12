/********************************************************************************
** Form generated from reading UI file 'GranatProject3.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRANATPROJECT3_H
#define UI_GRANATPROJECT3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GranatProject3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GranatProject3Class)
    {
        if (GranatProject3Class->objectName().isEmpty())
            GranatProject3Class->setObjectName(QStringLiteral("GranatProject3Class"));
        GranatProject3Class->resize(600, 400);
        menuBar = new QMenuBar(GranatProject3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GranatProject3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GranatProject3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GranatProject3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(GranatProject3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GranatProject3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GranatProject3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GranatProject3Class->setStatusBar(statusBar);

        retranslateUi(GranatProject3Class);

        QMetaObject::connectSlotsByName(GranatProject3Class);
    } // setupUi

    void retranslateUi(QMainWindow *GranatProject3Class)
    {
        GranatProject3Class->setWindowTitle(QApplication::translate("GranatProject3Class", "GranatProject3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GranatProject3Class: public Ui_GranatProject3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRANATPROJECT3_H
