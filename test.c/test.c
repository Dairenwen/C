#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>//strlen,strcpy字符串拷贝，memset字符串置换，字符串比较函数strcmp函数头文件
#include<windows.h>//Sleep函数头文件
#include<stdlib.h>//system(执行系统命令函数）头文件
//头文件可以自己写，add.h声明，add.c定义，此文件可引入头文件使用函数
//int Dai(int x, int y)
//{
//	int c = 0;
//	if (x > y)
//	{
//		c = x;
//    }
//	else if (x < y)
//	{
//		c = y;
//	}
//	return c;
//}
//形参是实参的一份临时拷贝，对形参的修改不会改变实参！
//void swap(int* pa, int* pb)//pa为指针变量//这里的papb为形参，只在函数内部发挥作用，执行完后失效
//{
//	int tmp = 0;
//	tmp = *pa;//*pa解引用操作，通过地址找到内容
//	*pa = *pb;
//	*pb = tmp;
//}
//void decide(int x)//判断素数
//{
//	int i = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//		{
//			printf("不是素数\n");
//			break;
//		}
//	}
//	if (i == x)
//	{
//		printf("是素数\n");
//	}
//}
//void decide(int x)//判断闰年
//{
//	if (x % 4 == 0 || x % 100 == 0)
//	{
//		printf("是闰年\n");
//	}
//	else if (x % 400 == 0)
//	{
//		printf("哟西，闰年\n");
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//}
//void find(int x)//二分查找 应用函数
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
//	int left = 0;
//	int mid = 0;
//	int right = sizeof(arr1) / sizeof(arr1[0]) - 1;
//	while(left<=right)
//	{
//		mid = (left + right) / 2;
//		if (x < arr1[mid])
//		{
//			right = mid - 1;
//		}
//		else if (x > arr1[mid])
//		{
//			left = mid + 1;
//		}
//		else 
//		{
//			printf("找到了，是%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("404 not found \n");
//	}
//}
//#include"num.h"//自己创作头文件用""
//void print(int x)//分数字打印1234（递归例1）
//{
//	if (x > 9)//一定要注明条件，每次递归之后必须越来越接近限制条件（将复杂任务化简为简单任务）
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//}
//int luckin(char* pa)//char*为指针变量，字符串传过来的是第一个字符的地址！
//{
//	if (*pa != '\0')
//	{
//		pa++;
//		return luckin(pa)+1;
//	}
//	else
//	    return 0;
//}
//int plus(int x)//阶乘；
//{
//	if (x == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return x * plus(x - 1);
//	}
//}
//int fei(int x)//斐波那契数列（算法可以简化）
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (x > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		x--;
//	}
//	return c;
//}
//void design(int* arr, int x)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x - 1; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < x - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = 0;
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//			break;
//	}
//}
int main()
{
	/*int n = 3;
	int ret = 1;
	int i = 1;
	int sum = 0;
	 while (i<=n)
	 {
		ret = ret * i;
		sum = sum + ret;
		i++;
	 }
	printf("sum= %d\n", sum);

	return 0;




	int n = 3;
	int ret = 1;
	int i = 1;
	while (i <= n)
	{
		ret = ret * i;
		i++;
	}
	printf("sum= %d\n", ret);*/
	//二分查找：
	//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	//printf("请输入你想查找的数字：\n");
	//int k = 0;
	//scanf("%d", &k);
	//
	//int mid = 0;
	//int left = 0;
	//int right = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);//计算元素的个数
	//right = sz - 1;
	//while (left <= right)
	//{
	//	mid = (left + right) / 2;
	//	if (arr[mid] > k)
	//		right = mid - 1;
	//	else if (arr[mid] < k)
	//		left = mid + 1;
	//	else if (arr[mid] = k)
	//	{
	//		printf("find it %d\n",mid);
	//		break;
	//	}
	//}
	//	if (left > right)
	//	printf("404 not found\n");
	//char arr1[] = "GENSHEN IMPACT";//这里注意字符串用char arr定义
	//char arr2[] = "66666666666666";//而数组用int arr[]={}
	//int left = 0;
	////int right = sizeof(arr1) / sizeof(arr1[0])-2;//计算元素个数
	////int right = strlen(arr1) - 1;
	//while (left <= right)
	//{
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	printf("%s\n", arr2);
	//	Sleep(1234);//Sleep函数用于控制执行时间，单位毫秒！
	//	system("cls");//cls系统命令清屏
	//	left++;
	//	right--;
	//	

	//}
	//if (left > right)
	//{
	//	printf("数据加载中：\n");
	//	Sleep(1234);
	//	system("cls");
	//	printf("your password: \n");
	//}
	//char arr[20] = { 0 };
	//int i = 0;
	//char arr1[] = "GENSHEN IMPACT!!!";
	//char arr2[] = "_________________";
	//int left = 0;
	//int right = sizeof(arr1) / sizeof(arr1[0]) - 2;


	//for (i = 1; i <= 3; i++)
	//{
	//	printf("请输入您的密码：");
	//	scanf("%s", &arr);//&不要忘记！
	//	if (strcmp(arr, "060821") == 0)//==判断符号不要忘记！(==不能比较字符串是否相等）
	//	{
	//		printf("输入成功，正在进入系统\n");
	//		Sleep(1234);
	//		while (left <= right)
	//		{
	//			arr2[left] = arr1[left];
	//			arr2[right] = arr1[right];
	//			printf("%s", arr2);
	//			Sleep(1324);
	//			system("cls");
	//			left++;
	//			right--;

	//		}
	//		if (left > right)
	//		{
	//			printf("您今天已上线3个小时。请注意休息！");
	//		}
	//		break;
	//	}
	//	else

	//	{
	//		printf("输入错误，请再次输入：");
	//	}
	//}
//int i = 0;
//int j = 0;
//for (i = 100; i <= 200; i++)
//{
//	for (j = 2; j <= i; j++)
//	{
//		if (i % j == 0)
//		{
//			break;
//		}
//
//	}
//	if (i == j)
//	{
//		printf("%d\n", i);//试除法
//	}
//}
//sqrt开平方函数
//#include<math.h>
//int a = 0;
//int b = 1;
//double sum = 0.0;//双浮点型表示方式
//
//for (a = 1; a < 101; a++)
//{
//	sum=sum+b*1.0/a;//分数的表示类型
//	b = -b;
//}
//printf("the sum= %lf\n", sum);
//int a = 0;
//double sum1= 0.0;
//double sum2 = 0.0;//double sum1，sum2，sum3貌似是错的？
//double sum3 = 0.0;
//int i,j = 0;
//for (i = 1; i < 100; i += 2)
//{
//	sum1 =sum1+1.0/ i;
//}
//for (j = 2; j <= 100; j += 2)
//{
//	sum2 =sum2+1.0/ j;
//}
//sum3 = sum1 - sum2;
//printf("%lf\n", sum3);
// 
//int arr[] = { 1,3,5,7,9,15353,2343653 };
//int max = arr[1];
//int i = 0;
//int sz = sizeof(arr) / sizeof(arr[0]);
//for (i = 1; i <sz; i++)
//{
//	if (arr[i] > max)
//	{
//		max = arr[i];
//	}
//}
//printf("%d\n", max);
// 
//int left = 0;
//int k = 3;
//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//int right = sizeof(arr) / sizeof(arr[0])-1;
//
//while (left <= right)
//{
//	int mid = (left + right) / 2;//必须放到大括号里；
//	if (k < arr[mid])
//	{
//		right = mid - 1;
//	}
//	else if (k > arr[mid])
//	{
//		left = mid + 1;
//	}
//	else
//	{
//		printf("find it,%d\n", mid);
//		break;
//	}
//    
//}
//if (left > right)
//{
//	printf("404 not found\n");
//}
//
//double sum = 0.0;
//int a = 1;
//int b = 0;
//for (b = 1; b <= 100; b++)
//{
//	sum = sum +a*1.0/ b;
//	a = -a;
//
//}
//printf("%lf\n", sum);
//int i = 0;
//int j = 0;
//for (i = 1; i <= 9; i++)
//{
//	for (j = 1; j <= i; j++)
//	{
//		printf("%d*%d=%-2d ",i,j,i*j);//%2d表示打印两位 eg08 11
//	}                                 //%-2d不够向前填充
//	printf("\n");
//}//打印99乘法表
//猜数字游戏，重点！！！！！！！见game1.c文件
// 
//char arr1[] = "hello world";
//char arr2[20] = "###########";
//strcpy(arr2, arr1);//strcpy函数（destination，source），由source拷贝到destination当中去
//printf("%s\n", arr2);
//char arr[] = "hello bit!";
//printf("%s\n", arr);
//memset(arr, '6', 5);//memset（目标字符串，'替换成什么字符',替换前几位）
//printf("%s\n", arr);
// 
//int a, b = 0;
//scanf("%d%d", &a, &b);
//int i = Dai(a, b);
//printf("%d\n",i);
// 
//int a = 0;//将ab的互换
//int b = 0;
//scanf("%d%d", &a, &b);
//swap(&a, &b);//创建函数swap，放入ab地址//这里的ab为实参
//printf("%d %d\n", a, b);
//int a = 0;
//printf("请输入数字>: \n");
//scanf("%d", &a);
//decide(a);
// 
//int a = 0;
//printf("请输入年份>: \n");
//scanf("%d", &a);
//decide(a);
// 
// 
//int a = 0;
//printf("请输入你想查找的数字>: \n");
//scanf("%d", &a);
//find(a);
//printf("%d", printf("%d", printf("%d", 43)));//printf打印完后返回值为打印的字符个数
//int a = 0;//自己创建头文件，引用函数
//num(&a);
//printf("%d\n", a);
//num(&a);
//printf("%d\n", a);
//int a = 0;
//scanf("%d", &a);
//print(a);
//char arr[] = "hello bit";//\0是字符串结束标志，不作为长度
// 
//int a = 0;
//a = luckin(arr);
//printf("%d", a);
// 
//int a = 0;
//scanf("%d", &a);
//int b = plus(a);
//printf("%d\n", b);
// 
//int a = 0;
//scanf("%d", &a);
//int b =fei(a);
//printf("%d\n", b);
// 
//int arr[] = {9,8,7,6,5,4,3,2,1,0};
//int sz = sizeof(arr) / sizeof(arr[0]);
//design(arr, sz);
// 
//int i = 1;
//for (i = 0; i < sz; i++)
//{
//	printf("%d ", arr[i]);
//}

return 0;
}

			
			
		
	
	




		
		


   



	




	
	
	




	
