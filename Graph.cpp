

#include "Graph.h"


Graph::Graph(): numEdge(0), numVert(0) {
	N = new Vertex[capacity];
	E = new Edge[capacity];
}

Graph::~Graph() {
	delete[] N;
	delete[] E;
}
