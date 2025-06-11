#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<math.h>
#include<ctype.h>
#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"card_service.h"
#include"billing_file.h"
#include"billing_service.h"

int main()
{
	int nSelection = 0;
	printf("\n欢迎进入计费管理系统\n");
	bool init = initCardList();
	bool initbill = initBillingList();
	if (init == false||initbill==false)
	{
		printf(RED"初始化失败！\n"NONE);
		return 0;
	}

	do
	{
		//输出系统菜单
		menu();
		printf("请选择菜单单项编号（0~8）：");
		scanf("%d", &nSelection);

		switch (nSelection)
		{
			case Quit:
				SaveCardList();
				releaseCardList();
				releaseBillingList();
				printf("\n退出\n");
				break;

			case Add:
				printf("\n添加卡\n");
				addlist();
				SaveCardList();
				break;

			case Searchcard:
				printf("\n查询卡\n");
				querylist();
				SaveCardList();
				break;

			case Logon:
				printf("\n上机\n");
				logon();
				SaveCardList();
				SaveBillingList();
				break; 

			case Logoff:
				printf("\n下机\n");
				logoff();
				SaveCardList();
				SaveBillingList();
				break;

			case Recharge:
				printf("\n充值\n");
				recharge();
				SaveCardList();
				break;

			case Refund:
				printf("\n退费\n");
				refund();
				SaveCardList();
				break;

			case Searchcount:
				printf("\n查询统计\n");
				count();
				SaveCardList();
				break;

			case Cancel:
				printf("\n注销卡\n");
				cancel();
				SaveCardList();
				break;

			default:
				printf("\n输入的菜单序号错误\n");
				break;
					
		}
	} while (nSelection);

	return 0;
}