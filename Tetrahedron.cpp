#include "Point.h"
#include "Vector.h"
#include "Tetrahedron.h"
#include "InputExceptions.h"
#include <iostream>

Tetra::Tetra() {}

Tetra::Tetra(Point p1, Point p2, Point p3, Point p4) {
	A = p1;
	B = p2;
	C = p3;
	D = p4;
}

Tetra::~Tetra() {
	//cout << "Tetra destroyed" << endl; //debug
	//tozi deconstructor e prazen, zashtoto obektite shte se unishtojat avtomatichno
}

void Tetra::RegularCheck() {

}

void Tetra::OrthogonalCheck() {
	double ab = Vector(A, B).VectorLength(), ac = Vector(A, C).VectorLength(), ad = Vector(A, D).VectorLength(), bc = Vector(B, C).VectorLength(), bd = Vector(B, D).VectorLength(), cd = Vector(C, D).VectorLength();
	double first = pow(ab, 2) + pow(cd, 2), sec = pow(ac, 2) + pow(bd, 2), thr = pow(ad, 2) + pow(bc, 2);
	cout << first << " " << sec << " " << thr << endl;
	if (fabs(sec - first) < first * .001) {
		if (fabs(thr - first) < first * .001) {
			cout << "Tetrahedron is orthogonal" << endl;
		}
	}
}

void Tetra::Volume() {
	/*
	http://eguruchela.com/math/calculator/parellelepiped-tetrahedron-volume
	https://keisan.casio.com/exec/system/1223345456
	https://en.wikipedia.org/wiki/Tetrahedron#Coordinates_for_a_regular_tetrahedron
	*/
	double x1 = A.getX(), x2 = B.getX(), x3 = C.getX(), x4 = D.getX();
	double y1 = A.getY(), y2 = B.getY(), y3 = C.getY(), y4 = D.getY();
	double z1 = A.getZ(), z2 = B.getZ(), z3 = C.getZ(), z4 = D.getZ();
	double volume = (x4 - x1)* ((y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1))
		+ (y4 - y1) * ((z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1))
		+ (z4 - z1) * ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
	volume = fabs(volume / 6);
	cout << "Volume: " << volume << endl;
}

void Tetra::SurfaceArea() {
	double x1 = A.getX(), x2 = B.getX(), x3 = C.getX(), x4 = D.getX();
	double y1 = A.getY(), y2 = B.getY(), y3 = C.getY(), y4 = D.getY();
	double z1 = A.getZ(), z2 = B.getZ(), z3 = C.getZ(), z4 = D.getZ();
	//get volume
	double volume = (x4 - x1) * ((y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1))
		+ (y4 - y1) * ((z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1))
		+ (z4 - z1) * ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
	volume = fabs(volume / 6);
	//get a from volume
	double a = pow(volume * 6 * sqrt(2), (1.0 / 3));
	//get area
	double surArea = sqrt(3) * pow(a, 2);
	cout << "Surface Area: " << surArea << endl;
}

bool Tetra::operator<(const Point point)
{
	return true;
}

bool Tetra::operator>(const Point point)
{
	return true;
}

bool Tetra::operator==(const Point point)
{
	return true;
}

ostream& Tetra::ins(ostream &out) const {
	Point::ins(out);
	out << "Tetrahedron details: " << endl;
	out << endl << "Point A: " << A << endl;
	out << "Point B: " << B << endl;
	out << "Point C: " << C << endl;
	out << "Point D: " << D << endl;

	return out;
}

istream& Tetra::ext(istream& in) {
	cout << "Enter Point A values: " << endl;
	in >> A;
	do {
		cout << "Enter Point B values: " << endl;
		in >> B;
		if (A == B)
			EqualPointException();
	} while (A == B);

	do {
		cout << "Enter Point C values: " << endl;
		in >> C;
		if (A == C || B == C)
			EqualPointException();
	} while (A == C || B == C);
	do {
		cout << "Enter Point D values: " << endl;
		in >> D;
		if (A == D || B == D || C == D)
			EqualPointException();
	} while (A == D || B == D || C == D);
	in.ignore();
	return in;
}