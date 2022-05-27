#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, b, r = 1, i, j;
	printf("请输入两个整数:");
	scanf("%d%d", &a, &b);
	i = a;
	j = b;
		do
		{
			r = a % b;
			a = b;
			b = r;
		} while (r != 0);
		printf("%d和%d的最大公约数是:%d\n", i, j, a);
		printf("最小公倍数是:%d", i * j / a);
		return 0;
}
