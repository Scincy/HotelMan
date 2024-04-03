#include "RoomService.h"
void Initialize(RoomService* service, char* name, int price, int provideCount = 1)
{
	service->serviceName = name;
	service->servicePrice = price;
	service->privideCount = provideCount;
	return;
}
RoomService IntToServiceStruct(int serviceID)
{

}