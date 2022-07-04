#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fac1(int n)
{
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

//int Fac2(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * Fac2(n - 1);
//}

int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = Fac1(n);                   //ret = Fac2(n);
	printf("阶乘为:%d\n", ret);
	return 0;
}
