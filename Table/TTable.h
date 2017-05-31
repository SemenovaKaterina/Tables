#pragma once
#include "Polynom.h"
#include "Monom.h"
class TTable
{
public:
	int Count; //����� �������
	int Efficiency; //�������������

public:
	TTable() { Count = 0; } //�����������
	//�������������� ������
	int GetCount() { return Count; } //�������� ���������� �������
	int GetEfficiency() { return Efficiency; } //�������� �������������
	void SetCount(int C) { Count = C; } //���������� ���������� �������
	void SetEfficiensy(int E) { Efficiency = E; } //���������� �������������
	bool IsEmpty() { return Count == 0; } //�����?
	virtual bool IsFull(); //���������?
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
};

