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

void ObjectSelectOne()
{
	cout << "You have selected the object Point which has only 1 operation available." << endl;

	Point P, P2;

	cout << "Enter values for 1st point to compare:" << endl;
	cin >> P;

	cout << "Enter values for 2nd point to compare:" << endl;
	cin >> P2;

	if (P.operator==(P2))
		cout << "The points are equal." << endl;
	else
		cout << "The points are NOT equal." << endl;

}

int main() {
	setlocale(LC_ALL, "");
	cout << setprecision(2);
	bool insertSelect; //Променлива за проверката на метода на вход
	unsigned objectSelect, operationSelect;

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
				myfile >> objectSelect;
				if (objectSelect == 1)
				{
					break;
				}
			}
			
            myfile.close();

			switch (objectSelect)
			{
			case 1: ObjectSelectOne(); break;
			case 2: break;
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
		cout << "4 - Segment" << endl;
		cout << "5 - Triangle" << endl;
		cout << "6 - Tetrahedron" << endl;
		cout << "0 - Exit" << endl;
		cin >> objectSelect;
		} while (objectSelect < 0 || objectSelect > 6);
		
		switch (objectSelect)
			{
		    case 1: {
				ObjectSelectOne(); break; 
		    }
			case 2: 
			{
				Vector V;

				cin >> V;

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
					//
				}
			}
				break;
		}
	}


	cin.get();
	return 0;
}