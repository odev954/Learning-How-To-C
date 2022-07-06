#include <stdio.h>
#include "ArrayList.h"

int main()
{
	ArrayList array = create(3);

	for (int i = 0; i < 5; i++)
	{
		addElement(&array, i);
	}

	for (int i = 0; i < array.length; i++)
	{
		printf("%d ", array.list[i]);
	}
	printf("\n");

	deleteElement(&array, 3);

	for (int i = 0; i < array.length; i++)
	{
		printf("%d ", array.list[i]);
	}
	printf("\n");

	return 0;
}