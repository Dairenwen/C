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
	int nDel;//ɾ����ʶ��δɾ����ɾ��

}Card;

//������
typedef struct CardNode
{
	Card card;
	struct CardNode* next;
}CardNode;