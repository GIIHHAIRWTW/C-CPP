#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* my_strcpy(char* dest, const char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	//拷贝src指向的字符串到dest指向的空间，包含‘\0’;
	while (*dest++ = *src++)
	{
		;
	}
	//返回目的空间起始地址
	return ret;
}

int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "hello";
	my_strcpy(arr1,arr2);
	printf("%s\n", arr1);
	return 0;
}