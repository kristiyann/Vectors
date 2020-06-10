#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>
#include <math.h>

//Дефиниция на класа Vector
using namespace std;

Vector::Vector() {}

Vector::Vector(double x1, double x2, double x3) {
	x = x1;
	y = x2;
	z = x3;
}


Vector::Vector(Point v1, Point v2) {
	A = v1;
	B = v2;
	//xyz стойностите на вектора, извикан чрез този конструктор се пресмятат като от съответният елемент на 2-рия вектор се изкарва този на 1-вия
	x = v2.getX() - v1.getX();
	y = v2.getY() - v1.getY();
	z = v2.getZ() - v1.getZ();
}

Vector::Vector(const Vector & other) {
	x = other.x;
	y = other.y;
	z = other.z;
	A = other.A;
	B = other.B;

}

Vector::~Vector() {
	cout << "Vector destroyed" << endl; //debug
	//Този деструктор стой празен, тъй като обектите ще могат да се унищожат автоматично
}

Vector& Vector::operator=(const Vector & other) {
	if (this == &other)
	{
		return *this;
	}

	x = other.x;
	y = other.y;
	z = other.z;
	A = other.A;
	B = other.B;

	return *this;
}


double Vector::VectorLength() {
	double vectorLength;
	//Формула за дължина на вектор
	vectorLength = pow(x, 2)*pow(y, 2)*pow(z, 2);
	vectorLength = pow(vectorLength, 0.5);

	return vectorLength;
}


void Vector::VectorDirection() {
	double xDirection, yDirection, zDirection;
	//Формула за посока на вектор
	xDirection = x / VectorLength();
	yDirection = y / VectorLength();
	zDirection = z / VectorLength();

	cout << "(x,y,z)" << xDirection << yDirection << zDirection << endl;
}

bool Vector::vectorIsNull()
{
	//Формула дали вектор е нулев
	if (x==0)
	{
		if ((y == 0) && (z == 0))
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
	//Формула за успоредност на вектор
	xPar = x / v1;
	yPar = y / v2;
	zPar = z / v3;

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
	//Формула за перпендикулярност на вектор 
	perCheck = x * v1 + y * v2 + z * v3;

	if (perCheck == 0)
	{
		return true;
	}
	else return false;
}


Vector Vector::operator+(const Vector& rhs) {
	double x, y, z;
	//Събиране на 2 вектора
	x = this->x + rhs.x;
	y =this->y + rhs.y;
	z = this->z + rhs.z;

	return Vector(x,y,z);
}

Vector Vector::operator-(const Vector& rhs) {
	double x, y, z;
	//Изваждане на 2 вектора
	x = this->x - rhs.x;
	y = this->y - rhs.y;
	z = this->z - rhs.z;

	return Vector(x, y, z);
}

Vector Vector::operator*(const double& rhs) {
	double x, y, z;
	//Умножение на вектор с реално число
	x = this->x * rhs;
	y = this->y * rhs;
	z = this->z * rhs;

	return Vector(x, y, z);
}

double Vector::operator*(const Vector& rhs) {
	double product;
	//Скаларно произведение на 2 вектора
	product = this->x*rhs.x + this->y*rhs.x + this->z*rhs.z;

	return product;
}

Vector Vector::operator^(const Vector& rhs) {
	double x, y, z;
	//Векторно произведение на 2 вектора
	x = this->y*rhs.z - this->z*rhs.y;
	y = -1*(this->x*rhs.z + this->z*rhs.x);
	z = this->x*rhs.y + this->y*rhs.x;

	return Vector(x, y, z);
}

double Vector::operator()(const Vector& v, const Vector& w)
{
	double tripleProduct;
	//Смесено произведение на 3 вектора
	tripleProduct = this->x*((v.y*w.z)-(v.z*w.y))- this->y*((v.x*w.z) - (v.z*w.x))+ this->z*((v.x*w.y) - (v.y*w.x));
	
	return tripleProduct;
}

ostream& Vector::ins(ostream &out) const {
	Element::ins(out);
	out << endl << "Point A: " << A << endl;
	out << "Point B: " << B << endl;
	
	return out;
}


istream& Vector::ext(istream &in) {
	Element::ext(in);
	cout << "Enter Point A details: ";
	in >> A;
	cout << "Enter Point B details: ";
	in >> B;

	in.ignore();
	return in;
}