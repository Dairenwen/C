#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"tool.h"
#include"card_service.h"
#include"billing_file.h"
#include"billing_service.h"

extern BillingNode* headBilling; //�Ʒ���Ϣ����ͷָ��
//���Ʒ���Ϣ���浽billing.ams�ļ�
void SaveBillingList()
{
	FILE* tmp = fopen("billing.ams", "wb");
	if (tmp == NULL)
	{
		perror(RED"���ļ�ʧ�ܣ�\n"NONE);
		return;
	}

	BillingNode* cur = headBilling->next;//ע����ڱ�λ�㣡
	while (cur != NULL)
	{
		fwrite(cur, sizeof(Billing), 1, tmp);
        cur = cur->next;
	}
    
	fclose(tmp);
}

bool loadBillingList()
{
    FILE* tmp = fopen("billing.ams", "rb");
    if (tmp == NULL)
    {
        perror(RED"���ļ�ʧ�ܣ�\n"NONE);
        return false;
    }
    else
    {
		Billing billing;
        memset(&billing, 0, sizeof(billing));
        //������Ϊ�˷�ֹ�������룬��ʼ��
        while (fread(&billing,sizeof(Billing),1,tmp)==1)
        {
            addBillinglist(billing);
        }
        fclose(tmp);
        return true;
    }
}