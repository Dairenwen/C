#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"card_service.h"


bool loadCardList()
{
    FILE* tmp = fopen("card.txt", "r");
    if (tmp == NULL)
    {
        perror(RED"���ļ�ʧ�ܣ�\n"NONE);
        return false;
    }
    else
    {
        Card card;
        memset(&card, 0, sizeof(Card));
        //������Ϊ�˷�ֹ�������룬��ʼ��
        while (fscanf(tmp, "%18s %8s %d %ld %ld %lf %ld %d %lf %d",
            card.aName, card.aPwd,
            &card.nStatus, &card.tStart, &card.tEnd,
            &card.fTotalUse, &card.tLast, &card.nUseCount,
            &card.fBalance, &card.nDel) == 10)
        {
            addCardlist(card);
        }
        fclose(tmp);
        return true;
    }
}


extern CardNode* head;

void SaveCardList()
{
	FILE* tmp = fopen("card.txt", "w");
	if (tmp == NULL)
	{
		perror(RED"���ļ�ʧ�ܣ�\n"NONE);
		return;
	}

	CardNode* cur = head->next;//ע����ڱ�λ�㣡
	while (cur != NULL)
	{
		// �ַ�������룬�����Ҷ��룬������������λС��
		fprintf(tmp, "%-18s %-8s %3d %12ld %12ld %10.2lf %12ld %8d %10.2lf %3d\n",
			cur->card.aName, cur->card.aPwd,
			cur->card.nStatus, cur->card.tStart, cur->card.tEnd,
			cur->card.fTotalUse, cur->card.tLast, cur->card.nUseCount,
			cur->card.fBalance, cur->card.nDel);
		cur = cur->next;
	}
	fclose(tmp);
}
