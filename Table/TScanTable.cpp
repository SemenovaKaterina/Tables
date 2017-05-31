#include "TScanTable.h"

Monom* TScanTable::FindRecord(TKey k) //����� ������
{
	for (int i = 0; i < TabSize; i++)
	{//��� �� �������
		if (pRecs[i].Key == k) //����� �������
			return pRecs[i].pValue; //���������� ��������� �� 1-� �����
	}
	return NULL; //�� ����� �������
}

void TScanTable::InsRecord(TKey k, Monom*p) //�������� ������ � �������
{
	for (int i = 0; i < TabSize; i++)
	{//��� �� �������
		if (pRecs[i].Key == k)
			return; //������ �������� ��� ������ � ����������� ������� (���� ��������)
		if (pRecs[i].Key == "")
		{//��������� �����
			pRecs[i].Key = k;
			pRecs[i].pValue = p;
			SetCount(GetCount() + 1);
			return;
		}
	} //������ ��������, ���� ������ ��������
	cout << "��� �����";
}

void TScanTable::DelRecord(TKey k) //�������
{
	for (int i = 0; i < TabSize; i++)
	{//��� �� �������
		if (pRecs[i].Key == k)
		{//����� �������
			int j = i; //��������� �����
			for (j = i; j < TabSize - 1; j++)
				pRecs[j] = pRecs[j + 1]; //�������� ��������
			pRecs[j].Key = ""; pRecs[j].pValue = 0; //����������� �����
			SetCount(GetCount() - 1);
			return;
		}
	}//������ �������, ���� ������� �� ������
	cout << "��� ������ ��������";
}