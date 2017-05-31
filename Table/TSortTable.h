#pragma once
#include "TScanTable.h"
class TSortTable :public TScanTable
{
public:
	TSortTable(int Size = MaxSize) :TScanTable(Size) {}; //Конструктор
	TSortTable(TScanTable&); //Конструктор из просматриваемой таблицы
	void InsertSort(); //Метод Вставками
	TSortTable& operator=(TScanTable&); //Присваивание
};