#pragma once
//����ȫ�ֱ������߳������ļ�

enum Function
{
	Quit,//�˳�
	Add,//��ӿ�
	Searchcard,//��ѯ��
	Logon,//�ϻ�
	Logoff,//�»�
	Recharge,//��ֵ
	Refund,//�˿�
	Searchcount,//��ѯͳ��
	Cancel//ע��
};//������ʾѡ��

enum Status
{
	UnLog,//δ�ϻ�
	IsLog,//�����ϻ�
	Delete,//��ע��
	Invalid//ʧЧ
};

enum CountStatus
{
	clear,//δ����
	unclear//�ѽ���
};
enum Del
{
	UnDel,//δɾ��
	Del//ɾ��
};