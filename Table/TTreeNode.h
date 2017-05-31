#pragma once
#include "TTable.h"
class TTreeNode :public Polynom
{
	TTreeNode* left, *right; //��������� �� �����
public:
	TTreeNode(TKey k = 0, Monom* p = 0, TTreeNode* pl = 0, TTreeNode* pr = 0)
		:Polynom(k, p) {
		left = pl; right = pr;
	} //�����������
	TTreeNode* GetLeft() { return left; } //��������� �� ����� �����
	TTreeNode* GetRight() { return right; } //��������� �� ������ �����
	//friend...
	friend class TTreeTable;
};