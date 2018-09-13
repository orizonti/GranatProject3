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
#include "MainWindowInterface.h"

QSize GameCoord::CellSize = QSize(512, 256);
QString GameDir = "";


int main(int argc, char *argv[])
{

	QApplication App(argc, argv);

	//// Create the main frame

	MainWindowInterface Interface;



		GameDir = qgetenv("GAME_WORK_DIR");

		GameDisplayEngine GameEngine;
		GameEngine.SetWindow(&Interface);
		Interface.showFullScreen();
						  //GameEngine.RunGame();
		                 

		//return 0;
	return App.exec();
}

