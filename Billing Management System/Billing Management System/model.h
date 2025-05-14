#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

//存放自定义数据类型


typedef struct Card
{
	char aName[19];//卡号
	char aPwd[9];//密码
	int nStatus;//卡状态，未上机，正在上机，已注销，失效
	time_t tStart;//开卡时间
	//time_t是表示时间的算术类型，通常实现为整数类型（如long或者long long），用于存储时间戳
	time_t tEnd;//卡的截止时间
	double fTotalUse;//累计使用金额
	time_t tLast;//最后使用时间
	int nUseCount;//使用次数
	double fBalance;//余额
	int nDel;//删除标识，未删除，删除

}Card;

//链表结点
typedef struct CardNode
{
	Card card;
	struct CardNode* next;
}CardNode;