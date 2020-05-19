#pragma once
#include "Point.h"

class Vector : public Point
{
private:
	double vecX, vecY, vecZ;
	Point A;
	Point B;
public:
	Vector(double x1, double x2, double x3); 
	Vector(Point v1, Point v2); 
	Vector(const Vector & other); 
	~Vector(); 
	Vector& operator=(const Vector & other);
	double VectorLength();
	void VectorDirection();
};