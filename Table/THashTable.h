#pragma once
#include "TTable.h"
class THashTable :public TTable
{
public:
	THashTable(int Size) :TTable(){}
	virtual unsigned long HashFunc(TKey key);
	//������
	virtual string ToString() = 0; //������������� ������� � ������
	virtual TKey GetKey() = 0; //�������� �������� �����
	virtual Monom* GetValuePtr() = 0; //�������� ���������
	//�������� ��������
	virtual Monom* FindRecord(TKey k) = 0; //����� ������
	virtual void InsRecord(TKey k, Monom*p) = 0; //��������
	virtual void DelRecord(TKey k) = 0; //�������
	//���������
	virtual bool Reset() = 0; //���������� �� ������ �������
	virtual bool IsEnded() = 0; //������� �����������?
	virtual bool GoNext() = 0; //������� �� ���������

	friend class TArrayHash;
};

