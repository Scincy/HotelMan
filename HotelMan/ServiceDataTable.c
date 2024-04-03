#include "ServiceDataTable.h"
int GetServiceDefaultPrice(ServiceType type)
{
	switch (type)
	{
	case dinner: return 40000;
	case lunch: return 30000;
	case healthcare: return 20000;
	case snack: return 8000;
	case clean: return 0;
	case extraPerson: return 50000;
	default:
		return 0;
	}
}

const char* GetServiceNameStr(ServiceType type)
{
	switch (type)
	{
	case dinner: return "����Ļ�";
	case lunch: return "���ɽĻ�";
	case healthcare: return "�ｺ�̿�";
	case snack: return "�ٰ��÷���";
	case clean: return "û��";
	case extraPerson: return "�߰��ο�";
	default:
		return "";
	}
}