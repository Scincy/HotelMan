#pragma once
#include <stdbool.h>
typedef struct {
    bool intialized;
    /// <summary>
    /// �˻� ����� ������ �������� ����
    /// </summary>
    bool result;
    /// <summary>
    /// ����ؼ� ã�� ��ġ
    /// </summary>
    int foundIndex;
}ArraySearchResult;

void Initialize(ArraySearchResult* item);

void AddFoundIndex(ArraySearchResult* item, int newFoundIndex);