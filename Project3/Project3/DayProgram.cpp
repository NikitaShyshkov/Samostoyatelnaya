#include "DayProgram.h"

DayProgram::DayProgram()
{
	this->date = Date();
}

DayProgram::DayProgram(Date date)
{
	this->date = date;
}

void DayProgram::setDate(Date date)
{
	this->date = date;
}

Date DayProgram::getDate() const
{
	return date;
}

void DayProgram::insert(TvProgram* prog)
{
	queue.push(prog);
}

void DayProgram::showAll() const
{
	priority_queue<TvProgram*, vector<TvProgram*>, CompareTime> q = queue;
	while (!q.empty())
	{
		cout << "~~~~~~~~~~\n";
		q.top()->show();
		q.pop();
	}
}

void DayProgram::searchByTime(Time time)
{
	priority_queue<TvProgram*, vector<TvProgram*>, CompareTime> q = queue;
	while (!q.empty())
	{
		if (q.top()->getTime() == time)
		{
			cout << "~~~~~~~~~~\n";
			q.top()->show();
		}
		q.pop();
	}
}

void DayProgram::searchByType(string type)
{
	priority_queue<TvProgram*, vector<TvProgram*>, CompareTime> q = queue;
	while (!q.empty())
	{
		if (q.top()->type() == type)
		{
			cout << "~~~~~~~~~~\n";
			q.top()->show();
		}
		q.pop();
	}
}

bool DayProgram::operator<(const DayProgram& obj) const&
{
	return this->date > obj.date;
}

bool DayProgram::operator==(const DayProgram& obj) const&
{
	return this->date == obj.date;
}

void DayProgram::save(ofstream& file) const
{

	priority_queue<TvProgram*, vector<TvProgram*>, CompareTime> q = queue;
	while (!q.empty())
	{
		file << q.top()->ToString();
		q.pop();
	}
}

void DayProgram::load(ifstream& file)
{
	string str;
	while (!file.eof())
	{
		getline(file, str);
		int ind = str.find("=");
		string type = str.substr(0, ind);
		str.erase(0, ind + 1);
		ind = str.find("=");
		string title = str.substr(0, ind);
		str.erase(0, ind + 1);
		int hh, mm, ss;
		ind = str.find(":");
		hh = stoi(str.substr(0, ind));
		str.erase(0, ind + 1);
		ind = str.find(":");
		mm = stoi(str.substr(0, ind));
		str.erase(0, ind + 1);
		ind = str.find("=");
		ss = stoi(str.substr(0, ind));
		str.erase(0, ind + 1);
		string tmp1, tmp2;
		int i1, i2;
		if (type == "Education")
		{
			ind = str.find("=");
			tmp1 = str.substr(0, ind);
			str.erase(0, ind + 1);
			queue.push(new Education(title, Time(hh, mm, ss), tmp1));
		}
		else if (type == "Show")
		{
			ind = str.find("=");
			tmp1 = str.substr(0, ind);
			str.erase(0, ind + 1);
			queue.push(new Show(title, Time(hh, mm, ss), tmp1));
		}
		else if (type == "Movie")
		{
			ind = str.find("=");
			tmp1 = str.substr(0, ind);
			str.erase(0, ind + 1);
			ind = str.find("=");
			i1 = stoi(str.substr(0, ind));
			str.erase(0, ind + 1);
			queue.push(new Movie(title, Time(hh, mm, ss), tmp1, i1));
		}
		else if (type == "Children")
		{
			ind = str.find("=");
			i1 = stoi(str.substr(0, ind));
			str.erase(0, ind + 1);
			ind = str.find("=");
			i2 = stoi(str.substr(0, ind));
			str.erase(0, ind + 1);
			queue.push(new Children(title, Time(hh, mm, ss), i1, i2));
		}
	}
}