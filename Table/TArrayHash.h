#pragma once
#include "THashTable.h"
#define TabMaxSize 25
#define TabHashStep 5
class TArrayHash :public THashTable
{
	Polynom* pRecs; //Указатель на массив
	int TabSize; //Размер
	int HashStep; //Шаг вторичного перемешивания
	int FreePos; //Первая своб. строка, обнаруженная при поиске
	int CurPos; //Строка памяти при завершении поиска
	Polynom* pMark; //Маркер для инициализации строк с удаленными записями
	int GetNextPos(int pos) { return (pos + HashStep) % TabSize; }

public:
	TArrayHash(int Size = TabMaxSize, int Step = TabHashStep) :THashTable(Size)
	{
		pRecs = (Polynom*)operator new(sizeof(Polynom)*Size);
		for (int i = 0; i < Size; i++)
			new(&pRecs[i])Polynom("", 0);
		TabSize = Size;
		HashStep = Step;
	}

	//Доступ
	string ToString() override; //Преобразовать полином в строку
	TKey GetKey() override; //Получить значение ключа
	Monom* GetValuePtr() override; //Получить указатель на текущий
	//Основные операции
	Monom* FindRecord(TKey k) override; //Найти запись
	void InsRecord(TKey k, Monom* p) override; //Вставить
	void DelRecord(TKey k) override; //Удалить
	//Навигация
	bool Reset() override; //Установить на первую позицию
	bool IsEnded() override; //Таблица завершилась?
	bool GoNext() override; //Переход на следующую
};

