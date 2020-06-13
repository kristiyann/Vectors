#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>
#include <clocale>
#include <math.h>

//��������� �� ����� Vector
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
	//xyz ����������� �� �������, ������� ���� ���� ����������� �� ��������� ���� �� ����������� ������� �� 2-��� ������ �� ������� ���� �� 1-���
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
	//���� ���������� ���� ������, ��� ���� �������� �� ����� �� �� �������� �����������
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
	//������� �� ������� �� ������
	vectorLength = pow(x, 2) + pow(y, 2) + pow(z, 2);
	vectorLength = pow(vectorLength, 0.5);

	return vectorLength;
}


Vector Vector::VectorDirection() {
	double xDirection, yDirection, zDirection;
	//������� �� ������ �� ������
	xDirection = x / VectorLength();
	yDirection = y / VectorLength();
	zDirection = z / VectorLength();

	Vector V(xDirection, yDirection, zDirection);

	return V;
	//cout << "(x,y,z)" << xDirection << yDirection << zDirection << endl;

}

bool Vector::vectorIsNull()
{
	//������� ���� ������ � �����
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
	//������� �� ����������� �� ������
	double scalar = x * v1 + y * v2 + z * v3;
	if (scalar * scalar == ((x * x + y * y + z * z) * (v1 * v1 + v2 * v2 + v3 * v3)))
		return true;
	else
		return false;

}

bool Vector::vectorIsPerpendicular(double v1, double v2, double v3) {
	double perCheck;
	//������� �� ����������������� �� ������ 
	perCheck = x * v1 + y * v2 + z * v3;

	if (perCheck == 0)
	{
		return true;
	}
	else return false;
}


Vector Vector::operator+(const Vector& rhs) {
	double x, y, z;
	//�������� �� 2 �������
	x = this->x + rhs.x;
	y =this->y + rhs.y;
	z = this->z + rhs.z;

	return Vector(x,y,z);
}

Vector Vector::operator-(const Vector& rhs) {
	double x, y, z;
	//��������� �� 2 �������
	x = this->x - rhs.x;
	y = this->y - rhs.y;
	z = this->z - rhs.z;

	return Vector(x, y, z);
}

Vector Vector::operator*(const double& rhs) {
	double x, y, z;
	//��������� �� ������ � ������ �����
	x = this->x * rhs;
	y = this->y * rhs;
	z = this->z * rhs;

	return Vector(x, y, z);
}

double Vector::operator*(const Vector& rhs) {
	double product;
	//�������� ������������ �� 2 �������
	product = this->x*rhs.x + this->y*rhs.x + this->z*rhs.z;

	return product;
}

Vector Vector::operator^(const Vector& rhs) {
	double x, y, z;
	//�������� ������������ �� 2 �������
	x = this->y*rhs.z - this->z*rhs.y;
	y = -1*(this->x*rhs.z + this->z*rhs.x);
	z = this->x*rhs.y + this->y*rhs.x;

	return Vector(x, y, z);
}

double Vector::operator()(const Vector& v, const Vector& w)
{
	double tripleProduct;
	//������� ������������ �� 3 �������
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
	unsigned subOperationSelect;

	cout << "Choose input type by inputting the corresponding number." << endl;
	do
	{
		cout << "1 - Input x, y and z" << endl;
		cout << "2 - Input 2 points" << endl;
		cin >> subOperationSelect;
	} while (subOperationSelect < 1 || subOperationSelect > 2);

	if (subOperationSelect == 1) {
		Element::ext(in);
	}
	else
	{
		cout << "Enter Point A values: ";
		in >> A;
		cout << "Enter Point B values: ";
		in >> B;
	}

    in.ignore();
	return in;
}