#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"tool.h"
#include"card_service.h"
#include"billing_file.h"
#include"billing_service.h"

extern BillingNode* headBilling; //计费信息链表头指针
//将计费信息保存到billing.ams文件
void SaveBillingList()
{
	FILE* tmp = fopen("billing.ams", "wb");
	if (tmp == NULL)
	{
		perror(RED"打开文件失败！\n"NONE);
		return;
	}

	BillingNode* cur = headBilling->next;//注意带哨兵位点！
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
        perror(RED"打开文件失败！\n"NONE);
        return false;
    }
    else
    {
		Billing billing;
        memset(&billing, 0, sizeof(billing));
        //这样是为了防止出现乱码，初始化
        while (fread(&billing,sizeof(Billing),1,tmp)==1)
        {
            addBillinglist(billing);
        }
        fclose(tmp);
        return true;
    }
}