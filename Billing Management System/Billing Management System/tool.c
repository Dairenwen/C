#define _CRT_SECURE_NO_WARNINGS 1
#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"card_service.h"

//存放工具或者辅助文件

//将时间戳转换为字符串，格式为年-月-日 时:分:秒
//tm类型：结构体存储时间，可以通过localtime将time_t类型转换为tm类型
//可以使用strftime函数将tm类型转换为字符串
void timeToString(time_t t, char* pBuf)
{
	struct tm* pTimeInfo;
	pTimeInfo = localtime(&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M:%S", pTimeInfo);
}