#include <stdio.h>
#define CHECK_ELEMENT 13


int main()
{
	printf("element %d is in index %d", CHECK_ELEMENT, get_fib_index(CHECK_ELEMENT));
	return 0;
}

int get_fib_index(int number)
{
	int counter = 0;
	int element = 1;
	int previousElement = 0;
	int placeholder = 0;

	while (number > element)
	{
		placeholder = element;

		element += previousElement;

		previousElement = placeholder;

		counter++;
	}

	return number == element ? counter : -1;
}