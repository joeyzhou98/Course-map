#include "Edge.h"
#include <iostream>

using namespace std;

Edge::Edge(): id(0), start(0), end(0), weight(0.0) {}

Edge::Edge(int i, int s, int e, double w): id(i), start(s), end(e), weight(w) {}

int Edge::getStart() const {return start;}

int Edge::getEnd() const {return end;}

int Edge::getId() const {return id;}

double Edge::getWeight() const {return weight;}

void Edge::setWeight(const double w) {weight = w;}

void Edge::print() const
{
	cout << "Edge e" << id << " goes from v" << start << " to v" << end << " and its weight is " << weight << endl;
}
