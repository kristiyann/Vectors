#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
	z = 0;
}
Point::Point(double x1, double x2, double x3) {
	x = x1;
	y = x2;
	z = x3;
}
Point::Point(const Point & other) {
	x = other.x;
	y = other.y;
	z = other.z;

}
Point::~Point() {


}
Point& Point::operator=(const Point & other) {
	if (this == &other)
	{
		return *this;
	}

	x = other.x;
	y = other.y;
	z = other.z;

	return *this;

}

bool Point::operator==(const Point & other)
{
	if (x==other.x) 
	{
		if ((y == other.y) && (z==other.z))
		{
			return true;
		}
		else return false;
	}
	else return false;
}


double Point::getX() const
{
	return x;
}
void Point::setX(double val)
{
	x = val;
}

double Point::getY() const
{
	return y;
}
void Point::setY(double val)
{
	y = val;
}

double Point::getZ() const
{
	return z;
}
void Point::setZ(double val)
{
	z = val;
}