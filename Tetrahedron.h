#pragma once
#include "Point.h"

class Tetra : public Point
{
private:
	Point A;
	Point B;
	Point C;
	Point D;
public:
	//BIG5
	Tetra();
	Tetra(Point p1, Point p2, Point p3, Point p4);
	~Tetra();

	//functions
	void RegularCheck();
	void OrthogonalCheck();
	void Volume();
	void SurfaceArea();
	bool operator<(const Point point);
	bool operator>(const Point point);
	bool operator==(const Point point);

	virtual ostream& ins(ostream &) const;
	virtual istream& ext(istream&);
};
