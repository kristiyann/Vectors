#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>
#include <math.h>


using namespace std;

Vector::Vector(double x1, double x2, double x3) {
	vecX = x1;
	vecY = x2;
	vecZ = x3;
}


Vector::Vector(Point v1, Point v2) {
	A = v1;
	B = v2;
	vecX = v2.getX - v1.getX;
	vecY = v2.getY - v1.getY;
	vecZ = v2.getZ - v1.getZ;
}

Vector::Vector(const Vector & other) {
	vecX = other.vecX;
	vecY = other.vecY;
	vecY = other.vecY;
	A = other.A;
	B = other.B;

}

Vector::~Vector() {
	cout << "Vector destroyed" << endl; //debug
}

Vector& Vector::operator=(const Vector & other) {
	if (this == &other)
	{
		return *this;
	}

	vecX = other.vecX;
	vecY = other.vecY;
	vecY = other.vecY;
	A = other.A;
	B = other.B;

	return *this;
}


double Vector::VectorLength() {
	double vectorLength;

	vectorLength = pow(vecX, 2)*pow(vecY, 2)*pow(vecY, 2);
	vectorLength = pow(vectorLength, 0.5);

	return vectorLength;
}


void Vector::VectorDirection() {
	double xDirection, yDirection, zDirection;
	/*double len = VectorLength();
	if (len == 0)
	{
		//crash
	}*/

	xDirection = x / VectorLength();
	yDirection = y / VectorLength();
	zDirection = z / VectorLength();

	cout << "(x,y,z)" << xDirection << yDirection << zDirection << endl;

	
}

bool Vector::vectorIsNull()
{
	if (vecX==0)
	{
		if ((vecY == 0) && (vecZ == 0))
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool Vector::vectorIsParallel(double v1, double v2, double v3) {
	double xPar, yPar, zPar;

	xPar = vecX / v1;
	yPar = vecY / v2;
	zPar = vecY / v3;

	if (xPar==yPar)
	{
		if (yPar == zPar)
		{
			return true;
		}
		else return false;
	}
	else return false;

}

bool Vector::vectorIsPerpendicular(double v1, double v2, double v3) {
	double perCheck;

	perCheck = vecX * v1 + vecY * v2 + vecZ * v3;

	if (perCheck == 0)
	{
		return true;
	}
	else return false;
}