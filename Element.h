#pragma once
#include <clocale>
#include <iostream>

using namespace std;

//����� ����
class Element
{
//protected ������ ��������� ����������
protected:
	//3 ����������, ����� �� ��� ��� ����� ����
	double x, y, z;
public:
	//BIG5
	Element(); //default �����������
	Element(double x1, double x2, double x3); //����������� � ���������
	Element(const Element & other); //������� �����������
	virtual ~Element(); // ����������
	Element& operator=(const Element & other); //������������� �� =
	
    //�������� � ��������
	virtual double getX() const;
	virtual void setX(double val);
	virtual double getY() const;
	virtual void setY(double val);
	virtual double getZ() const;
	virtual void setZ(double val);

	//������������� �� ��������� �� �����
	virtual ostream& ins(ostream &) const;
	virtual istream& ext(istream &);
};

ostream& operator << (ostream &, const Element &);
istream& operator >> (istream &, Element &);
