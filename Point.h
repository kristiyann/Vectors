#pragma once
#include "Element.h"

class Point : public Element //������ Point ��������� Element
{
	//��� ���� private ��������, ��� ���� ���� ���� �������� ���� ���� �� �������
public:
	//BIG5
	Point(); //default �����������
	Point(double x1, double x2, double x3); //����������� � ���������
	Point(const Point & other); //������� �����������
	~Point(); // ����������
	Point& operator=(const Point & other); //������������� �� =

	bool operator==(const Point & other); //������������� �� ��������� == �� �������� 2 �����
};
