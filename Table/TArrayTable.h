#pragma once
#include "TTable.h"
#define MaxSize 25
enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };
class TArrayTable :public TTable
{
	Polynom* pRecs; //��������� �� ������
	int TabSize; //������
	int CurPos; //������� ������
public:
	TArrayTable(int Size = MaxSize); //�����������
	//�������������� ������
	int GetTabSize() { return TabSize; } //���-�� �������
	//������
	string ToString() override; //������������� ������� � ������
	TKey GetKey() override; //�������� �������� �����
	Monom* GetValuePtr() override; //�������� ��������� �� �������
	virtual Monom* GetValuePtr(TDataPos mode); //�������� ��������� �� �����������
	//�������� ��������
	virtual Monom* FindRecord(TKey k) = 0; //����� ������
	virtual void InsRecord(TKey k, Monom* p) = 0; //��������
	virtual void DelRecord(TKey k) = 0; //�������
	//���������
	bool Reset() override; //���������� �� ������ �������
	bool IsEnded() override; //������� �����������?
	bool GoNext() override; //������� �� ���������
	virtual bool SetCurrentPos(int pos); //���������� ������� ������
	int GetCurrentPos(); //�������� ����� ������� ������
	//friend...
	friend class TScanTable;
	friend class TSortTable;
};

