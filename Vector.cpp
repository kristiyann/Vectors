#include "Point.h"
#include "Vector.h"
#include <iostream>


using namespace std;

Vector::Vector(double x1, double x2, double x3) {
	vecX = x1;
	vecY = x2;
	vecZ = x3;
}


Vector::Vector(Point v1, Point v2) {
	A = v1;
	B = v2;
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



}


void Vector::VectorDirection() {



}