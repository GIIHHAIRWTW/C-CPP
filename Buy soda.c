#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//一瓶汽水一元，两个空瓶换一瓶汽水

int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	if (money == 0)
		total = 0;
	else
		total = 2 * money - 1;
	/*total = money;
	empty = money;
	while (empty >= 2)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}*/
	printf("total = %d\n", total);
	return 0;
}