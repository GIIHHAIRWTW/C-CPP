#define _CRT_SECURE_NO_WARNINGS 1
//1.λ�εĳ�Աͨ����ͬһ������
//2.λ�εĳ�Ա��������һ��ð�ź�����
#include<stdio.h>
struct S
{
	int a : 2;
	int b : 5;
	int c : 10;
	int d : 30;
};

int main()
{
	struct S s1 = { 0 };
	printf("%d", sizeof(s1));
	return 0;
}