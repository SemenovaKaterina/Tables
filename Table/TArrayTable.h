#pragma once
#include "TTable.h"
#define MaxSize 25
enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };
class TArrayTable :public TTable
{
	Polynom* pRecs; //Указатель на массив
	int TabSize; //Размер
	int CurPos; //Текущая запись
public:
	TArrayTable(int Size = MaxSize); //Конструктор
	//Информационные методы
	int GetTabSize() { return TabSize; } //Кол-во записей
	//Доступ
	string ToString() override; //Преобразовать полином в строку
	TKey GetKey() override; //Получить значение ключа
	Monom* GetValuePtr() override; //Получить указатель на текущий
	virtual Monom* GetValuePtr(TDataPos mode); //Получить указатель на определённый
	//Основные операции
	virtual Monom* FindRecord(TKey k) = 0; //Найти запись
	virtual void InsRecord(TKey k, Monom* p) = 0; //Вставить
	virtual void DelRecord(TKey k) = 0; //Удалить
	//Навигация
	bool Reset() override; //Установить на первую позицию
	bool IsEnded() override; //Таблица завершилась?
	bool GoNext() override; //Переход на следующую
	virtual bool SetCurrentPos(int pos); //Установить текущую запись
	int GetCurrentPos(); //Получить номер текущей записи
	//friend...
	friend class TScanTable;
	friend class TSortTable;
};

