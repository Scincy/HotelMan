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
	case dinner: return "저녁식사";
	case lunch: return "점심식사";
	case healthcare: return "헬스이용";
	case snack: return "다과플래터";
	case clean: return "청소";
	case extraPerson: return "추가인원";
	default:
		return "";
	}
}