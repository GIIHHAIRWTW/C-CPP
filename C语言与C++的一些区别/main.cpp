#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;  //ʹ�������ռ�std

//�����ռ�
namespace nsp1
{
	int a = 1;
	int num = 76;
}

namespace nsp2
{
	int a[20] = { 0 };
}

#include<iostream>
int main0()
{
	//std::cout << "Hello World!" << " " << 123 << " " << 3.14159;
	//int num = 0;
	//char name[50];
	//cin >> num >> name;
	//cout << num << " " <<name;

	using namespace nsp1;   //ȫ������
	using nsp1::a;   //ֻ����a
	a = 100;
	cout << a << "\n" << num << "\n";
	std::cout << nsp2::a[0] << endl;

	cout << boolalpha << true;

	//C++�ᱨ��
	void* p = NULL;  //void* --> int*   error C2440: ����ʼ����: �޷��ӡ�void *��ת��Ϊ��int *��
	int* p1 = (int*)p;

	double* pi = NULL;  //double* --> void*
	p = pi;
	
	return 0;
}

int main1()
{
	//const int age = 18;   //����һ��ֻ������
	//printf("%p\n", &age);
	//int* pt = (int*)&age;   //const int* --> int*
	//*pt = 20;
	//printf("%d %p\n", age, &age);   //���18
	int a = 5;
	int b = 6;
	(a > b ? a : b) = 20; //��20��ֵ����ı���
	printf("%d", b);
	return 0;
}

void fun(int* p)
{
	*p = 666;
}

void fnu(int& q)   //int& q = num   int& -> ��������  �൱�ڸ�numȡ����
{
	q = 999;
}

int main()
{
	int num = 0;
	fun(&num);
	printf("%d\n", num);

	fnu(num);
	cout << num << endl;

	//������ʵ����ͨ��ָ��ʵ�ֵ�
	int& a = num;  //�ָ�numȡ�˸�����
	cout << &num << endl << &a << endl;
	return 0;
}