#pragma once
#include "HeaderAndStructures.h"
#include <QWidget>
#include <QTimer>
class QSFMLCanvas : public QWidget, public sf::RenderWindow
{
public:

	QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 0);

	virtual ~QSFMLCanvas();

private:

	virtual void OnInit() = 0;

	virtual void OnUpdate() = 0;

	virtual QPaintEngine* paintEngine() const;

	virtual void showEvent(QShowEvent*);

	virtual void paintEvent(QPaintEvent*);

	QTimer myTimer;
	bool   myInitialized;
};


class MyCanvas : public QSFMLCanvas
{
public:

	MyCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size) :
		QSFMLCanvas(Parent, Position, Size)
	{

	}

private:

	void OnInit()
	{
		// Load the image
		myImage.loadFromFile("E:/WorkDir/Heights.png");
		// Setup the sprite
		mySprite.setTexture(myImage);
	}

	void OnUpdate()
	{
		// Clear screen
		clear(sf::Color(0, 128, 0));

		// Rotate the sprite
		//mySprite.rotate(getFrameTime() * 100.f);

		// Draw it
		draw(mySprite);
	}

	sf::Texture  myImage;
	sf::Sprite mySprite;
};