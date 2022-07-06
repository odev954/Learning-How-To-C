#include <stdio.h>
#include "Point.h"

int main()
{
	Point pointA = { 1, 3 };
	Point pointB = { 1, 4 };
	Point result = compareDistancesFromOrigin(pointA, pointB);

	printf("Comparing points, result: (%.2f, %.2f)", result.x, result.y);

	return 0;
}