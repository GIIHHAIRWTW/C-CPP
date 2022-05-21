#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Reverse(int n)
{
	while (n)
	{
		printf("%d ", n % 10);
		n = n / 10;
	}
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	a = Reverse(a);
	return 0;
}