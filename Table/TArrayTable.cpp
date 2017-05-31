#include "TArrayTable.h"

TArrayTable::TArrayTable(int Size) //Конструктор
{
	TabSize = Size;
	pRecs = (Polynom*)operator new(sizeof(Polynom)*Size);
	for (int i = 0; i < Size; i++)
		new(&pRecs[i])Polynom("", 0);
	CurPos = 0;
}

string TArrayTable::ToString() //Преобразовать полином в строку
{
	return pRecs[CurPos].ToString();
}

TKey TArrayTable::GetKey() //Получить значение ключа
{
	return pRecs[CurPos].Key;
}

Monom* TArrayTable::GetValuePtr() //Получить указатель на начало списка мономов
{
	return pRecs[CurPos].pValue;
}

Monom* TArrayTable::GetValuePtr(TDataPos mode) //Получить указатель на определённый моном
{
	switch (mode)
	{
	case FIRST_POS: return pRecs[0].pValue;
	case CURRENT_POS: return pRecs[CurPos].pValue;
	case LAST_POS: return pRecs[TabSize - 1].pValue;
	}
	return NULL;
}

bool TArrayTable::Reset() //Установить на первую позицию
{
	if (TabSize < 1)
		return false;
	CurPos = 0;
	return true;
}

bool TArrayTable::IsEnded() //Таблица завершилась?
{
	return CurPos == (TabSize - 1);
}

bool TArrayTable::GoNext() //Переход на следующую
{
	if (IsEnded())
		return false;
	CurPos++;
	return true;
}

bool TArrayTable::SetCurrentPos(int pos) //Установить текущую запись
{
	if ((pos > -1) && (pos < TabSize))
	{
		CurPos = pos;
		return true;
	}
	return false;
}

int TArrayTable::GetCurrentPos() //Получить номер текущей записи
{
	return CurPos;
}