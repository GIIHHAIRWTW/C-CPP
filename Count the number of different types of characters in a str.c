#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int letter = 0, blank = 0, digit = 0, other = -1;
	char ch;
	int i = 0;
	printf("请输入一串字符:");
	do
	{
		ch = getchar();
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			letter++;
		else if (ch == ' ')
			blank++;
		else if (ch >= '0' && ch <= '9')
			digit++;
		else
			other++;
	} while (ch != '\n');
	printf("输入的字符中有英文字母%d个，空格%d个，数字%d个，其它字符%d个\n", letter, blank, digit, other);
	return 0;
}