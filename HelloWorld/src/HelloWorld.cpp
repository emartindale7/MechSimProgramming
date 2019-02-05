//============================================================================
// Name        : HelloWorld.cpp
// Author      : Evan L. Martindale
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip> // for std::setprecision()
#include "headerfile.h"

int main() {

	int x;

	std::cout << "Bonjour, tout le monde!" << std::endl ; // prints Hello
	std::cout << "Please enter a number: " ;
	std::cin >> x;
	std::cout << "Your number was " << x << std::endl;

	/*
	int a;// double b;
	std::cout << "Size of int: " << sizeof(a);
	*/
	/*
	std::cout << std::setprecision(18);

	double d1(1.0);
	std::cout << d1 << std::endl;
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
	std::cout << d2 << std::endl;
	*/

	/*
	int outval {}, inval{};
	std::cout << "Please enter a number: " << std::endl;
	std::cin >> inval;
	outval = calcfactorial(inval);
	std::cout << "The factorial of your number is: " << outval;
	*/
	return 0;
}

