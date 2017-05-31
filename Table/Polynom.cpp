#include "Polynom.h"

void Polynom::Pol(TKey s)
{
	int a = 0; //a � ������� ������ S
	while ((s[a] != '_') && (s[a] != ' '))
	{
		Key += s[a];
		a++;
	}

	pValue = 0;
	char per = ' '; //x y z
	int n = 0; //�����������
	int e = 0; //�������
	int k = 1; //����������
	s += "+";
	for (unsigned int i = a; i < s.length(); i++)
	{
		char c = s[i];
		if (c == ' ') //������������ �������
			continue;
		if (IsNumber(c))
		{
			if (per == ' ') //���� ��� �����������
				n = n * 10 + (int)c - 48;
			else //���� ��� �������
				e += ((int)c - 48)*Exp(per);
		}
		else if (IsVariable(c)) //���� ��� � ��� y ��� z
			per = c;
		else if (IsOperation(c)) //���� ��� �������� + ��� -
		{
			if (n)
			{
				n = n * k;
				k = 1;
				Insert(n, e);
			}
			if (c == '-') //������������� �����������
				k = -1;
			n = 0; e = 0; per = ' ';
		}
	}
}

void Polynom::Insert(int n, int e) //���������� ������, ����� ������� ��� �������
{
	Monom* i = pValue;
	if (i == 0) //���� ������� ����
		pValue = new Monom(n, e);
	else
	{
		while (i)
		{//�� ����� ��������
			if (i->exp == e) //���� ������� �������
			{
				i->num += n;
				break; //����� ������ ������ ��������� �� ����
			}
			if (i->exp < e) //���� ������� ���������� ������
			{
				InsertBefore(n, e, i); //�� ��������� ����� ���
				break;
			}
			if (i->next == 0) //��������� � �����
			{
				i->next = new Monom(n, e);
				break;
			}
			i = i->next;
		}
	}
}

void Polynom::InsertBefore(int n, int e, Monom* x) //�������� ����� ��
{
	if (x == pValue) //�������� ����� ������
	{
		Monom* i = pValue;
		pValue = new Monom(n, e);
		pValue->next = i;
	}
	else
	{
		Monom*i;
		for (i = pValue; i->next != x; i = i->next); //���� ����� ����� �������� �������
		i->next = new Monom(n, e);
		i->next->next = x;
	}
}

void Polynom::SetKey(TKey k) //���������� ����
{
	Key = k;
}

TKey Polynom::GetKey() //�������� ����
{
	return Key;
}

void Polynom::SetValuePtr(Monom* p) //���������� ���������
{
	pValue = p;
}

Monom* Polynom::GetValuePtr() //�������� ���������
{
	return pValue;
}

Monom* Polynom::GetCopy() //���������� �����
{
	Monom* res = new Monom(*pValue);
	return res;
}

bool Polynom::IsNumber(char c) //��� �����
{
	int chis = (int)c;
	if ((chis > 47) && (chis < 58)) //0...9
		return true;
	return false;
}

bool Polynom::IsVariable(char c) //��� x y z
{
	int chis = (int)c;
	if ((chis > 119) && (chis < 123)) //x, y, z
		return true;
	return false;
}

int Polynom::Exp(char c) //x-100 y-10 z-1 �������
{
	if (c == 'x')
		return 100; //x
	if (c == 'y')
		return 10; //y
	return 1; //z
}

bool Polynom::IsOperation(char c) //��� + ��� - ����� ��������
{
	if (c == '+' || c == '-')
		return true;
	return false;
}

string Polynom::ToString() //�������������� �������� � ������
{
	string res = "";
	char b[16];
	Monom* i = pValue;
	if (i == 0) //���� ������� ����
		return "0";
	while (i)
	{
		sprintf_s(b, "%d", i->num);
		res += b;
		res += "x";
		sprintf_s(b, "%d", i->exp / 100);
		res += b;
		res += "y";
		sprintf_s(b, "%d", i->exp / 10 % 10);
		res += b;
		res += "z";
		sprintf_s(b, "%d", i->exp % 10);
		res += b;
		if (i->next)
		{
			if (i->next->num > 0)
				res += "+";
		}
		i = i->next;
	}
	return res;
}