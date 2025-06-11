#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"tool.h"
#include"card_service.h"

extern CardNode* head;

void menu()//打印菜单
{
	printf("----------菜单----------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
}

int getSize(const char* arr)//用于计算数组长度
{
	return strlen(arr);
}

void copy(char* des, const char* dri, int size)//拷贝字符串
{
	memcpy(des, dri, sizeof(char) * (size + 1));
}

void add()//添加卡
{
	Card card;
	memset(&card, 0, sizeof(Card));
	char aName[64] = { 0 };
	char aPwd[32] = { 0 };
	//建立两个数组用来读取数据并判断
	printf("---------添加卡---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);

		printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
		scanf("%s", &aPwd);

		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		int nPwdSize = getSize(aPwd);
		Card* judge = queryCardName(aName);
		if (judge)
		{
			printf(RED"卡号已存在！请重新输入：\n"NONE);
		}
		if (nNameSize > 18 || nPwdSize > 8)
		{
			printf(RED"卡号或者密码超过规定长度！请重新输入：\n"NONE);
		}
	} while (getSize(aName) > 18 || getSize(aPwd) > 8 || queryCardName(aName));

	//将输入的卡号和密码拷贝到结构体中
	copy(card.aName, aName, getSize(aName));
	copy(card.aPwd, aPwd, getSize(aPwd));

	printf("请输入开卡金额：");
	scanf("%lf", &card.fBalance);

	//设置累计金额：
	card.fTotalUse = card.fBalance;

	//设置状态：
	card.nUseCount = 0;
	card.nDel = UnDel;
	card.nStatus = UnLog;

	//使用time来获取时间戳
	card.tStart = card.tEnd = card.tLast = time(NULL);

	//将卡信息添加到数组中
	bool ret=addCard(card);
	if (ret)
	{
		printf(BLUE"添加成功！\n"NONE);
		printf("\n----输入卡的信息如下：----\n");
		printf("卡号\t\t\t密码\t\t卡状态\t余额\n");
		printf("%-18s\t%-8s\t%d\t%0.1f\n", card.aName, card.aPwd,
										   card.nStatus, card.fBalance);
	}
	else
	{
		printf(RED"添加失败！卡片数量已满！\n"NONE);
		printf("请删除一些卡片后再添加！\n");	
	}
}


void addlist()//添加卡
{
	Card card;
	memset(&card, 0, sizeof(Card));
	char aName[64] = { 0 };
	char aPwd[32] = { 0 };
	//建立两个数组用来读取数据并判断
	printf("---------添加卡---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);

		printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
		scanf("%s", &aPwd);

		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		int nPwdSize = getSize(aPwd);
		Card* judge = queryCardNamelist(aName);
		if (judge)
		{
			printf(RED"卡号已存在！请重新输入：\n"NONE);
		}
		if (nNameSize > 18 || nPwdSize > 8)
		{
			printf(RED"卡号或者密码超过规定长度！请重新输入：\n"NONE);
		}
	} while (getSize(aName) > 18 || getSize(aPwd) > 8 || queryCardNamelist(aName));

	//将输入的卡号和密码拷贝到结构体中
	copy(card.aName, aName, getSize(aName));
	copy(card.aPwd, aPwd, getSize(aPwd));

	double money = 0;
	do
	{
		printf("请输入开卡金额：");
		scanf("%lf", &money);
		if (money < 0)
		{
			printf(RED"输入金额错误！请重新输入：\n"NONE);
		}
	} while (money < 0);
	card.fBalance = money;
	card.fstart = money; //设置开卡金额
	card.fCharge = money; //设置开卡金额为充值金额
	card.fRefund = 0; //设置退费金额为0

	//设置累计金额：
	card.fTotalUse = 0;

	//设置状态：
	card.nUseCount = 0;
	card.nDel = UnDel;
	card.nStatus = UnLog;

	//使用time来获取时间戳
	card.tStart = card.tEnd = card.tLast = time(NULL);

	//将卡信息添加到链表中
	addCardlist(card);
}

void _query()//模糊查询卡
{
	char aName[64] = { 0 };
	printf("---------模糊查询卡---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);
		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf(RED"卡号超过规定长度！请重新输入：\n"NONE);
		}
	} while (getSize(aName) > 18);

	//对输入的卡号进行模糊查询
	bool ret = _queryCardName(aName);
	if (ret==false)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("输出所有可能卡号：\n");
		printallcard(aName);
	}
}

void _querylist()//模糊查询卡
{
	char aName[64] = { 0 };
	printf("---------模糊查询卡---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);
		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf(RED"卡号超过规定长度！请重新输入：\n"NONE);
		}
	} while (getSize(aName) > 18);

	//对输入的卡号进行模糊查询
	bool ret = _queryCardNamelist(aName);
	if (ret == false)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("输出所有可能卡号：\n");
		printallcardlist(aName);
	}
}

void query()//查询卡
{
	char aName[64] = { 0 };
	//建立数组用来读取卡号并判断
	printf("---------查询卡---------\n");
	printf("你可以选择精确/模糊查询：(输入0/1）\n");
	int nSelect = 0;
	do
	{
		scanf("%d", &nSelect);
		switch (nSelect)
		{
			case 0:
				printf("你选择了精确查询！\n");
				break;
			case 1:
				printf("你选择了模糊查询！\n");
				_query();
				return;
			default:
				printf(RED"输入错误！请重新输入：\n"NONE);
				break;
		}
	}while (nSelect);

	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);

		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("卡号超过规定长度！请重新输入：\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardName(aName);
	if (pCard == NULL)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("该卡号存在！请输入密码查看信息：\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
			scanf("%s", &aPwd);

			//对输入的数据进行一下判断
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"密码超过规定长度！请重新输入：\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			char aTime[20] = { 0 };
			timeToString(pCard->tLast, aTime);

			printf("\n----查询到的卡的信息如下：----\n");
			printf("卡号\t\t\t密码\t\t卡状态\t余额\t累计金额\t使用次数\t上次使用时间\n");
			printf("%-18s\t%-8s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", pCard->aName, pCard->aPwd, 
											   pCard->nStatus, pCard->fBalance,
											   pCard->fTotalUse,pCard->nUseCount,
											   aTime);
		}
		else
		{
			printf(RED"密码错误！\n"NONE);
		}
	}
}

void querylist()//查询卡
{
	char aName[64] = { 0 };
	//建立数组用来读取卡号并判断
	printf("---------查询卡---------\n");
	printf("你可以选择精确/模糊查询：(输入0/1）\n");
	int nSelect = 0;
	do
	{
		scanf("%d", &nSelect);
		switch (nSelect)
		{
		case 0:
			printf("你选择了精确查询！\n");
			break;
		case 1:
			printf("你选择了模糊查询！\n");
			_querylist();
			return;
		default:
			printf(RED"输入错误！请重新输入：\n"NONE);
			break;
		}
	} while (nSelect);

	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);

		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("卡号超过规定长度！请重新输入：\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("该卡号存在！请输入密码查看信息：\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
			scanf("%s", &aPwd);

			//对输入的数据进行一下判断
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"密码超过规定长度！请重新输入：\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			char aTime[20] = { 0 };
			timeToString(pCard->tLast, aTime);

			printf("\n----查询到的卡的信息如下：----\n");
			printf("卡号\t\t\t密码\t\t卡状态\t余额\t累计金额\t使用次数\t上次使用时间\n");
			printf("%-18s\t%-8s\t%s\t%0.1f\t%0.1f\t\t%d\t\t%s\n", pCard->aName, pCard->aPwd,
				tostringStatus(pCard->nStatus), pCard->fBalance,
				pCard->fTotalUse, pCard->nUseCount,
				aTime);
		}
		else
		{
			printf(RED"密码错误！\n"NONE);
		}
	}
}

void logon()//上机
{
	char aName[64] = { 0 };
	//建立数组用来读取卡号并判断
	printf("---------上机---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);

		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("卡号超过规定长度！请重新输入：\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("该卡号存在！请输入密码进行操作：\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
			scanf("%s", &aPwd);

			//对输入的数据进行一下判断
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"密码超过规定长度！请重新输入：\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			printf("该卡号存在！执行上机中：\n");
			Sleep(1);
			bool ret = logonCardList(aName);
			if (ret)
			{
				printf(GREEN"上机成功！\n"NONE);
			}
			else
			{
				printf(RED"上机失败！\n"NONE);
			}
		}
		else
		{
			printf(RED"密码错误！\n"NONE);
		}
	}
}

void logoff()
{
	char aName[64] = { 0 };
	//建立数组用来读取卡号并判断
	printf("---------下机---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);

		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("卡号超过规定长度！请重新输入：\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("该卡号存在！请输入密码进行操作：\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
			scanf("%s", &aPwd);

			//对输入的数据进行一下判断
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"密码超过规定长度！请重新输入：\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			printf("该卡号存在！执行下机中：\n");
			Sleep(1);
			bool ret = logoffCardList(aName);
			if (ret)
			{
				printf(GREEN"下机成功！\n"NONE);
			}
			else
			{
				printf(RED"下机失败！\n"NONE);
			}
		}
		else
		{
			printf(RED"密码错误！\n"NONE);
		}
	}
}

void recharge()//充值
{
	char aName[64] = { 0 };
	//建立数组用来读取卡号并判断
	printf("---------充值---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);
		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("卡号超过规定长度！请重新输入：\n");
		}
	} while (getSize(aName) > 18);
	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("该卡号存在！请输入密码进行操作：\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
			scanf("%s", &aPwd);
			//对输入的数据进行一下判断
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"密码超过规定长度！请重新输入：\n"NONE);
			}
		} while (getSize(aPwd) > 8);
		bool judge = queryCardPwd(pCard, aPwd);
		if (judge)
		{
			printf("该卡号存在！执行充值中：\n");
			Sleep(1);
			rechargeCardList(aName);
		}
		else
		{
			printf(RED"密码错误！\n"NONE);
		}
	}
}


void refund()//退费
{
	char aName[64] = { 0 };
	//建立数组用来读取卡号并判断
	printf("---------退费---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);
		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("卡号超过规定长度！请重新输入：\n");
		}
	} while (getSize(aName) > 18);
	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("该卡号存在！请输入密码进行操作：\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
			scanf("%s", &aPwd);
			//对输入的数据进行一下判断
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"密码超过规定长度！请重新输入：\n"NONE);
			}
		} while (getSize(aPwd) > 8);
		bool judge = queryCardPwd(pCard, aPwd);
		if (judge)
		{
			printf("该卡号存在！执行退费中：\n");
			Sleep(1);
			refundCardList(aName);
		}
		else
		{
			printf(RED"密码错误！\n"NONE);
		}
	}
}

void count()//查询统计
{
	time_t start, end;
	if (!inputTimeRange(&start, &end)) return;

	int mode = 0;
	printf("请选择统计方向：1-开卡明细 2-消费明细 3-充退明细：");
	scanf("%d", &mode);
	if (mode == 1) 
	{
		print_open_detail_and_summary(start, end);
	}
	else if (mode == 2) 
	{
		print_consume_detail_and_summary(start, end);
	}
	else if (mode==3)
	{
		print_recharge_refund_detail_and_summary(start, end);
	}
	else
	{
		printf("输入错误！\n");
		return;
	}
}


void cancel()//注销卡
{
	char aName[64] = { 0 };
	//建立数组用来读取卡号并判断
	printf("---------注销卡---------\n");
	do
	{
		printf(YELLOW"请输入卡号：（请注意输入不能超过18个字符）"NONE);
		scanf("%s", &aName);

		//对输入的数据进行一下判断
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("卡号超过规定长度！请重新输入：\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("没有找到该卡号！\n");
	}
	else
	{
		printf("该卡号存在！请输入密码查看信息：\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"请输入密码：（请注意输入不能超过8个字符）"NONE);
			scanf("%s", &aPwd);

			//对输入的数据进行一下判断
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"密码超过规定长度！请重新输入：\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			printf("该卡号存在！正在为你注销：\n");
			Sleep(1);
			bool ret=cancelCardList(aName);
			if (ret)
			{
				printf(GREEN"注销成功！\n"NONE);
			}
			else
			{
				printf(RED"注销失败！\n"NONE);
			}
		}
		else
		{
			printf(RED"密码错误！\n"NONE);
		}
	}
}