#pragma once
#include <vector>
#include "Debtor.h"

class DebtorsList
{
protected:
	vector<Debtor> list;
public:
	void push_back(Debtor obj);
	void erase(int number);
	float allMoney()const;
	int size()const;
	void show()const;
};

