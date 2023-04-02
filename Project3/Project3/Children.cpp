#include "Children.h"

Children::Children()
{
    this->min = 0;
    this->max = 0;
}

Children::Children(string title, Time time, int min, int max) :TvProgram(title, time)
{
    if (title.empty()) throw "Title is empty!";
    if (min > max) throw "Wrong year!";
    this->min = min;
    this->max = max;
}

void Children::setMinAge(int min)
{
    if (min > max) throw "Wrong year!";
    this->min = min;
}

void Children::setMaxAge(int max)
{
    if (min > max) throw "Wrong year!";
    this->max = max;
}

int Children::getMinAge() const
{
    return min;
}

int Children::getMaxAge() const
{
    return max;
}

string Children::ToString() const
{
    string times = to_string(getTime().getHour()) + ":" + to_string(getTime().getMinutes()) + ":" + to_string(getTime().getSeconds());
    return type() + "=" + getTitle() + "=" + times + "=" + to_string(getMinAge()) + "=" + to_string(getMaxAge());
}

string Children::type() const
{
    return "Children";
}

void Children::show() const
{
    cout << type() << " " << getTitle() << " " << getTime() << "\nMin age: " << getMinAge() << " Max age: " << getMaxAge() << endl;
}
