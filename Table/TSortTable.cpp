#include "TSortTable.h"

TSortTable::TSortTable(TScanTable&x) //Конструктор из просматриваемой таблицы
{
	pRecs = (Polynom*)operator new(sizeof(Polynom)*x.TabSize);
	for (int i = 0; i < x.TabSize; i++)
		new(&pRecs[i])Polynom(x.pRecs[i].Key, x.pRecs[i].pValue);
	TabSize = x.TabSize; //Установить размер текущей позиции
	CurPos = x.CurPos;
	SetCount(x.GetCount());
	InsertSort(); //Отсортировать
}

TSortTable& TSortTable::operator=(TScanTable&x)
{//Присваивание
	pRecs = (Polynom*)operator new(sizeof(Polynom)*x.TabSize);
	for (int i = 0; i < x.TabSize; i++)
		new(&pRecs[i])Polynom(x.pRecs[i].Key, x.pRecs[i].pValue);
	TabSize = x.TabSize;
	CurPos = x.CurPos;
	SetCount(x.GetCount());
	InsertSort();
	return *this;
}

void TSortTable::InsertSort()
{//Метод Вставками
	Polynom temp = Polynom("", 0); // временная переменная для хранения значения элемента сортируемого массива
	int	item; // индекс предыдущего элемента
	for (int counter = 1; counter < TabSize; counter++)
	{
		temp = pRecs[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 && pRecs[item].Key > temp.Key) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			pRecs[item + 1] = pRecs[item]; // перестановка элементов массива
			pRecs[item] = temp;
			item--;
		}
	}
}