#pragma once
#include "TTable.h"
#include "TTreeNode.h"
class TTreeTable :public TTable
{
	TTreeNode* pRoot; //Указатель на корень
	TTreeNode* pFind; //Результат FindRecord() (поиска по дереву)
	TTreeNode* pCurrent; //Указатель на текущую запись
	int CurPos; //Номер текущей записи
	void DeleteTreeTab(TTreeNode* pNode); //Удалить
public:
	TTreeTable() :TTable() //Конструктор
	{
		pRoot = pFind = pCurrent = 0; CurPos = 0;
	}
	~TTreeTable() { DeleteTreeTab(pRoot); } //Деструктор
	//Доступ
	string ToString() override; //Преобразовать полином в строку
	TKey GetKey() override; //Получить значение ключа
	Monom* GetValuePtr() override; //Получить указатель
	//Основные операции
	Monom* FindRecord(TKey k) override; //Найти запись
	void InsRecord(TKey k, Monom* p) override; //Вставить
	void DelRecord(TKey k) override; //Удалить
	//Навигация
	bool Reset() override; //Установить на первую позицию
	bool IsEnded() override; //Таблица завершилась?
	bool GoNext() override; //Переход на следующую
	//Свои функции
	TTreeNode* Search(TTreeNode* r, TKey k); //Рекурсивный поиск
	TTreeNode* Insertion(TTreeNode* r, TKey k, Monom* p); //Рекурсивная вставка
	TTreeNode* Delete(TTreeNode* r, TKey k); //Рекурсивное удаление
	TTreeNode* min(TTreeNode* r); //Минимальный элемент
};