#include"game.h"
void playboard(char board[HANGS][LIES], int hangs, int lies, char set)
{
	int i = 0;
	for (i = 0; i < hangs; i++)
	{
		int j = 0;
		for (j = 0; j < lies; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[HANGS][LIES], int hang, int lie)
{
	int i = 0;
	for (i = 0; i <= hang; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= hang; i++)
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= lie; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void designboard(char board[HANGS][LIES], int hangs, int lies)
{
	int count = EASY_MODE;
	while (count)
	{
		int x = rand() % HANG + 1;
		int y = rand() % LIE + 1;
		if (board[x][y] == '0')
		{ 
			board[x][y] = '1';
			count--;
		}
	}
}
//'3'-'0'=3;'1'-'0'=1
int get_mine_count(char mine[HANGS][LIES], int a, int b)
{
	int k = mine[a - 1][b] +
		mine[a][b - 1] +
		mine[a + 1][b - 1] +
		mine[a + 1][b] +
		mine[a + 1][b + 1] +
		mine[a][b + 1] +
		mine[a - 1][b + 1] - 8 * '0';
	return k;
}    
void playerboard(char mine[HANGS][LIES], char show[HANGS][LIES], int hang, int lie)
{
	int a, b = 0;
	int num = 0;
	while (num<HANG*LIE-EASY_MODE)
	{
		printf("请输入坐标：>");
		scanf("%d%d", &a, &b);
		if (a >= 1 && a <= hang && b >= 1 && b <= lie)
		{
			printf("输入正确:> \n");
			if (mine[a][b] == '1')//踩雷
			{
				printf("你被炸死了！哈哈哈\n");
				displayboard(mine, HANG, LIE);
				break;
			}
			else//不踩雷
			{
				int count = get_mine_count(mine, a, b);
				show[a][b] = count + '0';
				displayboard(show, HANG, LIE);
				num++;
			}
		}
		else
		{
			printf("非法，重输：>");
		}
	}
	if (num == HANG*LIE-EASY_MODE)
	{  
		printf("恭喜你，排雷成功！\n");
		displayboard(mine, HANG, LIE);
	}
}