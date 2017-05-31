#include "TSortTable.h"

TSortTable::TSortTable(TScanTable&x) //����������� �� ��������������� �������
{
	pRecs = (Polynom*)operator new(sizeof(Polynom)*x.TabSize);
	for (int i = 0; i < x.TabSize; i++)
		new(&pRecs[i])Polynom(x.pRecs[i].Key, x.pRecs[i].pValue);
	TabSize = x.TabSize; //���������� ������ ������� �������
	CurPos = x.CurPos;
	SetCount(x.GetCount());
	InsertSort(); //�������������
}

TSortTable& TSortTable::operator=(TScanTable&x)
{//������������
	pRecs = (Polynom*)operator new(sizeof(Polynom)*x.TabSize);
	for (int i = 0; i < x.TabSize; i++)
		new(&pRecs[i])Polynom(x.pRecs[i].Key, x.pRecs[i].pValue);
	TabSize = x.TabSize;
	CurPos = x.CurPos;
	SetCount(x.GetCount());
	InsertSort();
	return *this;
}

void TSortTable::InsertSort()
{//����� ���������
	Polynom temp = Polynom("", 0); // ��������� ���������� ��� �������� �������� �������� ������������ �������
	int	item; // ������ ����������� ��������
	for (int counter = 1; counter < TabSize; counter++)
	{
		temp = pRecs[counter]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = counter - 1; // ���������� ������ ����������� �������� �������
		while (item >= 0 && pRecs[item].Key > temp.Key) // ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		{
			pRecs[item + 1] = pRecs[item]; // ������������ ��������� �������
			pRecs[item] = temp;
			item--;
		}
	}
}