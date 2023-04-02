#pragma once
#include <map>
#include <iomanip>
#include "DebtorsList.h"
class House
{
protected:
	map<int, DebtorsList> arr;
public:
	void insert(Debtor obj);
	void erase(int number);
	void showAllBuildings();
	void showTheHighestDebt();
	void showAll();
};

