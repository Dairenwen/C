#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<errno.h>
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 5
#define ADDR_MAX 30
#define TELE_MAX 12

#define start_sz 3
#define inc_sz 2

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;

//¾²Ì¬°æ±¾
//typedef struct Contact
//{
//	PeoInfo data[MAX];
//	int sz;
//}Contact;

//¶¯Ì¬°æ±¾
typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;

void initcontact(Contact* pc);

void Addcontact(Contact* pc);

void Delcontact(Contact* pc);

void Searchcontact(const Contact* pc);

void Modifycontact(Contact* pc);

void Showcontact(const Contact* pc);

int FindSbname(const Contact* pc, char name[]);

void Destroycontact(Contact* pc);