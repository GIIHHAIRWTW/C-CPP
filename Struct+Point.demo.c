#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct Stu
{
	char name[20];
	char id[20];
}Stu;
void Print1(Stu tmp)
{
	printf("Name:%s\n", tmp.name);
	printf("Id:%s\n", tmp.id);
}
void Print2(Stu* ps)
{
	printf("Name:%s\n", ps->name);
	printf("Id:%s\n", ps->id);
}
int main()
{
	Stu s = { "ÕÅÈý","B00040101" };
	Print1(s);
	Print2(&s);
	return 0;
}
