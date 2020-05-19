#pragma once
#include "Element.h"

class Point : public Element
{
private:
	double x, y, z;
public:
	Point();
	Point(double x1, double x2, double x3); //konstruktor s parametri
	Point(const Point & other); //kopirasht konstruktor
	~Point(); // destruktor
	Point& operator=(const Point & other); //predefinirane na =
	bool operator==(const Point & other); //predefinirane na == za da sravnqva 2 tochki
};
