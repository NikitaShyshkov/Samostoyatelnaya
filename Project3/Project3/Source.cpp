#include <iostream>
#include "DayProgram.h"
using namespace std;

enum programs {
	education = 1,
	movie,
	show,
	children
};

struct Compare : public std::binary_function<DayProgram*, DayProgram*, bool>
{
	bool operator()(const DayProgram* lhs, const DayProgram* rhs) const
	{
		return lhs->getDate() > rhs->getDate();
	}
};

void AddProgram(DayProgram& obj)
{
	int type = -1, year, year2;
	string title, hlp;
	Time time;
	do
	{
		system("pause");
		system("cls");
		cout << "Введите тип(Education = 1, Movie = 2, Show = 3, Сhildren = 4): ";
		cin >> type;
	} while (type < 1 || type > 4);
	cout << "Введите название: ";
	cin.ignore();
	getline(cin, title);
	cout << "Введите время показа:\n";
	cin >> time;
	switch (type)
	{
	case education:
		cout << "Введите науку: ";
		cin.ignore();
		getline(cin, hlp);
		try
		{
			obj.insert(new Education(title, time, hlp));
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
		break;
	case movie:
		cout << "Введите описание: ";
		cin.ignore();
		getline(cin, hlp);
		cout << "Введите год: ";
		cin >> year;

		try
		{
			obj.insert(new Movie(title, time, hlp, year));
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
		break;
	case show:
		cout << "Введите тему шоу: ";
		cin.ignore();
		getline(cin, hlp);

		try
		{
			obj.insert(new Show(title, time, hlp));
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
		break;
	case children:
		cout << "Введите минимальный возраст: ";
		cin >> year;
		cout << "Введите максимальный возраст: ";
		cin >> year2;

		try
		{
			obj.insert(new Children(title, time, year, year2));
		}
		catch (const char* s)
		{
			cout << s << endl;
		}
		break;
	}
}

void ProgramMenu(DayProgram& obj)
{
	int menu = 0;
	Time time;
	string type;
	string datee;
	do
	{
		system("pause");
		system("cls");
		cout << "~~~~~~~~~~Program Menu~~~~~~~~~~\n";
		cout << "1 - Добавить программу\n";
		cout << "2 - Показать все\n";
		cout << "3 - Поиск по времени(начала)\n";
		cout << "4 - Поиск по типу\n";
		cout << "5 - Сохранить в файл\n";
		cout << "0 - Выход\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			AddProgram(obj);
			break;
		case 2:
			obj.showAll();
			break;
		case 3:
			cout << "Введите время: ";
			cin.ignore();
			cin >> time;
			obj.searchByTime(time);
			break;
		case 4:
			cout << "Введите тип: ";
			cin.ignore();
			getline(cin, type);
			obj.searchByType(type);
			break;
		case 5:
			//datee = to_string(obj.getDate().getDay()) + "." + to_string(obj.getDate().getMonth()) + "." + to_string(obj.getDate().getYear());
			ofstream file("programs.txt");
			if (file.is_open())
			{
				obj.save(file);
				file.close();
			}
			break;
		}
	} while (menu != 0);
}
int main()
{
	setlocale(LC_ALL, "ukr");
	priority_queue<DayProgram*, vector<DayProgram*>, Compare> arr;
	int menu = 0, choose = -1;
	Date d;
	bool isExist = false;
	priority_queue<DayProgram*, vector<DayProgram*>, Compare> tmp;
	ifstream file; int i;
	do
	{
		system("pause");
		system("cls");
		cout << "~~~~~~~~~~Menu~~~~~~~~~~\n";
		cout << "1 - Создать дневную программу\n";
		cout << "2 - Выбрать дневную программу\n";
		cout << "3 - Загрузить из файла\n";
		cout << "0 - Выход\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Введите дату:\n";
			cin >> d;
			tmp = arr;
			while (!tmp.empty())
			{
				if (*tmp.top() == d)
				{
					cout << "Программа на этот день уже существует!\n";
					isExist = true;
					break;
				}
				tmp.pop();
			}
			if (isExist)
			{
				break;
			}
			arr.push(new DayProgram(d));
			break;
		case 2:
			tmp = arr;
			i = 1;
			if (tmp.empty())
			{
				cout << "Пусто!\n";
				break;
			}
			while (!tmp.empty())
			{
				cout << i << ": " << (*tmp.top()).getDate() << endl;
				tmp.pop();
				i++;
			}do
			{
				cout << "Выберите номер: ";
				cin >> choose;
			} while (choose < 1 || choose > arr.size());
			tmp = arr;
			for (int j = 0; j < choose; j++)
			{
				if (choose - 1 == j)
				{
					ProgramMenu(*tmp.top());
					break;
				}
				tmp.pop();
			}
			break;
		case 3: {
			tmp = arr;
			i = 1;
			if (tmp.empty())
			{
				cout << "Пусто!\n";
				break;
			}
			while (!tmp.empty())
			{
				cout << i << ": " << (*tmp.top()).getDate() << endl;
				tmp.pop();
				i++;
			}do
			{
				cout << "Выберите номер: ";
				cin >> choose;
			} while (choose < 1 || choose > arr.size());
			tmp = arr;
			for (int j = 0; j < choose; j++)
			{
				if (choose - 1 == j)
				{
					ifstream in("programs.txt");
					if (in.is_open())
					{
						tmp.top()->load(in);
					}
					break;
				}
				tmp.pop();
			}}
		}
	} while (menu != 0);

	return 0;
}

//Для того, что бы загрузить из файла нужно создать дневную программу и потом при загрузке из файла выбрать куда выгружать