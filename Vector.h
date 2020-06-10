#pragma once
#include "Point.h"

class Vector : public Point //Класът Vector наследява Element
{
protected:
	//Нови елементи, които ще са нужни за Vector
	Point A;
	Point B;
public:
	//BIG5
	Vector(); //default конструктор
	Vector(double x1, double x2, double x3); //конструктор с параметри
	Vector(Point v1, Point v2); //конструктор с параметри #2
	Vector(const Vector & other); //копиращ конструктор
	~Vector(); // деструктор
	Vector& operator=(const Vector & other); //предефиниране на =

	//Функции на класа
	double VectorLength();
	void VectorDirection();
	bool vectorIsNull();
	bool vectorIsParallel(double, double, double);
	bool vectorIsPerpendicular(double, double, double); 

	 //Предефиниране на оператори за класа
	Vector operator+(const Vector& rhs);
	Vector operator-(const Vector& rhs);
	Vector operator*(const double& rhs);
	double operator*(const Vector& rhs);
	Vector operator^(const Vector& rhs);
	double operator()(const Vector& v, const Vector& w);

};