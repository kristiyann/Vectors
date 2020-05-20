#pragma once
#include <exception>

using namespace std;

class VectorLengthException : public exception
{
public:
	VectorLengthException(const double message);
	
	

};
