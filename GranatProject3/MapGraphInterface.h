#pragma once
#include "HeaderAndStructures.h"
class VertexIteratorImpl;
class OutEdgeIteratorImpl;

struct game_field_traversal_catetory;

class MapGraphInterface
{
public:
	typedef int vertex_descriptor;
	typedef int degree_size_type;
	typedef int vertices_size_type;


	typedef std::pair <vertex_descriptor, vertex_descriptor> edge_descriptor;
	typedef boost::undirected_tag                            directed_category;
	typedef boost::disallow_parallel_edge_tag                edge_parallel_category;
	typedef game_field_traversal_catetory                    traversal_category;


	typedef void in_edge_iterator;
	typedef void edge_iterator;
	typedef void edges_size_type;

	typedef VertexIteratorImpl  vertex_iterator;
	typedef OutEdgeIteratorImpl out_edge_iterator;

	bool canPass(int x, int y) const;
	int getWidth() const;
	int getHeight() const;

	MapGraphInterface& operator+(MapGraphInterface& MapGraph)
	{
		return *this;
	}

	virtual void GetGlobalMapRegion(QPair<int, int> BLPosition)
	{
		qDebug() << BLPosition;
	}
	MapGraphInterface()
	{
		            //  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
		MapRegion = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 0
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 1
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 2
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 3
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 4
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 5
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 6
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 7
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 8
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 9
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 10
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 11
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 12
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 13
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 14
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 15
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 16
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 17
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 18
					  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // 19
		            };
	}
	

protected:
	QVector<QVector<double>> MapRegion;
};


typedef boost::graph_traits<MapGraphInterface>::vertex_descriptor  Vertex;
typedef boost::graph_traits<MapGraphInterface>::edge_descriptor    Edge;
typedef boost::graph_traits<MapGraphInterface>::vertex_iterator    VertexIterator;
typedef boost::graph_traits<MapGraphInterface>::out_edge_iterator  OutEdgeIterator;
typedef boost::graph_traits<MapGraphInterface>::degree_size_type   DegreeSizeType;
typedef boost::graph_traits<MapGraphInterface>::vertices_size_type VerticesSizeType;


class VertexIteratorImpl : public boost::forward_iterator_helper<VertexIteratorImpl, Vertex, std::ptrdiff_t, Vertex*, Vertex>
{
public:
	VertexIteratorImpl();
	VertexIteratorImpl(const MapGraphInterface& field, int index);

	void operator++ ();
	bool operator== (const VertexIteratorImpl& anotherIterator) const;
	Vertex operator*() const;

private:
	bool isValid();

	int mIndex;
	const MapGraphInterface* mField;
};
class OutEdgeIteratorImpl : public boost::forward_iterator_helper<OutEdgeIterator, Edge, std::ptrdiff_t, Edge*, Edge>
{
public:

	OutEdgeIteratorImpl(const MapGraphInterface& field, Vertex cellPosition, int index = 0);
	OutEdgeIteratorImpl();

	Edge operator*() const;
	void operator++ ();
	bool operator== (const OutEdgeIterator& other) const;

private:

	Vertex getCurrentPosition() const;
	Vertex getTargetPosition() const;
	void updateShift();
	bool isValid();

	int mShift;
	Vertex mCellPosition;
	const MapGraphInterface* mField;

	static const int sShiftsX[8];
	static const int sShiftsY[8];
};

struct EdgeWeightMap 
{
	typedef double value_type;
	typedef value_type reference;
	typedef Edge key_type;
	typedef boost::readable_property_map_tag category;

	reference operator[](key_type e) const 
	{
		return 1;
	}
};

namespace boost
{
	template<>
	struct property_map< MapGraphInterface, edge_weight_t > 
	{
		typedef EdgeWeightMap type;
		typedef EdgeWeightMap const_type;
	};

}

typedef boost::property_map<MapGraphInterface, boost::edge_weight_t>::const_type EdgeWeightMapConst;
typedef boost::property_traits<EdgeWeightMapConst>::reference                    EdgeWeightMapValueType;
typedef boost::property_traits<EdgeWeightMapConst>::key_type                     EdgeWeightMapKey;



namespace boost 
{
	template <> struct vertex_property_type<MapGraphInterface>
	{
		typedef boost::graph_traits<MapGraphInterface>::vertex_descriptor type;
	};

}


class VertexIndexMap //maps vertex to index
{
public:
	typedef boost::readable_property_map_tag     category;
	typedef MapGraphInterface::vertex_descriptor key_type;

	typedef int           value_type;
	typedef value_type    reference;

	VertexIndexMap(const MapGraphInterface& g) : _g(&g) {}

	const MapGraphInterface * _g;
};

namespace boost 
{
	template<>
	struct property_map<MapGraphInterface, vertex_index_t > 
	{
		typedef VertexIndexMap const_type;
	};


} //namespace boost




EdgeWeightMapConst     get(boost::edge_weight_t, const MapGraphInterface graph);     //GET WEIGHT MAP TO MAP GRAPH
EdgeWeightMapValueType get(EdgeWeightMapConst pMap, EdgeWeightMapKey pKey);          //GET WEIGHT TO EDGE THAT PASS BY pKey

VertexIndexMap             get(boost::vertex_index_t, const MapGraphInterface & g);  //GET INDEX MAP TO MAP GRAPH
VertexIndexMap::value_type get(VertexIndexMap map, VertexIndexMap::key_type vertex);  //GET INDEX TO VERTEX

Vertex target(Edge edge, const MapGraphInterface &graph); //GET END VERTEX TO edge
Vertex source(Edge edge, const MapGraphInterface &graph); //GET START VERTEX TO edge

DegreeSizeType                              out_degree(Vertex v, const MapGraphInterface& graph); //COUNT OF OUT EDGE OF VERTEX
std::pair<OutEdgeIterator, OutEdgeIterator> out_edges(Vertex v, const MapGraphInterface& graph);  //START AND END ITERATOR OF OUT EDGES
std::pair<VertexIterator, VertexIterator>   vertices(const MapGraphInterface& graph); // GET START VERTEX AND VERTEX AFTER END
VerticesSizeType                            num_vertices(const MapGraphInterface& graph); // VERTEX COUNT FOR GRAPH

Vertex              getVertex(int x, int y, const MapGraphInterface& graph);
std::pair<int, int> getCoordinates(const Vertex position, const MapGraphInterface& graph);


struct game_field_traversal_catetory:
	public boost::vertex_list_graph_tag,
	public boost::incidence_graph_tag
{
};




