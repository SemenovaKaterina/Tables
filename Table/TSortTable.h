#pragma once
#include "TScanTable.h"
class TSortTable :public TScanTable
{
public:
	TSortTable(int Size = MaxSize) :TScanTable(Size) {}; //�����������
	TSortTable(TScanTable&); //����������� �� ��������������� �������
	void InsertSort(); //����� ���������
	TSortTable& operator=(TScanTable&); //������������
};