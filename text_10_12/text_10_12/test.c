#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include"game.h"
void menu()
{
	printf("***********************\n");
	printf("*********ɨ��**********\n");
	printf("***********************\n");
	printf("***1.����Ϸ***0.�˳�***\n");
	printf("***********************\n");
}
void game()
{
	char mine[HANGS][LIES] = { 0 };
	char show[HANGS][LIES] = { 0 };
	playboard(mine, HANGS, LIES, '0');
	playboard(show, HANGS, LIES, '*');
	//displayboard(mine, HANG, LIE);
	displayboard(show, HANG, LIE);
	designboard(mine, HANG, LIE);
	//displayboard(mine, HANG, LIE);
	playerboard(mine, show, HANG, LIE);

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
			printf("����ɹ�>: \n");
			game();
			break;
		case 0:
			printf("�����˳�>:\n");
			break;
		default:
			break;
		}
	} while (input);
	printf("���˳�>:");
	return 0;
}