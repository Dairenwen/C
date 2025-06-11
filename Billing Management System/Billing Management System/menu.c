#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"tool.h"
#include"card_service.h"

extern CardNode* head;

void menu()//��ӡ�˵�
{
	printf("----------�˵�----------\n");
	printf("1.��ӿ�\n");
	printf("2.��ѯ��\n");
	printf("3.�ϻ�\n");
	printf("4.�»�\n");
	printf("5.��ֵ\n");
	printf("6.�˷�\n");
	printf("7.��ѯͳ��\n");
	printf("8.ע����\n");
	printf("0.�˳�\n");
}

int getSize(const char* arr)//���ڼ������鳤��
{
	return strlen(arr);
}

void copy(char* des, const char* dri, int size)//�����ַ���
{
	memcpy(des, dri, sizeof(char) * (size + 1));
}

void add()//��ӿ�
{
	Card card;
	memset(&card, 0, sizeof(Card));
	char aName[64] = { 0 };
	char aPwd[32] = { 0 };
	//������������������ȡ���ݲ��ж�
	printf("---------��ӿ�---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);

		printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
		scanf("%s", &aPwd);

		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		int nPwdSize = getSize(aPwd);
		Card* judge = queryCardName(aName);
		if (judge)
		{
			printf(RED"�����Ѵ��ڣ����������룺\n"NONE);
		}
		if (nNameSize > 18 || nPwdSize > 8)
		{
			printf(RED"���Ż������볬���涨���ȣ����������룺\n"NONE);
		}
	} while (getSize(aName) > 18 || getSize(aPwd) > 8 || queryCardName(aName));

	//������Ŀ��ź����뿽�����ṹ����
	copy(card.aName, aName, getSize(aName));
	copy(card.aPwd, aPwd, getSize(aPwd));

	printf("�����뿪����");
	scanf("%lf", &card.fBalance);

	//�����ۼƽ�
	card.fTotalUse = card.fBalance;

	//����״̬��
	card.nUseCount = 0;
	card.nDel = UnDel;
	card.nStatus = UnLog;

	//ʹ��time����ȡʱ���
	card.tStart = card.tEnd = card.tLast = time(NULL);

	//������Ϣ��ӵ�������
	bool ret=addCard(card);
	if (ret)
	{
		printf(BLUE"��ӳɹ���\n"NONE);
		printf("\n----���뿨����Ϣ���£�----\n");
		printf("����\t\t\t����\t\t��״̬\t���\n");
		printf("%-18s\t%-8s\t%d\t%0.1f\n", card.aName, card.aPwd,
										   card.nStatus, card.fBalance);
	}
	else
	{
		printf(RED"���ʧ�ܣ���Ƭ����������\n"NONE);
		printf("��ɾ��һЩ��Ƭ������ӣ�\n");	
	}
}


void addlist()//��ӿ�
{
	Card card;
	memset(&card, 0, sizeof(Card));
	char aName[64] = { 0 };
	char aPwd[32] = { 0 };
	//������������������ȡ���ݲ��ж�
	printf("---------��ӿ�---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);

		printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
		scanf("%s", &aPwd);

		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		int nPwdSize = getSize(aPwd);
		Card* judge = queryCardNamelist(aName);
		if (judge)
		{
			printf(RED"�����Ѵ��ڣ����������룺\n"NONE);
		}
		if (nNameSize > 18 || nPwdSize > 8)
		{
			printf(RED"���Ż������볬���涨���ȣ����������룺\n"NONE);
		}
	} while (getSize(aName) > 18 || getSize(aPwd) > 8 || queryCardNamelist(aName));

	//������Ŀ��ź����뿽�����ṹ����
	copy(card.aName, aName, getSize(aName));
	copy(card.aPwd, aPwd, getSize(aPwd));

	double money = 0;
	do
	{
		printf("�����뿪����");
		scanf("%lf", &money);
		if (money < 0)
		{
			printf(RED"������������������룺\n"NONE);
		}
	} while (money < 0);
	card.fBalance = money;
	card.fstart = money; //���ÿ������
	card.fCharge = money; //���ÿ������Ϊ��ֵ���
	card.fRefund = 0; //�����˷ѽ��Ϊ0

	//�����ۼƽ�
	card.fTotalUse = 0;

	//����״̬��
	card.nUseCount = 0;
	card.nDel = UnDel;
	card.nStatus = UnLog;

	//ʹ��time����ȡʱ���
	card.tStart = card.tEnd = card.tLast = time(NULL);

	//������Ϣ��ӵ�������
	addCardlist(card);
}

void _query()//ģ����ѯ��
{
	char aName[64] = { 0 };
	printf("---------ģ����ѯ��---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);
		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf(RED"���ų����涨���ȣ����������룺\n"NONE);
		}
	} while (getSize(aName) > 18);

	//������Ŀ��Ž���ģ����ѯ
	bool ret = _queryCardName(aName);
	if (ret==false)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("������п��ܿ��ţ�\n");
		printallcard(aName);
	}
}

void _querylist()//ģ����ѯ��
{
	char aName[64] = { 0 };
	printf("---------ģ����ѯ��---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);
		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf(RED"���ų����涨���ȣ����������룺\n"NONE);
		}
	} while (getSize(aName) > 18);

	//������Ŀ��Ž���ģ����ѯ
	bool ret = _queryCardNamelist(aName);
	if (ret == false)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("������п��ܿ��ţ�\n");
		printallcardlist(aName);
	}
}

void query()//��ѯ��
{
	char aName[64] = { 0 };
	//��������������ȡ���Ų��ж�
	printf("---------��ѯ��---------\n");
	printf("�����ѡ��ȷ/ģ����ѯ��(����0/1��\n");
	int nSelect = 0;
	do
	{
		scanf("%d", &nSelect);
		switch (nSelect)
		{
			case 0:
				printf("��ѡ���˾�ȷ��ѯ��\n");
				break;
			case 1:
				printf("��ѡ����ģ����ѯ��\n");
				_query();
				return;
			default:
				printf(RED"����������������룺\n"NONE);
				break;
		}
	}while (nSelect);

	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);

		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("���ų����涨���ȣ����������룺\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardName(aName);
	if (pCard == NULL)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("�ÿ��Ŵ��ڣ�����������鿴��Ϣ��\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
			scanf("%s", &aPwd);

			//����������ݽ���һ���ж�
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"���볬���涨���ȣ����������룺\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			char aTime[20] = { 0 };
			timeToString(pCard->tLast, aTime);

			printf("\n----��ѯ���Ŀ�����Ϣ���£�----\n");
			printf("����\t\t\t����\t\t��״̬\t���\t�ۼƽ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
			printf("%-18s\t%-8s\t%d\t%0.1f\t%0.1f\t\t%d\t\t%s\n", pCard->aName, pCard->aPwd, 
											   pCard->nStatus, pCard->fBalance,
											   pCard->fTotalUse,pCard->nUseCount,
											   aTime);
		}
		else
		{
			printf(RED"�������\n"NONE);
		}
	}
}

void querylist()//��ѯ��
{
	char aName[64] = { 0 };
	//��������������ȡ���Ų��ж�
	printf("---------��ѯ��---------\n");
	printf("�����ѡ��ȷ/ģ����ѯ��(����0/1��\n");
	int nSelect = 0;
	do
	{
		scanf("%d", &nSelect);
		switch (nSelect)
		{
		case 0:
			printf("��ѡ���˾�ȷ��ѯ��\n");
			break;
		case 1:
			printf("��ѡ����ģ����ѯ��\n");
			_querylist();
			return;
		default:
			printf(RED"����������������룺\n"NONE);
			break;
		}
	} while (nSelect);

	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);

		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("���ų����涨���ȣ����������룺\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("�ÿ��Ŵ��ڣ�����������鿴��Ϣ��\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
			scanf("%s", &aPwd);

			//����������ݽ���һ���ж�
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"���볬���涨���ȣ����������룺\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			char aTime[20] = { 0 };
			timeToString(pCard->tLast, aTime);

			printf("\n----��ѯ���Ŀ�����Ϣ���£�----\n");
			printf("����\t\t\t����\t\t��״̬\t���\t�ۼƽ��\tʹ�ô���\t�ϴ�ʹ��ʱ��\n");
			printf("%-18s\t%-8s\t%s\t%0.1f\t%0.1f\t\t%d\t\t%s\n", pCard->aName, pCard->aPwd,
				tostringStatus(pCard->nStatus), pCard->fBalance,
				pCard->fTotalUse, pCard->nUseCount,
				aTime);
		}
		else
		{
			printf(RED"�������\n"NONE);
		}
	}
}

void logon()//�ϻ�
{
	char aName[64] = { 0 };
	//��������������ȡ���Ų��ж�
	printf("---------�ϻ�---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);

		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("���ų����涨���ȣ����������룺\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("�ÿ��Ŵ��ڣ�������������в�����\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
			scanf("%s", &aPwd);

			//����������ݽ���һ���ж�
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"���볬���涨���ȣ����������룺\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			printf("�ÿ��Ŵ��ڣ�ִ���ϻ��У�\n");
			Sleep(1);
			bool ret = logonCardList(aName);
			if (ret)
			{
				printf(GREEN"�ϻ��ɹ���\n"NONE);
			}
			else
			{
				printf(RED"�ϻ�ʧ�ܣ�\n"NONE);
			}
		}
		else
		{
			printf(RED"�������\n"NONE);
		}
	}
}

void logoff()
{
	char aName[64] = { 0 };
	//��������������ȡ���Ų��ж�
	printf("---------�»�---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);

		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("���ų����涨���ȣ����������룺\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("�ÿ��Ŵ��ڣ�������������в�����\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
			scanf("%s", &aPwd);

			//����������ݽ���һ���ж�
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"���볬���涨���ȣ����������룺\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			printf("�ÿ��Ŵ��ڣ�ִ���»��У�\n");
			Sleep(1);
			bool ret = logoffCardList(aName);
			if (ret)
			{
				printf(GREEN"�»��ɹ���\n"NONE);
			}
			else
			{
				printf(RED"�»�ʧ�ܣ�\n"NONE);
			}
		}
		else
		{
			printf(RED"�������\n"NONE);
		}
	}
}

void recharge()//��ֵ
{
	char aName[64] = { 0 };
	//��������������ȡ���Ų��ж�
	printf("---------��ֵ---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);
		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("���ų����涨���ȣ����������룺\n");
		}
	} while (getSize(aName) > 18);
	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("�ÿ��Ŵ��ڣ�������������в�����\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
			scanf("%s", &aPwd);
			//����������ݽ���һ���ж�
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"���볬���涨���ȣ����������룺\n"NONE);
			}
		} while (getSize(aPwd) > 8);
		bool judge = queryCardPwd(pCard, aPwd);
		if (judge)
		{
			printf("�ÿ��Ŵ��ڣ�ִ�г�ֵ�У�\n");
			Sleep(1);
			rechargeCardList(aName);
		}
		else
		{
			printf(RED"�������\n"NONE);
		}
	}
}


void refund()//�˷�
{
	char aName[64] = { 0 };
	//��������������ȡ���Ų��ж�
	printf("---------�˷�---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);
		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("���ų����涨���ȣ����������룺\n");
		}
	} while (getSize(aName) > 18);
	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("�ÿ��Ŵ��ڣ�������������в�����\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
			scanf("%s", &aPwd);
			//����������ݽ���һ���ж�
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"���볬���涨���ȣ����������룺\n"NONE);
			}
		} while (getSize(aPwd) > 8);
		bool judge = queryCardPwd(pCard, aPwd);
		if (judge)
		{
			printf("�ÿ��Ŵ��ڣ�ִ���˷��У�\n");
			Sleep(1);
			refundCardList(aName);
		}
		else
		{
			printf(RED"�������\n"NONE);
		}
	}
}

void count()//��ѯͳ��
{
	time_t start, end;
	if (!inputTimeRange(&start, &end)) return;

	int mode = 0;
	printf("��ѡ��ͳ�Ʒ���1-������ϸ 2-������ϸ 3-������ϸ��");
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
		printf("�������\n");
		return;
	}
}


void cancel()//ע����
{
	char aName[64] = { 0 };
	//��������������ȡ���Ų��ж�
	printf("---------ע����---------\n");
	do
	{
		printf(YELLOW"�����뿨�ţ�����ע�����벻�ܳ���18���ַ���"NONE);
		scanf("%s", &aName);

		//����������ݽ���һ���ж�
		int nNameSize = getSize(aName);
		if (nNameSize > 18)
		{
			printf("���ų����涨���ȣ����������룺\n");
		}
	} while (getSize(aName) > 18);

	Card* pCard = queryCardNamelist(aName);
	if (pCard == NULL)
	{
		printf("û���ҵ��ÿ��ţ�\n");
	}
	else
	{
		printf("�ÿ��Ŵ��ڣ�����������鿴��Ϣ��\n");
		char aPwd[32] = { 0 };
		do
		{
			printf(YELLOW"���������룺����ע�����벻�ܳ���8���ַ���"NONE);
			scanf("%s", &aPwd);

			//����������ݽ���һ���ж�
			int nPwdSize = getSize(aPwd);
			if (nPwdSize > 8)
			{
				printf(RED"���볬���涨���ȣ����������룺\n"NONE);
			}
		} while (getSize(aPwd) > 8);

		bool judge = queryCardPwd(pCard, aPwd);

		if (judge)
		{
			printf("�ÿ��Ŵ��ڣ�����Ϊ��ע����\n");
			Sleep(1);
			bool ret=cancelCardList(aName);
			if (ret)
			{
				printf(GREEN"ע���ɹ���\n"NONE);
			}
			else
			{
				printf(RED"ע��ʧ�ܣ�\n"NONE);
			}
		}
		else
		{
			printf(RED"�������\n"NONE);
		}
	}
}