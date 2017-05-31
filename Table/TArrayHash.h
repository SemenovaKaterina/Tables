#pragma once
#include "THashTable.h"
#define TabMaxSize 25
#define TabHashStep 5
class TArrayHash :public THashTable
{
	Polynom* pRecs; //��������� �� ������
	int TabSize; //������
	int HashStep; //��� ���������� �������������
	int FreePos; //������ ����. ������, ������������ ��� ������
	int CurPos; //������ ������ ��� ���������� ������
	Polynom* pMark; //������ ��� ������������� ����� � ���������� ��������
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }

public:
	TArrayHash(int Size = TabMaxSize, int Step = TabHashStep) :THashTable(Size)
	{
		pRecs = (Polynom*)operator new(sizeof(Polynom)*Size);
		for (int i = 0; i < Size; i++)
			new(&pRecs[i])Polynom("", 0);
		TabSize = Size;
		HashStep = Step;
	}

	//������
	string ToString() override; //������������� ������� � ������
	TKey GetKey() override; //�������� �������� �����
	Monom* GetValuePtr() override; //�������� ��������� �� �������
	//�������� ��������
	Monom* FindRecord(TKey k) override; //����� ������
	void InsRecord(TKey k, Monom* p) override; //��������
	void DelRecord(TKey k) override; //�������
	//���������
	bool Reset() override; //���������� �� ������ �������
	bool IsEnded() override; //������� �����������?
	bool GoNext() override; //������� �� ���������
};

