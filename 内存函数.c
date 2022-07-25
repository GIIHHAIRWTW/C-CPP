#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//内存拷贝
//void* memcpy(void* destination, const void* source, size_t num);
// 处理内存重叠拷贝的情况
//void* memmove(void* destination, const void* source, size_t num);
//int memcmp(const void* ptr1,const void* ptr2,size_t num);
//void* memset(void* ptr, int value, size_t num);
void* my_memcpy(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest && src);
	while (num--)
	{
		*(char*)dest = *(char*)src;
		++(char*)dest;
		++(char*)src;
	}
	return ret;
}

void* my_memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest && src);
	if (dest < src)
	{
		//从前向后拷贝
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		//从后向前拷贝
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[] = { 1,2,3,4,5,6,7,8,9,10 };
	//my_memcpy(arr2, arr1, sizeof(arr1));
	//[1,2,3,4,5] --> [3,4,5,6,7]
	my_memmove(arr1 + 2, arr1, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	//[3,4,5,6,7] ---> [1,2,3,4,5]
	my_memmove(arr2, arr2 + 2, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}