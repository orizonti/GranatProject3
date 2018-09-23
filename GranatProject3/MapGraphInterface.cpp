#include "MapGraphInterface.h"

const int OutEdgeIteratorImpl::sShiftsX[8] = {
	-1, 0, 1,
	-1,    1,
	-1, 0, 1 };
const int OutEdgeIteratorImpl::sShiftsY[8] = {
	1,  1,  1,
	0,      0,
	-1, -1, -1 };

bool MapGraphInterface::canPass(int x, int y) const
{

	bool Pass;
	if (x >= MapRegion[0].size() || y >= MapRegion.size())
		Pass = false;

	if (x < 0 || y <0)
		return false;

	if (MapRegion[x][y] == 0)
		Pass = true;
	if (MapRegion[x][y] == 1)
		Pass = false;

	qDebug() << "Can pass - " << x << y << Pass;
	return Pass;
}

int MapGraphInterface::getWidth() const
{
	return MapRegion[0].size() - 1;
}

int MapGraphInterface::getHeight() const
{
	return MapRegion.size() - 1;
}

std::pair<int, int> getCoordinates(const Vertex position, const MapGraphInterface& graph)
{
	return std::make_pair(position % graph.getWidth(), position / graph.getWidth());
}

Vertex getVertex(int x, int y, const MapGraphInterface& graph)
{
	return x + y * graph.getWidth();
}


VerticesSizeType num_vertices(const MapGraphInterface& graph)
{
	return graph.getWidth() * graph.getHeight();
}




std::pair<VertexIterator, VertexIterator> vertices(const MapGraphInterface& graph)
{
	return std::make_pair(VertexIterator(graph, 0), VertexIterator(graph, num_vertices(graph)));
}
Vertex source(Edge edge, const MapGraphInterface &graph)
{
	return edge.first;
}

Vertex target(Edge edge, const MapGraphInterface &graph)
{
	return edge.second;
}

std::pair<OutEdgeIterator, OutEdgeIterator> out_edges(Vertex v, const MapGraphInterface& graph)
{
	return std::make_pair(OutEdgeIterator(graph, v, 0), OutEdgeIterator(graph, v, 8));
}
DegreeSizeType out_degree(Vertex v, const MapGraphInterface& graph)
{
	DegreeSizeType result = 0;

	std::pair<OutEdgeIterator, OutEdgeIterator> edges = out_edges(v, graph);
	for (OutEdgeIterator i = edges.first; i != edges.second; ++i) {
		++result;
	}

	return result;
}


bool VertexIteratorImpl::isValid()
{
	return (mField != NULL) && (mIndex < num_vertices(*mField)) && (mIndex >= 0);
}

EdgeWeightMapValueType get(EdgeWeightMapConst pMap, EdgeWeightMapKey pKey)
{
	return pMap[pKey];
}
EdgeWeightMapConst get(boost::edge_weight_t, const MapGraphInterface graph)
{
	return EdgeWeightMapConst();
}

EdgeWeightMapValueType get(boost::edge_weight_t tag, const MapGraphInterface& g, EdgeWeightMapKey e)
{
	return get(tag, g)[e];
}



VertexIndexMap get(boost::vertex_index_t, const MapGraphInterface & g)
{
	return VertexIndexMap(g);
};

VertexIndexMap::value_type get(VertexIndexMap map, VertexIndexMap::key_type vertex)
{
	return vertex; // VERTEX INDEX IT IS VERTEX THAT IS INT VALUE
};



VertexIteratorImpl::VertexIteratorImpl()
	: mField(NULL)
	, mIndex(0)
{

}

VertexIteratorImpl::VertexIteratorImpl(const MapGraphInterface& field, int index)
	: mField(&field)
	, mIndex(index)
{

}


bool VertexIteratorImpl::operator== (const VertexIteratorImpl& anotherIterator) const
{
	return mIndex == anotherIterator.mIndex;
}

void VertexIteratorImpl::operator++ ()
{
	if (isValid()) {
		++mIndex;
	}
}
Vertex VertexIteratorImpl::operator*() const
{
	return mIndex;
}

OutEdgeIteratorImpl::OutEdgeIteratorImpl()
	: mField(NULL)
	, mCellPosition(0)
	, mShift(0)
{

}

OutEdgeIteratorImpl::OutEdgeIteratorImpl(const MapGraphInterface& field, Vertex cellPosition, int index/* = 0*/)
	: mField(&field)
	, mCellPosition(cellPosition)
	, mShift(index)
{
	updateShift();
}

void OutEdgeIteratorImpl::operator++ ()
{
	++mShift;
	updateShift();
}

void OutEdgeIteratorImpl::updateShift()
{
	if (isValid()) {
		int x, y;
		std::tie(x, y) = getCoordinates(mCellPosition, *mField);
		int dx = sShiftsX[mShift];
		int dy = sShiftsY[mShift];
		if (!mField->canPass(x + dx, y + dy)) {
			++mShift;
			updateShift();
		}
	}
}

bool OutEdgeIteratorImpl::isValid()
{
	return (mField != NULL) && (mShift < 8) && (mShift >= 0);
}
Vertex OutEdgeIteratorImpl::getCurrentPosition() const
{
	return mCellPosition;
}

Vertex OutEdgeIteratorImpl::getTargetPosition() const
{
	return getCurrentPosition() + sShiftsX[mShift] + mField->getWidth() * sShiftsY[mShift];
}

Edge OutEdgeIteratorImpl::operator*() const
{
	return std::make_pair(getCurrentPosition(), getTargetPosition());
}

bool OutEdgeIteratorImpl::operator== (const OutEdgeIteratorImpl& other) const
{
	return mShift == other.mShift;
}

BOOST_CONCEPT_ASSERT((boost::VertexListGraphConcept<MapGraphInterface>));
BOOST_CONCEPT_ASSERT((boost::IncidenceGraphConcept<MapGraphInterface>));

BOOST_CONCEPT_ASSERT((boost::ReadablePropertyMapConcept<EdgeWeightMap, Edge>));

BOOST_CONCEPT_ASSERT((boost::ReadablePropertyGraphConcept<MapGraphInterface, Edge, boost::edge_weight_t>));