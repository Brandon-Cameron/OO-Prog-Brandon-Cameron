#include <iostream>
#include <cmath>
#include "triangle.h"

int main()
{
	Triangle triangle;

	std::cout << "Hypotenuse of triangle is " << triangle.hypot() << std::endl;
	std::cout << "Area of triangle is " << triangle.area() << std::endl;

	return 1;
}