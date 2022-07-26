#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷����!\n");
	}
	else
	{
		printf("����������:");
		scanf("%s", ps->data[ps->size].name);
		printf("����������:");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�:");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰:");
		scanf("%s", ps->data[ps->size].tele);
		printf("������סַ:");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ�!\n");
	}
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��!");
	}
	else
	{
		printf("%-8s\t%-4s\t%-5s\t%-12s\t%-20s\n","����","����","�Ա�","�绰","סַ");
		for (int i = 0; i < ps->size; i++)
		{
			printf("%-8s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//ͨ�ò���
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name));
		{
			return i;
		}
	}
	return -1;
}

void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ������ϵ�˵�����:");
	scanf("%s", name);
	//�ҵ������±꣬���򷵻�-1
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����!\n");
	}
	else
	{
		for (int j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�!");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ�˵�����:");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����!");
	}
	else
	{
		printf("%-8s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-8s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ�˵�����:");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����!");
	}
	else
	{
		printf("����������:");
		scanf("%s", ps->data[pos].name);
		printf("����������:");
		scanf("%d", &(ps->data[pos].age));
		printf("�������Ա�:");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:");
		scanf("%s", ps->data[pos].tele);
		printf("������סַ:");
		scanf("%s", ps->data[pos].addr);
		printf("�޸����!");
	}
}