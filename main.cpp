#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "Triangle.h"
#include "Tetrahedron.h"
#include "InputExceptions.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

//Global variables
unsigned objectSelect, operationSelect; 
unsigned subOperationSelect;
Vector V; Point A, B; Triangle T; //Global class object variables to be used everywhere
//

//function prototypes to prevent errors such as: identifier not found.
void ExitFunction();
void PreExitFunction();
void SelectNewObjectConsole();
void SelectNewObjectTxt();
void SelectNewOperation();
void VectorOperations(Vector);
void TriangleSelected(Triangle);
Vector VectorInput();
//

void ExitFunction()
{
	bool writeCheck = 1;
	cout << "Write last object information to file? 0 for yes, 1 for no." << endl;
	cin >> writeCheck;

	if (writeCheck)
	{
		exit(0);
	}
	else
	{
		ofstream myfile2;
		myfile2.open("VectorObjectsInformation.txt", ios_base::app); 
		//ios::app makes sure the information from the text file is not deleted when it is opened.
		
		//Write Point 
		myfile2 << "Point details: " << endl;
		myfile2 << A << endl;
		myfile2 << "------------------ " << endl;
			 
		//Write Vector 
		myfile2 << "Vector details: " << endl;
		myfile2 << V << endl;
		myfile2 << "------------------ " << endl;

		//Write Triangle
		myfile2 << "Triangle details: " << endl;
		myfile2 << T << endl;
		myfile2 << "------------------ " << endl;

		myfile2.close();

		exit(0);
	}
}

void PreExitFunction()
{
	bool yesno;
	cout << "Would you like to choose a different operation? 0 - yes, 1 - no" << endl;
	cin >> yesno;
	if (yesno)
	{
		cout << "Would you like to choose a new object? 0 - yes, 1 - no" << endl;
		cin >> yesno;
		if (yesno)
		{
			ExitFunction();
		}
		else
		{
			SelectNewObjectConsole();
		}
	}
	else
	{
		SelectNewOperation();
	}
}

void ObjectSelectOne(Point P, Point P2)
{
	cout << "You have selected the object Point which has only 1 operation available." << endl;

	cout << "Enter values for 1st point to compare:" << endl;
	cin >> P;

	cout << "Enter values for 2nd point to compare:" << endl;
	cin >> P2;

	A = P; //@Viktor, very important line which makes sure the values written to the file are not 0 (unless they are set as 0 of course). Need this for every object.

	if (P.operator==(P2))
		cout << "The points are equal." << endl;
	else
		cout << "The points are NOT equal." << endl;
}

//Вход през конзола
void SelectNewObjectConsole()
{
	cout << "Choose a geomethrical object by inputting the corresponding number." << endl;
	do
	{
		cout << "1 - Point" << endl;
		cout << "2 - Vector" << endl;
		cout << "3 - Line" << endl;
		cout << "4 - Segment (Coming soon!)" << endl;
		cout << "5 - Triangle" << endl;
		cout << "6 - Tetrahedron" << endl;
		cout << "0 - Exit" << endl;
		cin >> objectSelect;
	} while (objectSelect < 0 || objectSelect > 6);

	switch (objectSelect)
	{
	case 1: {
		ObjectSelectOne(A,B); //Point only has 1 operation available.
		PreExitFunction();
		break;
	}
	case 2:
	{
		VectorOperations(V);
		PreExitFunction();
		break;
	}
	case 3: PreExitFunction(); break;
	case 4: PreExitFunction(); break;
	case 5: PreExitFunction(); break;
	case 6: PreExitFunction(); break;
	case 0: 
	{
		ExitFunction();
		break;
	}
    }
}

//Вход чрез текстов  файл
void SelectNewObjectTxt()
{
	double vectorX, vectorY, vectorZ;
	double vectorX2, vectorY2, vectorZ2;

	ifstream myfile;

	myfile.open("vectors.txt", ios::in);

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			//1
			myfile >> objectSelect;

			//Switch used for limiting the information gathered from the text file, depending on the first object selected.
			switch (objectSelect)
			{
			case 1: break;
			case 2:
			{
				//2
				myfile >> subOperationSelect;

				if (subOperationSelect == 1)
				{
					//3
					myfile >> vectorX;
					//4
					myfile >> vectorY;
					//5
					myfile >> vectorZ;

					//debug
					cout << vectorX << vectorY << vectorZ << "nice :)" << endl;

					
				}
				else if (subOperationSelect == 2)
				{
					//3
					myfile >> vectorX;
					//4
					myfile >> vectorY;
					//5
					myfile >> vectorZ;
					//6
					myfile >> vectorX2;
					//7
					myfile >> vectorY2;
					//8
					myfile >> vectorZ2;

					//Point A(vectorX, vectorY, vectorZ);
					//Point B(vectorX2, vectorY2, vectorZ2);

					//Vector V(A,B);
				}
				break;
			}
			}
			myfile >> operationSelect;
		}
		myfile.close(); //file closed.

		//Switch used for picking operations based on the object selected.
		switch (objectSelect)
		{
		case 1: ObjectSelectOne(A, B); ExitFunction(); break; //Point only has 1 operation available.
		case 2: {
			
			VectorOperations(V);
			ExitFunction();
			break;
		}
		case 3: ExitFunction(); break;
		case 4: ExitFunction(); break;
		case 5: ExitFunction(); break;
		case 6: ExitFunction(); break;
		}
	}
	else cout << "Unable to open file!";

}

void SelectNewOperation()
{
	switch (objectSelect)
	{
	case 1: {
		ObjectSelectOne(A, B); //Point only has 1 operation available.
		PreExitFunction();
		break;
	}
	case 2:
	{
		VectorOperations(V);
		PreExitFunction();
		break;
	}
	case 3: PreExitFunction();  break;
	case 4: PreExitFunction(); break;
	case 5: PreExitFunction(); break;
	case 6: PreExitFunction(); break;
	}

}

void VectorOperations(Vector Vec) {
	unsigned operationSelect;

	Vec = VectorInput();

	cout << endl << "Choose an operation to execute:" << endl;
	do
	{
		cout << "1 - Length" << endl;
		cout << "2 - Unit Vector" << endl;
		cout << "3 - Zero Vector" << endl;
		cout << "4 - Parallel Vectors" << endl;
		cout << "5 - Perpendicular Vectors" << endl;
		cout << "6 - Addition" << endl;
		cout << "7 - Subtraction" << endl;
		cout << "8 - Multiplication By Number" << endl;
		cout << "9 - Dot Product" << endl;
		cout << "10 - Multiplication By Vector" << endl;
		cout << "11 - Triple Product" << endl;
		cout << "0 - Exit" << endl;
		cin >> operationSelect;
	} while (operationSelect < 0 || operationSelect > 11);
	cout << endl;

	V = Vec; //important line

	if (operationSelect == 1) {
		//daljina
		cout << "Vector length: " << Vec.VectorLength() << endl;

	}
	else if (operationSelect == 2) {
		//posoka
		cout << "Vector Direction" << Vec.VectorDirection();
	}
	else if (operationSelect == 3) {
		//nulev
		if (Vec.vectorIsNull())
			cout << "Zero vector!" << endl;
		else
			cout << "NOT a zero vector!" << endl;
	}
	else if (operationSelect == 4) {
		//usporednost
		double v1, v2, v3;
		cout << "Please enter v1 value for the 2nd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 2nd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 2nd vector: ";
		cin >> v3;
		//if one of the vectors has a length of 0
		if (Vec.VectorLength() == 0 || pow(pow(v1, 2) + pow(v2, 2) + pow(v3, 2), 0.5) == 0)
			VectorLengthException(1);
		else {
			if (Vec.vectorIsParallel(v1, v2, v3))
				cout << endl << "Vectors are parallel!" << endl;
			else
				cout << endl << "Vectors are NOT parallel!" << endl;

		}
	}
	else if (operationSelect == 5) {
		//perpendikolqrnost
		double v1, v2, v3;
		cout << "Please enter v1 value for the 2nd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 2nd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 2nd vector: ";
		cin >> v3;
		//if one of the vectors has a length of 0
		if (Vec.vectorIsNull() || ((v1 == 0) && (v2 == 0) && (v3 == 0)))
			VectorLengthException(2);
		else {
			if (Vec.vectorIsPerpendicular(v1, v2, v3))
				cout << endl << "Vectors are perpendicular!" << endl;
			else
				cout << endl << "Vectors are NOT perpendicularl!" << endl;
		}
	}
	else if (operationSelect == 6) {
		double v1, v2, v3;
		cout << "Please enter v1 value for the 2nd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 2nd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 2nd vector: ";
		cin >> v3;
		Vector V2(v1, v2, v3);
		cout << endl << "Adding the two vectors:" << endl << (Vec + V2);
	}
	else if (operationSelect == 7) {
		double v1, v2, v3;
		cout << "Please enter v1 value for the 2nd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 2nd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 2nd vector: ";
		cin >> v3;
		Vector V2(v1, v2, v3);
		cout << endl << "Subtracting the two vectors: " << endl << (Vec - V2);
	}
	else if (operationSelect == 8) {
		double r;
		cout << "Please enter r:";
		cin >> r;
		cout << endl << "Multiplying the vector by " << r << ":" << endl << (Vec * r);
	}
	else if (operationSelect == 9) {
		double v1, v2, v3;
		cout << "Please enter v1 value for the 2nd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 2nd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 2nd vector: ";
		cin >> v3;
		Vector V2(v1, v2, v3);
		cout << endl << "Dot product of the two vectors: " << (Vec * V2) << endl;
	}
	else if (operationSelect == 10) {
		double v1, v2, v3;
		cout << "Please enter v1 value for the 2nd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 2nd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 2nd vector: ";
		cin >> v3;
		Vector V2(v1, v2, v3);
		cout << endl << "Multiplying the two vectors: " << endl << (Vec ^ V2);
	}
	else if (operationSelect == 11) {
		double v1, v2, v3;
		cout << "Please enter v1 value for the 2nd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 2nd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 2nd vector: ";
		cin >> v3;
		Vector V2(v1, v2, v3);
		cout << endl;
		cout << "Please enter v1 value for the 3rd vector: ";
		cin >> v1;
		cout << endl << "Please enter v2 value for the 3rd vector: ";
		cin >> v2;
		cout << endl << "Please enter v3 value for the 3rd vector: ";
		cin >> v3;
		Vector V3(v1, v2, v3);
		cout << endl << "Product of the three vectors: " << Vec(V2, V3) << endl;
	}
}

Vector VectorInput() {
	Vector Vec;
	cin >> Vec;
	return Vec;
}

void TriangleSelected(Triangle Tri) {
	
	cin >> Tri;

	T = Tri;

	T.triType();
	cout << "Area: " << Tri.triArea() << endl;
	cout << "Perimeter: " << Tri.triPerimeter() << endl;
	cout << "Medicenter: " << endl << Tri.triMedicenter() << endl;
	Point P;
	cout << "Enter values for point:" << endl;
	cin >> P;
	if ((Tri < P))
		cout << "The point is in the triangle" << endl;
	if ((Tri > P))
		cout << "The point is NOT in the triangle" << endl;
	if ((Tri == P))
		cout << "The point is on a side of the triangle" << endl;
}

int main() {
	setlocale(LC_ALL, "");
	cout << setprecision(2);
	bool insertSelect; //Променлива за проверката на метода на вход
	
	cout << "Select method of insertion: type 0 for using a txt file or 1 for using console." << endl;
	cin >> insertSelect;

	//Проверка на метода на вход
	if (insertSelect == 0)
	{
		//Вход чрез текстов  файл
		SelectNewObjectTxt();
	}
	else {
		//Вход през конзола
		SelectNewObjectConsole();
	}

	cin.get();
	return 0;
}

