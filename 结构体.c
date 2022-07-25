#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stddef.h>   //offsetof();头文件
//#pragma pack(4) 设置默认对齐数为4
//#pragma pack() 取消设置的默认对齐数
//设计结构体时既满足对其又要节省空间:
//        让占用空间小的成员尽量集中在一起
// 宏 size_t offsetof(structName,memberName);计算结构体成员偏移量
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
	1.第一个成员变量在与结构体变量偏移量为0的地址处
	2.其它成员变量要对其到某个数字(对齐数)的整数倍的地址处
	对齐数—编译器默认对齐数与该成员大小的较小值
	VS的默认对齐数为8
	3.结构体总大小为最大对齐数(每个成员变量都有一个对齐数)的整数倍
	4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍，
	  结构体的整体大小就是所有最大对齐数(含嵌套结构体的对齐数)的整数倍
	*/
	printf("%d\n", sizeof(s1));//1 + '3' + 4 + 1 + '3' ---> 12
	printf("%d\n", sizeof(s2));//1 + 1 + 2 + '4' ---> 8
	printf("%d\n", sizeof(s3));//1 + '3' + 8 + 4 ---> 16
	printf("%d\n", offsetof(struct S2, c1));//0
	printf("%d\n", offsetof(struct S2, c2));//1
	printf("%d\n", offsetof(struct S2, a));//4
	return 0;
}