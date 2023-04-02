#pragma once
#include "TvProgram.h"
class Education : public TvProgram
{
protected:
	string science;
public:
	Education();
	Education(string title, Time time, string science);

	void setScience(string science);
	string getScience()const;

	string ToString()const override;
	string type()const override;
	void show()const override;
};

