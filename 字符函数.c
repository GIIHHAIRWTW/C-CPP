#define _CRT_SECURE_NO_WARNINGS 1
#include<ctype.h>
#include<stdio.h>
/*
iscntrl		任何控制字符
isspace		空白字符:'',\n,\f(换页),\r(回车),\t(制表符),\v(垂直制表符)
isdigit		十进制数字 0-9
isxdigit	十六进制数字,0-9,a-f,A-F
islower		a-z
isupper		A-Z
isalpha		a-z或A-Z
isalnum		0-9或a-z或A-Z
ispunct		标点符号，任何不属于数字或者字母的图形字符(可打印)
isgraph		任何图形字符
isprint		任何可打印字符,包括图形字符和空白字符
*/

/*
int tolower(int c)
int toupper(int c)
*/

int main()
{
	char arr[] = "I Am A Student";
	int i = 0;
	while (arr[i])
	{
		if (isupper(arr[i]))
		{
			arr[i] = tolower(arr[i]);
		}
		i++;
	}
	printf("%s", arr);
	return 0;
}