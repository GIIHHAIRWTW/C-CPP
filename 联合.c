#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��Ա����ͬһ��ռ�
//���ϵĴ�С����������Ա�Ĵ�С
//������Ա��С��������������������ʱ����Ҫ���뵽����������������
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