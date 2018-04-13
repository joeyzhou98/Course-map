#include "Vertex.h"
#include <iostream>

using namespace std;

Vertex::Vertex(): id(0), value(0), description("no description") {}

Vertex::Vertex(int i, double j, string d): id(i), value(j), description(d) {}

int Vertex::getId() const {return id;}

double Vertex::getValue() const {return value;}

string Vertex::getDescription() const {return description;}

void Vertex::print() const
{
	cout << description << " (" << value << " credits)" << endl;
}
