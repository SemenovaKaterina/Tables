#pragma once
#include "TArrayTable.h"
class TScanTable :public TArrayTable
{
public:
	TScanTable(int Size = MaxSize) :TArrayTable(Size) {}; //Конструктор
	//Основные операции
	Monom* FindRecord(TKey k) override; //Найти запись
	void InsRecord(TKey k, Monom*p) override; //Вставить
	void DelRecord(TKey k) override; //Удалить
};

