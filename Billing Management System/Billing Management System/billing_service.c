#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"tool.h"
#include"card_service.h"
#include"billing_file.h"

BillingNode* headBilling = NULL;

bool initBillingList()//初始化账单链表
{
	headBilling = (BillingNode*)malloc(sizeof(BillingNode));
	if (headBilling == NULL)
	{
		return false;
	}
	headBilling->next = NULL;
	return loadBillingList();
}

bool addBillinglist(Billing _billing)//添加卡
{
	//先来找尾
	BillingNode* cur = headBilling;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	BillingNode* newNode = (BillingNode*)malloc(sizeof(BillingNode));
	if (newNode == NULL)
	{
		perror(RED"内存分配失败！\n"NONE);
		return false;
	}
	else
	{
		newNode->billing = _billing;
		newNode->next = NULL;
		cur->next = newNode;
	}
	return true;
}

void ModifyBillingList(Billing* _billing)
{
	BillingNode* cur = headBilling->next;
	BillingNode* prev = cur;
	bool found = false;
	while (cur != NULL)
	{
		if (strcmp(cur->billing.aName, _billing->aName) == 0)
		{
			found = true;
			prev = cur;
		}
		cur = cur->next;
	}
	if(found)
	{
		prev->billing = *_billing;
		printf(GREEN"账单修改成功！\n"NONE);
	}
	else
	{
		printf(RED"未找到该账单！\n"NONE);
	}
}

const char* ToStringStatus(int n)
{
	switch (n)
	{
	case clear:
		return "已结算";
	case unclear:
		return "未结算";
	default:
		return "未知状态";
	}
}

void releaseBillingList()
{
	BillingNode* pCur = headBilling;
	while (pCur != NULL)
	{
		BillingNode* pNext = pCur->next;
		free(pCur);
		pCur = pNext;
	}
	headBilling = NULL;
}