#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* p1 = NULL;
	char* p2 = NULL;
	char* cur = (char*)str1;
	if (*str2 == '\0')
	{
		return (char*)str1;
	}
	while (*cur)
	{
		p1 = cur;
		p2 = (char*)str2;
		while ((p1 != '\0') && (p2 != '\0') && (*p1 == *p2))
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			return cur;//找到子串
		}
		if (*p2 == '\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;//找不到字串
}

int main()
{
	char* p1 = "ababcdef";
	char* p2 = "abc";
	char* ret = my_strstr(p1,p2);
	if (ret == NULL)
	{
		printf("找不到子串");
	}
	else
	{
		printf("%s", ret);
	}
	return 0;
}

