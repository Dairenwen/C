#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"game.h"
void playboard(char board[HANG][LIE], int hang, int lie)
{
	int i = 0;
	for (i = 0; i < hang; i++)
	{
		int j = 0;
		for (j = 0; j < lie; j++)
		{
			board[i][j]=' ';
		}
	}
}
void displayboard(char board[HANG][LIE], int hang, int lie)
{
	int i = 0;
	for (i = 0; i < hang; i++)
	{
		int j = 0;
		for (j = 0; j < lie; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < lie - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < hang - 1)
		{
			for (j = 0; j < lie;j++)
			{
				printf("---");
				if (j < lie - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void playerboard(char borad[HANG][LIE], int hang, int lie)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("请输入:> ");
	    scanf("%d %d", &i, &j);
		if (i >= 1 && i <= lie && j >= 1 && j <= hang)
		{
			printf("输入正确，请稍后>: \n");
			Sleep(1000);
			if (borad[i - 1][j - 1] == ' ')
			{
				borad[i - 1][j - 1] = '$';
				break;
			}
			else
			{
				printf("已被占用，请重新输入");
			}
		}
		else
		{
			printf("输入非法，请重新输入>: \n");
		}
	}
}
void computerboard(char borad[HANG][LIE], int hang, int lie)
{
	printf("电脑走>: \n");
    Sleep(1500);
	int a = 0;
	int b = 0;
	while (1)
	{
		a = rand() % hang;//a=0,1,2
	    b = rand() % lie;//b=0,1,2
		if (borad[a][b] == ' ')
		{
			borad[a][b] = '#';
			break;
		}
		else
			continue;
	}
}
int judgefull(char borad[HANG][LIE], int hang, int lie)
{
	int i = 0;
	for (i = 0; i < hang; i++)
	{
		int j = 0;
		for (j = 0; j < lie;j++)
		{
			if (borad[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char judgement(char borad[HANG][LIE], int hang, int lie)
{
	int i = 0;
	//行相同
	for (i = 0; i < hang; i++)
	{
		if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][0] != ' ')
		    return borad[i][0];
	}
	int j = 0;
	//列相同
	for (j = 0; j < lie; j++)
	{
		if (borad[0][j] == borad[1][j] && borad[1][j] == borad[2][j] && borad[0][j] != ' ')
			return borad[0][j];
	}
	//两个对角线
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[0][0] != ' ')
		return borad[0][0];
	if (borad[2][0] == borad[1][1] && borad[1][1] == borad[0][2] && borad[2][0] != ' ')
		return borad[2][0];
	if (1 == judgefull(borad,HANG,LIE))
	{
		return 'B';
	}
    return 'A';
}