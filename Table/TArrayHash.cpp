#include "TArrayHash.h"

string TArrayHash::ToString() //������������� ������� � ������
{
	return pRecs[CurPos].ToString();
}

TKey TArrayHash::GetKey() //�������� �������� �����
{
	if ((CurPos < 0) || (CurPos >= TabSize))
		return "";
	return pRecs[CurPos].GetKey();
}

Monom* TArrayHash::GetValuePtr() //�������� ��������� �� �������
{
	if ((CurPos < 0) || (CurPos >= TabSize))
		return 0;
	return pRecs[CurPos].GetValuePtr();
}

Monom* TArrayHash::FindRecord(TKey k) //����� ������
{
	Monom* pValue = 0;
	FreePos = -1;
	Efficiency = 0;
	CurPos = HashFunc(k) % TabSize;
	for (int i = 0; i < TabSize; i++)
	{
		Efficiency++;
		if (pRecs[CurPos].GetKey() == "") 
			break;
		else if (&pRecs[CurPos] == pMark)
		{
			if (FreePos == -1)
				FreePos = CurPos;
		}
		else if (pRecs[CurPos].GetKey() == k)
		{
			pValue = pRecs[CurPos].GetValuePtr();
			break;
		}
		CurPos = GetNextPos(CurPos);
	}
	return pValue;
}

void TArrayHash::InsRecord(TKey k, Monom* p) //��������
{
	FreePos = -1;
	CurPos = HashFunc(k) % TabSize;
	for (int i = 0; i < TabSize; i++)
	{
		if (pRecs[CurPos].GetKey() == "") //���� ��������
		{
			if (FreePos == -1) 
			{
				pRecs[CurPos] = Polynom(k, p); //� ������� ������ �������� �������
				SetCount(GetCount() + 1);
				break;
			}
			else
			{
				pRecs[FreePos] = Polynom(k, p); //���� FreePos, �� ����������
				SetCount(GetCount() + 1);
				break;
			}
		}
		else if (&pRecs[CurPos] == pMark) //��������� pMark
		{
			if (FreePos == -1)
				FreePos = CurPos; //���������� � FreePos
		}
		else if (pRecs[CurPos].GetKey() == k) //���� ������
		{
			pRecs[CurPos] = Polynom(k, p); //��������������
			break;
		}
		CurPos = GetNextPos(CurPos); //����������� ���. ������ �� ����. �������
	}
}

void TArrayHash::DelRecord(TKey k) //�������
{
	Monom* p = FindRecord(k); //����� ������
	if (p) //���� �����
	{
		SetCount(GetCount() - 1);
		pRecs[CurPos].SetKey("");
		pRecs[CurPos].SetValuePtr(new Monom(0, 0));
	}
}

bool TArrayHash::IsEnded() //������� �����������?
{
	return CurPos >= TabSize; //true - ����. ���������, false - ���� ��������� �������
}

bool TArrayHash::Reset() //���������� �� ������ �������
{
	CurPos = 0;
	return true;
}

bool TArrayHash::GoNext() //������� �� ��������� ������� � �������
{
	if (!IsEnded())
	{
		while (++CurPos<TabSize)
		{
			if (pRecs[CurPos].GetKey() != "")
				break;
		}
	}
	return !IsEnded();
}