#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stddef.h>   //offsetof();ͷ�ļ�
//#pragma pack(4) ����Ĭ�϶�����Ϊ4
//#pragma pack() ȡ�����õ�Ĭ�϶�����
//��ƽṹ��ʱ�����������Ҫ��ʡ�ռ�:
//        ��ռ�ÿռ�С�ĳ�Ա����������һ��
// �� size_t offsetof(structName,memberName);����ṹ���Աƫ����
//typedef struct Node
//{
//	int date;
//	struct Node* next;
//}Node;
//int main()
//{
//	struct Node n1;
//	Node n2;
//	return 0;
//}
struct S1
{
	char c1;
	int a;
	char c2;
};
struct S2
{
	char c1;
	char c2;
	int a;
};
struct S3
{
	char c;
	struct S2;
	int b;
};
int main()
{
	struct S1 s1 = { 0 };
	struct S2 s2 = { 0 };
	struct S3 s3 = { 0 };
	/*
	1.��һ����Ա��������ṹ�����ƫ����Ϊ0�ĵ�ַ��
	2.������Ա����Ҫ���䵽ĳ������(������)���������ĵ�ַ��
	��������������Ĭ�϶�������ó�Ա��С�Ľ�Сֵ
	VS��Ĭ�϶�����Ϊ8
	3.�ṹ���ܴ�СΪ��������(ÿ����Ա��������һ��������)��������
	4.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ���������������������
	  �ṹ��������С����������������(��Ƕ�׽ṹ��Ķ�����)��������
	*/
	printf("%d\n", sizeof(s1));//1 + '3' + 4 + 1 + '3' ---> 12
	printf("%d\n", sizeof(s2));//1 + 1 + 2 + '4' ---> 8
	printf("%d\n", sizeof(s3));//1 + '3' + 8 + 4 ---> 16
	printf("%d\n", offsetof(struct S2, c1));//0
	printf("%d\n", offsetof(struct S2, c2));//1
	printf("%d\n", offsetof(struct S2, a));//4
	return 0;
}