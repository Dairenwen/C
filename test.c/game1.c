//#include<stdio.h>
//#include<stdlib.h>//srand��randͷ�ļ�
//#include<time.h>//time����ͷ�ļ�
//#include<windows.h>
//void menu()//void��ʾû�з���ֵ������һ��İ��������
//{
//	printf("******************************\n"); Sleep(500);
//	printf("********��ѡ��ʼ��ʽ********\n"); Sleep(500);
//	printf("***1.��Ϸ��ʼ****0.��Ϸ����***\n"); Sleep(500);
//	printf("******************************\n"); Sleep(500);
//}
//void game()//����һ�������
//{
//	int i = 0;
//	i = rand()%100+1;//����һ��1-100�������
//    while (1)//1ֱ�Ӵ����ж�����
//	{
//		int j = 0;
//		printf("���������֣�> ");
//		scanf_s("%d", &j);//scanf_s���ü���#define...
//		if (j < i)
//		{
//			printf("��С��\n");
//			Sleep(1234);
//		}
//		else if (j > i)
//		{
//			printf("�´���\n");
//			Sleep(1234);
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶��ˣ�");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;                  //������Ҫ�õ�unsighed int��srand�����Ͼ���long������
//	srand((unsigned int)time(NULL));//�����������Ҫ������rand����ǰ��srand����
//	do                              //��ʱ���������ʱ�����ɵ���ʼ��-��1970.1.1.00��00��00��
//	{                               //do...whileѭ������ִ��һ�Σ����ж�������
//		menu();//����˵�����
//		printf("���������֣�> \n");
//		scanf_s("%d", &input);
//		switch (input)//switch������з�֧
//		{
//		case 1:
//			game();
//			Sleep(1000);
//			system("cls");
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			system("cls");
//			break;
//		default:
//			printf("ѡ�����\n");
//			system("cls");
//			break;
//		}
//	} while (input);
//	printf("�˳�����\n");
//	return 0;
//}
