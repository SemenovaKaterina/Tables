#pragma once
class Monom
{
	int num; //�����������
	int exp; //������� xyz
	Monom* next; //��������� �� ��������� �����
public:
	Monom(int n = 0, int e = 0){ num = n; exp = e; } //�����������
	friend class Polynom; //������ ������� �������� protected ������
};

