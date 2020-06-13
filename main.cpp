#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

void ObjectSelectOne(Point P, Point P2)
{
	cout << "You have selected the object Point which has only 1 operation available." << endl;

	cout << "Enter values for 1st point to compare:" << endl;
	cin >> P;

	cout << "Enter values for 2nd point to compare:" << endl;
	cin >> P2;

	if (P.operator==(P2))
		cout << "The points are equal." << endl;
	else
		cout << "The points are NOT equal." << endl;
}

void ExitFunction()
{
	//undecided if and how its going to be used yet.
}

int main() {
	setlocale(LC_ALL, "");
	cout << setprecision(2);
	bool insertSelect; //Променлива за проверката на метода на вход
	unsigned objectSelect, operationSelect;
	unsigned subOperationSelect;
	double vectorX, vectorY, vectorZ;
	double vectorX2, vectorY2, vectorZ2;
	Vector V; Point A, B;
	
	cout << "Select method of insertion: type 0 for using a txt file or 1 for using console." << endl;
	cin >> insertSelect;

	//Проверка на метода на вход
	if (insertSelect == 0)
	{
		//Вход чрез текстов файл
		
		ifstream myfile;
		
		myfile.open("vectors.txt", ios::in);
		
		if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				//1 txt input //
				myfile >> objectSelect;

				//Switch used for limiting the information gathered from the text file, depending on the first object selected.
				switch (objectSelect)
				{
				case 1: break;
				case 2: 
				{
					//2 txt input //
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
						cout << vectorX << vectorY << vectorZ << "nice :)" <<endl;

						//Vector V(vectorX, vectorY, vectorZ);
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
			case 1: ObjectSelectOne(A,B); break; //Point only has 1 operation available.
			case 2: {
				switch (operationSelect)
				{
				case 1: cout << "debug succ" << endl;
				}

				 }
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: break;
			}
		}
        else cout << "Unable to open file!";
	}
	else {
		//Вход през конзола
		cout << "Choose a geomethrical object by inputting the corresponding number." << endl;
		do
		{
		cout << "1 - Point" << endl;
		cout << "2 - Vector" << endl;
		cout << "3 - Line" << endl;
		cout << "4 - Segment (Coming soon!)" << endl;
		cout << "5 - Triangle" << endl;
		cout << "6 - Tetrahedron (Coming soon!)" << endl;
		cout << "0 - Exit" << endl;
		cin >> objectSelect;
		} while (objectSelect < 0 || objectSelect > 6);
		
		switch (objectSelect)
			{
		    case 1: {
				ObjectSelectOne(A, B); //Point only has 1 operation available.
				break; 
		    }
			case 2: 
			{
				break;
			}
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: break;
			case 0: {
				bool writeCheck = 1;
				cout << "Write object information to file? 0 for yes, 1 for no." << endl;
				cin >> writeCheck;

				if (writeCheck)
				{
					exit(0);
				}
				else
				{
					ofstream myfile2;
					myfile2.open("VectorObjectsInformation.txt");
					switch (objectSelect)
					{
					case 1:
					{
						myfile2 << "Point details: " << endl;
						myfile2 << A;
						break; }
					case 2:
					{
						myfile2 << "Vector details: " << endl;
						myfile2 << V;
						break; }
					}
					myfile2.close();

					exit(0);
				}
				break;
			}
				
		}
	}

	cin.get();
	return 0;
}

