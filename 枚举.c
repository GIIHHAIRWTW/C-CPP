#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.���Ӵ���ɶ��ԺͿ�ά����
//2.ö�������ͼ�飬��Ϊ�Ͻ�
//3.��װ����ֹ������Ⱦ
//4.���ڵ���
//5.ʹ�÷��㣬һ�ζ���������
enum COLOR
{
	RED = 2,
	GREEN,
	BLUE = 8
};

int main()
{
	//enum COLOR c = RED;
	printf("%d %d %d", RED, GREEN, BLUE);
	return 0;
}