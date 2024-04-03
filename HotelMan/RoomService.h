typedef struct
{
	char* serviceName;
	int servicePrice;
	int privideCount;
}RoomService;

void Initialize(RoomService* service, char* name, int price, int provideCount);

RoomService IntToServiceStruct(int serviceID);
