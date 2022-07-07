#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int is_left_move(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)
		return 0;
	char* ret = strncat(str1, str1, len1);
	if (ret == NULL)
		return 0;
	else
		return 1;
}

int main()
{
	char arr1[30] = "abcdef";
	char arr2[] = "cdef";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes");
	else
		printf("No");
	return 0;
}