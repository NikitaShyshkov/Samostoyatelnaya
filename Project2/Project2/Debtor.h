#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Debtor
{
protected:
	string name;
	float money;
	int number;
public:
	Debtor();
	Debtor(string name, float money, int number);

	void setName(string name);
	void setMoney(float money);
	void setNumber(int number);
	string getName()const;
	float getMoney()const;
	int getNumber()const;

	void show()const;
};

