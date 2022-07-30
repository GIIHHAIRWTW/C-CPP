#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;  //使用命名空间std

//命名空间
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

	using namespace nsp1;   //全部导出
	using nsp1::a;   //只导出a
	a = 100;
	cout << a << "\n" << num << "\n";
	std::cout << nsp2::a[0] << endl;

	cout << boolalpha << true;

	//C++会报错
	void* p = NULL;  //void* --> int*   error C2440: “初始化”: 无法从“void *”转换为“int *”
	int* p1 = (int*)p;

	double* pi = NULL;  //double* --> void*
	p = pi;
	
	return 0;
}

int main1()
{
	//const int age = 18;   //定义一个只读变量
	//printf("%p\n", &age);
	//int* pt = (int*)&age;   //const int* --> int*
	//*pt = 20;
	//printf("%d %p\n", age, &age);   //输出18
	int a = 5;
	int b = 6;
	(a > b ? a : b) = 20; //把20赋值给大的变量
	printf("%d", b);
	return 0;
}

void fun(int* p)
{
	*p = 666;
}

void fnu(int& q)   //int& q = num   int& -> 引用类型  相当于给num取别名
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

	//引用其实就是通过指针实现的
	int& a = num;  //又给num取了个别名
	cout << &num << endl << &a << endl;
	return 0;
}