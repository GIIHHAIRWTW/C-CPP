#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	int count = 0;
	while (num)
	{
		num = num & (num - 1);
		count++;
	}
	printf("二进制中的1的个数=%d\n", count);
	return 0;
}