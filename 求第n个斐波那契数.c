#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

//int Fib2(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib2(n - 1) + Fib2(n - 2);
//}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fib(n);
	printf("ret=%d\n", ret);
	return 0;
}