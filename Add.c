#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int a, b;
	printf("��������������:");
	scanf("%d%d", &a, &b);
	int c = Add(a, b);
	printf("����֮��Ϊ:%d\n", c);
	return 0;
}