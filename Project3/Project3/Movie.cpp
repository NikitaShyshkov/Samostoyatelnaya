#include "Movie.h"

Movie::Movie()
{
    this->directBox = "null";
    this->year = 0;
}

Movie::Movie(string title, Time time, string directBox, int year) :TvProgram(title, time)
{
    if (title.empty()) throw "Title is empty!";
    if (year < 1895) throw "Wrong year!";
    this->directBox = directBox;
    this->year = year;
}

void Movie::setDirectBox(string directBox)
{
    this->directBox = directBox;
}

void Movie::setYear(int year)
{
    if (year < 1895) throw "Wrong year!";
    this->year = year;
}

string Movie::getDirectBox() const
{
    return directBox;
}

int Movie::getYear() const
{
    return year;
}

string Movie::ToString() const
{
    string times = to_string(getTime().getHour()) + ":" + to_string(getTime().getMinutes()) + ":" + to_string(getTime().getSeconds());
    return type() + "=" + getTitle() + "=" + times + "=" + getDirectBox() + "=" + to_string(getYear());
}

string Movie::type() const
{
    return "Movie";
}

void Movie::show() const
{
    cout << type() << " " << getTitle() << " " << getTime() << "\nDirect box: " << getDirectBox() << " Year: " << getYear() << endl;
}
