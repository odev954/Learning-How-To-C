#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct Rectangle 
{
	double length;
	double width;
} Rectangle;

double getArea(Rectangle shape)
{
	return shape.width * shape.length;
}

Rectangle compareRectanglesArea(Rectangle shapeA, Rectangle shapeB)
{
	Rectangle result = shapeA;

	if (getArea(shapeA) < getArea(shapeB))
	{
		result = shapeB;
	}

	return result;
}

int canBeEncapsulated(Rectangle shapeA, Rectangle shapeB)
{
	return (shapeA.width > shapeB.width && shapeA.length > shapeB.length) ||
		   (shapeB.width > shapeA.width && shapeB.length > shapeA.length) ? 1 : 0;
}

#endif