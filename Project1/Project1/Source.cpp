#include <iostream>
#include <list>
#include <math.h>
using namespace std;

void fill(list<float>* ram, float size)
{
	int bytes;
	do
	{
		bytes = rand() % 1500 + 500;
		if (bytes > size)
		{
			ram->push_back(size);
			return;
		}
		size -= bytes;
		ram->push_back(bytes);
	} while (size != 0);
}
auto search(list<float>* ram, float size)
{
	auto tmp = ram->begin();
	float difference = 8000;
	for (auto it = ram->begin(); it != ram->end(); it++)
	{
		if (fabs(*it - size) < difference)
		{
			tmp = it;
			difference = fabs(*it - size);
		}
	}
	return tmp;
}

void show(list<float>* ram)
{
	for (auto item : *ram)
	{
		cout << item << " ";
	}
	cout << "\n\n";
}

int main()
{
	srand(time(0));
	int ram_size = 8000;
	list<float> ram;
	fill(&ram, ram_size);
	show(&ram);
	float get_size;
	do
	{
		cout << "Enter size in bytes: " << endl;
		cin >> get_size;
		if (get_size > ram_size)
		{
			get_size = 0;
			continue;
		}
		
	} while (get_size <= 0);
	auto tmp = search(&ram, get_size);
	cout << "Inserted into cell with " << *tmp << " bytes\n";
	*tmp -= get_size;

	return 0;
}