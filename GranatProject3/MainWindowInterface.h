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
virtual void GetNextEvent();
virtual QPair<float, float> ConvertMousePos();
};


class MainWindowInterface : public QWidget, public DisplayInterface
{
	Q_OBJECT

public:
	MainWindowInterface(QWidget *parent = Q_NULLPTR);
	~MainWindowInterface();


//				double x_pos_real;
//				double y_pos_real;

// x_pos_real = double(event.mouseMove.x - Window->size().width() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.first;
// y_pos_real = double(event.mouseMove.y - Window->size().height() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.second;

// x_pos_real = double(event.mouseButton.x - Window->size().width() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.first;
// y_pos_real = double(event.mouseButton.y - Window->size().height() / 2) / (Window->CellSize.height()*Window->Scale) - Window->OffsetCamera.second;
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

	void DisplayMapObjectData(MapObject& DrawObject);
	void DisplayTerrainData(TerrainObjectClass* DrawObjects);

	public slots:
	void ShowNormalSlot();

private:
	Ui::MainWindowInterface ui;
};
