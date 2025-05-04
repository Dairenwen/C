//#include<stdio.h>
//#include<stdlib.h>//srand，rand头文件
//#include<time.h>//time函数头文件
//#include<windows.h>
//void menu()//void表示没有返回值（定义一个陌生函数）
//{
//	printf("******************************\n"); Sleep(500);
//	printf("********请选择开始方式********\n"); Sleep(500);
//	printf("***1.游戏开始****0.游戏结束***\n"); Sleep(500);
//	printf("******************************\n"); Sleep(500);
//}
//void game()//生成一个随机数
//{
//	int i = 0;
//	i = rand()%100+1;//生成一个1-100的随机数
//    while (1)//1直接代替判断条件
//	{
//		int j = 0;
//		printf("请输入数字：> ");
//		scanf_s("%d", &j);//scanf_s不用加上#define...
//		if (j < i)
//		{
//			printf("猜小了\n");
//			Sleep(1234);
//		}
//		else if (j > i)
//		{
//			printf("猜大了\n");
//			Sleep(1234);
//		}
//		else
//		{
//			printf("恭喜你，猜对了！");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input = 0;                  //函数需要用到unsighed int，srand本质上就是long长整型
//	srand((unsigned int)time(NULL));//生成随机数必要条件，rand函数前用srand函数
//	do                              //用时间戳来决定时间生成的起始点-（1970.1.1.00：00：00）
//	{                               //do...while循环，先执行一次，再判断条件！
//		menu();//定义菜单函数
//		printf("请输入数字：> \n");
//		scanf_s("%d", &input);
//		switch (input)//switch语句运行分支
//		{
//		case 1:
//			game();
//			Sleep(1000);
//			system("cls");
//			break;
//		case 0:
//			printf("退出游戏\n");
//			system("cls");
//			break;
//		default:
//			printf("选择错误\n");
//			system("cls");
//			break;
//		}
//	} while (input);
//	printf("退出程序\n");
//	return 0;
//}
