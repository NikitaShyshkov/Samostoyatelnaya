#include "Debtor.h"

Debtor::Debtor()
{
    this->name = "null";
    this->money = 0;
    this->number = -1;
}

Debtor::Debtor(string name, float money, int number)
{
    this->name = name;
    this->money = money;
    this->number = number;
}

void Debtor::setName(string name)
{
    this->name = name;
}

void Debtor::setMoney(float money)
{
    this->money = money;
}

void Debtor::setNumber(int number)
{
    this->number = number;
}

string Debtor::getName() const
{
    return name;
}

float Debtor::getMoney() const
{
    return money;
}

int Debtor::getNumber() const
{
    return number;
}

void Debtor::show() const
{
    cout << "#" << getNumber() << "\n" << getName() << " ";
    cout << fixed << setprecision(2) << getMoney();
    cout << " UAH\n";
}
