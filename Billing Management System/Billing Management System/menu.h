#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
//��ɫ�궨��
#define NONE         "\033[m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"

void menu();//��ӡ�˵�

int getSize(const char* arr);//���ڼ������鳤��

void copy(char* des, const char* dri, int size);//�����ַ���

void add();//��ӿ�

void addlist();//��ӿ�

void query();//��ѯ��

void querylist();//��ѯ��

void _query();//ģ����ѯ��

void _querylist();//ģ����ѯ��

void logon();//�ϻ�

void logoff();//�»�

void cancel();//ע����

void recharge();//��ֵ

void count();//��ѯͳ��
