#pragma once
#include <exception>

using namespace std;

class VectorLengthException : public exception
{
public:
	explicit VectorLengthException(const double message);
	
	

};
