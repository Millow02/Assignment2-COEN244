


#include "Graph.h"


class DerivedGraph :  public Graph
{
private:

public:
	//constructor & destructor
	DerivedGraph();
	DerivedGraph(const DerivedGraph&);
	~DerivedGraph();

	//virtual member functions
	virtual bool addVertex(Vertex& v);
	virtual bool addVertices(Vertex* vArray, int size);
	virtual bool removeVertex(Vertex& vert);	
	virtual bool addEdge(Edge& e);
	virtual bool remove(Edge& e);
	virtual int searchVertex(Vertex& v);
	virtual int searchEdge(Edge& e);
	virtual void toString() const;
	virtual bool clean();

};
