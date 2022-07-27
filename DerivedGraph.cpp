

#include "DerivedGraph.h"
#include <iostream>
#include <string>
using namespace std;


//constructors and destructor
DerivedGraph::DerivedGraph() {

}

DerivedGraph::~DerivedGraph() {
	
}

DerivedGraph::DerivedGraph(const DerivedGraph& original) {
	numVert = original.numVert;
	numEdge = original.numEdge;
	for (int i = 0; i < capacity; i++) {
		E[i] = original.E[i];
		N[i] = original.N[i];
	}
}


//derived member functions
bool DerivedGraph::addVertex(Vertex& v) {

	if (numVert == capacity) return false;

	else {
		N[numVert] = v;
		numVert = numVert + 1;
		return true;
	}
}

bool DerivedGraph::addVertices(Vertex* vArray, int size) {
	
	if ((numVert + size) > capacity)	return false;

	else {
		for (int i = 0; i < size; i++) {
			N[numVert + i] = vArray[i];
		}
		numVert = numVert + size;
		return true;
	}
}

bool DerivedGraph::removeVertex(Vertex& vert) {
	//check if the vertex exists in the graph and at what position
	int exists = (*this).searchVertex(vert);		

	//if it doesn't exist, it can't be removed
	if (exists == -1)return false;					

	//if it does exist...
	else {	

		//remove the vertex from vertex array
		for (int b = exists; b < (numVert - 1); b++) {	
			N[b] = N[b + 1];
		}
		numVert--;
				
		//remove the edges that have this vertex from edge array
		for (int c = numEdge - 1; c >= 0; c--) {			
			if ((E[c].getStart() == &vert) || (E[c].getEnd() == &vert)) {
				(*this).remove(E[c]);
			}
		}
		return true;
	}
}

bool DerivedGraph::addEdge(Edge& e) {
	if (numEdge == capacity) { return false; }
	else {
		E[numEdge] = e;
		numEdge++;
		return true;
	}
}

bool DerivedGraph::remove(Edge& e) {
	
	//find where the edge is in the array
	int index = (*this).searchEdge(e);

	//if the edge doesn't exist in array, can't remove it
	if (index == -1)return false;	

	//if the edge exists in the array, remove it
	else {
		for (int i = index; i < (numEdge - 1); i++) {
			E[i] = E[i + 1];
		}
		numEdge--;
		return true;
	}
}

int DerivedGraph::searchVertex(Vertex& v) {
	for (int a = 0; a < numVert; a++) {
		if ((N[a].getId() == v.getId()) && (N[a].getValue() == v.getValue())) {
			return a;
		}
	}
	return -1;
}

int DerivedGraph::searchEdge(Edge& e) {
	for (int i = 0; i < numEdge; i++) {
		if ((E[i].getWeight()==e.getWeight()) && (E[i].getStart()==e.getStart()) && (E[i].getEnd() == e.getEnd())) {
			return i;
		}
	}
	return -1;
}

void DerivedGraph::toString() const {
	cout << "\nVERTICES\n";
	for (int i = 0; i < numVert; i++) {
		cout << N[i].getValue() << ", ";
	}
	cout << "\nEDGES\n";
	for (int i = 0; i < numEdge; i++) {
		cout << "(w=" << E[i].getWeight() << " , " << (E[i].getStart())->getId() 
			<< " , " << (E[i].getEnd())->getId() << ")\n";
	}
	
}

bool DerivedGraph::clean() {
	numVert = 0;
	numEdge = 0;
	return true;
}


	
