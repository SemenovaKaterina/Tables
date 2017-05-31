#pragma once
#include "TTable.h"
#include "TTreeNode.h"
class TTreeTable :public TTable
{
	TTreeNode* pRoot; //��������� �� ������
	TTreeNode* pFind; //��������� FindRecord() (������ �� ������)
	TTreeNode* pCurrent; //��������� �� ������� ������
	int CurPos; //����� ������� ������
	void DeleteTreeTab(TTreeNode* pNode); //�������
public:
	TTreeTable() :TTable() //�����������
	{
		pRoot = pFind = pCurrent = 0; CurPos = 0;
	}
	~TTreeTable() { DeleteTreeTab(pRoot); } //����������
	//������
	string ToString() override; //������������� ������� � ������
	TKey GetKey() override; //�������� �������� �����
	Monom* GetValuePtr() override; //�������� ���������
	//�������� ��������
	Monom* FindRecord(TKey k) override; //����� ������
	void InsRecord(TKey k, Monom* p) override; //��������
	void DelRecord(TKey k) override; //�������
	//���������
	bool Reset() override; //���������� �� ������ �������
	bool IsEnded() override; //������� �����������?
	bool GoNext() override; //������� �� ���������
	//���� �������
	TTreeNode* Search(TTreeNode* r, TKey k); //����������� �����
	TTreeNode* Insertion(TTreeNode* r, TKey k, Monom* p); //����������� �������
	TTreeNode* Delete(TTreeNode* r, TKey k); //����������� ��������
	TTreeNode* min(TTreeNode* r); //����������� �������
};