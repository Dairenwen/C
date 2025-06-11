#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

//����Զ�����������


typedef struct Card
{
	char aName[19];//����
	char aPwd[9];//����
	int nStatus;//��״̬��δ�ϻ��������ϻ�����ע����ʧЧ
	time_t tStart;//����ʱ��
	//time_t�Ǳ�ʾʱ����������ͣ�ͨ��ʵ��Ϊ�������ͣ���long����long long�������ڴ洢ʱ���
	time_t tEnd;//���Ľ�ֹʱ��
	double fTotalUse;//�ۼ�ʹ�ý��
	time_t tLast;//���ʹ��ʱ��
	int nUseCount;//ʹ�ô���
	double fBalance;//���
	double fstart;//�������
	double fCharge;//��ֵ���
	double fRefund;//�˿���
	int nDel;//ɾ����ʶ��δɾ����ɾ��

}Card;

//������
typedef struct CardNode
{
	Card card;
	struct CardNode* next;
}CardNode;

//������Ϣ
typedef struct Billing
{
	char aName[19];//����
	time_t tStart;//�ϻ�ʱ��
	time_t tEnd;//�»�ʱ��
	double fAmount;//���ѽ��
	int nStatus;//����״̬��δ���㣬�ѽ���
	int nDel;//ɾ����ʶ��δɾ����ɾ��
}Billing;

//������Ϣ������
typedef struct BillingNode
{
	Billing billing;
	struct BillingNode* next; 
}BillingNode;

//�ϻ���Ϣ�ṹ��
typedef struct LogonInfo
{
	char aName[19];//����
	time_t tStart;//�ϻ�ʱ��
	double fBalance;//�ϻ������
}LogonInfo;

//�»���Ϣ�ṹ��
typedef struct LogoffInfo
{
	char aName[19];//����
	time_t tStart;//�ϻ�ʱ��
	time_t tEnd;//�»�ʱ��
	double fAmount;//���ѽ��
	double fBalance;//�»������
}LogoffInfo;