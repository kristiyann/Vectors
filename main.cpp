#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	bool insertSelect; //���������� �� ���������� �� ������ �� ����
	unsigned objectSelect, operationSelect;

	cout << "Select method of insertion: type 0 for using a txt file or 1 for using console." << endl;
	cin >> insertSelect;

	//�������� �� ������ �� ����
	if (insertSelect == 0)
	{
		//���� ���� ������� ����
		string fileName, line;
		cout << "Enter file name(including file format, e.g. - filename.txt):" << endl;
		cin >> fileName;

		ifstream myfile(fileName);
		
		myfile.open(fileName);

		if (myfile.is_open())
		{
			while (!myfile.eof())
			{
				cout << line << endl;
			}
			myfile.close();
		}

		else cout << "Unable to open file!";
	}
	else {
		//���� ���� �������
		cout << "Choose a geomethrical object by inputting the corresponding number." << endl;
		do
		{
		cout << "1 - Point" << endl;
		cout << "2 - Vector" << endl;
		cout << "3 - Line" << endl;
		cout << "4 - Segment" << endl;
		cout << "5 - Triangle" << endl;
		cout << "6 - Tetrahaedon" << endl;
		cout << "0 - Exit" << endl;
		cin >> objectSelect;
		} while (objectSelect < 0 || objectSelect > 6);
		
		switch (objectSelect)
			{
		case 1: {
			double x, y, z;
			double x2, y2, z2;

			cout << "Please enter x value for the point:" << endl;
			cin >> x;
			cout << "Please enter y value for the point:" << endl;
			cin >> y;
			cout << "Please enter z value for the point:" << endl;
			cin >> z;

			Point P(x, y, z);

			cout << "Choose an operation to execute:" << endl;
			do {
				cout << "1 - Compare points" << endl;
				cin >> operationSelect;
			} while (operationSelect > 1);

			cout << "Enter xyz values for 2nd point to compare:" << endl;
			cin >> x2; cin >> y2; cin >> z2;

			Point P2(x2,y2,z2);

			P.operator==(P2);

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
				cout << "Write object information to file? 0 for yes, 1 for no!" << endl;
				cin >> writeCheck;

				if (writeCheck)
				{
					exit(0);
				}
				else
				{

				}
			}
				break;
		}
	}


	cin.get();
	return 0;
}