#pragma once

bool initBillingList();//初始化账单列表

bool addBillinglist(Billing bililing);//添加账单到账单列表

void ModifyBillingList(Billing* _billing);//修改账单列表中的账单

const char* ToStringStatus(int n);//将账单状态转换为字符串

void releaseBillingList();//释放账单列表内存

