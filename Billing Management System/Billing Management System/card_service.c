#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"card_service.h"
#include"billing_file.h"
#include"billing_service.h"

//全局变量结构
Card aCard[50];
int nCardCount = 0;

CardNode* head = NULL;


bool initCardList()//初始化链表
{
	head = (CardNode*)malloc(sizeof(CardNode));
	if (head == NULL)
	{
		return false;
	}
	head->next = NULL;
	return loadCardList();
}



bool addCard(Card card)//添加卡
{
	if (nCardCount >= 50)
	{
		return false; // 数组已满
	}
	else
	{
		aCard[nCardCount] = card;
		nCardCount++;
		return true;
	}
}

bool addCardlist(Card card)//添加卡
{
	//先来找尾
	CardNode* cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	CardNode* newNode = (CardNode*)malloc(sizeof(CardNode));
	if (newNode == NULL)
	{
		perror(RED"内存分配失败！\n"NONE);
		return false;
	}
	else
	{
		newNode->card = card;
		newNode->next = NULL;
		cur->next = newNode;
	}
	return true;
}

Card* queryCardName(const char* aName)//查询卡
{
	for (int i = 0; i < nCardCount; i++)
	{
		if (strcmp(aCard[i].aName, aName) == 0)
		{
			return &aCard[i];
		}
	}
	return NULL;
}

Card* queryCardNamelist(const char* aName)//查询卡
{
	CardNode* cur = head;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			return &(cur->card);
		}
		cur = cur->next;
	}
	return NULL;
}

bool _queryCardName(const char* aName)//模糊查询卡
{
	int nNameSize = getSize(aName);
	for (int i = 0; i < nCardCount; i++)
	{
		if (memcmp(aCard[i].aName, aName, sizeof(char) * nNameSize) == 0)
		{
			return true;
		}
	}
	return false;
}

bool _queryCardNamelist(const char* aName)//模糊查询卡
{
	int nNameSize = getSize(aName);
	CardNode* cur = head;
	while (cur != NULL)
	{
		if (memcmp(cur->card.aName, aName, sizeof(char) * nNameSize) == 0)
		{
			return true;
		}
		cur = cur->next;
	}
	return false;
}
bool queryCardPwd(const Card* pCard,const char* Pwd)
{
	return strcmp(pCard->aPwd, Pwd) == 0;
}

const char* tostringStatus(int n)
{
	switch (n)
	{
	case UnLog:
		return "未上机";
	case IsLog:
		return "上机中";
	case Delete:
		return "已注销";
	case Invalid:
		return "已失效";
	default:
		return "未知状态";
	}
}
void printallcard(const char* aName)
{
	int nNameSize = getSize(aName);
	for (int i = 0; i < nCardCount; i++)
	{
		if (memcmp(aCard[i].aName, aName, sizeof(char) * nNameSize) == 0)
		{
			char aTime[20] = { 0 };
			timeToString(aCard[i].tLast, aTime);
			printf("卡号\t\t\t密码\t\t卡状态\t余额\t累计金额\t使用次数\t上次使用时间\n");
			printf("%-18s\t%-8s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", aCard[i].aName, aCard[i].aPwd,
																  aCard[i].nStatus, aCard[i].fBalance,
																  aCard[i].fTotalUse, aCard[i].nUseCount,
		           												  aTime);
		}
	}
}

void printallcardlist(const char* aName)
{
	int nNameSize = getSize(aName);
	CardNode* cur = head;
	while (cur != NULL)
	{
		if (memcmp(cur->card.aName, aName, sizeof(char) * nNameSize) == 0)
		{
			char aTime[20] = { 0 };
			timeToString(cur->card.tLast, aTime);
			printf("卡号\t\t\t密码\t\t卡状态\t余额\t累计金额\t使用次数\t上次使用时间\n");
			printf("%-18s\t%-8s\t%s\t%0.1f\t%0.1f\t\t%d\t\t%s\n", cur->card.aName, cur->card.aPwd,
																  tostringStatus(cur->card.nStatus), cur->card.fBalance,
																  cur->card.fTotalUse, cur->card.nUseCount,
																  aTime);
		}
		cur = cur->next;
	}
}

void printCardList()
{
	CardNode* cur = head->next;
	printf("卡号\t\t\t密码\t\t卡状态\t余额\t累计金额\t使用次数\t上次使用时间\n");
	while (cur != NULL)
	{
		char aTime[20] = { 0 };
		timeToString(cur->card.tLast, aTime);
		printf("%-18s\t%-8s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", cur->card.aName, cur->card.aPwd,
			cur->card.nStatus, cur->card.fBalance,
			cur->card.fTotalUse, cur->card.nUseCount,
			aTime);
		cur = cur->next;
	}
}

bool judgeonstatus(CardNode* cur)
{
	if (cur->card.nStatus == UnLog)
	{
		printf("状态正常，正在上机！\n");
		printf(GREEN"卡号：%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == IsLog)
	{
		printf("该卡正在上机！\n");
		printf(LIGHT_GREEN"卡号：%s\n"NONE, cur->card.aName);
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("该卡已经注销！\n");
		printf(RED"卡号：%s\n"NONE, cur->card.aName);
	}
	else
	{
		printf("该卡已经失效！\n");
		printf(BLUE"卡号：%s\n"NONE, cur->card.aName);
	}
	return false;
}

bool logonCardList(const char* aName)
{
	CardNode* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			bool ret=judgeonstatus(cur);
			if (ret)
			{
				if (cur->card.fBalance <= 0)
				{
					printf(RED"余额不足！\n"NONE);
					printf(YELLOW"请充值后再上机！\n"NONE);
					return false;
				}
				cur->card.nStatus = IsLog;
				cur->card.tLast = time(NULL);
				Billing bill; LogonInfo info;
				strcpy(bill.aName, cur->card.aName);
				strcpy(info.aName, cur->card.aName);
				bill.tStart = cur->card.tLast;
				bill.tEnd = 0; // 上机时结束时间为0
				bill.fAmount = 0; // 上机时消费金额为0
				bill.nStatus = unclear; // 上机状态
				bill.nDel = UnDel;
				info.tStart = cur->card.tLast;
				info.fBalance = cur->card.fBalance;
				
				addBillinglist(bill);

				char aTime[20] = { 0 };
				timeToString(info.tStart, aTime);

				printf("\n----上机信息如下：----\n");
				printf("卡号\t\t\t上机时间\t\t\t卡上余额\n");
				printf("%-18s\t%s\t\t%0.2f\n", info.aName, aTime, info.fBalance);
				return true;
			}
			else
			{
				return false;
			}
		}
		cur = cur->next;
	}
	return NULL;
}

bool judgeoffstatus(CardNode* cur)
{
	if (cur->card.nStatus == UnLog)
	{
		printf("该卡未上机！\n");
		printf(LIGHT_GREEN"卡号：%s\n"NONE, cur->card.aName);
		return false;
	}
	else if (cur->card.nStatus == IsLog)
	{
		printf("状态正常，正在下机！\n");
		printf(GREEN"卡号：%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("该卡已经注销！\n");
		printf(RED"卡号：%s\n"NONE, cur->card.aName);
	}
	else
	{
		printf("该卡已经失效！\n");
		printf(BLUE"卡号：%s\n"NONE, cur->card.aName);
	}
	return false;
}

double countmoney(CardNode* cur)
{
	double money = 0;
	time_t tNow = time(NULL);
	double diff = difftime(tNow, cur->card.tLast);
	if (diff > 0)
	{
		money = (double)diff / 3600 * 12; //按照小时计算费用
	}
	return money;
}

bool logoffCardList(const char* aName)
{
	CardNode* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			bool ret = judgeoffstatus(cur);
			if (ret)
			{
				cur->card.nStatus = UnLog;
				cur->card.nUseCount++;
				double used = countmoney(cur);
				if (cur->card.fBalance < used)
				{
					printf(RED"余额不足！请充值后再下机\n"NONE);
					return false;
				}
				cur->card.fBalance -= used;
				cur->card.fTotalUse += used;
				
				Billing bill; LogoffInfo info;

				strcpy(bill.aName, cur->card.aName);
				bill.tStart = cur->card.tLast;
				cur->card.tLast = time(NULL);
				bill.tEnd = cur->card.tLast; 
				bill.fAmount = used; // 上机时消费金额为0
				bill.nStatus = clear; // 上机状态
				bill.nDel = UnDel;

				strcpy(info.aName, cur->card.aName);
				info.tStart = used;
				info.fBalance = cur->card.fBalance;
				// 在文件中找到消费记录，更改结束时间和消费金额
				ModifyBillingList(&bill);

				char aTime1[20] = { 0 };
				char aTime2[20] = { 0 };
				timeToString(bill.tStart, aTime1);
				timeToString(bill.tEnd, aTime2);

				printf("\n----下机信息如下：----\n");
				printf("卡号\t\t\t上机时间\t\t下机时间\t\t消费金额\t卡上余额\n");
				printf("%-18s\t%s\t%s\t%0.2f\t\t%0.2f\n", info.aName, aTime1, aTime2,used,info.fBalance);

				return true;
			}
			else
			{
				return false;
			}
		}
		cur = cur->next;
	}
	return false;
}

bool rechargeCardList(const char* aName)
{
	CardNode* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			if (cur->card.nStatus == Delete || cur->card.nStatus == Invalid)
			{
				printf(RED"该卡已经注销或者失效！\n"NONE);
				return false;
			}

			double money;

			do
			{
				printf("请输入充值金额：");
				scanf("%lf", &money);
				if (money < 0)
				{
					printf(RED"输入金额错误！请重新输入：\n"NONE);
				}
			} while (money < 0);

			cur->card.fBalance += money;
			cur->card.fCharge += money;
			cur->card.tLast = time(NULL);
			printf(GREEN"充值成功！\n"NONE);
			printf("当前余额为%0.1f\n", cur->card.fBalance);
			return true;
		}
		cur = cur->next;
	}
	return false;
}

bool judgerefundstatus(CardNode* cur)
{
	if (cur->card.nStatus == UnLog)
	{
		printf("该卡未上机，正在退款\n");
		printf(GREEN"卡号：%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == IsLog)
	{
		printf("正在上机，无法退款！\n");
		printf(LIGHT_GREEN"卡号：%s\n"NONE, cur->card.aName);
		return false;
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("该卡已经注销！\n");
		printf(RED"卡号：%s\n"NONE, cur->card.aName);
		return false;
	}
	else
	{
		printf("该卡已经失效！\n");
		printf(BLUE"卡号：%s\n"NONE, cur->card.aName);
		return false;
	}
}

bool refundCardList(const char* aName)
{
	CardNode* cur = head->next;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			bool ret = judgerefundstatus(cur);
			if (!ret) return false;
			double money;
			do
			{
				printf("请输入退款金额：");
				scanf("%lf", &money);
				if (money < 0)
				{
					printf(RED"输入金额错误！请重新输入：\n"NONE);
				}
				if (money > cur->card.fBalance)
				{
					printf(RED"退款金额超过余额！请重新输入：\n"NONE);
				}
			} while (money < 0|| money > cur->card.fBalance);

			cur->card.fBalance -= money;
			cur->card.fRefund += money;
			cur->card.tLast = time(NULL);
			printf(GREEN"退款成功！\n"NONE);
			printf("当前余额为%0.3f\n", cur->card.fBalance);
			return true;
		}
		cur = cur->next;
	}
	return false;
}



bool judgecancelstatus(CardNode* cur)
{
	if (cur->card.nStatus == IsLog)
	{
		printf("该卡正在上机，无法注销！\n");
		printf(LIGHT_GREEN"卡号：%s\n"NONE, cur->card.aName);
		return false;
	}
	else if (cur->card.nStatus == UnLog)
	{
		printf("该卡未上机，正在注销！\n");
		printf(GREEN"卡号：%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("该卡已经注销！\n");
		printf(RED"卡号：%s\n"NONE, cur->card.aName);
		return false;
	}
	else
	{
		printf("该卡已经失效！\n");
		printf(BLUE"卡号：%s\n"NONE, cur->card.aName);
		return false;
	}
}

bool cancelCardList(const char* aName)
{
	int nNameSize = getSize(aName);
	CardNode* cur = head->next;
	CardNode* prev = head;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			//if (cur == head)//不要忽略头删的情况
			//{
			//	head = cur->next;
			//}
			//else
			//{
			//	prev->next = cur->next;
			//}
			//free(cur);
			//cur = NULL;
			bool ret = judgecancelstatus(cur);
			if (ret)
			{
				cur->card.nStatus = Delete;
				cur->card.fBalance = 0;
				return true;
			}
			return false;
		}
		prev = cur;
		cur = cur->next;
	}
	return false;
}

// 判断是否为闰年
int isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取每个月的天数，year用于判断二月
int getDaysInMonth(int year, int month)
{
	if (month < 1 || month > 12) return 0;
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && isLeapYear(year)) {
		return 29;
	}
	return days[month - 1];
}

// 输入时间段并校验
int inputTimeRange(time_t* start, time_t* end) {
	int y1, m1, d1, y2, m2, d2;
	printf("请输入起始时间(格式:YYYY MM DD): ");
	if (scanf("%d %d %d", &y1, &m1, &d1) != 3) return 0;
	printf("请输入结束时间(格式:YYYY MM DD): ");
	if (scanf("%d %d %d", &y2, &m2, &d2) != 3) return 0;

	// 校验起始日期的月份和天数合法性
	if (m1 < 1 || m1 > 12) {
		printf(RED"起始日期的月份不合法！\n"NONE);
		return 0;
	}
	int maxDay1 = getDaysInMonth(y1, m1);
	if (d1 < 1 || d1 > maxDay1) {
		printf(RED"起始日期的天数不合法！\n"NONE);
		return 0;
	}
	// 校验结束日期的月份和天数合法性
	if (m2 < 1 || m2 > 12) {
		printf(RED"结束日期的月份不合法！\n"NONE);
		return 0;
	}
	int maxDay2 = getDaysInMonth(y2, m2);
	if (d2 < 1 || d2 > maxDay2) {
		printf(RED"结束日期的天数不合法！\n"NONE);
		return 0;
	}

	struct tm tm1 = { 0 }, tm2 = { 0 };
	tm1.tm_year = y1 - 1900; tm1.tm_mon = m1 - 1; tm1.tm_mday = d1;
	tm2.tm_year = y2 - 1900; tm2.tm_mon = m2 - 1; tm2.tm_mday = d2;

	*start = mktime(&tm1);
	*end = mktime(&tm2);
	if (*start == -1 || *end == -1 || *start > *end) {
		printf(RED"时间段输入不合法！\n"NONE);
		return 0;
	}
	return 1;
}

void print_open_detail_and_summary(time_t start, time_t end)
{
	printf("\n-----------【开卡明细】-----------\n");
	int total_count = 0;
	double total_money = 0;
	CardNode* cur = head->next;
	while (cur) {
		if (cur->card.tStart >= start && cur->card.tStart <= end) {
			char tstr[20];
			timeToString(cur->card.tStart, tstr);
			printf("卡号: %-18s 开卡时间: %s 开卡金额: %.3f\n",
				cur->card.aName, tstr, cur->card.fstart);
			total_count++;
			total_money += cur->card.fstart;
		}
		cur = cur->next;
	}
	printf("合计开卡数: %d, 累计开卡金额: %.3f\n", total_count, total_money);
}

extern BillingNode* headBilling;

void print_consume_detail_and_summary(time_t start, time_t end)
{
	printf("\n----------【上下机消费明细】----------\n");
	double total_consume = 0;
	int unclear_count = 0; // 未结算消费记录计数
	int clear_count = 0; // 已结算消费记录计数
	BillingNode* cur = headBilling->next;
	while (cur) {
		// 统计在时间段内有消费的卡
		if (cur->billing.tStart >= start && cur->billing.tStart <= end )
		{
			char aTime1[20] = { 0 };
			char aTime2[20] = { 0 };
			timeToString(cur->billing.tStart, aTime1);
			if (!cur->billing.tEnd)
			{
				printf("卡号: %-18s 单次上机时间:%s\t下机时间:未下机",cur->billing.aName, aTime1);
				printf("\t消费金额:%.3f\t消费状态:%s\n", cur->billing.fAmount, ToStringStatus(cur->billing.nStatus));
			}
			else
			{
				timeToString(cur->billing.tEnd, aTime2);
				printf("卡号: %-18s 单次上机时间:%s\t下机时间:%s\t消费金额:%.3f\t消费状态:%s\n",
					cur->billing.aName, aTime1, aTime2, cur->billing.fAmount, ToStringStatus(cur->billing.nStatus));
			}
			total_consume += cur->billing.fAmount;
			if (cur->billing.nStatus == unclear) {
				unclear_count++;
			}
			else if (cur->billing.nStatus == clear) {
				clear_count++;
			}
		}
		cur = cur->next;
	}
	printf("合计消费金额: %.3f，已结算：%d张，未结算：%d张\n", total_consume, clear_count,unclear_count);
}

void print_recharge_refund_detail_and_summary(time_t start, time_t end)
{
	printf("\n----------【充值/退费明细】----------\n");
	double total_recharge = 0;
	double total_refund = 0;
	CardNode* cur = head->next;
	while (cur) {
		// 假设开卡时间在时间段内的卡，统计其余额变化
		if (cur->card.tStart >= start && cur->card.tStart <= end) {
			char tstr[20];
			timeToString(cur->card.tStart, tstr);
			// 这里只能统计开卡金额（即初始充值），如有退费字段请补充
			printf("卡号: %-18s 开卡时间: %s 充值金额: %.2f 退费金额: %.2f 余额: %.2f\n",
				cur->card.aName, tstr, cur->card.fCharge,cur->card.fRefund, cur->card.fBalance);
			total_recharge += cur->card.fCharge; // 假设有充值字段
			// 若有退费字段，累加 total_refund
			total_refund += cur->card.fRefund; // 假设有退费字段
		}
		cur = cur->next;
	}
	printf("合计充值金额: %.2f，合计退费金额: %.2f\n", total_recharge, total_refund);
}

void releaseCardList()
{
	CardNode* pCur = head;
	while (pCur != NULL)
	{
		CardNode* pNext = pCur->next;
		free(pCur);
		pCur = pNext;
	}
	head = NULL;
}