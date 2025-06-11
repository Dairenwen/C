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
	printf("\n��ӭ����Ʒѹ���ϵͳ\n");
	bool init = initCardList();
	bool initbill = initBillingList();
	if (init == false||initbill==false)
	{
		printf(RED"��ʼ��ʧ�ܣ�\n"NONE);
		return 0;
	}

	do
	{
		//���ϵͳ�˵�
		menu();
		printf("��ѡ��˵������ţ�0~8����");
		scanf("%d", &nSelection);

		switch (nSelection)
		{
			case Quit:
				SaveCardList();
				releaseCardList();
				releaseBillingList();
				printf("\n�˳�\n");
				break;

			case Add:
				printf("\n��ӿ�\n");
				addlist();
				SaveCardList();
				break;

			case Searchcard:
				printf("\n��ѯ��\n");
				querylist();
				SaveCardList();
				break;

			case Logon:
				printf("\n�ϻ�\n");
				logon();
				SaveCardList();
				SaveBillingList();
				break; 

			case Logoff:
				printf("\n�»�\n");
				logoff();
				SaveCardList();
				SaveBillingList();
				break;

			case Recharge:
				printf("\n��ֵ\n");
				recharge();
				SaveCardList();
				break;

			case Refund:
				printf("\n�˷�\n");
				refund();
				SaveCardList();
				break;

			case Searchcount:
				printf("\n��ѯͳ��\n");
				count();
				SaveCardList();
				break;

			case Cancel:
				printf("\nע����\n");
				cancel();
				SaveCardList();
				break;

			default:
				printf("\n����Ĳ˵���Ŵ���\n");
				break;
					
		}
	} while (nSelection);

	return 0;
}