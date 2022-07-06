#include <stdio.h>
#include "Rectangle.h"

int main()
{
	Rectangle shapeA = { 5, 6 };
	Rectangle shapeB = { 3, 4 };
	Rectangle result = compareRectanglesArea(shapeA, shapeB);

	printf("Area of shapeA: %.2f\n", getArea(shapeA));
	printf("Area comparison: (width %.2f, length %.2f)\n", result.width, result.length);
	printf("Can be Encapsulated: %s\n", canBeEncapsulated(shapeA, shapeB) ? "True" : "False");

	return 0;
}