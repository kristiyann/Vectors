#include "Element.h"

//Дефиниция на класа Element
Element::Element() {
	//Стойности по подразбиране на променливите
	x = 0;
	y = 0;
	z = 0;
}
Element::Element(double x1, double x2, double x3) {
	x = x1;
	y = x2;
	z = x3;
}
Element::Element(const Element & other) {
	x = other.x;
	y = other.y;
	z = other.z;

}
Element::~Element() {
	//Този деструктор стой празен, тъй като обектите ще могат да се унищожат автоматично
}
Element& Element::operator=(const Element & other) {
	if (this == &other)
	{
		return *this;
	}

	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}



//Дефиниция на аксесорите и мутаторите на класа
double Element::getX() const
{
	return x;
}
void Element::setX(double val)
{
	x = val;
}

double Element::getY() const
{
	return y;
}
void Element::setY(double val)
{
	y = val;
}

double Element::getZ() const
{
	return z;
}
void Element::setZ(double val)
{
	z = val;
}

//Предефиниране на оператори за класа
ostream& Element::ins(ostream &out) const {
	return out 
	<< "X value: " << x << endl 
	<< "Y value: " << y << endl 
	<< "Z value: " << z << endl;
}


istream& Element::ext(istream &in) {
	cout << "Enter x value: ";
	in >> x;
	cout << "Enter y value: ";
	in >> y;
	cout << "Enter z value: ";
	in >> z;

	in.ignore();
	return in;
}


ostream& operator << (ostream &out, const Element &pr)
{
	return pr.ins(out);
}


istream& operator >> (istream &in, Element &pr)
{
	return pr.ext(in);
}
