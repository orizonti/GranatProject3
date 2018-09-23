#include "PathFinding.h"

void PathFinding::FindPath(GameCoord Destination)
{
	qDebug() << "==============================";
}

void PathFinding::FindPath(int sourceX, int sourceY, int targetX, int targetY)
{
	MapGraphInterface& graph = *Map + *UnitsOnMap;

	qDebug() << "==============================";
	qDebug() << "FIND PATH FROM - " << sourceX << sourceY << "TO - " << targetX << targetY;
	Vertex source = getVertex(sourceX, sourceY, graph);
	Vertex destination = getVertex(targetX, targetY, graph);

	std::vector<Vertex> predecessor(num_vertices(graph));
	std::vector<EdgeWeightMapValueType> dist(num_vertices(graph));
	StepsList result;
	try
	{
		boost::astar_search(graph, source,
			GameFieldHeuristic(graph, destination),
			boost::visitor(AstarGoalVisitor(destination)).predecessor_map(&predecessor[0]).distance_map(&dist[0])
		);
	}
	catch (FoundGoal f)
	{
		for (int i = destination; i != source; i = predecessor[i])
		{
			std::pair<int, int> coordinates = getCoordinates(i, graph);
			qDebug() << "Vertex - " << coordinates.first << coordinates.second << "Number - " << i;
		}
	}
	qDebug() << "==============================";
}
