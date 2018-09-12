#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GranatProject3.h"

class GranatProject3 : public QMainWindow
{
	Q_OBJECT

public:
	GranatProject3(QWidget *parent = Q_NULLPTR);

private:
	Ui::GranatProject3Class ui;
};
