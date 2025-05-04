//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int hannuota(int x)//汉诺塔问题
//{
//	if (x == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return hannuota(x - 1) * 2 + 1;
//	}
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("汉诺塔的个数>: \n");
//	scanf("%d", &a);
//	b = hannuota(a);
//	printf("%d", b);
//	return 0;
//}
//int taijie(int x)
//{
//	int a = 1;
//	int b = 2;
//	int c = 0;
//	if (x == 1)
//		return 1;
//	if (x == 2)
//		return 2;
//	while (x > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		x--;
//	}
//	return c;
//}
//int main()
//{
//	int i = 0;
//	int b = 0;
//	printf("台阶级数>: \n");
//	scanf("%d", &i);
//	b = taijie(i);
//	printf("共有%d种方法\n", b);
//	return 0;
//}
