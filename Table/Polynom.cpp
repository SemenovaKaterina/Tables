#include "Polynom.h"

void Polynom::Pol(TKey s)
{
	int a = 0; //a й элемент строки S
	while ((s[a] != '_') && (s[a] != ' '))
	{
		Key += s[a];
		a++;
	}

	pValue = 0;
	char per = ' '; //x y z
	int n = 0; //Коэффициент
	int e = 0; //Степень
	int k = 1; //Домножение
	s += "+";
	for (unsigned int i = a; i < s.length(); i++)
	{
		char c = s[i];
		if (c == ' ') //Игнорировать пробелы
			continue;
		if (IsNumber(c))
		{
			if (per == ' ') //Если это коэффициент
				n = n * 10 + (int)c - 48;
			else //Если это степень
				e += ((int)c - 48)*Exp(per);
		}
		else if (IsVariable(c)) //Если это х или y или z
			per = c;
		else if (IsOperation(c)) //Если это операция + или -
		{
			if (n)
			{
				n = n * k;
				k = 1;
				Insert(n, e);
			}
			if (c == '-') //Отрицательный коэффициент
				k = -1;
			n = 0; e = 0; per = ' ';
		}
	}
}

void Polynom::Insert(int n, int e) //Добавление монома, поиск позиции для вставки
{
	Monom* i = pValue;
	if (i == 0) //Если полином пуст
		pValue = new Monom(n, e);
	else
	{
		while (i)
		{//До конца полинома
			if (i->exp == e) //Если степени совпали
			{
				i->num += n;
				break; //Тогда нового монома создавать не надо
			}
			if (i->exp < e) //Если степень следующего меньше
			{
				InsertBefore(n, e, i); //То вставляем перед ним
				break;
			}
			if (i->next == 0) //Добавляем в конец
			{
				i->next = new Monom(n, e);
				break;
			}
			i = i->next;
		}
	}
}

void Polynom::InsertBefore(int n, int e, Monom* x) //Добавить моном до
{
	if (x == pValue) //Добавить перед первым
	{
		Monom* i = pValue;
		pValue = new Monom(n, e);
		pValue->next = i;
	}
	else
	{
		Monom*i;
		for (i = pValue; i->next != x; i = i->next); //Ищем моном после которого вставка
		i->next = new Monom(n, e);
		i->next->next = x;
	}
}

void Polynom::SetKey(TKey k) //Установить ключ
{
	Key = k;
}

TKey Polynom::GetKey() //Получить ключ
{
	return Key;
}

void Polynom::SetValuePtr(Monom* p) //Установить указатель
{
	pValue = p;
}

Monom* Polynom::GetValuePtr() //Получить указатель
{
	return pValue;
}

Monom* Polynom::GetCopy() //Изготовить копию
{
	Monom* res = new Monom(*pValue);
	return res;
}

bool Polynom::IsNumber(char c) //Это число
{
	int chis = (int)c;
	if ((chis > 47) && (chis < 58)) //0...9
		return true;
	return false;
}

bool Polynom::IsVariable(char c) //Это x y z
{
	int chis = (int)c;
	if ((chis > 119) && (chis < 123)) //x, y, z
		return true;
	return false;
}

int Polynom::Exp(char c) //x-100 y-10 z-1 степени
{
	if (c == 'x')
		return 100; //x
	if (c == 'y')
		return 10; //y
	return 1; //z
}

bool Polynom::IsOperation(char c) //Это + или - между мономами
{
	if (c == '+' || c == '-')
		return true;
	return false;
}

string Polynom::ToString() //Преобразование полинома в строку
{
	string res = "";
	char b[16];
	Monom* i = pValue;
	if (i == 0) //Если полином пуст
		return "0";
	while (i)
	{
		sprintf_s(b, "%d", i->num);
		res += b;
		res += "x";
		sprintf_s(b, "%d", i->exp / 100);
		res += b;
		res += "y";
		sprintf_s(b, "%d", i->exp / 10 % 10);
		res += b;
		res += "z";
		sprintf_s(b, "%d", i->exp % 10);
		res += b;
		if (i->next)
		{
			if (i->next->num > 0)
				res += "+";
		}
		i = i->next;
	}
	return res;
}