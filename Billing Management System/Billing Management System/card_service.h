#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

bool initCardList();//��ʼ������

bool addCard(Card card);//��ӿ�

bool addCardlist(Card card);//��ӿ�

Card* queryCardName(const char* aName);//��ѯ����

Card* queryCardNamelist(const char* aName);//��ѯ����

bool queryCardPwd(const Card* pCard, const char* Pwd);//��ѯ����

bool _queryCardName(const char* aName);//ģ����ѯ��

bool _queryCardNamelist(const char* aName);//ģ����ѯ��

const char* tostringStatus(int n);//��״̬ת��Ϊ�ַ���

void printallcard(const char* aName);//��ӡ���п��ܿ���

void printallcardlist(const char* aName);//��ӡ���п��ܿ���

void printCardList();//��ӡ���п���Ϣ

bool cancelCardList(const char* aName);//ע����

void releaseCardList();//�ͷ�����

bool logonCardList(const char* aName);//�ϻ�

bool judgeonstatus(CardNode* cur);//�жϿ���״̬

bool logoffCardList(const char* aName);//�»�

bool judgeoffstatus(CardNode* cur);//�жϿ���״̬

double countmoney(CardNode* cur);//�������ѽ��

bool rechargeCardList(const char* aName);//��ֵ

bool refundCardList(const char* aName);//�˿�

bool judgecancelstatus(CardNode* cur);//�жϿ���״̬

int isLeapYear(int year);//�ж��Ƿ�������

int getDaysInMonth(int year, int month);//��ȡĳ�µ�����

int inputTimeRange(time_t* start, time_t* end);//����ʱ�䷶Χ

void print_open_detail_and_summary(time_t start, time_t end);// ��ӡ������ϸ�ͻ���

void print_consume_detail_and_summary(time_t start, time_t end);// ��ӡ������ϸ�ͻ���

void print_recharge_refund_detail_and_summary(time_t start, time_t end);// ��ӡ��ֵ���˿���ϸ�ͻ���

