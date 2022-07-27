

#include "Vertex.h"
#include <iostream>

Vertex::Vertex() {
	id = 0;
	value = "";
}

Vertex::Vertex(short a, string b) : id(a), value(b) {  }

Vertex::~Vertex() {  }


string Vertex::getValue() {
	return value;
}

short Vertex::getId() {
	return id;
}

void Vertex::setValue(string newVal) {
	value = newVal;
}

void Vertex::setId(short newId) {
	id = newId;
}

void Vertex::printVertex() {
	std::cout << "Id: " << id << "\nValue: " << value << endl;
}
