#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include <string.h>
//int mstrlen(char* pa)
//{
//	if (*pa != '\0')
//	{
//		return mstrlen(pa+1) + 1;
//	}
//}
//void reverse(char arr[])
//{
//	char tmp = arr[0];
//	int str = mstrlen(arr);
//	arr[0] = arr[str - 1];
//	arr[str - 1] = '\0';
//	if (mstrlen(arr+1) > 1)
//		reverse(arr + 1);
//	arr[str - 1] = tmp;
//}
//int main()
//{
//	char arr[] = "abcdefghik";
//	reverse(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int canculate(int a)
//{
//	if (a > 9)
//	{
//		return canculate(a / 10) + a % 10;
//	}
//	if (a <= 9)
//		return a;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int sum = 0;
//	sum =canculate(a);
//    printf("%d", sum);
//}


/*int main()
{
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	int j = 1;
	int k = 1;
	while (a > 2)
	{
		i = j;
		j = k;
		k = i + j ;
		a--;
	}
	printf("%d", k);

	return 0;
}*/

//typedef struct Stu
//{
//	char arr[20];
//	int age;
//	char tele[12];
//	char b[3];
//}Stu;//stu为类型，如果是struct就是变量
//
//void print1(Stu a)
//{
//	printf("%s\n", a.arr );
//	printf("%d\n", a.age);
//	printf("%s\n", a.tele);
//	printf("%s\n", a.b);
//}
//
//void print2(Stu* pa)
//{
//	printf("%s\n", pa->arr);
//	printf("%d\n", pa->age);
//	printf("%s\n", pa->tele);
//	printf("%s\n", pa->b);
//}
//int main()
//{
//	Stu a = { "孙歆茹",18,"18971238949","女" };
//	print1(a);
//	print2(&a);
//	return 0;
//}

//int game(int x)
//{
//	if (x == 0)
//		return 0;
//	else
//	{
//		x = x & (x - 1);
//		return game(x) + 1;
//	}
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int b = game(a);
//	printf("%d", b);
//	return 0;
//}

//int main()
//{
//	int a,b = 0;
//	scanf("%d%d", &a,&b);
//	int c = a ^ b;
//	int num = 0;
//	while (c)
//	{
//		c = c & (c - 1);
//		num++;
//	}
//	printf("%d", num);
//	return 0;
//}

//优化多用const assert
//#include<assert.h>//警告函数头文件
//char* my(char* arr, const char* arr1)
//{
//	assert(arr != NULL);//为真不执行 为假执行
//	assert(arr1 != NULL);
//	while (*arr++ = *arr1++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr[20] = "abcdef";
//	char arr1[20] = "###";
//	my(arr, arr1);
//	printf("%s", arr);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    int d = 0;
//    int arr[100] = { 0 };
//    scanf("%d", &a);
//    int i = 0;
//    for (i = 0; i < a; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    i = 0;
//    for (i = 0; i < a; i++)
//    {
//        if (arr[i] >= 85)
//            b++;
//        else if (arr[i] >= 60 && arr[i] < 85)
//            c++;
//        else
//            d++;
//
//    }
//    printf("%d %d %d", b, c, d);
//    return 0;
//}

//void menu()
//{
//	printf("***************************\n");
//	printf("********猜数字游戏*********\n");
//	printf("***************************\n");
//	printf("***1.玩游戏*****0.退出*****\n");
//	printf("***************************\n");
//}
//void game()
//{
//	int a = rand() % 100 + 1;
//	int b = 0;
//	int c = 5;
//	while (c)
//	{
//		printf("输入你的数字>:\n");
//		scanf("%d", &b);
//		if (a > b)
//		{
//			printf("猜小了\n");
//			c--;
//			printf("剩余%d次机会\n", c);
//		}
//		else if (a < b)
//		{
//			printf("猜大了\n");
//			c--;
//			printf("剩余%d次机会\n", c);
//		}
//		else
//		{
//			printf("猜对了！\n");
//			break;
//		}
//	}
//	if (c == 0)
//	{
//		printf("你太菜了！\n");
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请输入:>");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("正在退出\n");
//			break;
//		default:
//			printf("输入错误。。");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[10] = { 0 };
//	int left = 0;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	while (left <= 9)
//	{
//		int tmp = 0;
//		tmp = arr1[left];
//		arr1[left] = arr2[left];
//		arr2[left] = tmp;
//		left++;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int i = 1;
//	int max = 1;
//	while (i <= a && i <= b)
//	{
//		if (a % i == 0 && b % i == 0)
//		{
//			if (i > max)
//			{
//				max = i;
//			}
//		}
//		i++;
//	}
//	printf("%d", max);
//	return 0;
//}

//void reverse(char* arr, int sz)
//{
//	int left = 0;
//	char tmp = 0;
//	while (left < sz)
//	{
//		tmp = *(arr + sz-1);
//		*(arr + sz-1) = *(arr + left);
//		*(arr + left) = tmp;
//		sz--;
//		left++;
//	}
//}
//int main()
//{
//	char arr[] = "abcdefg";
//	int sz = strlen(arr);
//	reverse(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = {1,4,7,9,8,6,5,4,1,5};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		while (arr[left] % 2 != 0)
//		{
//			left++;
//		}
//		while (arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if(left < right)
//		{
//			int tmp = 0;
//			tmp = arr[right];
//			arr[right] = arr[left];
//			arr[left] = tmp;
//			left++;
//			right--;
//		}
//	}
//	
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 1,4,7,9,8,6,5,4,1,5 };
//	int arr1[10] = { 0 };
//	int arr2[10] = { 0 };
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr[i] % 2 == 0)
//		{
//			arr1[i] = arr[i];
//		}
//		else
//		{
//			arr2[i] = arr[i];
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr2[i] != 0)
//		printf("%d ", arr2[i]);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		if (arr1[i] != 0)
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

//int main()
//{
//    int a = 0;
//    int b = 0;
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    scanf("%d%d", &a, &b);
//    int arr1[1000] = { 0 };
//    int arr2[1000] = { 0 };
//    int arr3[2000] = { 0 };
//    for (i = 0; i < a; i++)
//    {
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < b; i++)
//    {
//        scanf("%d", &arr2[i]);
//    }
//    i = 0;
//    while (j < a && k < b)
//    {
//        if (arr1[j] > arr2[k])
//        {
//            arr3[i] = arr2[k];
//            k++;
//            i++;
//        }
//        else if (arr1[j] < arr2[k])
//        {
//            arr3[i] = arr1[j];
//            j++;
//            i++;
//        }
//    }
//    if (j == a)
//    {
//        while (k < b)
//        {
//            arr3[i] = arr2[k];
//            k++;
//            i++;
//        }
//    }
//    else
//    {
//        while (j < a)
//        {
//            arr3[i] = arr1[j];
//            j++;
//            i++;
//        }
//    }
//    for (i = 0; i < a + b; i++)
//    {
//        printf("%d ", arr3[i]);
//    }
//    return 0;
//}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	for (i = 1; i <= a ; i++)
//	{
//		int j = 0;
//		for (j = 0; j <a - i ; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*i-1 ; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i =a-1; i>0; i--)
//	{
//		int j = 0;
//		for (j = 0; j<a-i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*i-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//水仙花数！！求几位数，就是每位的几次方
//#include<math.h>
//double judge(long int i,int b)
//{
//	if (i > 9)
//	{
//		return judge(i / 10,b) + pow(i % 10, b);
//	}
//	else
//		return pow(i, b);
//}
//int main()
//{
//	long int i = 0;
//	int b = 0;
//	printf("0\n");
//	for (b = 1; b <= 5; b++)
//	{
//		for (i = pow(10,b-1); i < pow(10, b); i++)
//		{
//                if (i == (long int)judge(i,b))
//				{
//					printf("%ld\n", i);
//				}
//				
//		}
//	}
//	return 0;
//}

//double game(int a, int i)
//{
//	int b = 0;
//	int my = 0;
//	for (b = 0; b < i; b++)
//	{
//		my = my + pow(10, b) * a;
//	}
//	return my;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= 5; i++)
//	{
//		sum = sum + (int)game(a, i);
//	}
//	printf("%d", sum);
//	return 0;
//}

//double game(int a, int i)
//{
//	int b = 0;
//	int my = 0;
//	for (b = 0; b < i; b++)
//	{
//		my = my + pow(10, b) * a;
//	}
//	return my;
//}
//int main()
//{
//	int a = 0;
//	int k = 0;
//	scanf("%d %d", &a, &k);
//	int i = 0;
//	int sum = 0;
//	for (i = 1; i <= k; i++)
//	{
//		sum = sum + (int)game(a, i);
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int Func_drink(int money) {
//	int ret = money;//最终喝到的汽水瓶数
//	int ex = 0;//用空瓶交换到的汽水瓶数
//	int rest = 0;//每次用空瓶换后剩余空瓶数
//	ex = money;
//	while (ex >= 1) {
//		ex += rest;
//		ret += ex / 2;
//		rest = ex % 2;
//		ex /= 2;
//	}
//	return ret;
//}
//int main() {
//	int money;
//	printf("请输入钱数：\n");
//	scanf("%d", &money);
//	printf("可以喝到的汽水瓶数为：%d\n", Func_drink(money));
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 99999; i++)
//	{
//		int count = 1;
//		int tmp = i;
//		int sum = 0;
//		//判断i是否为水仙花数
//		//1. 求判断数字的位数
//		while (tmp / 10)
//		{
//			count++;
//			tmp = tmp / 10;
//		}
//
//		//2. 计算每一位的次方和
//		tmp = i;
//		while (tmp)
//		{
//			sum += pow(tmp % 10, count);
//			tmp = tmp / 10;
//		}
//
//		//3. 判断
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int ren(int arr[], int sz)
//{
//	int i = 0;
//	int a = 0;
//	for (i = 0; i < sz; i++)
//	{
//		a ^= arr[i];
//	}
//	return a;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = ren(arr, sz);
//	printf("%d", ret);
//	return 0;
//}


//int game(int a)
//{
//	int qishui = a;
//	int pingzi = qishui;
//	int shengxia = 0;
//	
//	while (pingzi >= 1)
//	{
//		pingzi += shengxia;
//		shengxia = pingzi % 2;
//		qishui += pingzi / 2;
//		pingzi /= 2;
//	}
//	return qishui;
//}
////	int ret = money;//最终喝到的汽水瓶数
////	int ex = 0;//用空瓶交换到的汽水瓶数
////	int rest = 0;//每次用空瓶换后剩余空瓶数
////	ex = money;
////	while (ex >= 1) {
////		ex += rest;
////		ret += ex / 2;
////		rest = ex % 2;
////		ex /= 2;
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = game(a);
//	printf("%d", ret);
//	return 0;
//}