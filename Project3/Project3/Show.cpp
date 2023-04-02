#include "Show.h"

Show::Show()
{
    this->theme = "null";
}

Show::Show(string title, Time time, string theme):TvProgram(title, time)
{
    if (title.empty()) throw "Title is empty!";
    if (theme.empty()) throw "Theme is empty!";
    this->theme = theme;
}

void Show::setTheme(string theme)
{
    this->theme = theme;
}

string Show::getTheme() const
{
    return theme;
}

string Show::ToString() const
{
    string times = to_string(getTime().getHour()) + ":" + to_string(getTime().getMinutes()) + ":" + to_string(getTime().getSeconds());
    return type() + "=" + getTitle() + "=" + times + "=" + getTheme();
}

string Show::type() const
{
    return "Show";
}

void Show::show() const
{
    cout << type() << " " << getTitle() << " " << getTime() << "\nTheme: " << getTheme() << endl;
}
