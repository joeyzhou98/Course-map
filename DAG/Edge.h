#ifndef EDGE_H_
#define EDGE_H_

class Edge{ //or prerequisite

public:
	Edge();
	Edge(int, int, int, double);
	int getStart() const;
	int getEnd() const;
	int getId() const;
	double getWeight() const;
	void setWeight(const double);
	void print() const;

private:
	int id; //unique edge id
	int start; //course prerequisite id for end course id
	int end;
	double weight; //used to tell the weight of that prerequisite. Eg: class COEN346, Operating Systems has
	//prerequisite: COEN311; COMP353 or COEN352 that means that the edge that goes from COEN311 to COEN346 (indicating
	//a prerequisite) has weight of 0.67 and the edges that goes from COMP352 or COEN352 to COEN346 have weight 0.33
	//this implies a total weight of 1 or above in order to be qualified for a class so doing COMP352 AND COEN352 won't
	//be enough since their total weight will be 0.66, forcing the student to take COEN311 which has a weight of
	//0.67 towards COEN346.
};




#endif /* EDGE_H_ */
