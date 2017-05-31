#pragma once
class Monom
{
	int num; //коэффициент
	int exp; //степень xyz
	Monom* next; //Указатель на следующий моном
public:
	Monom(int n = 0, int e = 0){ num = n; exp = e; } //Конструктор
	friend class Polynom; //Классу Полином доступны protected данные
};

