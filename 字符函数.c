#define _CRT_SECURE_NO_WARNINGS 1
#include<ctype.h>
#include<stdio.h>
/*
iscntrl		�κο����ַ�
isspace		�հ��ַ�:'',\n,\f(��ҳ),\r(�س�),\t(�Ʊ��),\v(��ֱ�Ʊ��)
isdigit		ʮ�������� 0-9
isxdigit	ʮ����������,0-9,a-f,A-F
islower		a-z
isupper		A-Z
isalpha		a-z��A-Z
isalnum		0-9��a-z��A-Z
ispunct		�����ţ��κβ��������ֻ�����ĸ��ͼ���ַ�(�ɴ�ӡ)
isgraph		�κ�ͼ���ַ�
isprint		�κοɴ�ӡ�ַ�,����ͼ���ַ��Ϳհ��ַ�
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