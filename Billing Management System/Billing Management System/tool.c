#define _CRT_SECURE_NO_WARNINGS 1
#include"global.h"
#include"model.h"
#include"menu.h"
#include"card_file.h"
#include"card_service.h"

//��Ź��߻��߸����ļ�

//��ʱ���ת��Ϊ�ַ�������ʽΪ��-��-�� ʱ:��:��
//tm���ͣ��ṹ��洢ʱ�䣬����ͨ��localtime��time_t����ת��Ϊtm����
//����ʹ��strftime������tm����ת��Ϊ�ַ���
void timeToString(time_t t, char* pBuf)
{
	struct tm* pTimeInfo;
	pTimeInfo = localtime(&t);
	strftime(pBuf, 20, "%Y-%m-%d %H:%M:%S", pTimeInfo);
}