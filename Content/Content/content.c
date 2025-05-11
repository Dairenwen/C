#define _CRT_SECURE_NO_WARNINGS 1
#include"content.h"

//��̬�汾
//void initcontact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��̬�汾
void initcontact(Contact* pc)
{
	pc->sz = 0;
	PeoInfo* tmp = (PeoInfo*)calloc(start_sz, sizeof(PeoInfo) * start_sz);
	if (tmp == NULL)
	{
		perror("initcontact::calloc");
		return;
	}
	pc->data = tmp;
	pc->capacity = start_sz;
}

//��̬�汾
//void Addcontact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("���ˣ���Ӳ���\n");
//		return;
//	}
//	printf("���������֣�");
//	scanf("%s", pc->data[pc->sz].name);//����name������Ԫ�ص�ַ��������&
//	printf("���������䣺");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�������Ա�");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("�������ַ��");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("������绰��");
//	scanf("%s", pc->data[pc->sz].tele);
//	pc->sz++;
//}

//��̬�汾
void checkdata(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* tmp = (PeoInfo*)realloc(pc->data, (pc->capacity + inc_sz) * sizeof(PeoInfo));
		if (tmp == NULL)
		{
			perror("checkdata::realloc");
			return;
		}
		pc->data = tmp;
		pc->capacity += inc_sz;
	}
}
void Addcontact(Contact* pc)
{
	checkdata(pc);
	printf("���������֣�");
	scanf("%s", pc->data[pc->sz].name);//����name������Ԫ�ص�ַ��������&
	printf("���������䣺");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�");
	scanf("%s", pc->data[pc->sz].sex);
	printf("�������ַ��");
	scanf("%s", pc->data[pc->sz].addr);
	printf("������绰��");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
}

void Showcontact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("  %-10s\t%-5s\t%-5s\t%-10s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-2d%-10s\t%-5d\t%-5s\t%-10s\t%-12s\n",i+1, pc->data[i].name,
															pc->data[i].age,
															pc->data[i].sex,
															pc->data[i].addr,
															pc->data[i].tele);
	}
}

void Delcontact(Contact* pc)
{
	printf("��ѡ����Ҫɾ����ͨѶ¼��");
	int input = 0;
	int i = 0;
	scanf("%d", &input);
	if (pc->sz == 0)
	{
		printf("��Ǹ��û������\n");
		return;
	}
	for (i = input - 1; i < (pc->sz) - 1; i++)
	{
		strcpy(pc->data[i].name, pc->data[i + 1].name);
		pc->data[i].age = pc->data[i + 1].age;
		strcpy(pc->data[i].sex, pc->data[i + 1].sex);
		strcpy(pc->data[i].addr, pc->data[i + 1].addr);
		strcpy(pc->data[i].tele, pc->data[i + 1].tele);
	}
	pc->sz--;
}

int FindSbname(const Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			printf("�٣������У���С֭\n");
			return i;
		}
	}
	return -1;
}

void Searchcontact(const Contact* pc)
{
	assert(pc);
	char name[10] = { 0 };
	printf("���������֣�");
	scanf("%s", &name);
	int ret = FindSbname(pc, name);
	if (ret == -1)
	{
		printf("����û��\n");
	}
	else
	{
		printf("%-2d%-10s\t%-5d\t%-5s\t%-10s\t%-12s\n", ret + 1, pc->data[ret].name,
			pc->data[ret].age,
			pc->data[ret].sex,
			pc->data[ret].addr,
			pc->data[ret].tele);
	}
}

void Modifycontact(Contact* pc)
{
	printf("��������Ҫ�޸ĵ����֣�");
	char name[10] = { 0 };
	scanf("%s", &name);
	int ret = FindSbname(pc, name);
	if (ret == -1)
	{
		printf("ŶӴ��û��������ݣ����ڸ�ʲô����\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", pc->data[ret].name);
		printf("���������䣺");
		scanf("%d", &(pc->data[ret].age));
		printf("�������Ա�");
		scanf("%s", pc->data[ret].sex);
		printf("�������ַ��");
		scanf("%s", pc->data[ret].addr);
		printf("������绰��");
		scanf("%s", pc->data[ret].tele);
	}
}
//�ͷ��ڴ�ռ�ÿռ�
void Destroycontact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}