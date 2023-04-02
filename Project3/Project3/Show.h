#pragma once
#include "TvProgram.h"
class Show : public TvProgram
{
protected:
	string theme;
public:
	Show();
	Show(string title, Time time, string theme);

	void setTheme(string theme);
	string getTheme()const;

	string ToString()const override;
	string type()const override;
	void show()const override;
};

