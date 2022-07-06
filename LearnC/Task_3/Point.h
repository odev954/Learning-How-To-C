#ifndef POINT_H
#define POINT_H
#endif

typedef struct Point 
{
	double x;
	double y;
} Point;

double calculatedSquaredDistance(Point pointA, Point pointB)
{
	double deltaX = pointA.x - pointB.x;
	double deltaY = pointA.y - pointB.y;

	return deltaX * deltaX + deltaY * deltaY;
}

int compareDistancesFromOrigin(Point pointA, Point pointB)
{
	int result = 0;
	Point origin = { 0, 0 };
	double distanceA = calculatedSquaredDistance(origin, pointA);
	double distanceB = calculatedSquaredDistance(origin, pointB);

	if (distanceA > distanceB)
	{
		result = 1;
	}
	else if (distanceA < distanceB)
	{
		result = -1;
	}
	return result;
}