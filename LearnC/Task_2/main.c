#include <stdio.h>
#define POSITION 6


int main()
{
	printf("fibonaachi element at position %d is %d", POSITION, getFibonaachiElementAt(POSITION));
	return 0;
}

int getFibonaachiElementAt(int index)
{
	int counter = 0;
	int element = 1;
	int previousElement = 0;
	int placeholder = 0;

	while (counter < index)
	{
		placeholder = element;
		
		element += previousElement;

		previousElement = placeholder;

		counter++;
	}

	return element;
}