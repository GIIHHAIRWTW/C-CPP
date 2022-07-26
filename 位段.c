#define _CRT_SECURE_NO_WARNINGS 1
//1.位段的成员通常是同一种类型
//2.位段的成员名后面有一个冒号和数字
#include<stdio.h>
struct S
{
	int a : 2;
	int b : 5;
	int c : 10;
	int d : 30;
};

int main()
{
	struct S s1 = { 0 };
	printf("%d", sizeof(s1));
	return 0;
}