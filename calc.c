#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void menu()
{
	printf("**************************\n");
	printf("**  1.add        2.sub  **\n");
	printf("**  3.mul        4.div  **\n");
	printf("**        0.exit        **\n");
	printf("**************************\n");
}

float Add(float x, float y)
{
	return x + y;
}

float Sub(float x, float y)
{
	return x - y;
}

float Mul(float x, float y)
{
	return x * y;
}

float Div(float x, float y)
{
	return x / y;
}

void calc(float(*pf)(float,float))
{
	float x = 0;
	float y = 0;
	printf("����������������:");
	scanf("%f%f", &x, &y);
	printf("%f\n", pf(x, y));
}

//int main()
//{
//	int input = 0;
//	float x = 0;
//	float y = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("����������������:");
//			scanf("%f%f", &x, &y);
//			printf("%f\n", Add(x, y));
//			break;
//		case 2:
//			printf("����������������:");
//			scanf("%f%f", &x, &y);
//			printf("%f\n", Sub(x, y));
//			break;
//		case 3:
//			printf("����������������:");
//			scanf("%f%f", &x, &y);
//			printf("%f\n", Mul(x, y));
//			break;
//		case 4:
//			printf("����������������:");
//			scanf("%f%f", &x, &y);
//			printf("%f\n", Div(x, y));
//			break;
//		case 0:
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//}


//int main()
//{
//	int input = 0;
//	float x = 0;
//	float y = 0;
//	float (*pfArr[])(float, float) = { 0,Add,Sub,Mul,Div };
//	do
//	{
//		menu();
//		printf("��ѡ��:");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("����������������:");
//			scanf("%f%f", &x, &y);
//			printf("%f\n", pfArr[input](x, y));
//		}
//		else if (input == 0)
//		{
//			printf("�˳�\n");
//		}
//		else
//		{
//			printf("ѡ�����\n");
//		}
//
//	} while (input);
//	return 0;
//}


int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);
		case 2:
			calc(Sub);
		case 3:
			calc(Mul);
		case 4:
			calc(Div);
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}