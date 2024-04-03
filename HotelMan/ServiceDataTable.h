#pragma once
#define MAX_SERVICE_COUNT 5
typedef enum
{
	dinner = 0,
	lunch = 1,
	healthcare = 2,
	snack = 3,
	clean = 4,
	extraPerson = 5
}ServiceType;

int GetServiceDefaultPrice(ServiceType type);

const char* GetServiceNameStr(ServiceType type);