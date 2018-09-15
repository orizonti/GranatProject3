#pragma once
#include "HeaderAndStructures.h"
#include <QWidget>
#include <QTimer>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <qdebug.h>
#include <QWidget>
#include <QTimer>

#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
#include <X11/Xlib.h>
#endif

class GameDisplayEngine;

class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:

	QSFMLCanvas(QWidget* Parent);

	virtual ~QSFMLCanvas();
	bool _initialized;

	//==========================================================
	bool pollEvent(sf::Event& ev);
	sf::Keyboard::Key QtKeyToSFML(int QtKey);
	void pushEvent(sf::Event & ev);
	std::vector<sf::Event> SfEvents;

	void ConvertMousePos(sf::Event& event);
	//==========================================================
	
	void DrawGame(GameDisplayEngine& Game);

	//==========================================================
	virtual void showEvent(QShowEvent*);
	virtual void paintEvent(QPaintEvent*);
	//==========================================================

	//==========================================================
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void wheelEvent(QWheelEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void resizeEvent(QResizeEvent *event);
	//==========================================================
	void KeyboardControl(sf::Event Keyboard);




	 sf::View* Camera;
	 float Scale = 1;
	 QSize WindowSize;
	 QSize CellSize;
	 QPair<int,int> OffsetCamera; //POSITION OF CAMERA VIEW ON MAP IN CELL COUNT

	bool   myInitialized;
};


