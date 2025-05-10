#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
//struct Stu
//{
//	char name[10];
//	int age;
//	char sex[10];
//};
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
//void bubble_sort(void* base, size_t sz, size_t width, int(*p)(const void*, const void*))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (p((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		int b = 0;
//		for (b = 1; b <= 5; b++)
//		{
//			int c = 0;
//			for (c = 1; c <= 5; c++)
//			{
//				int d = 0;
//				for (d = 1; d <= 5; d++)
//				{
//					int e = 0;
//					for (e = 1; e <= 5; e++)
//					{
//						if ((b == 2) + (a == 3) == 1 && (b == 2) + (e == 4) == 1 && (c == 1) + (d == 2) == 1 && (c == 5) + (d == 3) == 1 && (e == 4) + (a == 1) == 1 && a*b*c*d*e==120)
//						{
//							printf("%d %d %d %d %d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[100][100] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j <=i; j++)
//		{
//			if (j == 0)
//			{
//				arr[i][j] = 1;
//			}
//			else if (i == j)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n - i - 1; j++)
//		{
//			printf("  ");
//		}
//		for (j = 0; j <=i; j++)
//		{
//			printf("%-2d  ",arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9} };
//	int i = 0;
//	int number = 0;
//	scanf("%d", &number);
//	int a = 0;
//	int b = 4;
//	while (b>=0&&a<=4)
//	{
//		if (arr[a][b] > number)
//		{
//			b--;
//		}
//		else if (arr[a][b] < number)
//		{
//			a++;
//		}
//		else
//		{
//			printf("x = %d, y = %d\n", a + 1, b + 1);
//			b--;
//			a++;
//		}
//	}
//	return 0;
//}

//void game( char* p1, char* p2)
//{
//	assert(p1);
//	assert(p2);
//	while (p1 <= p2)
//	{
//		char tmp = 0;
//		tmp = *(p1);
//		*(p1) = *(p2);
//		*(p2) = tmp;
//		p1++;
//		p2--;
//	}
//}
//void reverse(char arr[],int k)
//{
//	int len = strlen(arr);
//	game(arr, arr + k - 1);
//	game(arr+k,arr+len-1);
//	game(arr, arr + len - 1);
//}
//int main()
//{
//	char arr[100] = "abcdefg";
//	int a = 0;
//	int len = strlen(arr);
//	scanf("%d", &a);
//	//reverse(arr,a);
//	int i = 0;
//	for (i = 0; i < a; i++)
//	{
//		char tmp = arr[0];
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//	printf("%s", arr);
//	return 0;
//}

//int is_return(char arr1[], char arr2[])
//{
//	if (strlen(arr1) != strlen(arr2))
//		return 0;
//	int i = 0;
//	int a = strlen(arr1);
//	for (i = 0; i <a; i++)
//	{
//		reverse(arr1, 1);
//		if (strcmp(arr2, arr1) == 0)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[10] = "cdefab";
//	int ret = is_return(arr1,arr2);
//	return 0;
//}

//void game(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		if (arr[left] % 2 != 0)
//		{
//			left++;
//		}
//		if (arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (arr[left] % 2 == 0 && arr[right] % 2 != 0)
//		{
//			int tmp = 0;
//			tmp = arr[right];
//			arr[right] = arr[left];
//			arr[left] = tmp;
//			left++;
//			right--;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = {2,4,6,8,10,1,3,5,7,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	game(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int my_strlen1(char* pa)
//{
//	if (*pa != '\0')
//	{
//		return my_strlen1(pa + 1) + 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int my_strlen2(const char* pb)
//{
//	const char* pi = pb;
//	while (*pb)
//	{
//		pb++;
//	}
//	return pb - pi;
//}
//int my_strlen3(char* pc)
//{
//	int num = 0;
//	while (*pc)
//	{
//		pc++;
//		num++;
//	}
//	return num;
//}
//int main()
//{
//	char arr[10] = "abcdef";
//	printf("%d\n", my_strlen1(arr));
//	printf("%d\n", my_strlen2(arr));
//	printf("%d\n", my_strlen3(arr));
//	return 0;
//}

//void my_strcpy(char* p1, const char* p2)
//{
//	while (*p1++ = *p2++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[10] = {0 };
//	char arr2[20] = "abcdefg";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//void my_strcat(char* arr1, char* arr2)
//{
//
//}
//int main()
//{
//	char arr1[20] = "abcd";
//	char arr2[20] = "efgh";
//	strcat(arr1, arr2);
//	printf("%s", arr1);
//	my_strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}
//
//char* my_strstr(char* str1, char* str2)
//{
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	const char* s1 = 0;
//	const char* s2 = 0;
//	const char* cp = str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[10] = "abcdefg";
//	char arr2[10] = "de";
//	char* ret = my_strstr(arr1,arr2);
//	if (ret == NULL)
//	{
//		printf("No\n");
//	}
//	else
//	{
//		printf("%s", ret);
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
//void bubble_sort(void* base, size_t sz, size_t width, int(*p)(const void*, const void*))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (p((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//void swap(char* p1, char* p2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = 0;
//		tmp = *p1;
//		*p1 = *p2;
//		*p2 = tmp;
//		p1++;
//		p2++;
//	}
//}
//int cmp_int(const void* pa, const void* pb)
//{
//	return *(int*)pa - *(int*)pb;
//}
//void bubble_sort(void* base, size_t sz, size_t width, int(*p)(const void*, const void*))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (p((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
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
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//char* my_strstr(char* str1, char* str2)
//{
//	assert(str1 && str2);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	const char* s1 = 0;
//	const char* s2 = 0;
//	const char* cp = str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[10] = "abbccdef";
//	char arr2[10] = "bcc";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf(" ");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}

//int my_strlen(char* p)
//{
//	if (*p)
//	{
//		return my_strlen(p + 1) + 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char arr[10] = { 0 };
//	gets(arr);
//	int ret= my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}

//void my_strcpy(char* str1, char* str2)
//{
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[10] = "abcdef";
//	char arr2[10] = "******";
//	my_strcpy(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//int my_strcmp(char* arr1, char* arr2)
//{
//	while (*arr1!='\0' || *arr2!='\0')
//	{
//		if (*arr1 == *arr2)
//		{
//			arr1++;
//			arr2++;
//		}
//		else if (*arr1 > *arr2)
//		{
//			return 1;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[20] = "abcdefg";
//	char arr2[20] = "abcdefg";
//	int ret = my_strcmp(arr1, arr2);
//	printf("%d", ret);
//	return 0;
//}

//void my_strcat(char* str1, char* str2)
//{
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//}
//int main()
//{
//	char arr1[300] = "abcdefg";
//	char arr2[10] = "hijkl";
//	my_strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//int main()
//{
//	char arr1[30] = { 0 };
//	gets(arr1);
//	char arr2[10] = " ";
//	char arr3[30] = { 0 };
//	strcpy(arr3, arr1);
//	char* ret = NULL;
//	for (ret = strtok(arr3, arr2); ret != NULL; ret = strtok(NULL, arr2))
//	{
//		printf("%d ",strlen(ret));
//	}
//	return 0;
//}

//int main()
//{
//	char arr[20] = { 0 };
//	gets(arr);
//	char ch;
//	/*int i = 0;
//	while ((arr[i] = getchar()) != '\n')
//	{
//		i++;
//	}
//	arr[i] = '\0';*/
//	int len = strlen(arr);
//	int j = 0;
//	for (j = 0; j < len; j++)
//	{
//		printf("%c", toupper(arr[j]));
//	}
//	return 0;
//}

//void* my_memcpy(void* str1, const void* str2, size_t width)
//{
//	void* ret = str1;
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		*(char*)str1 = *(char*)str2;
//		str1=(char*)str1+1;
//		str2=(char*)str2+1;
//	}
//	return ret;
//}
//void* my_memmove(void* str1, void* str2, size_t width)
//{
//	char* ret = str1;
//	assert(str1 && str2);
//	if (str1 < str2)
//	{
//		my_memcpy(str1,str2, width);
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < width; i++)
//		{
//			*((char*)str1 + width - 1 - i) = *((char*)str2 + width - 1 - i);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr1[20] = { 0 };
//	int i = 0;
//	/*my_memcpy(arr, arr+2, n);
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//	my_memmove(arr, arr+2, 20);
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", arr[i]);
//	}
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

//void find(int arr[], int len, int* num1, int* num2)
//{
//	int tmp = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		tmp ^= arr[i];
//	}
//	int wei = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((tmp >> i) & 1) == 1)
//		{
//			wei = i;
//			break;
//		}
//	}
//	for (i = 0; i < len; i++)
//	{
//		if (((arr[i] >> wei) & 1) == 0)
//		{
//			*num1 ^= arr[i];
//		}
//		else
//		{
//			*num2 ^= arr[i];
//		}
//	}
//}
//int main()
//{
//	/*int arr[100] = { 0 };
//	int i = 0;
//	while ((arr[i] = getchar()) != '\n')
//	{
//		i++;
//	}
//	arr[i] = 0;*/
//	int arr[10] = { 1,1,2,2,3,3,4,6,5,5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int a = 0;
//	int b = 0;
//	find(arr, len, &a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

//void* my_memcpy(void* str1, const void* str2, size_t n)
//{
//    void* ret = str1;
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		*(char*)str1 = *(char*)str2;
//		str1 = (char*)str1 + 1;
//		str2 = (char*)str2 + 1;
//	}
//	return ret;
//}
//void* my_memmove(void* str1, void* str2, size_t n)
//{
//	void* ret = str1;
//	if (str1 < str2)
//	{
//		my_memcpy(str1, str2, n);
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < n; i++)
//		{
//			*((char*)str1 + n - 1 - i) = *((char*)str2 + n - 1 - i);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//	int n; int i;
//	scanf("%d", &n);
//	//my_memcpy(arr2, arr1, n);
//	my_memmove(arr1+2, arr1, n);
//	for (i = 0; i < (n / 4); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}

//int main()
//{
//    char arr[100] = { 0 };
//    char arr1[1] = " ";
//    gets(arr);
//    //arr[i] = '\0';
//    char* ret = NULL;
//    for (ret = strtok(arr, arr1); ret != NULL; ret = strtok(NULL, arr1))
//    {
//        printf("%zd ", strlen(ret));
//    }
//    return 0;
//}

//char* my_strstr(const char* str1, char* str2)
//{
//	assert(str1 && str2);
//	if (*str2 == '\0')
//	{
//		return (char*)str1;
//	}
//	const char* s1 = 0;
//	const char* s2 = 0;
//	const char* cp = str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = str2;
//		while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr[20] = "abcddefgh";
//	char arr1[10] = "dd";
//	char* ret = my_strstr(arr, arr1);
//	printf("%s",ret);
//	return 0;
//}

//int cmp_int(const void* s1, const void* s2)
//{
//	return *(int*)s1 - *(int*)s2;
//}
//void swap(char* put1, char* put2, int width)
//{
//	assert(put1 && put2);
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *(put1);
//		*(put1) = *(put2);
//		*(put2) = tmp;
//		put1++;
//		put2++;
//	}
//}
//void bubble_sort(void* base, size_t sz, size_t width, int(*p)(const void*, const void*))
//{
//	assert(base);
//	int i = 0;
//	for (i = 0; i < sz - 1; i ++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (p((char*)base + width * j, (char*)base + (j + 1) * width) < 0)
//			{
//				swap((char*)base + width * j, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[20] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
//	for(i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int tmp = 0;
//    double sum = 0.0;
//    for (i = 1; i <= n; i++)
//    {
//        int j = 0;
//        tmp = 1;
//        for (j = 1; j <= i; j++)
//        {
//            tmp = tmp * j;
//        }
//        sum = sum + 1.0 / tmp;
//    }
//    printf("%.8f", sum + 1);
//    return 0;
//}


