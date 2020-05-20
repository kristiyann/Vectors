#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>

using namespace std;

int main() {

	//just testigng
	Vector a(1,2,3);
	Vector b(1, 2, 3);
	double c = a*b;

	cout << c << endl;


	system("PAUSE");
	return 0;
}