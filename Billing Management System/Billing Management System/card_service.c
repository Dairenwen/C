#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"card_service.h"

//ȫ�ֱ����ṹ
Card aCard[50];
int nCardCount = 0;
CardNode* head = NULL;



bool initCardList()//��ʼ������
{
	head = (CardNode*)malloc(sizeof(CardNode));
	if (head == NULL)
	{
		return false;
	}
	head->next = NULL;
	return loadCardList();
}

bool addCard(Card card)//��ӿ�
{
	if (nCardCount >= 50)
	{
		return false; // ��������
	}
	else
	{
		aCard[nCardCount] = card;
		nCardCount++;
		return true;
	}
}

bool addCardlist(Card card)//��ӿ�
{
	//������β
	CardNode* cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	CardNode* newNode = (CardNode*)malloc(sizeof(CardNode));
	if (newNode == NULL)
	{
		perror(RED"�ڴ����ʧ�ܣ�\n"NONE);
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

Card* queryCardName(const char* aName)//��ѯ��
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

Card* queryCardNamelist(const char* aName)//��ѯ��
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

bool _queryCardName(const char* aName)//ģ����ѯ��
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

bool _queryCardNamelist(const char* aName)//ģ����ѯ��
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

void printallcard(const char* aName)
{
	int nNameSize = getSize(aName);
	for (int i = 0; i < nCardCount; i++)
	{
		if (memcmp(aCard[i].aName, aName, sizeof(char) * nNameSize) == 0)
		{
			char aTime[20] = { 0 };
			timeToString(aCard[i].tLast, aTime);
			printf("����\t\t\t����\t\t��״̬\t���\t�ۼƽ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
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
			printf("����\t\t\t����\t\t��״̬\t���\t�ۼƽ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
			printf("%-18s\t%-8s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", cur->card.aName, cur->card.aPwd,
																  cur->card.nStatus, cur->card.fBalance,
																  cur->card.fTotalUse, cur->card.nUseCount,
																  aTime);
		}
		cur = cur->next;
	}
}

void printCardList()
{
	CardNode* cur = head->next;
	printf("����\t\t\t����\t\t��״̬\t���\t�ۼƽ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
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
		printf("״̬�����������ϻ���\n");
		printf(GREEN"���ţ�%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == Logon)
	{
		printf("�ÿ������ϻ���\n");
		printf(LIGHT_GREEN"���ţ�%s\n"NONE, cur->card.aName);
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("�ÿ��Ѿ�ע����\n");
		printf(RED"���ţ�%s\n"NONE, cur->card.aName);
	}
	else
	{
		printf("�ÿ��Ѿ�ʧЧ��\n");
		printf(BLUE"���ţ�%s\n"NONE, cur->card.aName);
	}
	return false;
}

bool logonCardList(const char* aName)
{
	CardNode* cur = head;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			bool ret=judgeonstatus(cur);
			if (ret)
			{
				if (cur->card.fBalance <= 0)
				{
					printf(RED"���㣡\n"NONE);
					printf(YELLOW"���ֵ�����ϻ���\n"NONE);
					return false;
				}
				cur->card.nStatus = Logon;
				cur->card.nUseCount++;
				cur->card.tLast = time(NULL);
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

bool judgeoffstatus(CardNode* cur)
{
	if (cur->card.nStatus == UnLog)
	{
		printf("�ÿ�δ�ϻ���\n");
		printf(LIGHT_GREEN"���ţ�%s\n"NONE, cur->card.aName);
		return false;
	}
	else if (cur->card.nStatus == Logon)
	{
		printf("״̬�����������»���\n");
		printf(GREEN"���ţ�%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("�ÿ��Ѿ�ע����\n");
		printf(RED"���ţ�%s\n"NONE, cur->card.aName);
	}
	else
	{
		printf("�ÿ��Ѿ�ʧЧ��\n");
		printf(BLUE"���ţ�%s\n"NONE, cur->card.aName);
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
		money = (double)diff / 3600 * 12; // ����ÿСʱ12Ԫ���ܹ�ƽ�԰ɣ�
		//������һɫi9-13900HX+RTX5090d���ϲ������
	}
	return money;
}

bool logoffCardList(const char* aName)
{
	CardNode* cur = head;
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
					printf(RED"���㣡���ֵ�����»�\n"NONE);
					return false;
				}
				cur->card.fBalance -= used;
				cur->card.fTotalUse += used;
				cur->card.tLast = time(NULL);
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
	CardNode* cur = head;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			if (cur->card.nStatus == Delete || cur->card.nStatus == Invalid)
			{
				printf(RED"�ÿ��Ѿ�ע������ʧЧ��\n"NONE);
				return false;
			}

			double money;

			do
			{
				printf("�������ֵ��");
				scanf("%lf", &money);
				if (money < 0)
				{
					printf(RED"������������������룺\n"NONE);
				}
			} while (money < 0);

			cur->card.fBalance += money;
			cur->card.tLast = time(NULL);
			printf(GREEN"��ֵ�ɹ���\n"NONE);
			printf("��ǰ���Ϊ%0.1f\n", cur->card.fBalance);
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
		printf("�ÿ�δ�ϻ��������˿�\n");
		printf(GREEN"���ţ�%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == Logon)
	{
		printf("�����ϻ����޷��˿\n");
		printf(LIGHT_GREEN"���ţ�%s\n"NONE, cur->card.aName);
		return false;
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("�ÿ��Ѿ�ע����\n");
		printf(RED"���ţ�%s\n"NONE, cur->card.aName);
		return false;
	}
	else
	{
		printf("�ÿ��Ѿ�ʧЧ��\n");
		printf(BLUE"���ţ�%s\n"NONE, cur->card.aName);
		return false;
	}
}

bool refundCardList(const char* aName)
{
	CardNode* cur = head;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			bool ret = judgerefundstatus(cur);
			if (!ret) return false;
			double money;
			do
			{
				printf("�������˿��");
				scanf("%lf", &money);
				if (money < 0)
				{
					printf(RED"������������������룺\n"NONE);
				}
				if (money > cur->card.fBalance)
				{
					printf(RED"�˿���������������룺\n"NONE);
				}
			} while (money < 0|| money > cur->card.fBalance);

			cur->card.fBalance -= money;
			cur->card.tLast = time(NULL);
			printf(GREEN"�˿�ɹ���\n"NONE);
			printf("��ǰ���Ϊ%0.1f\n", cur->card.fBalance);
			return true;
		}
		cur = cur->next;
	}
	return false;
}



bool judgecancelstatus(CardNode* cur)
{
	if (cur->card.nStatus == UnLog)
	{
		printf("�ÿ������ϻ����޷�ע����\n");
		printf(LIGHT_GREEN"���ţ�%s\n"NONE, cur->card.aName);
		return false;
	}
	else if (cur->card.nStatus == Logon)
	{
		printf("�ÿ�δ�ϻ�������ע����\n");
		printf(GREEN"���ţ�%s\n"NONE, cur->card.aName);
		return true;
	}
	else if (cur->card.nStatus == Delete)
	{
		printf("�ÿ��Ѿ�ע����\n");
		printf(RED"���ţ�%s\n"NONE, cur->card.aName);
		return false;
	}
	else
	{
		printf("�ÿ��Ѿ�ʧЧ��\n");
		printf(BLUE"���ţ�%s\n"NONE, cur->card.aName);
		return false;
	}
}

bool cancelCardList(const char* aName)
{
	int nNameSize = getSize(aName);
	CardNode* cur = head;
	CardNode* prev = head;
	while (cur != NULL)
	{
		if (strcmp(cur->card.aName, aName) == 0)
		{
			//if (cur == head)//��Ҫ����ͷɾ�����
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
			cur->card.nStatus = Delete;
			cur->card.fBalance = 0;
			return true;
		}
		prev = cur;
		cur = cur->next;
	}
	return false;
}

// ����ʱ��β�У��
int inputTimeRange(time_t* start, time_t* end) {
	int y1, m1, d1, y2, m2, d2;
	printf("��������ʼʱ��(��ʽ:YYYY MM DD): ");
	if (scanf("%d %d %d", &y1, &m1, &d1) != 3) return 0;
	printf("���������ʱ��(��ʽ:YYYY MM DD): ");
	if (scanf("%d %d %d", &y2, &m2, &d2) != 3) return 0;
	struct tm tm1 = { 0 }, tm2 = { 0 };
	tm1.tm_year = y1 - 1900; tm1.tm_mon = m1 - 1; tm1.tm_mday = d1;
	tm2.tm_year = y2 - 1900; tm2.tm_mon = m2 - 1; tm2.tm_mday = d2;
	*start = mktime(&tm1);
	*end = mktime(&tm2);
	if (*start == -1 || *end == -1 || *start > *end) {
		printf("ʱ������벻�Ϸ���\n");
		return 0;
	}
	return 1;
}

void print_open_detail_and_summary(time_t start, time_t end)
{
	printf("\n��������ϸ��\n");
	int total_count = 0;
	double total_money = 0;
	CardNode* cur = head->next;
	while (cur) {
		if (cur->card.tStart >= start && cur->card.tStart <= end) {
			char tstr[20];
			timeToString(cur->card.tStart, tstr);
			printf("����: %-18s ����ʱ��: %s �������: %.2f\n",
				cur->card.aName, tstr, cur->card.fBalance);
			total_count++;
			total_money += cur->card.fBalance;
		}
		cur = cur->next;
	}
	printf("�ϼƿ�����: %d, �ϼƿ������: %.2f\n", total_count, total_money);
}

void print_consume_detail_and_summary(time_t start, time_t end)
{
	printf("\n�����»�������ϸ��\n");
	double total_consume = 0;
	int total_count = 0;
	CardNode* cur = head->next;
	while (cur) {
		// ͳ����ʱ����������ѵĿ�
		if (cur->card.tLast >= start && cur->card.tLast <= end && cur->card.nUseCount > 0) {
			char tstr[20];
			timeToString(cur->card.tLast, tstr);
			printf("����: %-18s �ϴ���/�»�ʱ��: %s ���ѽ��: %.2f ʹ�ô���: %d\n",
				cur->card.aName, tstr, cur->card.fTotalUse, cur->card.nUseCount);
			total_consume += cur->card.fTotalUse;
			total_count += cur->card.nUseCount;
		}
		cur = cur->next;
	}
	printf("�ϼ����ѽ��: %.2f���ϼ���/�»�����: %d\n", total_consume, total_count);
}

void print_recharge_refund_detail_and_summary(time_t start, time_t end)
{
	printf("\n����ֵ/�˷���ϸ��\n");
	double total_recharge = 0;
	double total_refund = 0;
	CardNode* cur = head->next;
	while (cur) {
		// ���迪��ʱ����ʱ����ڵĿ���ͳ�������仯
		if (cur->card.tStart >= start && cur->card.tStart <= end) {
			char tstr[20];
			timeToString(cur->card.tStart, tstr);
			// ����ֻ��ͳ�ƿ���������ʼ��ֵ���������˷��ֶ��벹��
			printf("����: %-18s ����ʱ��: %s �������: %.2f ���: %.2f\n",
				cur->card.aName, tstr, cur->card.fBalance + cur->card.fTotalUse, cur->card.fBalance);
			total_recharge += cur->card.fBalance + cur->card.fTotalUse;
			// �����˷��ֶΣ��ۼ� total_refund
		}
		cur = cur->next;
	}
	printf("�ϼƳ�ֵ���: %.2f���ϼ��˷ѽ��: %.2f\n", total_recharge, total_refund);
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