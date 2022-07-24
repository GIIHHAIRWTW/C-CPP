#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	//errno是一个全局的错误码变量
//	//当C语言库函数在执行过程中发生了错误，就会把对应的错误码赋值给errno
//	//0 ---> No error
//	//1 ---> Operation not permitted
//	//2 ---> No such file or directory
//	//3 ---> No such process
//	// ......
//	char* str = strerror(3);
//	printf("%s", str);
//	return 0;
//}