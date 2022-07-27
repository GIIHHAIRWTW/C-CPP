#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//void* malloc(size_t size);   动态开辟内存，不初始化
//void* calloc(size_t num, size_t size);   动态开辟内存，初始化为0
//void* realloc(void* memblock, size_t size);   调整动态开辟的内存
// 
//void free(void* ptr);   释放动态开辟的内存
int main()
{
	int* p = (int*)malloc(5*sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}

	int* ptr = (int*)realloc(p, 10*sizeof(int));
	if (ptr != NULL)
	{
		p = ptr;
	}
	int i = 0;
	for (i = 5; i < 10; i++)
	{
		*(p + i) = i;
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;
	return 0;
}