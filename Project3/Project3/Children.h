#pragma once
#include "TvProgram.h"
class Children : public TvProgram
{
protected:
	int min;
	int max;
public:
	Children();
	Children(string title, Time time, int min, int max);

	void setMinAge(int min);
	void setMaxAge(int max);
	int getMinAge()const;
	int getMaxAge()const;

	string ToString()const override;
	string type()const override;
	void show()const override;
};

