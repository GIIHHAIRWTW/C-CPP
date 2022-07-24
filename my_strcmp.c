#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int strcmp(const char* str1, const char* str2);
/*
CÓïÑÔ±ê×¼
str1>str2 ---> >0
str1==str2 ---> =0
str1<str2 ---> <0
*/

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	//if (*str1 > *str2)
	//	return 1;
	//else
	//	return -1;
	return (*str1 - *str2);
}

int main()
{
	char* p1 = "abcdef";
	char* p2 = "rbcdef";
	printf("%d\n", my_strcmp(p1, p2));
	return 0;
}