#include "TTable.h"

bool TTable::IsFull()
{//���������?
	Polynom* p = new Polynom();
	if (!p) //���� �� ������
		return true;
	delete p;
	return false;
}