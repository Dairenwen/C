#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

bool initCardList();//初始化链表

bool addCard(Card card);//添加卡

bool addCardlist(Card card);//添加卡

Card* queryCardName(const char* aName);//查询卡号

Card* queryCardNamelist(const char* aName);//查询卡号

bool queryCardPwd(const Card* pCard, const char* Pwd);//查询密码

bool _queryCardName(const char* aName);//模糊查询卡

bool _queryCardNamelist(const char* aName);//模糊查询卡

void printallcard(const char* aName);//打印所有可能卡号

void printallcardlist(const char* aName);//打印所有可能卡号

void printCardList();//打印所有卡信息

bool cancelCardList(const char* aName);//注销卡

void releaseCardList();//释放链表

bool logonCardList(const char* aName);//上机

bool judgeonstatus(CardNode* cur);//判断卡的状态

bool logoffCardList(const char* aName);//下机

bool judgeoffstatus(CardNode* cur);//判断卡的状态

double countmoney(CardNode* cur);//计算消费金额

bool rechargeCardList(const char* aName);//充值

bool refundCardList(const char* aName);//退款

bool judgecancelstatus(CardNode* cur);//判断卡的状态

int inputTimeRange(time_t* start, time_t* end);

void print_open_detail_and_summary(time_t start, time_t end);

void print_consume_detail_and_summary(time_t start, time_t end);

void print_recharge_refund_detail_and_summary(time_t start, time_t end);

