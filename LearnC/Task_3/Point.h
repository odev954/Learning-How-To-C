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

Point compareDistancesFromOrigin(Point pointA, Point pointB)
{
	Point result = pointB;
	Point origin = { 0, 0 };

	if (calculatedSquaredDistance(origin, pointA) > 
		calculatedSquaredDistance(origin, pointB))
	{
		result = pointA;
	}
	return result;
}