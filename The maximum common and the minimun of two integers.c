#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, b, r = 1, i, j;
	printf("��������������:");
	scanf("%d%d", &a, &b);
	i = a;
	j = b;
	while (r != 0)
		do
		{
			r = a % b;
			a = b;
			b = r;
		} while (r != 0);
		printf("%d��%d�����Լ����:%d\n", i, j, a);
		printf("��С��������:%d", i * j / a);
		return 0;
}