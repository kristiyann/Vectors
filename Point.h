#pragma once
#include "Element.h"

class Point : public Element //Класът Point наследява Element
{
	//Без нови private елементи, тъй като този клас използва само тези от базовия
public:
	//BIG5
	Point(); //default конструктор
	Point(double x1, double x2, double x3); //конструктор с параметри
	Point(const Point & other); //копиращ конструктор
	~Point(); // деструктор
	Point& operator=(const Point & other); //предефиниране на =

	bool operator==(const Point & other); //предефиниране на оператора == да сравнява 2 точки
};
