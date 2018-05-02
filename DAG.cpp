#include <typeinfo>
#include "DAG.h"
#include "Vertex.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

DAG::DAG(){}

DAG::~DAG(){clean();} //clears all elements in vectors

void DAG::fillRoot(vector<int> &root) const //fills argument with root vertex ids
{
	for (unsigned int i = 0; i<vertexList.size(); i++)
	{
		bool temp = true;
		for (unsigned int j = 0; j<edgeList.size(); j++)
		{
			if (edgeList[j]->getEnd() == vertexList[i]->getId())
			{
				temp = false;
				break;
			}
		}
		if (temp)
			root.push_back(vertexList[i]->getId());
	}
}

void DAG::fillLeaf(vector<int> &leaf) const //fills argument with leaf vertex ids
{
	for (unsigned int i = 0; i<vertexList.size(); i++)
	{
		bool temp = true;
		for (unsigned int j = 0; j<edgeList.size(); j++)
		{
			if (edgeList[j]->getStart() == vertexList[i]->getId())
			{
				temp = false;
				break;
			}
		}
		if (temp)
			leaf.push_back(vertexList[i]->getId());
	}
}

bool DAG::checkCycle() const //checks cycle using checkCycleRecur
{
	vector<int> visited;
	int visitedIndex = 0;
	vector<int> root;
	fillRoot(root);
	bool temp = false; //will be switched to true if cycle was found
	for (unsigned int i = 0; i<root.size(); i++) //loops through all root vertices
	{
		checkCycleRecur(root[i], visited, visitedIndex, temp);
	}
	return temp;
}

void DAG::checkCycleRecur(int s, vector<int> &visited, int &visitedIndex, bool &temp) const
{
	if (!temp) //allows to skip recursion if a cycle was found
	{
		for (unsigned int i = 0; i < visited.size(); i++)
			if (visited[i] == s) //if new source id was already visited which means there is a cycle
				temp = true;
		visited.push_back(s); //else add source id to visited
		visitedIndex++;
		vector<int> adj; //create adjacency vector for current source vertex
		for (unsigned int i = 0; i<edgeList.size(); i++)
		{
			if (edgeList[i]->getStart() == s)
			adj.push_back(edgeList[i]->getEnd());
		}
		for (unsigned int i = 0; i<adj.size(); ++i) //call this recursive function on new "source" vertex id
		{
			checkCycleRecur(adj[i], visited, visitedIndex, temp);
		}
		visited.pop_back(); //if reach dead end, decrement path and delete this id from visited vector
		visitedIndex--;
	}
}

bool compare(Vertex* v1, Vertex* v2){return ((v1->getId())<(v2->getId()));} //function for sort

void DAG::sortVertices()
{
	if (vertexList.size() != 0)
		sort(vertexList.begin(), vertexList.end(), compare); //sorts vertices by ascending order according to id
}

void DAG::printAllPaths(int s, int d) const //prints all paths from root to leaf
{
	int* path = new int[vertexList.size()];
	int pathIndex = 0;
	printAllPathsRecur(s, d, path, pathIndex);
}

void DAG::printAllPathsRecur(int s, int d, int path[], int &pathIndex) const
{
	path[pathIndex] = s; //add source id to path
	pathIndex++; //increment path
	if (s == d) //if the source id corresponds to destination id, then print out path
	{
	    for (int i = 0; i<pathIndex; i++)
	        cout << "v" << path[i] << " ";
	    cout << endl;
	}
	else //else go through all adjacent vertices
	{
		vector<int> adj; //create adjacency vector for current source vertex
		for (unsigned int i = 0; i<edgeList.size(); i++)
		{
			if (edgeList[i]->getStart() == s)
				adj.push_back(edgeList[i]->getEnd());
		}
	    for (unsigned int i = 0; i<adj.size(); ++i) //call this recursive function on new "source" vertex id
	    	printAllPathsRecur(adj[i], d, path, pathIndex);
	}
	pathIndex--; //if reach dead end, decrement path
}

void DAG::printAllPathsRecur(int s, int d, int path[], int &pathIndex, int sNode, int eNode) const
{
	path[pathIndex] = s; //add source id to path
	pathIndex++; //increment path
	if (s == d) //if the source id corresponds to destination id
	{
		for (int j = 0; j < pathIndex - 1; j++) //and by looping through the path
		{
			if (path[j] == sNode && path[j+1] == eNode) //if in the path, the id and next id corresponds to the edge's
			{
				for (int i = 0; i<pathIndex; i++) //print out path
				cout << "v" << path[i] << " ";
				cout << endl;
			}
		}
	}
	else //else go through all adjacent vertices
	{
		vector<int> adj; //create adjacency vector for current source vertex
		for (unsigned int i = 0; i<edgeList.size(); i++)
		{
			if (edgeList[i]->getStart() == s)
				adj.push_back(edgeList[i]->getEnd());
		}
	    for (unsigned int i = 0; i<adj.size(); ++i) //call this recursive function on new "source" vertex id
	    	printAllPathsRecur(adj[i], d, path, pathIndex, sNode, eNode);
	}
	pathIndex--; //if reach dead end, decrement path
}

bool DAG::addVertex(Vertex& v)
{
	if (!(searchVertex(v))) //if no other vertex id is the same in the graph
	{
		Vertex* ptr = &v;
		vertexList.push_back(ptr); //add a pointer to the vertex in the vertex list
		if (checkCycle()) //but if the graph now has a cycle
		{
			vertexList.pop_back(); //delete the vertex from the graph
			cout << "Error: This vertex will create a cycle" << endl; //and issue a message
			return false; //action unsuccessful
		}
		else
		{
			return true; //action successful
		}
	} //else
	cout << "There is already this vertex in the graph" << endl;
	return false; //action unsuccessful
}

bool DAG::addVertices(Vertex* vArray, unsigned int size)
{
	if (size == 0)
	{
		cout << "Error: empty list" << endl; //if list is empty, output message and return false
		return false;
	}
	for (unsigned int i = 0; i < size; i++) //loop through all the elements in vertex list
	{
		addVertex(vArray[i]); //add each to to vertex list
	}
	return true; //action successful
}

bool DAG::removeVertex(Vertex& v) //remove vertex and any connecting edges
{
	int id = v.getId();
	bool temp = false;
	if (searchVertex(v)) //if vertex to be removed exists in graph
	{
		temp = true;
		for (unsigned int i = 0; i<vertexList.size(); i++)
			if (vertexList[i]->getId() == v.getId())
				 vertexList.erase(vertexList.begin()+i); //erase that edge
		for (unsigned int i = 0; i<edgeList.size(); i++) //loop through edges
		{
			if (edgeList[i]->getEnd() == id || edgeList[i]->getStart() == id) //if any edge have a connection
			{
				edgeList.erase(edgeList.begin()+i); //remove it
				i--; //and decrement counter
			}
		}
	}
	return temp; //return true or false depending on if the vertex was removed
}

bool DAG::addEdge(Edge& e)
{
	if (!searchEdge(e)) //if no other edge is the same in the graph
	{
		Edge* ptr = &e;
		edgeList.push_back(ptr); //add a pointer to the edge in the edge list
		if (checkCycle()) //but if the graph now has a cycle
		{
			edgeList.pop_back(); //delete the edge from the graph
			cout << "Error: This edge will create a cycle" << endl; //and issue a message
			return false; //action unsuccessful
		}
		else
		{
			return true; //action successful
		}
	} //else
	cout << "There is already this edge in the graph" << endl;
	return false; //action unsuccessful
}

bool DAG::addEdges(Edge* eArray, unsigned int size)
{
	if (size == 0)
	{
		cout << "Error: empty list" << endl; //if list is empty, output message and return false
		return false;
	}
	for (unsigned int i = 0; i < size; i++) //loop through all the elements in vertex list
	{
		addEdge(eArray[i]); //add each to to edge list
	}
	return true; //action successful
}

bool DAG::removeEdge(Edge& e)
{
	int start = e.getStart(); //get start id
	int end = e.getEnd(); //get end id
	for (unsigned int i = 0; i < edgeList.size(); i++) //loop through all edges
	{
		if (start == edgeList[i]->getStart() && end == edgeList[i]->getEnd()) //if both start and end id corresponds
		{
			edgeList.erase(edgeList.begin()+i); //erase that edge which also pulls back all edges after this by 1 position
			return true; //return true, edge removed
		}
	}
	return false; //else return false, edge wasn't found
}

bool DAG::removeEdges(Edge* eArray, unsigned int size)
{
	if (size == 0)
	{
		cout << "Error: empty list" << endl; //if list is empty, output message and return false
		return false; //action unsuccessful
	}
	for (unsigned int i = 0; i < size; i++)
	{
		removeEdge(eArray[i]); //remove each edge in array
	}
	return true; //action successful
}

bool DAG::searchVertex(const Vertex& v) const
{
	int id = v.getId(); //get id
	double value = v.getValue(); //get value
	for (unsigned int i = 0; i < vertexList.size(); i++) //loop through all vertices
	{
		if (id == vertexList[i]->getId() && value == vertexList[i]->getValue()) //if both start and end id corresponds
			return true; //return true
	}
	return false; //else return false
}

bool DAG::searchEdge(const Edge& e) const //simple traverse search algorithm
{
	int start = e.getStart(); //get start id
	int end = e.getEnd(); //get end id
	for (unsigned int i = 0; i < edgeList.size(); i++) //loop through all edges
	{
		if (start == edgeList[i]->getStart() && end == edgeList[i]->getEnd()) //if both start and end id corresponds
			return true; //return true
	}
	return false; //else return false
}

void DAG::display(Vertex &v) const //display all paths from root to the vertex
{
	if (searchVertex(v)) //if vertex exists in graph
	{
		vector<int> root;
		fillRoot(root);
		cout << "Paths to v" << v.getId() << ":" << endl;
		for (unsigned int i = 0; i<root.size(); i++) //go through all root vertex ids
		{
			int* path = new int[vertexList.size()];
			int pathIndex = 0;
			printAllPathsRecur(root[i], v.getId(), path, pathIndex); //with recursion function set with destination argument vertex's id
		}
		cout << endl;
	}
}

void DAG::display(Edge &e) const //display all paths from root to leaf containing this edge
{
	vector<int> root;
	fillRoot(root);
	vector<int> leaf;
	fillLeaf(leaf);
	int* path = new int[vertexList.size()];
	int pathIndex = 0;
	int start = e.getStart();
	int end = e.getEnd();
	cout << "All paths containing this edge:" << endl;
	for (unsigned int i = 0; i < root.size(); i++)
		for (unsigned int j = 0; j < leaf.size(); j++)
		{ //overloaded recursion function with extra arguments being the start and end id of the edge we want to find
			printAllPathsRecur(root[i], leaf[j], path, pathIndex, start, end);
		}
	cout << endl;
}

void DAG::display() const //print out all vertices and edges
{
	cout << "Vertices: " << endl;
	for (unsigned int i = 0; i<vertexList.size(); i++)
	{
		cout << "v" << vertexList[i]->getId() << ": ";
		vertexList[i]->print();

	}
	cout << endl;
	cout << "Edges: " << endl;
	for (unsigned int i = 0; i<edgeList.size(); i++)
	{
		edgeList[i]->print();
	}
}

void DAG::toString() const //prints out all paths from root to leaf
{
	vector<int> root;
	fillRoot(root);
	vector<int> leaf;
	fillLeaf(leaf);
	cout << "All paths from root to leaf: " << endl;
	for (unsigned int i = 0; i < root.size(); i++)
		for (unsigned int j = 0; j < leaf.size(); j++)
			printAllPaths(root[i], leaf[j]);
}

bool DAG::clean()
{
	if (vertexList.empty() && edgeList.empty()) //if both vectors are empty, return false
		return false;
	vertexList.clear(); //clear vertex list
	edgeList.clear(); //clear edge list
	return true;
}

bool DAG::operator ==(const DAG& graph) const //checks if both graphs have exact same vertices and edges
{
	if ((vertexList.size() != graph.vertexList.size()) || (edgeList.size() != graph.edgeList.size()))
		return false;
	for (unsigned int i = 0; i < vertexList.size(); i++)
	{
		if (vertexList[i]->getId() != graph.vertexList[i]->getId())
			return false;
		if (vertexList[i]->getValue() != graph.vertexList[i]->getValue())
			return false;
	}
	for (unsigned int i = 0; i < edgeList.size(); i++)
	{
		if (edgeList[i]->getId() != graph.edgeList[i]->getId())
			return false;
		if (edgeList[i]->getStart() != graph.edgeList[i]->getStart())
			return false;
		if (edgeList[i]->getEnd() != graph.edgeList[i]->getEnd())
			return false;
		if (edgeList[i]->getWeight() != graph.edgeList[i]->getWeight())
			return false;
	}
	return true;
}

void DAG::operator =(const DAG& g) //assigns all vertices and edges from argument to this
{
	if (&g != this) //check for self assignment
	{
		clean();
		vertexList.resize(g.vertexList.size()); //make vertexlist size same as the argument's
		for (unsigned int i = 0; i < g.vertexList.size(); i++)
		{	//create a new, but same vertex as the argument's at each of the vertexlist positions
			vertexList[i] = new Vertex(g.vertexList[i]->getId(), g.vertexList[i]->getValue(), g.vertexList[i]->getDescription());

		}
		edgeList.resize(g.edgeList.size()); //make edgelist size same as the argument's
		for (unsigned int i = 0; i < g.edgeList.size(); i++)
		{	//create a new, but same edge as the argument's at each of the edgelist positions
			edgeList[i] = new Edge(g.edgeList[i]->getId(), g.edgeList[i]->getStart(), g.edgeList[i]->getEnd(), g.edgeList[i]->getWeight());
		}
	}
	else
		cout << "Error: self assignment" << endl;
}

DAG& DAG::operator ++() //preincrement weight of edges by 1
{
	for (unsigned int i = 0; i < edgeList.size(); i++)
	{
		edgeList[i]->setWeight(edgeList[i]->getWeight() + 1.0);
	}
	return *this;
}

DAG DAG::operator ++(int) //postincrement weight of edges by 1
{
	DAG temp;
	temp.vertexList.resize(vertexList.size()); //make temp's vertexlist size same as the this'
	for (unsigned int i = 0; i < vertexList.size(); i++)
	{	//create a new, but same vertex as the this' at each of the vertexlist positions
		temp.vertexList[i] = new Vertex(vertexList[i]->getId(), vertexList[i]->getValue(), vertexList[i]->getDescription());
	}
	temp.edgeList.resize(edgeList.size()); //make temp's edgelist size same as the this'
	for (unsigned int i = 0; i < edgeList.size(); i++)
	{	//create a new, but same edge as this' at each of the edgelist positions
		temp.edgeList[i] = new Edge(edgeList[i]->getId(), edgeList[i]->getStart(), edgeList[i]->getEnd(), edgeList[i]->getWeight());
	}
	++(*this);
	return temp;
}

DAG DAG::operator +(const DAG& g) const //return a graph containing all vertices and edges of both this and argument graph
{
	DAG temp;
	for (unsigned int i = 0; i < vertexList.size(); i++)
		temp.addVertex(*(vertexList[i]));
	for (unsigned int i = 0; i < g.vertexList.size(); i++)
		temp.addVertex(*(g.vertexList[i]));
	for (unsigned int i = 0; i < edgeList.size(); i++)
		temp.addEdge(*(edgeList[i]));
	for (unsigned int i = 0; i < g.edgeList.size(); i++)
		temp.addEdge(*(g.edgeList[i]));
	return temp;
}

bool DAG::operator >(const DAG& g) const //check sum of weights of graphs
{
	double sum1 = 0;
	double sum2 = 0;
	for (unsigned int i = 0; i < edgeList.size(); i++)
	{
		sum1 = sum1 + edgeList[i]->getWeight();
	}
	for (unsigned int i = 0; i < g.edgeList.size(); i++)
	{
		sum2 = sum2 + g.edgeList[i]->getWeight();
	}
	return (sum1 > sum2);
}

ostream& operator <<(ostream& out, const DAG& g) //allows to print out all vertices and edges via <<
{
	out << "Vertices: " << endl;
	for (unsigned int i = 0; i < g.vertexList.size(); i++)
	{
		out << g.vertexList[i]->getId() << ", " << g.vertexList[i]->getValue() << ", ";
		out << g.vertexList[i]->getDescription();
		out << endl;
	}
	out << "Edges: " << endl;
	for (unsigned int i = 0; i < g.edgeList.size(); i++)
	{

		out << g.edgeList[i]->getId() << ", " << g.edgeList[i]->getWeight() << ", from ";
		out << g.edgeList[i]->getStart() << " to " << g.edgeList[i]->getEnd();
		out << endl;
	}
	return out;
}


