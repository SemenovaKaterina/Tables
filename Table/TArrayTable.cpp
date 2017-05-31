#include "TArrayTable.h"

TArrayTable::TArrayTable(int Size) //�����������
{
	TabSize = Size;
	pRecs = (Polynom*)operator new(sizeof(Polynom)*Size);
	for (int i = 0; i < Size; i++)
		new(&pRecs[i])Polynom("", 0);
	CurPos = 0;
}

string TArrayTable::ToString() //������������� ������� � ������
{
	return pRecs[CurPos].ToString();
}

TKey TArrayTable::GetKey() //�������� �������� �����
{
	return pRecs[CurPos].Key;
}

Monom* TArrayTable::GetValuePtr() //�������� ��������� �� ������ ������ �������
{
	return pRecs[CurPos].pValue;
}

Monom* TArrayTable::GetValuePtr(TDataPos mode) //�������� ��������� �� ����������� �����
{
	switch (mode)
	{
	case FIRST_POS: return pRecs[0].pValue;
	case CURRENT_POS: return pRecs[CurPos].pValue;
	case LAST_POS: return pRecs[TabSize - 1].pValue;
	}
	return NULL;
}

bool TArrayTable::Reset() //���������� �� ������ �������
{
	if (TabSize < 1)
		return false;
	CurPos = 0;
	return true;
}

bool TArrayTable::IsEnded() //������� �����������?
{
	return CurPos == (TabSize - 1);
}

bool TArrayTable::GoNext() //������� �� ���������
{
	if (IsEnded())
		return false;
	CurPos++;
	return true;
}

bool TArrayTable::SetCurrentPos(int pos) //���������� ������� ������
{
	if ((pos > -1) && (pos < TabSize))
	{
		CurPos = pos;
		return true;
	}
	return false;
}

int TArrayTable::GetCurrentPos() //�������� ����� ������� ������
{
	return CurPos;
}