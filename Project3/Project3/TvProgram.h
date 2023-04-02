#pragma once
#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

class TvProgram
{
protected:
	string title;
	Time time;
public:
	TvProgram();
	TvProgram(string title, Time time);

	void setTitle(string title);
	void setTime(Time time);
	string getTitle()const;
	Time getTime()const;

	bool operator < (const TvProgram& obj)const&;

	virtual string ToString()const = 0;
	virtual string type()const = 0;
	virtual void show()const = 0;
};

