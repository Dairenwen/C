#define _CRT_SECURE_NO_WARNINGS 1
#include"content.h"

//静态版本
//void initcontact(Contact* pc)
//{
//	pc->sz = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态版本
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

//静态版本
//void Addcontact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("满了，添加不了\n");
//		return;
//	}
//	printf("请输入名字：");
//	scanf("%s", pc->data[pc->sz].name);//这里name代表首元素地址，不用再&
//	printf("请输入年龄：");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别：");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入地址：");
//	scanf("%s", pc->data[pc->sz].addr);
//	printf("请输入电话：");
//	scanf("%s", pc->data[pc->sz].tele);
//	pc->sz++;
//}

//动态版本
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
	printf("请输入名字：");
	scanf("%s", pc->data[pc->sz].name);//这里name代表首元素地址，不用再&
	printf("请输入年龄：");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别：");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入地址：");
	scanf("%s", pc->data[pc->sz].addr);
	printf("请输入电话：");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
}

void Showcontact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("  %-10s\t%-5s\t%-5s\t%-10s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
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
	printf("请选择你要删除的通讯录：");
	int input = 0;
	int i = 0;
	scanf("%d", &input);
	if (pc->sz == 0)
	{
		printf("抱歉，没有数据\n");
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
			printf("嘿，还真有，你小汁\n");
			return i;
		}
	}
	return -1;
}

void Searchcontact(const Contact* pc)
{
	assert(pc);
	char name[10] = { 0 };
	printf("请输入名字：");
	scanf("%s", &name);
	int ret = FindSbname(pc, name);
	if (ret == -1)
	{
		printf("还真没有\n");
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
	printf("输入你想要修改的名字：");
	char name[10] = { 0 };
	scanf("%s", &name);
	int ret = FindSbname(pc, name);
	if (ret == -1)
	{
		printf("哦哟，没有这个数据，你在搞什么啊！\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", pc->data[ret].name);
		printf("请输入年龄：");
		scanf("%d", &(pc->data[ret].age));
		printf("请输入性别：");
		scanf("%s", pc->data[ret].sex);
		printf("请输入地址：");
		scanf("%s", pc->data[ret].addr);
		printf("请输入电话：");
		scanf("%s", pc->data[ret].tele);
	}
}
//释放内存占用空间
void Destroycontact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}