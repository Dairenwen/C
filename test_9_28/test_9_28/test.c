#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include"game.h"
void menu()
{
	printf("*********************\n");
	printf("********������*******\n");
	printf("*********************\n");
	printf("**1.����Ϸ***0.�˳�**\n");
	printf("*********************\n");
}
void game()
{
	char board[HANG][LIE] = { 0 };
	playboard(board, HANG, LIE);//��ʼ��
	displayboard(board, HANG, LIE);//��ӡ
	char k = 0;
	while (1)
	{
		playerboard(board, HANG, LIE);
		displayboard(board, HANG, LIE);
		k = judgement(board, HANG, LIE);
		if (k != 'A')
		{
			break;
		}
        computerboard(board, HANG, LIE);
		displayboard(board, HANG, LIE);
		k = judgement(board, HANG, LIE);
		if (k != 'A')
		{
			break;
		}
    }
	if (k == '$')
	{
		printf("YOU ARE WINNER\n");
	}
	if (k == '#')
	{
		printf("YOU ARE LOSER\n");
	}
	if (k == 'B')
	{
		printf("YOU CAN GO ON\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			system("cls");
			break;
		case 0:
			printf("wrong\n");
			break;
		default:
			printf("����������ٴ����԰ɣ�>: ");
			break;
		}
	} while (input);
	Sleep(1234);
	printf("�����˳�������\n");
	return 0;
}
