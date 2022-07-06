#include <stdio.h>
#include "Point.h"

int main()
{
	Point pointA = { 1, 3 };
	Point pointB = { 1, 1 };

	printf("Comparing points, result: %d", compareDistancesFromOrigin(pointA, pointB));

	return 0;
}