#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include <string.h>
#include<assert.h>
//int bin_search(int arr[], int left, int right, int key)
//{
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	if (left > right)
//		return -1;
//}
//int main()
//{
//	int left = 0;
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int right = sizeof(arr) / sizeof(arr[0])-1;
//	int key = 0;
//	scanf("%d", &key);
//	int a = bin_search(arr, left, right, key);
//	printf("%d", a);
//	return 0;
//}

//void init(int arr[20])
//{
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void print(int arr[20])
//{
//	int i = 0;
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void reverse(int arr[20],int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int tmp = 0;
//		tmp = arr[right];
//		arr[right] = arr[left];
//		arr[left] = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	init(arr);
//	print(arr);
//	reverse(arr,sz);
//	return 0;
//}

//int is_prime(int i)
//{
//	int a = 0;
//	for (a = 2; a <= i; a++)
//	{
//		if (i % a == 0)
//			break;
//	}
//	if (i == a)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int a = is_prime(i);
//		if (a == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}

//void judge(int a)
//{
//	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
//	{
//		printf("hi");
//	}
//	else
//		printf("no");
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	judge(a);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	for (i = 1; i <= a; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, j * i);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[5] = { 1,2,3,4,5 };
//	int arr2[5] = { 2,3,4,5,6 };
//	int arr3[5] = { 3,4,5,6,7 };
//	int arr4[5] = { 4,5,6,7,8 };
//	int arr5[5] = { 0,0,0,0,0 };
//	int* arr6[5] = { arr1,arr2,arr3,arr4,arr5 };
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ",arr6[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//void print(int(*p)[4], int x, int y)//这里数组指针就是要写成int(*p)[]的格式，语法
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][4] = { {1,2,3,4} , {2,3,4,5} ,{3,4,5,6} };
//	print(arr, 3, 4);//arr传的是首元素地址，二位数组首元素就是一个一维数组{1，2，3，4}
//	return 0;
//}

//int main()
//{
//	int a, b = 0;
//	scanf("%d%d", &a, &b);
//	if (a > b)
//		printf("%d", a);
//	else if (a < b)
//		printf("%d", b);
//	return 0;
//}

//int add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	int (*p)(int, int) = &add;
//	printf("%d", p(a, b));
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf("%d%d%d", &a, &b, &c);
//	if (a > b && a > c)
//	{
//		if (b > c)
//			printf("%d%d%d", a, b, c);
//		else
//			printf("%d%d%d", a, c, b);
//	}
//	if (b > a && b > c)
//	{
//		if (a > c)
//			printf("%d%d%d", b, a, c);
//		else
//			printf("%d%d%d", b, c, a);
//	}
//	if (c > a && c > b)
//	{
//		if (a > b)
//			printf("%d%d%d", c, a, b);
//		else
//			printf("%d%d%d", c, b, a);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 100; i < 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j <= i; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (i == j)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a,&b);
//	int i = 1;
//	int max = 0;
//	while (i <= a && i <= b)
//	{
//		if (a % i == 0 && b % i == 0)
//		{
//			if (i > max)
//				max = i;
//		}
//		i++;
//	}
//	printf("%d\n", max);
//	return 0;
//}

//int main()
//{
//	int a = 18;
//	int b = 24;
//	int c = 0;
//
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//
//	printf("%d\n", b);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	for (i = 1; i <= a; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", j, i, j * i);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//void reverse(int* a, int* b)
//{
//	int tmp = 0;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a,&b );
//	reverse(&a,&b);
//	printf("%d %d", a, b);
//	return 0;
//}

//int add(int x, int y)
//{
//	return x + y;
//}
//int jian(int x, int y)
//{
//	return x - y;
//}
//int chen(int x, int y)
//{
//	return x * y;
//}
//int chu(int x, int y)
//{
//	return x / y;
//}
//void menu()
//{
//	printf("************************\n");
//	printf("****1.********2.*****\n");
//	printf("****3.*****4.****\n");
//	printf("**5.****6.*******\n");
//	printf("****0.***************\n");
//}
//int main()
//{
//	int input = 0;
//	int (*p[5])(int, int) = { NULL,add,jian,chen,chu };
//	do
//	{
//		menu();
//		int a = 0;
//		int b = 0;
//		printf("请输入你的选择：》\n");
//		scanf("%d", &input);
//		printf("你的数字：》\n");
//        scanf("%d%d", &a, &b);
//		int ret = p[input](a, b);
//		printf("%d \n", ret);
//
//	} while (input);
//	return 0;
//}

//int power(int n, int a)
//{
//	if (a > 1)
//	{
//		return n * power(n, a - 1);
//	}
//	else
//		return n;
//}
//int main()
//{
//	int n = 0;
//	int a = 0;
//	scanf("%d%d", &n, &a);
//	int c = power(n, a);
//	printf("%d", c);
//	return 0;
//}

//int game(int a)
//{
//	if (a > 9)
//	{
//		return game(a / 10) + a % 10;
//	}
//	else
//		return a;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int b = game(a);
//	printf("%d", b);
//	return 0;
//}

//int game(char* arr)
//{
//	if (*arr != '\0')
//	{
//		return game(arr + 1) + 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[10] = "abcde";
//	int a= game(arr);
//	printf("%d",a);
//	return 0;
//}

//int game(char* arr)
//{
//	int i = 0;
//	while (*arr != '\0')
//	{
//		i++;
//		arr++;
//	}
//	return i;
//}
//int main()
//{
//	char arr[10] = "abcde";
//	int a = game(arr);
//	printf("%d", a);
//	return 0;
//}

//void game(int a)
//{
//	if (a > 9)
//	{
//		game(a / 10);
//	}
//	printf("%d ", a % 10);
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	game(a);
//	return 0;
//}

//int main()
//{
//	int a = 27;
//	int b = 18;
//	int c = 0;
//	while (c = a % b)
//	{
//		a = b;
//		b = c;
//	}
//	printf("%d", b);
//	return 0;


//int main()
//{
//    long int a = 0;
//    long int b = 0;
//    long int i = 0;
//    scanf("%ld%ld", &a, &i);
//    b = i;
//    int c = 0;
//    while (c = a % b)
//    {
//        a = b;
//        b = c;
//    }
//    printf("%ld", b + (a * i) / b);//两数相乘除以最大公约数就是最小公倍数
//    return 0;
//}

//冒泡排序:重要！
//引用qsort函数（东西，元素，大小，比较函数）
//int cmp_int(const void* pa, const void* pb)
//{
//	return *(int*)pb - *(int*)pa;
//}
//void bubble_reverse(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			qsort(arr, sz, sizeof(arr[0]), cmp_int);
//		}
//	}
//
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble_reverse(arr,sz);
//	for (i = 0; i < 10; i++ )
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	getchar();
//	int i = 0;
//	char ch = 0;
//	for (i = 0; i < n; i++)
//	{
//		ch = getchar();
//		switch (ch)
//		{
//		case '\n':
//		case ' ':
//			printf("空格");
//			break;
//		case '0':
//			printf("0");
//			break;
//		case 'a':
//			break;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    int c = 0;
//    int d = 0;
//    int e = 0;
//    int f = 0;
//    int g = 0;
//    scanf("%d:%d %d", &a, &b, &c);
//    d = c / 60;
//    e = c % 60;
//    f = b + e;
//    g = a + d;
//    if (b + e > 59)
//    {
//        g = g + (f / 60);
//        f = f % 60;  
//    }
//    printf("%02d:%02d", g % 24, f);
//    return 0;
//}

//int cmp_int(const void* pa, const void* pb)
//{
//	return *(int*)pa - *(int*)pb;
//}
//struct Stu
//{
//	char arr[20];
//	int age;
//};
//int cmp(const void* pa, const void* pb)
//{
//	return ((struct Stu*)pa)->age - ((struct Stu*)pb)->age;
//}
//void swap(char* put1, char* put2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *put1;
//		*put1 = *put2;
//		*put2 = tmp;
//		put1++;
//		put2++;
//	}
//}
//void bubble_sort(void* base, size_t sz, size_t width, int(*cmp)(const void*, const void*))
//{
//	size_t i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (cmp((char*)base + j * width, (char*) base + (j + 1) * width) > 0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//int main()
//{
//	struct Stu s1[3] = { {"zhangsan,20"},{"daiyiwen,18"},{"daixisdan,20"} };
//	int sz1 = sizeof(s1) / sizeof(s1[0]);
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(s1, sz1, sizeof(s1[0]), cmp);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int cmp_int(const void* pa, const void* pb)
//{
//	return *(int*)pa - *(int*)pb;
//}
//void swap(char* put1, char* put2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = 0;
//		tmp = *put1;
//		*put1 = *put2;
//		*put2 = tmp;
//		put1++;
//		put2++;
//	}
//}
//void bubble_sort(void* base, size_t sz, size_t width, int(*arr)(const void*, const void*))
//{
//	size_t i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		size_t j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr((char*)base + j * width, (char*)base + (j + 1) * width) < 0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	for(i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
////}

//int game(int a)
//{
//	if (a == 1)
//		return 1;
//	else if (a == 2)
//		return 1;
//	else
//		return game(a - 1) + game(a - 2);
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
//	int a = 0;
//	scanf("%d", &a);
//	int b = 1;
//	int c = 1;
//	int ret = 0;
//	if (a == 1 || a == 2)
//	{
//		ret = 1;
//	}
//	while (a>2)
//	{
//		ret = b + c;
//		b = c;
//		c = ret;
//		a--;
//	}
//	printf("%d", ret);
//	return 0;
//}

//void game(char* arr)
//{
//	int sz = strlen(arr);
//	char tmp = 0;
//	tmp = *(arr);
//	*(arr)=*(arr+sz-1);
//	*(arr + sz - 1) = '\0';
//	if (strlen(arr + 1) > 1)
//		game(arr + 1);
//	*(arr + sz - 1) = tmp;
//
//}
//int main()
//{
//	char arr[10] = "abcdfg";
//	game(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int game(int a)
//{
//	if (a > 1)
//	{
//		return game(a - 1) * a;
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = game(a);
//	printf("%d", ret);
//	return 0;
//}

//void str(const char* arr1, char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	while (*(arr1) != '\0')
//	{
//		*(arr2) = *(arr1);
//		arr2++;
//		arr1++;
//	}
//	if (*(arr1) == '\0')
//	{
//		*(arr2) = *(arr1);
//	}
//}
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[20] = "**********";
//	str(arr1, arr2);
//	printf("%s", arr2);
//    return 0;
//}

//int main()
//{
//	int a = 5; int b = 3;
//	printf("%d %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d", a, b);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int i = 0;
//	int num = 0;
//	scanf("%d", &a);
//	for (i = 0; i < 32; i++)
//	{
//		if ((a >> i) & 1)
//			num++;
//	}
//	printf("%d", num);
//	return 0;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int b = 0;
//	while (a = a & (a - 1))
//	{
//		b++;
//	}
//	printf("%d", b+1);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	for (i = 32; i > 0; i-=2)
//	{
//		printf("%d", (a >> i) & 1);
//	}
//	printf("\n");
//	for (i = 31; i >= 0; i-=2)
//	{
//		printf("%d", (a >> i) & 1);
//	}
//	return 0;
//}

//void game(int* pa, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(pa + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	game(arr, sz);
//	return 0;
//}

//void reverse(char arr[], int sz)
//{
//    char tmp = arr[0];
//    arr[0] = arr[sz - 1];
//    arr[sz - 1] = '\0';
//    if (strlen(arr + 1) > 1)
//        reverse(arr + 1, sz - 2);
//    arr[sz - 1] = tmp;
//
//}
//int main()
//{
//    char arr[10000] = { 0 };
//    int i = 0;
//    while (scanf("%c",&arr[i]) != EOF && arr[i]!='\n')
//    {
//        i++;
//    }
//    reverse(arr, i);
//    printf("%s", arr);
//    return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - i ; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j <2*i-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 1; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (n - i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int number(int a,int i)
//{
//	int j = 0;
//	int sum = 0;
//	for (j = 0; j <= i; j++)
//	{
//		sum = sum + a*(int)pow(10, j);
//	}
//	return sum;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int i = 0;
//	int Sn = 0;
//	for (i = 0; i < 5; i++)
//	{
//		Sn = Sn + number(a, i);
//	}
//	printf("%d", Sn);
//	return 0;
//}

//int jia(int x, int y)
//{
//	return x + y;
//}
//int jian(int x, int y)
//{
//	return x - y;
//}
//int cheng(int x, int y)
//{
//	return x * y;
//}
//int chu(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int(*p[5])(int,int) = {NULL,jia,jian,cheng,chu};
//	int num1 = 0;
//	int num2 = 0;
//	char ch = 0;
//	scanf("%d %c %d", &num1, &ch, &num2);
//	int input = 0;
//	if (ch == '+')
//	{
//		input = 1;
//	}
//	else if (ch == '-')
//	{
//		input = 2;
//	}
//	else if (ch == '*')
//	{
//		input = 3;
//	}
//	else
//	{
//		input = 4;
//	}
//	int ret = p[input](num1, num2);
//	printf("%d %c %d = %d", num1, ch, num2, ret);
//	return 0;
//}

//int find(int arr[],int sz)
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz ; i++)
//	{
//		ret ^=  arr[i];
//	}
//	return ret;
//}
//int main()
//{
//	int arr[11] = { 1,1,2,2,3,3,4,4,5,5,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = find(arr,sz);
//	printf("%d", ret);
//	return 0;
//}

void find(int arr[],int len, int* num1, int* num2)
{
	int tmp = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		tmp ^= arr[i];
	}
	int wei = 0;
	for (i = 0; i < 32; i++)
	{
		if (((tmp >> i) & 1 )== 1)
		{
			wei = i;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if (((arr[i] >> wei) & 1) == 0)
		{
			*num1 ^= arr[i];
		}
		else
		{
			*num2 ^= arr[i];
		}
	}
}
int main()
{
	/*int arr[100] = { 0 };
	int i = 0;
	while ((arr[i] = getchar()) != '\n')
	{
		i++;
	}
	arr[i] = 0;*/
	int arr[10] = { 1,1,2,2,3,3,4,6,5,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int a = 0;
	int b = 0;
	find(arr,len, &a, &b);
	printf("%d %d", a, b);
	return 0;
}