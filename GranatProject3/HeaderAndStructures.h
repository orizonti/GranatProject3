#pragma once
#include "QString"
#include "SFML\Graphics.hpp"
#include "qfile.h"
#include "QtXml\qxml.h"
#include "QtXml\qdom.h"
#include "QDebug"
#include "QSize"
#include "QPainterPath"
#include <iostream>
#include <qstring>
#include "QPolygon"
#include <Eigen/Dense>
#include <qstring>
#include <QDebug>
#include <QDir>
#include <math.h>
#include <qpoint.h>
#include <memory>
#include <QXmlStreamWriter>
#include <QFile>

#include <boost/graph/astar_search.hpp>
#include <boost/concept_check.hpp>
#include <iostream>
#include <map>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random.hpp>
#include <boost/random.hpp>


class DisplayInterface;
class TerrainObjectClass;

typedef QVector<TerrainObjectClass*> Terrains; 
typedef QPair<int, int> PairCoord;

enum Direction { Left = 0, Right = 1, Up = 2, Down = 3, UpLeft = 4, UpRight = 5, DownLeft = 6, DownRight = 7 };
enum TypeUnit   { MaceMap = 0, SpearMan};
enum TypeObject { House1  = 0, House2};

extern QString GameDir;
class EventControlInterface
{
public:
	virtual void KeyboardControl(sf::Event Key_event) = 0;
	virtual void MouseControl(sf::Event Mouse_event) = 0;

	friend void operator >> (sf::Event event, EventControlInterface& Interface);
};

class DrawContrainerInterface
{
public:
	friend void operator << (DisplayInterface& Display, DrawContrainerInterface& Int)
	{
		Int.Draw(Display);
	}
	virtual void Draw(DisplayInterface& Display) = 0;
};

extern sf::Font Font;


