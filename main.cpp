#include <cstdlib>
#include <iostream>
#include "RatNum.h"
#include "stdfloat.h"

int main(/*int argc, char** argv*/) {
	RatNum a(1, 2);
	RatNum b(1, 3);
	RatNum c = a + b;

	std::cout << a << " + " << b << " = " << c << std::endl;
	return EXIT_SUCCESS;
}
