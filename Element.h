#pragma once

using namespace std;

class Element
{
protected:
	double x, y, z;
public:
	Element();
	Element(double x1, double x2, double x3); //konstruktor s parametri
	Element(const Element & other); //kopirasht konstruktor
	~Element(); // destruktor
	Element& operator=(const Element & other); //predefinirane na =
	

	//accessors&mutators
	virtual double getX() const;
	virtual void setX(double val);
	virtual double getY() const;
	virtual void setY(double val);
	virtual double getZ() const;
	virtual void setZ(double val);
};
