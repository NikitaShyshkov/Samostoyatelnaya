#include <iostream>
#include "House.h"
using namespace std;

int main()
{
	House house;
	house.insert(Debtor("Nikita", 2770.90, 45));
	house.insert(Debtor("Kirill", 1890.53, 43));
	house.insert(Debtor("Petya", 2770.90, 37));
	house.insert(Debtor("Vasya", 2400.94, 108));
	house.insert(Debtor("Vasya", 2600.32, 100));
	house.insert(Debtor("Vasya", 2200.55, 105));
	house.showAllBuildings();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	house.showTheHighestDebt();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	house.showAll();

	return 0;
}