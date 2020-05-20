#pragma once
#include "Point.h"
#include "Vector.h"

class Line : public Vector
{
private:
	
public:
	//BIG5
	Line(Point A, Vector B);
	Line(Point A, Point B);
	Line(const Line & other);
	~Line();
	Line& operator=(const Line & other);

	//functions
	
};
