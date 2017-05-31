#pragma once
#include "TTable.h"
class THashTable :public TTable
{
public:
	THashTable(int Size) :TTable(){}
	virtual unsigned long HashFunc(TKey key);
	//Доступ
	virtual string ToString() = 0; //Преобразовать полином в строку
	virtual TKey GetKey() = 0; //Получить значение ключа
	virtual Monom* GetValuePtr() = 0; //Получить указатель
	//Основные операции
	virtual Monom* FindRecord(TKey k) = 0; //Найти запись
	virtual void InsRecord(TKey k, Monom*p) = 0; //Вставить
	virtual void DelRecord(TKey k) = 0; //Удалить
	//Навигация
	virtual bool Reset() = 0; //Установить на первую позицию
	virtual bool IsEnded() = 0; //Таблица завершилась?
	virtual bool GoNext() = 0; //Переход на следующую

	friend class TArrayHash;
};

