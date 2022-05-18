#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;	
	for (i = 101; i <= 200; i+=2)
	{
		int j = 0;
		for (j = 2; j <= i/2; j++)     //i/2可换为sqrt(i)
		{
			if (i % j == 0)
				break;
		}
		if (j >i/2)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
