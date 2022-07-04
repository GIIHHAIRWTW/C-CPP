#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct Stu
{
	char name[10];
	int age;
};

void Swap(char* buf1,char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

int cmp_stu_by_age(const void* e1, const void* e2)
{

	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

int cmp_stu_by_name(const void* e1, const void* e2)
{

	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}

void bubble_sort(void* base, int sz, int width,int(*cmp)(void*e1,void*e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if ((cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0))
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}

void test4()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]),cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test5()
{
	struct Stu s[3] = { {"zhangsan",30},{"lisi",20},{"wangwu",10} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	int i = 0;
	/*for (i = 0; i < sz; i++)
	{
		printf("%d ", s[i].age);
	}*/
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	/*for (i = 0; i < sz; i++)
	{
		printf("%s ", s[i].name);
	}*/

}

int main()
{
	test4();
	test5();
	return 0;
}