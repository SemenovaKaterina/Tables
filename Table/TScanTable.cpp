#include "TScanTable.h"

Monom* TScanTable::FindRecord(TKey k) //Найти запись
{
	for (int i = 0; i < TabSize; i++)
	{//Идём по массиву
		if (pRecs[i].Key == k) //Нашли элемент
			return pRecs[i].pValue; //Возвращаем указатель на 1-й моном
	}
	return NULL; //Не нашли элемент
}

void TScanTable::InsRecord(TKey k, Monom*p) //Вставить запись в таблицу
{
	for (int i = 0; i < TabSize; i++)
	{//Идём по массиву
		if (pRecs[i].Key == k)
			return; //Нельзя вставить две записи с одинаковыми ключами (ключ уникален)
		if (pRecs[i].Key == "")
		{//Свободное место
			pRecs[i].Key = k;
			pRecs[i].pValue = p;
			SetCount(GetCount() + 1);
			return;
		}
	} //Нельзя вставить, если массив заполнен
	cout << "Нет места";
}

void TScanTable::DelRecord(TKey k) //Удалить
{
	for (int i = 0; i < TabSize; i++)
	{//Идём по массиву
		if (pRecs[i].Key == k)
		{//Нашли элемент
			int j = i; //Запомнили номер
			for (j = i; j < TabSize - 1; j++)
				pRecs[j] = pRecs[j + 1]; //Сдвигаем элементы
			pRecs[j].Key = ""; pRecs[j].pValue = 0; //Освобождаем место
			SetCount(GetCount() - 1);
			return;
		}
	}//Нельзя удалить, если элемент не найден
	cout << "Нет такого элемента";
}