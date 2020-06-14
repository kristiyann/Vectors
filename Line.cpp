#include "Point.h"
#include "Vector.h"
#include "Line.h"
#include <iostream>
#include <clocale>


Line::Line(Point vA, Vector vB) {
	A = vA;
	lV = vB;
}
Line::Line(Point vA, Point vB) {
	Vector Line(vA,vB);
	
	A = vA;
	lV = Line;
}
Line::Line(const Line & other) {
	A = other.A;
	lV = other.lV;

}
Line::~Line() {
	std::cout << "Line destroyed" << std::endl; //debug
}
Line& Line::operator=(const Line & other) {
	if (this == &other)
	{
		return *this;
	}

	A = other.A;
	lV = other.lV;

	return *this;
}

//functions
/*Vector Line::lineDirection() {

	
}
Vector Line::normalVector() {


}
double Line::linesAngle(Line a) {



}*/

//overloading
//bool Line::operator+(const Point rhs) {}
//bool Line::operator||(const Line rhs) {}
//bool Line::operator==(const Line rhs) {}
//bool Line::operator&&(const Line rhs) {}
//bool Line::operator!=(const Line rhs) {}
//bool Line::operator|(const Line rhs) {}

ostream& Line::ins(ostream &out) const {
	Element::ins(out);


	return out;
}


istream& Line::ext(istream &in) {
	Element::ext(in);

	in.ignore();
	return in;


}