#ifndef GRAPH_H_
#define GRAPH_H_
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <string>

using namespace std;

class Graph{

public:
	Graph();
	virtual ~Graph();
	//add in one vertex; bool returns if it is added successfully.
	virtual bool addVertex(Vertex&)=0;
	//Bonus question: add in a set of vertices; bool returns true if it is added successfully
	virtual bool addVertices(Vertex*, unsigned int) = 0;
	//the edges that has connection with this vertex need to be removed;
	virtual bool removeVertex(Vertex&) = 0;
	//remove a edge; as a result, some node may remain as orphan.
	virtual bool addEdge(Edge&) = 0;
	//Bonus question : remove a set of edge; as a result, some node may remain as orphan.
	virtual bool addEdges(Edge*, unsigned int) = 0;
	// remove the edge
	virtual bool removeEdge(Edge&)=0;
	// remove edges
	virtual bool removeEdges(Edge*, unsigned int) = 0;
	// return bool if a vertex exists in a graph;
	virtual bool searchVertex(const Vertex&) const = 0;
	// return bool if a Edge exists in a graph;
	virtual bool searchEdge(const Edge&) const =0;
	// display the path that contains the vertex;
	virtual void display(Vertex&) const = 0;
	// display the path that contains the edge;
	virtual void display(Edge&) const = 0;
	// display the whole graph with your own defined format
	virtual void display() const = 0;
	// convert the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
	// define your own format of a string representation of the graph.
	virtual void toString() const = 0;
	//remove all the vertices and edges;
	virtual bool clean() = 0;
};




#endif /* GRAPH_H_ */
