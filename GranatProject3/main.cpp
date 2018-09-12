#include <QtWidgets/QApplication>
#include <QDebug>
#include <QDir>
#include "SFML\Graphics.hpp"
#include <Eigen/Dense>
#include <iostream>
#include <qstring>
#include "QPainterPath"
#include "QPolygon"
#include "qfile.h"
#include "QtXml\qxml.h"
#include "QtXml\qdom.h"
#include "GameDisplayEngine.h"
#include "QSFMLCanvas.h"
#include "qframe.h"

QSize GameCoord::CellSize = QSize(512, 256);
QString GameDir = "";


int main(int argc, char *argv[])
{

	//QApplication App(argc, argv);

	//// Create the main frame
	//QWidget* MainFrame = new QWidget;
	//MainFrame->setWindowTitle("Qt SFML");
	//MainFrame->resize(400, 400);
	//MainFrame->show();

	////	// Create a SFML view inside the main frame
	//	MyCanvas* SFMLView = new MyCanvas(MainFrame, QPoint(20, 20), QSize(360, 360));
	//	SFMLView->show();

	//return App.exec();



		//QCoreApplication a(argc, argv);

		GameDir = qgetenv("GAME_WORK_DIR");

		GameDisplayEngine GameEngine;
						  GameEngine.RunGame();
		                 

		return 0;
		//return a.exec();
}

