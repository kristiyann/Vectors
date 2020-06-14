#include "InputExceptions.h"
#include <iostream>

VectorLengthException::VectorLengthException(const unsigned message)
{
	switch (message) {
	case 0:
		std::cout << "[EXCEPTION] No unit vector because the length is 0!" << std::endl;
		break;
	case 1:
		std::cout << "[EXCEPTION] One of the vectors has a length of 0!" << std::endl;
		break;
	case 2:
		std::cout << "[EXCEPTION] One of the vectors is a zero vector!" << std::endl;
		break;
	}
}

EqualPointException::EqualPointException()
{
	std::cout << std::endl << "[EXCEPTION] Two points cannot be the same!" << std::endl << std::endl;
}