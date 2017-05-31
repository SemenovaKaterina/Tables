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
		cout << "Выберите таблицу: 1-Scan, 2-Sort, 3-Hash, 4-Tree, 5-All" << endl;
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
		cout << "Введите 0 для выхода или 1 для продолжения: ";
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
	cout << "Что вы хотите сделать: 1-Вставить, 2-Найти, 3-Удалить" << endl;
	cin >> Mode;
	switch (Mode)
	{
	case 1:
	{
			  cout << "Введите полином в формате Ключ_Полином: ";
			  cin >> s1;
			  Polynom* n = new Polynom("", 0);
			  n->Pol(s1);
			  A->InsRecord(n->GetKey(), n->GetValuePtr());
			  break;
	}
	case 2:
	{
			  cout << "Введите ключ: ";
			  cin >> s1;
			  if (A->FindRecord(s1))//Поиск записи
				  cout << "Нашли" << endl;
			  else
				  cout << "Не нашли" << endl;
			  break;
	}
	case 3:
	{
			  cout << "Введите ключ: ";
			  cin >> s1;
			  A->DelRecord(s1);//Удаление записи
			  break;
	}
	}
}

void Print(TTable*A)
{
	string s1;
	A->Reset();//Контроль текущей записи
	do
	{
		s1 = A->GetKey();
		if (s1 != "")//Получение ключа
			cout << "Ключ " << A->GetKey() << " Полином " << A->ToString() << endl;
	} while (A->GoNext());//Проверка перехода и завершения
}