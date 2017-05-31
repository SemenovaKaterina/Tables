#pragma once
#include "Monom.h"
#include <string>
#include <iostream>
using namespace std;
typedef string TKey;
class Polynom
{
	Monom* pValue; //��������� �� ������ �����
	TKey Key; //���� ������
public:
	Polynom(TKey k = 0, Monom* pData = 0){ Key = k; pValue = pData; } //�����������
	void Pol(TKey s); //�����������, �������������� ������ � �������
	void SetKey(TKey k); //���������� ����
	TKey GetKey(); //�������� ����
	void SetValuePtr(Monom* p); //���������� ���������
	Monom* GetValuePtr(); //�������� ���������
	virtual Monom* GetCopy(); //���������� �����

	string ToString(); //�������������� �������� � ������
	void Insert(int n, int e); //���������� ������, ����� ������� ��� �������
	void InsertBefore(int n, int e, Monom*x); //�������� ����� ��

	bool IsNumber(char c); //��� �����?
	bool IsVariable(char c); //��� ����������?
	bool IsOperation(char c); //��� ��������?
	int Exp(char c); //������� ����������

	//friend...
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TTreeNode;
	friend class TTreeTable;
	friend class TArrayHash;
	friend class THashTable;
};

