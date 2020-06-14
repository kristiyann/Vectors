#pragma once
#include <clocale>
#include <iostream>

using namespace std;

//Базов клас
class Element
{
//protected заради класовете наследници
protected:
	//3 променливи, които ще има във всеки клас
	double x, y, z;
public:
	//BIG5
	Element(); //default конструктор
	Element(double x1, double x2, double x3); //конструктор с параметри
	Element(const Element & other); //копиращ конструктор
	virtual ~Element(); // деструктор
	Element& operator=(const Element & other); //предефиниране на =
	
    //мутатори и аксесори
	virtual double getX() const;
	virtual void setX(double val);
	virtual double getY() const;
	virtual void setY(double val);
	virtual double getZ() const;
	virtual void setZ(double val);

	//Предефиниране на оператори за класа
	virtual ostream& ins(ostream &) const;
	virtual istream& ext(istream &);
};

ostream& operator << (ostream &, const Element &);
istream& operator >> (istream &, Element &);
