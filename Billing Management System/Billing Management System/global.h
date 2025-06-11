#pragma once
//定义全局变量或者常量的文件

enum Function
{
	Quit,//退出
	Add,//添加卡
	Searchcard,//查询卡
	Logon,//上机
	Logoff,//下机
	Recharge,//充值
	Refund,//退款
	Searchcount,//查询统计
	Cancel//注销
};//用来表示选项

enum Status
{
	UnLog,//未上机
	IsLog,//正在上机
	Delete,//已注销
	Invalid//失效
};

enum CountStatus
{
	clear,//未结算
	unclear//已结算
};
enum Del
{
	UnDel,//未删除
	Del//删除
};