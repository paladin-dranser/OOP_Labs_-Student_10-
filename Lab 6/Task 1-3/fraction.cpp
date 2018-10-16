#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

void Fraction::input()
{
	cout << "Числитель: ";
	cin >> m;
	cout << "Знаменатель: ";
	cin >> n;
}

void Fraction::output() const
{
	cout << m << "/" << n << endl;
}

void Fraction::mult(int a)
{
	m *= a;
}

string Fraction::isProper()
{
	return (m < n) ? "правильная" : "неправильная";
}
// задание 1
Fraction Fraction::operator+(const Fraction & fr)
{
	Fraction temp;
	temp.m = this->m * fr.n + fr.m * this->n;
	temp.n = this->n * fr.n;

	return temp;
}
// задание 1
bool Fraction::operator!=(const Fraction & fr)
{
	return (this->m * fr.n - fr.m * this->n != 0);
}
// задание 2
ostream & operator<<(ostream & os, const Fraction & fr)
{
    os << fr.m << '/' << fr.n << endl;

    return os;
}
// задание 2
istream & operator>>(istream & is, Fraction & fr)
{
    std::cout << "Введите дробь: ";
    is >> fr.m >> fr.n;

	// если ввели знаменатель равный нулю
	if (fr.n == 0)
		throw "Знаменатель не может быть равным нулю!"; // задание 3

	// если ввели знаменатель с минусом,
	// то меняем знаки числителя и знаменателя
    if (fr.n < 0)
    {
        fr.n = -fr.n;
        fr.m = -fr.m;
    }

    return is;
}
