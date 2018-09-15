#pragma once
#include "HeaderAndStructures.h"
#include "MapObjects.h"
#include "AnimationSetContainer.h"

class DisplayInterface;
class GameViewUnitContainer : public DrawContrainerInterface
{
public:
	GameViewUnitContainer();
	~GameViewUnitContainer();
	std::shared_ptr<MapUnitObject> CurrentUnit = NULL;
	QMap<QPair<int,int>,std::shared_ptr<MapUnitObject>> UnitOnMapContainer;

	void Draw(DisplayInterface& Display);

	void MoveUnits();


 void MapCellPressed(int x,int y);
};