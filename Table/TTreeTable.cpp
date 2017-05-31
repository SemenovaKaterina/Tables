#include "TTreeTable.h"

void TTreeTable::DeleteTreeTab(TTreeNode*pNode) //Удалить дерево
{
	if (pNode)
	{//Если текущий узел существует
		if (pNode->left) //Если есть левая ветвь
			DeleteTreeTab(pNode->left);
		if (pNode->right) //Если есть правая ветвь
			DeleteTreeTab(pNode->right);
		delete pNode; //Удаляем лист
	}
}

TKey TTreeTable::GetKey() //Получить значение ключа
{
	return pCurrent->Key;
}

Monom* TTreeTable::GetValuePtr() //Получить указатель
{
	return pCurrent->pValue;
}

Monom* TTreeTable::FindRecord(TKey k) //Найти запись
{
	TTreeNode* res = Search(pRoot, k); //Если нашлась запись, то вернет указатель
	if (res)
		return res->pValue;
	return NULL;
}

TTreeNode* TTreeTable::Search(TTreeNode* r, TKey k) //Рекурсивный поиск
{
	if (r == 0 || k == r->Key) //Если из листа ушли в пустоту или равен текущему ключу, который искали
		return r;
	if (k < r->Key) //Ищем в ветвях
		return Search(r->left, k); //Левая ветвь
	else
		return Search(r->right, k); //Правая ветвь
}

void TTreeTable::InsRecord(TKey k, Monom* p) //Вставить запись
{
	pRoot = Insertion(pRoot, k, p);
	SetCount(GetCount() + 1);
}

TTreeNode* TTreeTable::Insertion(TTreeNode* r, TKey k, Monom* p) //Рекурсивная вставка
{
	if (r == 0)
		return new TTreeNode(k, p); 
	else if (k < r->Key)
		r->left = Insertion(r->left, k, p);
	else if (k > r->Key)
		r->right = Insertion(r->right, k, p);
	return r;
}

void TTreeTable::DelRecord(TKey k) //Удалить
{
	pRoot = Delete(pRoot, k);
}

TTreeNode* TTreeTable::Delete(TTreeNode* r, TKey k) //Удаление через рекурсию
{
	if (r == 0)
		return r;
	if (k < r->Key) //Ищем в левом поддереве
		r->left = Delete(r->left, k);
	else if (k > r->Key) //Ищем в правом поддереве
		r->right = Delete(r->right, k);
	else if (r->left && r->right)
	{//Содержит правую и левую ветвь, т.е. ключи совпали, то надо удалить
		r->Key = min(r->right)->Key;
		r->pValue = min(r->right)->pValue;
		SetCount(GetCount() - 1);
		r->right = Delete(r->right, r->right->Key);
	}
	else
	{//Содержит только правую или левую ветвь
		if (r->left)
		{
			r = r->left;
			SetCount(GetCount() - 1);
		}
		else
		{
			r = r->right;
			SetCount(GetCount() - 1);
		}
	} //Возвращаем дерево с удалённым элементом
	return r;
}

TTreeNode* TTreeTable::min(TTreeNode* r) //Поиск минимального элемента
{
	if (r->left == 0)
		return r;
	return min(r->left);
}

bool TTreeTable::Reset() //Установить на первую позицию
{
	if (pRoot) //Если корень
	{
		pCurrent = pRoot;
		CurPos = 0;
		return true;
	}
	return false;
}

bool TTreeTable::IsEnded() //Таблица завершилась?
{
	return (pCurrent->left == 0) && (pCurrent->right == 0); 
}

bool TTreeTable::GoNext() //Переход на следующую позицию
{
	TTreeNode* i = pRoot;
	TTreeNode* res = 0;
	while (i)
	{
		if (i->Key > pCurrent->Key)
		{
			res = i;
			i = i->left;
		}
		else
			i = i->right;
	}
	pCurrent = res; //Запомнили ключ в текущей вершине
	if (pCurrent) //Удалось перейти или дерево закончилось
	{
		CurPos++;
		return true;
	}
	return false;
}

string TTreeTable::ToString() //Преобразовать полином в строку
{
	return pCurrent->ToString();
}