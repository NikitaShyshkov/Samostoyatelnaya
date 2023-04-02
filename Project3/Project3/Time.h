#pragma once
#include <time.h>
#include <iostream>
using namespace std;
class Time
{
	int hour;
	int minutes;
	int seconds;
	bool format;// true = utc (24-hours),    false = am/pm (12-hours)
public:
	Time();
	Time(int hour, int minutes, int seconds, bool format = true);
	Time(const Time& obj);
	Time& operator = (const Time& obj);
	~Time();
	//-------Set & Get
	void setHour(int hour);
	int getHour()const;
	void setMinutes(int minutes);
	int getMinutes()const;
	void setSeconds(int seconds);
	int getSeconds()const;
	void setFormat(bool format);
	bool getFormat()const;

	bool valid()const; //time check
	void tickTime(); //every tick add one second
	void untickTime(); //every tick remove one second
	void showTime()const; //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time& obj)const&;
	bool operator != (const Time& obj)const&;
	bool operator > (const Time& obj)const&;
	bool operator < (const Time& obj)const&;
	bool operator >= (const Time& obj)const&;
	bool operator <= (const Time& obj)const&;

	//--------- Assignment operators ---------	
	Time& operator += (int s);		// add seconds
	Time& operator -= (int s);
	Time& operator += (float m);	// add minutes
	Time& operator -= (float m);
	Time& operator += (long h);	// add hours
	Time& operator -= (long h);

	//--------- Arithmetic operators ---------
	Time operator + (int s)const&;	// add seconds
	Time operator - (int s)const&;
	Time operator + (float m)const&; // add minutes
	Time operator - (float m)const&;
	Time operator + (long h)const&; // add hours
	Time operator - (long h)const&;

	Time& operator -- ();
	Time operator -- (int);
	Time& operator ++ ();
	Time operator ++ (int);

	friend Time operator + (int n, const Time a);
	friend Time operator - (int n, const Time a);

	friend ostream& operator << (ostream& os, const Time& t);
	friend istream& operator >> (istream& is, Time& t);
};

