#ifndef DAG_H_
#define DAG_H_
#include "Graph.h"
#include <vector>
#include <string>

using namespace std;

class DAG: public Graph{

public:
	DAG(); //does nothing
	virtual ~DAG(); //destroys all elements in vectors via clean()
	void fillRoot(vector<int>&) const; //fill argument vector with root vertex ids
	void fillLeaf(vector<int>&) const; //fill argument vector with leaf vertex ids
	bool checkCycle() const; //return true if a cycle was found in the graph
	void sortVertices(); //sort all vertices in ascending order of id in the vertex list
	void printAllPaths(int, int) const; //prints all paths from source id to destination id
	virtual bool addVertex(Vertex&); //add a pointer to the vertex at the end of the vertex list
	virtual bool addVertices(Vertex*, unsigned int); //add all vertices in the array to the vertex list
	virtual bool removeVertex(Vertex&); //remove vertex and any connecting edges
	virtual bool addEdge(Edge&); //add a pointer to the edge at the end of the edge list
	virtual bool addEdges(Edge*, unsigned int); //add all edges in the array to the edge list
	virtual bool removeEdge(Edge&); //remove edge
	virtual bool removeEdges(Edge*, unsigned int); //remove edges
	virtual bool searchVertex(const Vertex&) const; //search for same id vertex, returns true if found, false otherwise
	virtual bool searchEdge(const Edge&) const; //search for same start and ending id, returns true if found, false otherwise
	virtual void display(Vertex&) const; //display any and all paths containing this vertex
	virtual void display(Edge&) const; //display any and all paths containing this edge
	virtual void display() const; //print out all vertices and edges
	virtual void toString() const; //display any and all paths
	virtual bool clean(); //clears all elements in vectors
	bool operator ==(const DAG&) const; //checks for exact same vertices and edges in both graphs
	void operator =(const DAG&); //assigns argument graph to graph being called on
	DAG& operator ++(); //preincrement weight of all edges by one
	DAG operator ++(int); //postincrement weight of all edges by one
	DAG operator +(const DAG&) const; //return a graph that has all nodes and edges of argument and this
	bool operator >(const DAG&) const; //check sum of edges of the two graphs and returns a boolean
	friend ostream& operator <<(ostream&, const DAG&); //prints out the graph

private:
	std::vector<Vertex*> vertexList;
	std::vector<Edge*> edgeList;
	void checkCycleRecur(int, vector<int>&, int&, bool&) const; //recursive function used for finding if there is a cycle in a path
	void printAllPathsRecur(int, int, int[], int&) const;
	void printAllPathsRecur(int, int, int[], int&, int, int) const; //recursive functions used for finding all paths and
	// can only be accessed with printAllPaths, any display vertex or edge function or toString

};




#endif /* DAG_H_ */
