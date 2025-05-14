#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<windows.h>
#include<time.h>

#define strat_sz 3
#define inc_sz 2

#define MAX 100

typedef struct peoinfo
{
	char name[20];
	char sex[10];
	char tele[13];
	char addr[40];
}Peo;

//typedef struct contact
//{
//	Peo data[MAX];
//	int sz;
//}Contact;

typedef struct contact
{
	Peo* data;
	int sz;
	int capacity;
}Contact;

void Initcontact(Contact* pc);

void Addcontact(Contact* pc);

void Delcontact(Contact* pc);

void Searchcontact(Contact* pc);

void Modifycontact(Contact* pc);

void Showcontact(Contact* pc);

void checkdata(Contact* pc);

void Destroycontact(Contact* pc);

void Savecontact1(Contact* pc);

void Savecontact2(Contact* pc);