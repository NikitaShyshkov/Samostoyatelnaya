#pragma once
#include <iostream>
#include "Date.h"
#include "Children.h"
#include "Education.h"
#include "Show.h"
#include "Movie.h"
#include <map>
#include <queue>
#include <fstream>
using namespace std;

struct CompareTime : public std::binary_function<TvProgram*, TvProgram*, bool>
{
	bool operator()(const TvProgram* lhs, const TvProgram* rhs) const
	{
		return lhs->getTime() > rhs->getTime();
	}
};
class DayProgram
{
protected:
	Date date;
	priority_queue<TvProgram*, vector<TvProgram*>, CompareTime> queue;
public:
	DayProgram();
	DayProgram(Date date);

	void setDate(Date date);
	Date getDate()const;

	void insert(TvProgram* prog);
	void showAll()const;

	void searchByTime(Time time);
	void searchByType(string type);

	bool operator < (const DayProgram& obj)const&;
	bool operator == (const DayProgram& obj)const&;

	void save(ofstream& file)const;
	void load(ifstream& file);
};
//Для хранения я выбрал очередь с приоритетом т.к. нужно было чтобы телепрограммы показывались по очереди и сортировались по времени
//upd: лучше бы использовал дерево
