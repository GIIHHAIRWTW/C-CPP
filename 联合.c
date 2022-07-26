#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//成员共用同一块空间
//联合的大小至少是最大成员的大小
//当最大成员大小不是最大对齐数的整数倍时，就要对齐到最大对齐数的整数倍
union Un
{
	char c;
	int i;
};

int main()
{
	union Un u;
	printf("%d\n", sizeof(u));
	printf("%p\n", &u);
	printf("%p\n", &u.c);
	printf("%p\n", &u.i);
	return 0;
}