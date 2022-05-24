#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Count_one(unsigned int a)
{
	int count = 0;
	while (a)
	{
		if (a % 2 == 1)
		{
			count++;
		}
		a = a / 2;
	}
	return count;
}

int main()
{
	int a = 0;
	int count = 0;
	scanf("%d", &a);
	count = Count_one(a);
	printf("二进制(补码)中有--%d--个1", count);
	return 0;
}
