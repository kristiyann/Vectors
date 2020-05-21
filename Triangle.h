#pragma once
#include "Point.h"

class Triangle : public Point
{
private:
	Point triA;
	Point triB;
	Point triC;
public:
	//BIG5
	Triangle(Point A, Point B, Point C);
	Triangle(const Triangle & other);
	~Triangle();
	Triangle& operator=(const Triangle & other);

	//functions
	void triType();
	double triArea();
	double triPerimeter();
	Point triMedicenter();
};
