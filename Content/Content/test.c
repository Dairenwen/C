#define _CRT_SECURE_NO_WARNINGS 1
#include"content.h"
void menu()
{
	printf("*************************************\n");
	printf("********  1. add     2. del    ******\n");
	printf("********  3. search  4. modify ******\n");
	printf("********  5. show    6. sort   ******\n");
	printf("************   0. exit   ************\n");
	printf("*************************************\n");
}
enum choose
{
	EXIT,
	add,
	del,
	search,
	modify,
	show,
	sort
};
int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	initcontact(&con);
	do
	{
		menu();
		printf("your choose:\n");
		scanf("%d", &input);
		switch (input)
		{
		    case add:
				Addcontact(&con);
				break;
			case del:
				Delcontact(&con);
				break;
			case search:
				Searchcontact(&con);
				break;
			case modify:
				Modifycontact(&con);
				break;
			case show:
				Showcontact(&con);
				break;
			case sort:
				break;
			case EXIT:
				Destroycontact(&con);
				break;
			default:
				break;
		}
	} while (input);
	return 0;
}