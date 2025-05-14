#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("*************************************\n");
	printf("********     CONTACT PLUS     *******\n");
	printf("********  1. add     2. del    ******\n");
	printf("********  3. search  4. modify ******\n");
	printf("********  5. show    0. exit   ******\n");
	printf("*************************************\n");
	printf("*************************************\n");
}
enum INPUT
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
Contact con;
int main()
{
	int input = 0;
	Initcontact(&con);
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case EXIT:
				//Savecontact1(&con);
				Savecontact2(&con);
				Destroycontact(&con);
				break;
			case ADD:
				Addcontact(&con);
				break;
			case DEL:
				Delcontact(&con);
				break;
			case SEARCH:
				Searchcontact(&con);
				break;
			case MODIFY:
				Modifycontact(&con);
				break;
			case SHOW:
				Showcontact(&con);
				break;
		}
	} while (input);
	return 0;
}