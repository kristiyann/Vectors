#include "Point.h"
#include "Vector.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "InputExceptions.h"
#include <iostream>
#include <math.h>


Triangle::Triangle() {
	
}

Triangle::Triangle(Point A, Point B, Point C) {
	triA = A;
	triB = B;
	triC = C;
}

Triangle::Triangle(const Triangle & other) {
	
	triA = other.triA;
	triB = other.triB;
	triC = other.triC;
}

Triangle::~Triangle() {
	//std::cout << "Vector destroyed" << std::endl; //debug
}

Triangle& Triangle::operator=(const Triangle & other) {
	if (this == &other)
	{
		return *this;
	}

	triA = other.triA;
	triB = other.triB;
	triC = other.triC;

	return *this;
}

void Triangle::triType()
{
	/*
	https://www.mathsisfun.com/algebra/vectors-dot-product.html
	*/
	cout << "The triangle is:" << endl;
	if (triA == triB && triA == triC)
		cout << "Equilateral" << endl;
	else if (triA == triB || triA == triC || triB == triC)
		cout << "Isosceles" << endl;
	else
		cout << "Scalene" << endl;
	Vector vectorA(triA.getX(), triA.getY(), triA.getZ());
	Vector vectorB(triB.getX(), triB.getY(), triB.getZ());
	Vector vectorC(triC.getX(), triC.getY(), triC.getZ());

	//check if dot product is 0
	//if 0 -> cos = 90 degrees
	if (vectorA.VectorLength() > vectorB.VectorLength()) {
		if (vectorA.VectorLength() > vectorC.VectorLength()) {
			//A is hyp
			if ((vectorB * vectorC) == 0)
				cout << "Right-angled between B & C" << endl;
		}
	}
	else if (vectorB.VectorLength() > vectorA.VectorLength()) {
		if (vectorB.VectorLength() > vectorC.VectorLength()) {
			//B is hyp
			if ((vectorA * vectorC) == 0)
				cout << "Right-angled between A & C" << endl;
		}
	}
	else {
		//C is hyp
		if ((vectorA * vectorB) == 0)
			cout << "Right-angled between A & B" << endl;
	}
	double dotAB = (vectorA * vectorB);
	double dotAC = (vectorA * vectorC);
	double dotBC = (vectorB * vectorC);

	double cosAB = dotAB / (vectorA.VectorLength() + vectorB.VectorLength());
	double cosAC = dotAC / (vectorA.VectorLength() * vectorC.VectorLength());
	double cosBC = dotBC / (vectorB.VectorLength() * vectorC.VectorLength());

	double angleAB = (cosAB * 180) / 3.14159265;
	double angleAC = (cosAC * 180) / 3.14159265;
	double angleBC = (cosBC * 180) / 3.14159265;
	//cout << "angles:" << angleAB << " " << angleAC << " " << angleBC << endl;
	if (angleAB > 90) {
		cout << "Obtuse" << endl;
	}
	if (angleAB < 90 && angleAC < 90 && angleBC < 90) {
		cout << "Acute" << endl;
	}

}

double Triangle::triArea()
{
	double x1 = triA.getX(), y1 = triA.getY(), z1 = triA.getZ();
	double x2 = triB.getX(), y2 = triB.getY(), z2 = triB.getZ();
	double x3 = triC.getX(), y3 = triC.getY(), z3 = triC.getZ();
	double a = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2) + pow((z2 - z3), 2));
	double b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2) + pow((z1 - z3), 2));
	double c = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
	double s = (a + b + c) / 2;
	double area = sqrt(s * (s - a) * (s - b) * (s - c));
	return area;
}
double Triangle::triPerimeter()
{
	double x1 = triA.getX(), y1 = triA.getY(), z1 = triA.getZ();
	double x2 = triB.getX(), y2 = triB.getY(), z2 = triB.getZ();
	double x3 = triC.getX(), y3 = triC.getY(), z3 = triC.getZ();
	double a = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2) + pow((z2 - z3), 2));
	double b = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2) + pow((z1 - z3), 2));
	double c = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
	return (a + b + c);
}
Point Triangle::triMedicenter()
{
	double x1 = triA.getX(), y1 = triA.getY(), z1 = triA.getZ();
	double x2 = triB.getX(), y2 = triB.getY(), z2 = triB.getZ();
	double x3 = triC.getX(), y3 = triC.getY(), z3 = triC.getZ();
	return Point(((x1 + x2 + x3) / 3), ((y1 + y2 + y3) / 3), ((z1 + z2 + z3) / 3));
}

bool Triangle::operator<(const Point point)
{
	/*
	https://stackoverflow.com/questions/37545304/determine-if-point-is-inside-triangle-in-3d
	P = aV0 + bV1 + cV2, where a + b + c = 1 .
	P is inside if and only if 0 <= a, b, c <= 1
	If the triangles formed by v1, P, v2 has the area S1, the triangle formed by P, v0, v2 has the area of S2
	and P, V0, V1 has the area of S3.
	Then a = S1/S, b = S2/S and c = S3/S, where S is the area of triangle V0, V1, V2
	*/
	//calc areas
	double fullArea = Triangle(triA, triB, triC).triArea();
	Triangle ABP(triA, triB, point);
	Triangle ACP(triA, triC, point);
	Triangle CBP(triC, triB, point);
	double a = ABP.triArea();
	double b = ACP.triArea();
	double c = CBP.triArea();
	//check if point is INSIDE triangle
	double newAreas = a + b + c;
	if (fabs(newAreas - fullArea) < fullArea * .001)
		if (a != 0 || b != 0 || c != 0)
			return true;
		else
			return false;
	else return false;
}

bool Triangle::operator>(const Point point)
{
	double fullArea = Triangle(triA, triB, triC).triArea();
	Triangle ABP(triA, triB, point);
	Triangle ACP(triA, triC, point);
	Triangle CBP(triC, triB, point);
	double a = ABP.triArea();
	double b = ACP.triArea();
	double c = CBP.triArea();
	//check if point is OUTSIDE triangle
	double newAreas = a + b + c;
	if (fabs(newAreas - fullArea) < fullArea * .001)
		return false;
	else
		return true;
}

bool Triangle::operator==(const Point point)
{
	double fullArea = Triangle(triA, triB, triC).triArea();
	Triangle ABP(triA, triB, point);
	Triangle ACP(triA, triC, point);
	Triangle CBP(triC, triB, point);
	double a = ABP.triArea();
	double b = ACP.triArea();
	double c = CBP.triArea();
	//check if point is IN triangle
	double newAreas = a + b + c;
	if (fabs(newAreas - fullArea) < fullArea * .001)
		if (a == 0 || b == 0 || c == 0)
			return true;
		else
			return false;
	else
		return false;
}

ostream& Triangle::ins(ostream &out) const {
	Point::ins(out);
	out << "Triangle details: " << endl;
	out << endl << "Point A: " << triA << endl;
	out << "Point B: " << triB << endl;
	out << "Point C: " << triC << endl;

	return out;
}

istream& Triangle::ext(istream& in) {
	cout << "Enter Point A values: " << endl;
	in >> triA;
	do {
		cout << "Enter Point B values: " << endl;
		in >> triB;
		if (triA == triB)
			EqualPointException();
	} while (triA == triB);

	do {
		cout << "Enter Point C values: " << endl;
		in >> triC;
		if (triA == triC || triB == triC)
			EqualPointException();
	} while (triA == triC || triB == triC);

	in.ignore();
	return in;
}