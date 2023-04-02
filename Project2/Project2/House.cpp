#include "House.h"

void House::insert(Debtor obj)
{
	if (obj.getNumber() <= 36)
	{
		arr[1].push_back(obj);
	}
	else if (obj.getNumber() <= 72)
	{
		arr[2].push_back(obj);
	}
	else if (obj.getNumber() <= 108)
	{
		arr[3].push_back(obj);
	}
	else if (obj.getNumber() <= 144)
	{
		arr[4].push_back(obj);
	}
}

void House::erase(int number)
{
	if (number <= 36)
	{
		arr[1].erase(number);
	}
	else if (number <= 72)
	{
		arr[2].erase(number);
	}
	else if (number <= 108)
	{
		arr[3].erase(number);
	}
	else if (number <= 144)
	{
		arr[4].erase(number);
	}
}

void House::showAllBuildings()
{
	for (int i = 1; i <= 4; i++)
	{
		cout << "#" << i << "\n\t";
		cout << fixed << setprecision(2) << arr[i].allMoney();
		cout << " UAH\n";
	}
}

void House::showTheHighestDebt()
{
	int id = 1;
	for (int i = 1; i <= 4; i++)
	{
		if (arr[i].allMoney() > arr[id].allMoney())
		{
			id = i;
		}
	}
	cout << "#" << id << "\n\t";
	cout << fixed << setprecision(2) << arr[id].allMoney();
	cout << " UAH\n";
}

void House::showAll()
{
	for (int i = 1; i <= 4; i++)
	{
		cout << "~~~~~~~~~~#" << i << "~~~~~~~~~~\n";
		arr[i].show();
	}
}
