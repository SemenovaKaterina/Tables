#pragma once
#include "Polynom.h"
#include "Monom.h"
class TTable
{
public:
	int Count; //Число записей
	int Efficiency; //Эффективность

public:
	TTable() { Count = 0; } //Конструктор
	//Информационные методы
	int GetCount() { return Count; } //Получить количество записей
	int GetEfficiency() { return Efficiency; } //Получить эффективность
	void SetCount(int C) { Count = C; } //Установить количество записей
	void SetEfficiensy(int E) { Efficiency = E; } //Установить эффективность
	bool IsEmpty() { return Count == 0; } //Пуста?
	virtual bool IsFull(); //Заполнена?
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
};

