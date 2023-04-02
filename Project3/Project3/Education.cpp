#include "Education.h"

Education::Education()
{
    this->science = "null";
}

Education::Education(string title, Time time, string science):TvProgram(title, time)
{
    if (title.empty()) throw "Title is empty!";
    if (science.empty()) throw "Science is empty!";
    this->science = science;
}

void Education::setScience(string science)
{
    this->science = science;
}

string Education::getScience() const
{
    return science;
}

string Education::ToString() const
{
    string times = to_string(getTime().getHour()) + ":" + to_string(getTime().getMinutes()) + ":" + to_string(getTime().getSeconds());
    return type() + "=" + getTitle() + "=" + times + "=" + getScience();
}
string Education::type() const
{
    return "Education";
}

void Education::show() const
{
    cout << type() << " " << getTitle() << " " << getTime() << "\nScience: " << getScience() << endl;
}
