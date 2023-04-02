#include "TvProgram.h"

TvProgram::TvProgram()
{
    this->title = "null";
    this->time = Time(0, 0, 0);
}

TvProgram::TvProgram(string title, Time time)
{
    this->title = title;
    this->time = time;
}

void TvProgram::setTitle(string title)
{
    if (title.empty()) throw "Title is empty!";
    this->title = title;
}

void TvProgram::setTime(Time time)
{
    this->time = time;
}

string TvProgram::getTitle() const
{
    return title;
}

Time TvProgram::getTime() const
{
    return time;
}

bool TvProgram::operator<(const TvProgram& obj) const&
{
    return this->getTime() > obj.getTime();
}
