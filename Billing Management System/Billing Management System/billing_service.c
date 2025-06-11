#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"tool.h"
#include"card_service.h"
#include"billing_file.h"

BillingNode* headBilling = NULL;

bool initBillingList()//��ʼ���˵�����
{
	headBilling = (BillingNode*)malloc(sizeof(BillingNode));
	if (headBilling == NULL)
	{
		return false;
	}
	headBilling->next = NULL;
	return loadBillingList();
}

bool addBillinglist(Billing _billing)//��ӿ�
{
	//������β
	BillingNode* cur = headBilling;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	BillingNode* newNode = (BillingNode*)malloc(sizeof(BillingNode));
	if (newNode == NULL)
	{
		perror(RED"�ڴ����ʧ�ܣ�\n"NONE);
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
		printf(GREEN"�˵��޸ĳɹ���\n"NONE);
	}
	else
	{
		printf(RED"δ�ҵ����˵���\n"NONE);
	}
}

const char* ToStringStatus(int n)
{
	switch (n)
	{
	case clear:
		return "�ѽ���";
	case unclear:
		return "δ����";
	default:
		return "δ֪״̬";
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