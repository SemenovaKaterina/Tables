#include "TArrayHash.h"

string TArrayHash::ToString() //Преобразовать полином в строку
{
	return pRecs[CurPos].ToString();
}

TKey TArrayHash::GetKey() //Получить значение ключа
{
	if ((CurPos < 0) || (CurPos >= TabSize))
		return "";
	return pRecs[CurPos].GetKey();
}

Monom* TArrayHash::GetValuePtr() //Получить указатель на текущий
{
	if ((CurPos < 0) || (CurPos >= TabSize))
		return 0;
	return pRecs[CurPos].GetValuePtr();
}

Monom* TArrayHash::FindRecord(TKey k) //Найти запись
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

void TArrayHash::InsRecord(TKey k, Monom* p) //Вставить
{
	FreePos = -1;
	CurPos = HashFunc(k) % TabSize;
	for (int i = 0; i < TabSize; i++)
	{
		if (pRecs[CurPos].GetKey() == "") //Если свободна
		{
			if (FreePos == -1) 
			{
				pRecs[CurPos] = Polynom(k, p); //В текущую запись помещаем полином
				SetCount(GetCount() + 1);
				break;
			}
			else
			{
				pRecs[FreePos] = Polynom(k, p); //Если FreePos, то записываем
				SetCount(GetCount() + 1);
				break;
			}
		}
		else if (&pRecs[CurPos] == pMark) //Проверяем pMark
		{
			if (FreePos == -1)
				FreePos = CurPos; //Записываем в FreePos
		}
		else if (pRecs[CurPos].GetKey() == k) //Если занята
		{
			pRecs[CurPos] = Polynom(k, p); //Перезаписываем
			break;
		}
		CurPos = GetNextPos(CurPos); //Передвинуть тек. запись на след. позицию
	}
}

void TArrayHash::DelRecord(TKey k) //Удалить
{
	Monom* p = FindRecord(k); //Поиск записи
	if (p) //Если нашли
	{
		SetCount(GetCount() - 1);
		pRecs[CurPos].SetKey("");
		pRecs[CurPos].SetValuePtr(new Monom(0, 0));
	}
}

bool TArrayHash::IsEnded() //Таблица завершилась?
{
	return CurPos >= TabSize; //true - табл. заполнена, false - есть свободные позиции
}

bool TArrayHash::Reset() //Установить на первую позицию
{
	CurPos = 0;
	return true;
}

bool TArrayHash::GoNext() //Переход на следующую сткочку в таблице
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