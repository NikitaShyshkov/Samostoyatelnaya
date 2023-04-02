#pragma once
#include "TvProgram.h"
class Movie : public TvProgram
{
protected:
	string directBox;
	int year;
public:
	Movie();
	Movie(string title, Time time, string directBox, int year);

	void setDirectBox(string directBox);
	void setYear(int year);
	string getDirectBox()const;
	int getYear()const;

	string ToString()const override;
	string type()const override;
	void show()const override;
};

