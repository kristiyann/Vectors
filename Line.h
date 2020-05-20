#pragma once
#include "Point.h"
#include "Vector.h"

class Line : public Vector
{
private:
	Point lA;
	Point lB;
	Vector lV;
public:
	//BIG5
	Line(Point A, Vector B);
	Line(Point A, Point B);
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
};
