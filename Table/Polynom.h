#pragma once
#include "Monom.h"
#include <string>
#include <iostream>
using namespace std;
typedef string TKey;
class Polynom
{
	Monom* pValue; //Указатель на первый моном
	TKey Key; //Ключ записи
public:
	Polynom(TKey k = 0, Monom* pData = 0){ Key = k; pValue = pData; } //Конструктор
	void Pol(TKey s); //Конструктор, преобразование строки в полином
	void SetKey(TKey k); //Установить ключ
	TKey GetKey(); //Получить ключ
	void SetValuePtr(Monom* p); //Установить указатель
	Monom* GetValuePtr(); //Получить указатель
	virtual Monom* GetCopy(); //Изготовить копию

	string ToString(); //Преобразование полинома в строку
	void Insert(int n, int e); //Добавление монома, поиск позиции для вставки
	void InsertBefore(int n, int e, Monom*x); //Добавить моном до

	bool IsNumber(char c); //Это число?
	bool IsVariable(char c); //Это переменная?
	bool IsOperation(char c); //Это операция?
	int Exp(char c); //Степень переменной

	//friend...
	friend class TArrayTable;
	friend class TScanTable;
	friend class TSortTable;
	friend class TTreeNode;
	friend class TTreeTable;
	friend class TArrayHash;
	friend class THashTable;
};

