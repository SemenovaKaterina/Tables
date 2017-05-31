#pragma once
#include "TTable.h"
class TTreeNode :public Polynom
{
	TTreeNode* left, *right; //Указатели на ветви
public:
	TTreeNode(TKey k = 0, Monom* p = 0, TTreeNode* pl = 0, TTreeNode* pr = 0)
		:Polynom(k, p) {
		left = pl; right = pr;
	} //Конструктор
	TTreeNode* GetLeft() { return left; } //Указатель на левую ветвь
	TTreeNode* GetRight() { return right; } //Указатель на правую ветвь
	//friend...
	friend class TTreeTable;
};