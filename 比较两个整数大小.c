#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, b, c;
	int max(int, int);
	printf("输入第一个整数:");
	scanf("%d", &a);
	printf("输入第二个整数:");
	scanf("%d", &b);
	c = max(a, b);
	printf("整数%d和整数%d的最大值是:%d\n", a, b, c);
	return 0;
}
int max(int x, int y)
{
	int z;
	if (x > y)
		z = x;
	else
		z = y;
	return z;
}
