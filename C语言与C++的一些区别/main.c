#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

int main()
{
	int a = 5;
	int b = 6;
	//int ret = a > b ? a : b;  //��Ŀ��������ص���ֵ�����ܷ��� ��=�� ���
	//printf("%d", ret);
	*(a > b ? &a : &b) = 20;

}


int main0()
{
	/*printf("Hello World!\n");
	char name[50] = { 0 };
	scanf("%s", name);
	printf("%s", name);
	while (true)
	{
		;
	}*/

	//C���Բ��ᱨ��
	//void* p = NULL;  //void* --> int*
	//int* p1 = p;

	//double* pi = NULL;  //double* --> void*
	//p = pi;

	//const int age = 18;   //����һ��ֻ������
	//printf("%p\n", &age);
	//int* pt = &age;
	//*pt = 20;
	//printf("%d %p\n", age, &age); //���22

	return 0;
}