#include "Point.h"
#include <clocale>

//��������� �� ����� Point
Point::Point() {
	//��������� �� ������������ �� ������������
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
	//���� ���������� ���� ������, ��� ���� �������� �� ����� �� �� �������� �����������
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
	//�������� ���� ���������� �� 2 ����� �� �����, � ��� ��, ��������� ������� true
	if ((x == other.x) && (y == other.y) && (z == other.z))
		return true;
	else
		return false;
}


ostream& Point::ins(ostream &out) const {
	Element::ins(out);
	

	return out;
}


istream& Point::ext(istream &in) {
	Element::ext(in);

	in.ignore();
	return in;
}