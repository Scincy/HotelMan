#pragma once
#include "ServiceList.h"
/// ����Ʈ �ʱ�ȭ
void Initialize(ServiceList* array) {
    array->count = 0;

    array->items = (RoomService*)malloc(sizeof(RoomService) * array->count + 1);
}
void Initialize(ServiceList* array, int capa) {
    array->count = 0;

    array->items = (RoomService*)malloc(sizeof(RoomService) * array->count + 1);
}

/// Ư�� ���񽺰� ����Ʈ�� �̹� �����ϰ� �ִ��� �˻��մϴ�.
ArraySearchResult IsServiceExist(ServiceList* array, char* compareName)
{
    ArraySearchResult result;
    Initialize(&result);

    if (array->items == NULL || array->count <= 0)
        return result;

    for (int i = 0; i < array->count; i++)
    {
        if (strcmp(array->items[i].serviceName, compareName) == 0)
        {
            AddFoundIndex(&result, i);
            return result;
        }
    }
    return result;
}

/// ���ο� �� ���� �߰�
void AddRoomService(ServiceList* array, RoomService item)
{
    //���񽺰� �迭�� �̹� �ִ��� �˻�, ������ ���� ���� �߰�
    ArraySearchResult checking;
    Initialize(&checking);
    checking = IsServiceExist(array, item.serviceName);
    if (checking.result)//�߰� ��� ���񽺰� �̹� ��ϵ� ���񽺶��
    {
        //���� ���� Ƚ���� �ø��� ����
        array[checking.foundIndex].count += item.privideCount;
        return;
    }
    array->items = (RoomService*)realloc(array->items, sizeof(RoomService) * (array->count + 1));
    array->items[array->count++] = item;
}
/// �� ���� ����
bool RemoveRoomService(ServiceList* array, char* name, int count)
{
    ArraySearchResult checking = IsServiceExist(array, name);
    if (!checking.result) return false;

    // �뼭�񽺸� ������ �� ���Ŵ���� �� ���� �� ���� ���񽺰� ��û�� ������?
    if (array->items[checking.foundIndex].privideCount - count <= 0)
    {
        //���� ����, ���� ���� ������� ����
        for (int i = checking.foundIndex; i < array->count; i++)//���� ��� ��ġ�� ���� ��Ҹ� ������ ��ܼ� ����
        {
            array->items[i] = array->items[i + 1];
        }
        array->count--;
    }
    else
    {
        //���� �� ���̱�
        array->items[checking.foundIndex].privideCount -= count;
    }
}