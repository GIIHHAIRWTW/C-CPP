#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//1.增加代码可读性和可维护性
//2.枚举有类型检查，更为严谨
//3.封装，防止命名污染
//4.便于调试
//5.使用方便，一次定义多个常量
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