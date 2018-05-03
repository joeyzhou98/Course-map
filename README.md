DAG (directed acyclic graph) data structure allows for course mapping model

To run, compile and run the binary in an IDE with the instructions coded in the driver.cpp file

Each node is a course

Each edge is a prerequisite
Each edge's weight is used to tell the weight of that prerequisite. Eg: class COEN346, Operating Systems has 
prerequisite: COEN311; COMP353 or COEN352 that means that the edge that goes from COEN311 to COEN346 (indicating
a prerequisite) has weight of 0.67 and the edges that goes from COMP352 or COEN352 to COEN346 have weight 0.33
this implies a total weight of 1 or above in order to be qualified for a class so doing COMP352 AND COEN352 won't
be enough since their total weight will be 0.66, forcing the student to take COEN311 which has a weight of
0.67 towards COEN346.

Specific instructions are called on the DAG class "g" created at beginning of the driver.cpp Eg: g.printAllPaths() to print all paths
List of instructions:
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

In the driver, courses and prerequisites are based off of computer engineering classes in Concordia University
These classes can be found on:
http://www.concordia.ca/academics/undergraduate/calendar/current/sec71/71-60.html

To do: 
-add while loop to allow user commands eg: user enters 1, then 17 to search for all paths containing course #17
-implement reading from a file containing all classes and prerequisites so don't need to manually enter all edges and nodes