#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

void menu()
{
	printf("***********************************\n");
	printf("*****    1.add       2.del    *****\n");
	printf("*****    3.search    4.modify *****\n");
	printf("*****    5.show      0.exit   *****\n");
	printf("***********************************\n");
}

int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);

	do
	{
		menu();
		printf("请输入您的选择:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case EXIT:
			break;
		default:
			printf("选择错误，请重新输入!\n");
			continue;
		}
	} while(input);
	return 0;
}