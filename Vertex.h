


#ifndef VERTEX_H
#define VERTEX_H
#include <string>
using namespace std;


class Vertex
{

public:
	Vertex();
	Vertex(short, string);
	~Vertex();
	string getValue();
	short getId();
	void setValue(string);
	void setId(short);
	void printVertex();

private:
	short id;
	string value;

};

#endif //VERTEX_H
