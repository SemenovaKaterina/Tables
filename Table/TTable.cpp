#include "TTable.h"

bool TTable::IsFull()
{//Заполнена?
	Polynom* p = new Polynom();
	if (!p) //Если не создан
		return true;
	delete p;
	return false;
}