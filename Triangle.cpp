#include "Point.h"
#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Point A, Point B, Point C) {
	triA = A;
	triB = B;
	triC = C;
	
}

Triangle::Triangle(const Triangle & other) {
	
	triA = other.triA;
	triB = other.triB;
	triC = other.triC;
}

Triangle::~Triangle() {
	std::cout << "Vector destroyed" << std::endl; //debug
}

Triangle& Triangle::operator=(const Triangle & other) {
	if (this == &other)
	{
		return *this;
	}

	triA = other.triA;
	triB = other.triB;
	triC = other.triC;

	return *this;
}

void Triangle::triType()
{


}

double Triangle::triArea()
{}
double Triangle::triPerimeter()
{}
Point Triangle::triMedicenter()
{}