#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int a, b;
	printf("请输入两个整数:");
	scanf("%d%d", &a, &b);
	int c = Add(a, b);
	printf("两数之和为:%d\n", c);
	return 0;
}