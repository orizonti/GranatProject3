#pragma once

#include <QWidget>
#include "ui_MainWindowInterface.h"
#include <QKeyEvent>
#include <qdebug.h>
#include "GameDisplayEngine.h"
#include "QSFMLCanvas.h"
#include "TerrainObjectClass.h"
#include "MapObjects.h"

class DisplayInterface
{
public:

virtual	void operator<<(std::shared_ptr<sf::Drawable> DrawObject) = 0;


virtual	void operator<<(QVector<std::shared_ptr<sf::Drawable>>& DrawObjects) = 0;
virtual	void operator<<(MapObject& DrawObject) = 0;

virtual	void operator<<(QList<std::shared_ptr<MapUnitObject>>& DrawObject) = 0;

virtual	void DrawObject(std::shared_ptr<sf::Drawable> DrawObject) = 0;
virtual	void DrawGroupObject(QVector<std::shared_ptr<sf::Drawable>>& DrawObjects) = 0;

virtual void DisplayMapObjectData(MapObject& DrawObject) = 0;
virtual void DisplayTerrainData(TerrainObjectClass* DrawObjects) = 0;

virtual	void operator<<(TerrainObjectClass* DrawObject) = 0;
virtual	void operator<<(QVector<TerrainObjectClass*>& DrawObject) = 0;

virtual	void ClearDisplay() = 0;
virtual	void Draw() = 0;
virtual bool pollEvent(sf::Event& event) = 0;
};


class MainWindowInterface : public QWidget, public DisplayInterface
{
	Q_OBJECT

public:
	MainWindowInterface(QWidget *parent = Q_NULLPTR);
	~MainWindowInterface();
	void keyPressEvent(QKeyEvent *event);
	QSFMLCanvas* Canvas;

	void operator<<(std::shared_ptr<sf::Drawable> DrawObject);
	void DrawObject(std::shared_ptr<sf::Drawable> DrawObject);

	void operator<<(QVector<std::shared_ptr<sf::Drawable>>& DrawObjects);
	void DrawGroupObject(QVector<std::shared_ptr<sf::Drawable>>& DrawObjects);

	void operator<<(MapObject& DrawObject);
	void operator<<(TerrainObjectClass* DrawObject);

	void operator<<(QList<std::shared_ptr<MapUnitObject>>& DrawObject);
	void operator<<(QVector<TerrainObjectClass*>& DrawObject);

	void ClearDisplay();
	void Draw();

    bool pollEvent(sf::Event& event);
	void DisplayMapObjectData(MapObject& DrawObject);
	void DisplayTerrainData(TerrainObjectClass* DrawObjects);

	public slots:
	void ShowNormalSlot();

private:
	Ui::MainWindowInterface ui;
};
