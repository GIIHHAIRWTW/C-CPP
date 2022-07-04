#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int pow(int x, int y)
{
	int z = 1;
	while (y)
	{
		z *= x;
		y--;
	}
	return z;
}

int main()
{
	int num = 100, a, b, c;
	printf("水仙花数有:");
	for (num = 100; num < 1000; num++)
	{
		a = num / 100;
		b = (num / 10) % 10;
		c = num % 10;
		if (num == pow(a, 3) + pow(b, 3) + pow(c, 3))
			printf("%d ", num);
	}
	return 0;
}
