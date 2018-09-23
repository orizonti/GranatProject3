#pragma once
#include "MapGraphInterface.h"
#include "HeaderAndStructures.h"
#include "GameCoord.h"


typedef std::list<Vertex> StepsList;

class PathFinding
{
public:
	void FindPath(GameCoord Destination);
    void FindPath(int sourceX, int sourceY, int targetX, int targetY);
private:
	QList<GameCoord>                   RoutePoints;
	std::shared_ptr<MapGraphInterface> Map;
	std::shared_ptr<MapGraphInterface> UnitsOnMap;
};

class GameFieldHeuristic : public boost::astar_heuristic<MapGraphInterface, int>
{
public:

	GameFieldHeuristic()
	{

	}

	GameFieldHeuristic(const MapGraphInterface& gameField, Vertex goal)
		: mGameField(&gameField)
	{
		std::pair<int, int> goalPosition = getCoordinates(goal, gameField);
		mGoalX = goalPosition.first;
		mGoalY = goalPosition.second;
	};

	int operator()(Vertex v) {
		std::pair<int, int> position = getCoordinates(v, *mGameField);
		int dx = mGoalX - position.first;
		int dy = mGoalY - position.second;
		int result = dx * dx + dy * dy;
		return result;
	}

private:

	int mGoalX;
	int mGoalY;
	const MapGraphInterface* mGameField;
};




struct FoundGoal {};
struct AstarGoalVisitor : public boost::default_astar_visitor {

	AstarGoalVisitor(Vertex goal)
		: mGoal(goal)
	{
	}

	void examine_vertex(Vertex u, const MapGraphInterface&)
	{
		if (u == mGoal) {
			throw FoundGoal();
		}
	}

private:
	Vertex mGoal;
};