#pragma once
#include "Point.h"

class Vector : public Point
{
protected:
	Point A;
	Point B;
public:
	//BIG5
	Vector(); 
	Vector(double x1, double x2, double x3); 
	Vector(Point v1, Point v2); 
	Vector(const Vector & other); 
	~Vector(); 
	Vector& operator=(const Vector & other); 

	//functions
	double VectorLength();
	void VectorDirection();
	bool vectorIsNull();
	bool vectorIsParallel(double, double, double);
	bool vectorIsPerpendicular(double, double, double); 

	 //overloading
	Vector operator+(const Vector& rhs);
	Vector operator-(const Vector& rhs);
	Vector operator*(const double& rhs);
	double operator*(const Vector& rhs);
	Vector operator^(const Vector& rhs);
	double operator()(const Vector& v, const Vector& w);

};