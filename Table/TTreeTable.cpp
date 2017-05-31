#include "TTreeTable.h"

void TTreeTable::DeleteTreeTab(TTreeNode*pNode) //������� ������
{
	if (pNode)
	{//���� ������� ���� ����������
		if (pNode->left) //���� ���� ����� �����
			DeleteTreeTab(pNode->left);
		if (pNode->right) //���� ���� ������ �����
			DeleteTreeTab(pNode->right);
		delete pNode; //������� ����
	}
}

TKey TTreeTable::GetKey() //�������� �������� �����
{
	return pCurrent->Key;
}

Monom* TTreeTable::GetValuePtr() //�������� ���������
{
	return pCurrent->pValue;
}

Monom* TTreeTable::FindRecord(TKey k) //����� ������
{
	TTreeNode* res = Search(pRoot, k); //���� ������� ������, �� ������ ���������
	if (res)
		return res->pValue;
	return NULL;
}

TTreeNode* TTreeTable::Search(TTreeNode* r, TKey k) //����������� �����
{
	if (r == 0 || k == r->Key) //���� �� ����� ���� � ������� ��� ����� �������� �����, ������� ������
		return r;
	if (k < r->Key) //���� � ������
		return Search(r->left, k); //����� �����
	else
		return Search(r->right, k); //������ �����
}

void TTreeTable::InsRecord(TKey k, Monom* p) //�������� ������
{
	pRoot = Insertion(pRoot, k, p);
	SetCount(GetCount() + 1);
}

TTreeNode* TTreeTable::Insertion(TTreeNode* r, TKey k, Monom* p) //����������� �������
{
	if (r == 0)
		return new TTreeNode(k, p); 
	else if (k < r->Key)
		r->left = Insertion(r->left, k, p);
	else if (k > r->Key)
		r->right = Insertion(r->right, k, p);
	return r;
}

void TTreeTable::DelRecord(TKey k) //�������
{
	pRoot = Delete(pRoot, k);
}

TTreeNode* TTreeTable::Delete(TTreeNode* r, TKey k) //�������� ����� ��������
{
	if (r == 0)
		return r;
	if (k < r->Key) //���� � ����� ���������
		r->left = Delete(r->left, k);
	else if (k > r->Key) //���� � ������ ���������
		r->right = Delete(r->right, k);
	else if (r->left && r->right)
	{//�������� ������ � ����� �����, �.�. ����� �������, �� ���� �������
		r->Key = min(r->right)->Key;
		r->pValue = min(r->right)->pValue;
		SetCount(GetCount() - 1);
		r->right = Delete(r->right, r->right->Key);
	}
	else
	{//�������� ������ ������ ��� ����� �����
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
	} //���������� ������ � �������� ���������
	return r;
}

TTreeNode* TTreeTable::min(TTreeNode* r) //����� ������������ ��������
{
	if (r->left == 0)
		return r;
	return min(r->left);
}

bool TTreeTable::Reset() //���������� �� ������ �������
{
	if (pRoot) //���� ������
	{
		pCurrent = pRoot;
		CurPos = 0;
		return true;
	}
	return false;
}

bool TTreeTable::IsEnded() //������� �����������?
{
	return (pCurrent->left == 0) && (pCurrent->right == 0); 
}

bool TTreeTable::GoNext() //������� �� ��������� �������
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
	pCurrent = res; //��������� ���� � ������� �������
	if (pCurrent) //������� ������� ��� ������ �����������
	{
		CurPos++;
		return true;
	}
	return false;
}

string TTreeTable::ToString() //������������� ������� � ������
{
	return pCurrent->ToString();
}