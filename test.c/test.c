#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>//strlen,strcpy�ַ���������memset�ַ����û����ַ����ȽϺ���strcmp����ͷ�ļ�
#include<windows.h>//Sleep����ͷ�ļ�
#include<stdlib.h>//system(ִ��ϵͳ�������ͷ�ļ�
//ͷ�ļ������Լ�д��add.h������add.c���壬���ļ�������ͷ�ļ�ʹ�ú���
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
//�β���ʵ�ε�һ����ʱ���������βε��޸Ĳ���ı�ʵ�Σ�
//void swap(int* pa, int* pb)//paΪָ�����//�����papbΪ�βΣ�ֻ�ں����ڲ��������ã�ִ�����ʧЧ
//{
//	int tmp = 0;
//	tmp = *pa;//*pa�����ò�����ͨ����ַ�ҵ�����
//	*pa = *pb;
//	*pb = tmp;
//}
//void decide(int x)//�ж�����
//{
//	int i = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//		{
//			printf("��������\n");
//			break;
//		}
//	}
//	if (i == x)
//	{
//		printf("������\n");
//	}
//}
//void decide(int x)//�ж�����
//{
//	if (x % 4 == 0 || x % 100 == 0)
//	{
//		printf("������\n");
//	}
//	else if (x % 400 == 0)
//	{
//		printf("Ӵ��������\n");
//	}
//	else
//	{
//		printf("��������\n");
//	}
//}
//void find(int x)//���ֲ��� Ӧ�ú���
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
//			printf("�ҵ��ˣ���%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("404 not found \n");
//	}
//}
//#include"num.h"//�Լ�����ͷ�ļ���""
//void print(int x)//�����ִ�ӡ1234���ݹ���1��
//{
//	if (x > 9)//һ��Ҫע��������ÿ�εݹ�֮�����Խ��Խ�ӽ��������������������񻯼�Ϊ������
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//}
//int luckin(char* pa)//char*Ϊָ��������ַ������������ǵ�һ���ַ��ĵ�ַ��
//{
//	if (*pa != '\0')
//	{
//		pa++;
//		return luckin(pa)+1;
//	}
//	else
//	    return 0;
//}
//int plus(int x)//�׳ˣ�
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
//int fei(int x)//쳲��������У��㷨���Լ򻯣�
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
	//���ֲ��ң�
	//int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	//printf("������������ҵ����֣�\n");
	//int k = 0;
	//scanf("%d", &k);
	//
	//int mid = 0;
	//int left = 0;
	//int right = 0;
	//int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�صĸ���
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
	//char arr1[] = "GENSHEN IMPACT";//����ע���ַ�����char arr����
	//char arr2[] = "66666666666666";//��������int arr[]={}
	//int left = 0;
	////int right = sizeof(arr1) / sizeof(arr1[0])-2;//����Ԫ�ظ���
	////int right = strlen(arr1) - 1;
	//while (left <= right)
	//{
	//	arr2[left] = arr1[left];
	//	arr2[right] = arr1[right];
	//	printf("%s\n", arr2);
	//	Sleep(1234);//Sleep�������ڿ���ִ��ʱ�䣬��λ���룡
	//	system("cls");//clsϵͳ��������
	//	left++;
	//	right--;
	//	

	//}
	//if (left > right)
	//{
	//	printf("���ݼ����У�\n");
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
	//	printf("�������������룺");
	//	scanf("%s", &arr);//&��Ҫ���ǣ�
	//	if (strcmp(arr, "060821") == 0)//==�жϷ��Ų�Ҫ���ǣ�(==���ܱȽ��ַ����Ƿ���ȣ�
	//	{
	//		printf("����ɹ������ڽ���ϵͳ\n");
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
	//			printf("������������3��Сʱ����ע����Ϣ��");
	//		}
	//		break;
	//	}
	//	else

	//	{
	//		printf("����������ٴ����룺");
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
//		printf("%d\n", i);//�Գ���
//	}
//}
//sqrt��ƽ������
//#include<math.h>
//int a = 0;
//int b = 1;
//double sum = 0.0;//˫�����ͱ�ʾ��ʽ
//
//for (a = 1; a < 101; a++)
//{
//	sum=sum+b*1.0/a;//�����ı�ʾ����
//	b = -b;
//}
//printf("the sum= %lf\n", sum);
//int a = 0;
//double sum1= 0.0;
//double sum2 = 0.0;//double sum1��sum2��sum3ò���Ǵ�ģ�
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
//	int mid = (left + right) / 2;//����ŵ��������
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
//		printf("%d*%d=%-2d ",i,j,i*j);//%2d��ʾ��ӡ��λ eg08 11
//	}                                 //%-2d������ǰ���
//	printf("\n");
//}//��ӡ99�˷���
//��������Ϸ���ص㣡��������������game1.c�ļ�
// 
//char arr1[] = "hello world";
//char arr2[20] = "###########";
//strcpy(arr2, arr1);//strcpy������destination��source������source������destination����ȥ
//printf("%s\n", arr2);
//char arr[] = "hello bit!";
//printf("%s\n", arr);
//memset(arr, '6', 5);//memset��Ŀ���ַ�����'�滻��ʲô�ַ�',�滻ǰ��λ��
//printf("%s\n", arr);
// 
//int a, b = 0;
//scanf("%d%d", &a, &b);
//int i = Dai(a, b);
//printf("%d\n",i);
// 
//int a = 0;//��ab�Ļ���
//int b = 0;
//scanf("%d%d", &a, &b);
//swap(&a, &b);//��������swap������ab��ַ//�����abΪʵ��
//printf("%d %d\n", a, b);
//int a = 0;
//printf("����������>: \n");
//scanf("%d", &a);
//decide(a);
// 
//int a = 0;
//printf("���������>: \n");
//scanf("%d", &a);
//decide(a);
// 
// 
//int a = 0;
//printf("������������ҵ�����>: \n");
//scanf("%d", &a);
//find(a);
//printf("%d", printf("%d", printf("%d", 43)));//printf��ӡ��󷵻�ֵΪ��ӡ���ַ�����
//int a = 0;//�Լ�����ͷ�ļ������ú���
//num(&a);
//printf("%d\n", a);
//num(&a);
//printf("%d\n", a);
//int a = 0;
//scanf("%d", &a);
//print(a);
//char arr[] = "hello bit";//\0���ַ���������־������Ϊ����
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

			
			
		
	
	




		
		


   



	




	
	
	




	
