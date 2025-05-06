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
	printf("*********扫雷**********\n");
	printf("***********************\n");
	printf("***1.玩游戏***0.退出***\n");
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
			printf("输入成功>: \n");
			game();
			break;
		case 0:
			printf("正在退出>:\n");
			break;
		default:
			break;
		}
	} while (input);
	printf("已退出>:");
	return 0;
}