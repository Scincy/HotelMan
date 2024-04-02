#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "RoomService.h"
#include "ArraySearchResult.h"
typedef struct {
    RoomService* items;
    /// <summary>
    /// ���� ����Ʈ�� �����ϴ� ������ ����
    /// </summary>
    int count;
} ServiceList;


/// ����Ʈ �ʱ�ȭ
void Initialize(ServiceList* array);
void Initialize(ServiceList* array, int capa);

/// Ư�� ���񽺰� ����Ʈ�� �̹� �����ϰ� �ִ��� �˻��մϴ�.
ArraySearchResult IsServiceExist(ServiceList* array, char* compareName);

/// ���ο� �� ���� �߰�
void AddRoomService(ServiceList* array, RoomService item);
/// �� ���� ����
bool RemoveRoomService(ServiceList* array, char* name, int count);

