#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
//void Initcontact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

void Loadcontact(Contact* pc)
{
	FILE* tmp = fopen("Contact_Plus.txt", "rb");
	if (tmp == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		Peo p;
		int i = 0;
		//fread的返回值为读到的数据个数
		while (fread(&p, sizeof(Peo), 1, tmp))
		{
			checkdata(pc);
			pc->data[i] = p;
			pc->sz++;
			i++;
		}
		fclose(tmp);
		tmp = NULL;
	}
}
void Initcontact(Contact* pc)
{
	pc->sz = 0;
	Peo* tmp = (Peo*)calloc(strat_sz, sizeof(Peo));
	if (tmp == NULL)
	{
		perror("calloc");
	}
	else
	{
		pc->data = tmp;
		pc->capacity = strat_sz;
	}
	//加载信息到通讯录
	Loadcontact(pc);
}

void checkdata(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		Peo* tmp = (Peo*)realloc(pc->data, sizeof(Peo) * (pc->capacity + inc_sz));
		if (tmp == NULL)
		{
			perror("realloc");
			return;
		}
		printf("扩容成功！\n");
		pc->data = tmp;
		pc->capacity += inc_sz;
	}
}

//void Addcontact(Contact* pc)
//{
//	if (pc->sz >= MAX)
//	{
//		printf("contact满了\n");
//	}
//	else
//	{
//		printf("请输入name:\n");
//		printf("请输入sex：\n");
//		printf("请输入tele:\n");
//		printf("请输入addr：\n");
//		scanf("%s\n%s\n%s\n%s", pc->data[pc->sz].name, pc->data[pc->sz].sex, pc->data[pc->sz].tele, pc->data[pc->sz].addr);
//		pc->sz++;
//	}
//}


void Addcontact(Contact* pc)
{
	checkdata(pc);
		printf("请输入name:\n");
		printf("请输入sex：\n");
		printf("请输入tele:\n");
		printf("请输入addr：\n");
		scanf("%s\n%s\n%s\n%s", pc->data[pc->sz].name, pc->data[pc->sz].sex, pc->data[pc->sz].tele, pc->data[pc->sz].addr);
		pc->sz++;
}


void Showcontact(Contact* pc)
{
	printf("%-10s\t%-10s\t%-12s\t%-40s\n", "名字", "性别", "电话", "地址");
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-10s\t%-12s\t%-40s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
	}
}

void Delcontact(Contact* pc)
{
	printf("请输入你想删除的名字：\n");
	char input[10] = { 0 };
	gets(input);
	int i = 0;
	int flag = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(input, pc->data[i].name) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("没有找到，你在搞什么啊！\n");
	}
	else
	{
		int j = 0;
		for (j = i; j < pc->sz - 1; j++)
		{
			strcpy(pc->data[j].name , pc->data[j + 1].name);
			strcpy(pc->data[j].sex, pc->data[j + 1].sex);
			strcpy(pc->data[j].tele, pc->data[j + 1].tele);
			strcpy(pc->data[j].addr, pc->data[j + 1].addr);
		}
		pc->sz--;
	}
}

void Searchcontact(Contact* pc)
{
	printf("请输入你想找到的名字：\n");
	char input[10] = { 0 };
	scanf("%s", &input);
	int i = 0;
	int flag = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(input, pc->data[i].name) == 0)
		{
			flag = 1;
			printf("嘿，你小汁！\n");
			printf("%-10s\t%-10s\t%-12s\t%-40s\n", pc->data[i].name, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
			break;
		}
	}
	if (flag == 0)
	{
		printf("没有找到，你在搞什么啊！\n");
	}
}

void Modifycontact(Contact* pc)
{
	printf("请输入你想修改的名字：\n");
	char input[10] = { 0 };
	scanf("%s", &input);
	int i = 0;
	int flag = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(input, pc->data[i].name) == 0)
		{
			flag = 1;
			printf("嘿，你小汁！\n");
			printf("请输入name:\n");
			printf("请输入sex：\n");
			printf("请输入tele:\n");
			printf("请输入addr：\n");
			scanf("%s\n%s\n%s\n%s", pc->data[i].name, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
			break;
		}
	}
	if (flag == 0)
	{
		printf("没有找到，你在搞什么啊！\n");
	}
}

void Destroycontact(Contact* pc)
{
	pc->sz = 0;
	pc->capacity = 0;
	free(pc->data);
	pc->data = NULL;
}

void Savecontact1(Contact* pc)
{
	FILE* tmp =fopen("Contact_Plus.txt", "wb");
	if (tmp == NULL)
	{
		perror("fopen");
	}
	else
	{
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			fwrite(pc->data, sizeof(Peo), 1, tmp);
		}
		fclose(tmp);
		tmp = NULL;
	}
}

void Savecontact2(Contact* pc)
{
	FILE* tmp = fopen("Contact_Plus.txt", "w");
	if (tmp == NULL)
	{
		perror("fopen");
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < pc->sz; i++)
		{
			fprintf(tmp ,"%s %s %s %s", pc->data[i].name, pc->data[i].sex, pc->data[i].tele, pc->data[i].addr);
		}
	}
	fclose(tmp);
	tmp = NULL;
}