#include "Element.h"
#include "Point.h"
#include "Vector.h"
#include "VectorLengthException.h"
#include <iostream>

using namespace std;

int main() {
	bool insertSelect;
	unsigned objectSelect, operationSelect;

	std::cout << "Select method of insertion: type 0 for using console or 1 for using a text file." << endl;
	std::cin >> insertSelect;

	if (insertSelect == 0)
	{

	}
	else {
		std::cout << "Choose geomethrical object by inputting the corresponding number." << endl;
		do
		{
		std::cout << "1 - Point" << endl;
		std::cout << "2 - Vector" << endl;
		std::cout << "3 - Line" << endl;
		std::cout << "4 - Segment" << endl;
		std::cout << "5 - Triangle" << endl;
		std::cout << "6 - Tetrahaedon" << endl;
		std::cin >> objectSelect;
		} while (objectSelect < 0 || objectSelect > 6);
		
		switch (objectSelect)
			{
		case 1: {
			double x, y, z;
			double x2, y2, z2;

			std::cout << "Please enter x value for point:" << endl;
			std::cin >> x;
			std::cout << "Please enter y value for point:" << endl;
			std::cin >> y;
			std::cout << "Please enter z value for point:" << endl;
			std::cin >> z;

			Point P(x, y, z);

			std::cout << "Choose operation" << endl;
			do {
				std::cout << "1 - Compare points" << endl;
				std::cin >> operationSelect;
			} while (operationSelect != 0);

			std::cout << "Enter xyz values for 2nd point to compare:" << endl;
			std::cin >> x; std::cin >> y; std::cin >> z;

			Point P2(x2,y2,z2);

			P.operator==(P2);

			break; 
		}
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
			case 6: break;

			}
		

	}


	system("PAUSE");
	return 0;
}