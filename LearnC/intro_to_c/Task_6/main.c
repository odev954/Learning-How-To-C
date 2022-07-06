#include <stdio.h>
#define CHECK_NUM 75

int main()
{
	printf("sqrt of %d is %d", CHECK_NUM, getSqrt(CHECK_NUM));

	return 0;
}

int getSqrt(int number)
{
	int sqrt = 0;

	while (sqrt * sqrt < number)
	{
		sqrt++;
	}

	return sqrt * sqrt == number ? sqrt : sqrt - 1;
}