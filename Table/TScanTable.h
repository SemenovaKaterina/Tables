#pragma once
#include "TArrayTable.h"
class TScanTable :public TArrayTable
{
public:
	TScanTable(int Size = MaxSize) :TArrayTable(Size) {}; //�����������
	//�������� ��������
	Monom* FindRecord(TKey k) override; //����� ������
	void InsRecord(TKey k, Monom*p) override; //��������
	void DelRecord(TKey k) override; //�������
};

