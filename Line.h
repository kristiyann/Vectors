#pragma once
#include "Point.h"
#include "Vector.h"

class Line : public Vector
{
private:
	Vector lV;
public:
	//BIG5
	Line(Point vA, Vector vB);
	Line(Point vA, Point vB);
	Line(const Line & other);
	~Line();
	Line& operator=(const Line & other);

	//functions
	Vector lineDirection();
	Vector normalVector();
	double linesAngle(Line a);

	//overloading
	bool operator+(const Point rhs);
	bool operator||(const Line rhs);
	bool operator==(const Line rhs);
	bool operator&&(const Line rhs);
	bool operator!=(const Line rhs);
	bool operator|(const Line rhs);
	virtual ostream& ins(ostream &) const;
	virtual istream& ext(istream &);
};
