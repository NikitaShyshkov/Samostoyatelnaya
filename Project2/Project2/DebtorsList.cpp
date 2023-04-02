#include "DebtorsList.h"

void DebtorsList::push_back(Debtor obj)
{
	list.push_back(obj);
}

void DebtorsList::erase(int number)
{
	for (auto it = list.begin() ; it != list.end(); it++)
	{
		if ((*it).getNumber() == number)
		{
			list.erase(it);
		}
	}
}

float DebtorsList::allMoney() const
{
	float all = 0;
	for (int i = 0; i < list.size(); i++)
	{
		all += list[i].getMoney();
	}
	return all;
}

int DebtorsList::size() const
{
	return list.size();
}

void DebtorsList::show() const
{
	for (int i = 0; i < list.size(); i++)
	{
		list[i].show();
	}
}
