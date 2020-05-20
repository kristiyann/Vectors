#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include <iostream>


Line::Line(Point A, Vector B) {
	lA = A;
	lV = B;


}
Line::Line(Point A, Point B) {
	Vector Line(A,B);
	
	lA = A;
	lV = Line;
}
Line::Line(const Line & other) {
	lA = other.lA;
	lV = other.lV;

}
Line::~Line() {
	std::cout << "Vector destroyed" << std::endl; //debug
}
Line& Line::operator=(const Line & other) {
	if (this == &other)
	{
		return *this;
	}

	lA = other.lA;
	lV = other.lV;

	return *this;
}

//functions
Vector Line::lineDirection() {


}
Vector Line::normalVector() {


}
double Line::linesAngle(Line a) {



}

//overloading
bool Line::operator+(const Point rhs) {}
bool Line::operator||(const Line rhs) {}
bool Line::operator==(const Line rhs) {}
bool Line::operator&&(const Line rhs) {}
bool Line::operator!=(const Line rhs) {}
bool Line::operator|(const Line rhs) {}