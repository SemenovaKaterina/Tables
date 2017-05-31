#include "TSortTable.h"
#include "TTreeTable.h"
#include "TArrayHash.h"
#include "THashTable.h"
#include <fstream>
#include <iostream>
#include <string>
#include <conio.h>
#include "stdio.h"
#include "locale.h"
using namespace std;

void Inspection(TTable*);
void Print(TTable*);

int main()
{
	setlocale(LC_CTYPE, "Rus");
	string s1;
	TScanTable* Scan = new TScanTable(30);
	TArrayHash* Hash = new TArrayHash();
	TTable* Tree = new TTreeTable();
	ifstream File("Input.txt");
	while (!File.eof())
	{
		getline(File, s1, '\n');
		Polynom* n = new Polynom("", 0);
		n->Pol(s1);
		Scan->InsRecord(n->GetKey(), n->GetValuePtr());
		Hash->InsRecord(n->GetKey(), n->GetValuePtr());
		Tree->InsRecord(n->GetKey(), n->GetValuePtr());
	}
	File.close();

	TSortTable* Sort;
	Sort = new TSortTable(*Scan);

	int Mode;
	while (true)
	{
		cout << "�������� �������: 1-Scan, 2-Sort, 3-Hash, 4-Tree, 5-All" << endl;
		cin >> Mode;
		switch (Mode)
		{
		case 1:
		{
				  Inspection(Scan);
				  break;
		}
		case 2:
		{
				  Inspection(Sort);
				  Sort->InsertSort();
				  break;
		}
		case 3:
		{
				  Inspection(Hash);
				  break;
		}
		case 4:
		{
				  Inspection(Tree);
				  break;
		}
		case 5:
		{
				  cout << "Scan" << endl;
				  Print(Scan);
				  cout << endl << "Sort" << endl;
				  Print(Sort);
				  cout << endl << "Hash" << endl;
				  Print(Hash);
				  cout << endl << "Tree" << endl;
				  Print(Tree);
				  break;
		}
		}
		cout << "������� 0 ��� ������ ��� 1 ��� �����������: ";
		cin >> Mode;
		if (Mode == 0)
			break;
	}
	return 0;
}

void Inspection(TTable* A)
{
	string s1;
	int Mode;
	Print(A);
	cout << "��� �� ������ �������: 1-��������, 2-�����, 3-�������" << endl;
	cin >> Mode;
	switch (Mode)
	{
	case 1:
	{
			  cout << "������� ������� � ������� ����_�������: ";
			  cin >> s1;
			  Polynom* n = new Polynom("", 0);
			  n->Pol(s1);
			  A->InsRecord(n->GetKey(), n->GetValuePtr());
			  break;
	}
	case 2:
	{
			  cout << "������� ����: ";
			  cin >> s1;
			  if (A->FindRecord(s1))//����� ������
				  cout << "�����" << endl;
			  else
				  cout << "�� �����" << endl;
			  break;
	}
	case 3:
	{
			  cout << "������� ����: ";
			  cin >> s1;
			  A->DelRecord(s1);//�������� ������
			  break;
	}
	}
}

void Print(TTable*A)
{
	string s1;
	A->Reset();//�������� ������� ������
	do
	{
		s1 = A->GetKey();
		if (s1 != "")//��������� �����
			cout << "���� " << A->GetKey() << " ������� " << A->ToString() << endl;
	} while (A->GoNext());//�������� �������� � ����������
}