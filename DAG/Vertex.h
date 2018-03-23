#ifndef VERTEX_H_
#define VERTEX_H_
#include <string>

using namespace std;

class Vertex{ //or course

public:
	Vertex();
	Vertex(int, double, string);
	int getId() const;
	double getValue() const;
	string getDescription() const;
	void print() const;

private:
	int id; //unique vertex id
	double value; //number of credits worth
	string description; //course code and description
};



#endif /* VERTEX_H_ */
