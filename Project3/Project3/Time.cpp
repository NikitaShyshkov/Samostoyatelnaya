#include "Time.h"

Time::Time()
{
    format = true;
    struct tm* tim = new tm;
    time_t tt = time(NULL);
    localtime_s(tim, &tt);

    this->hour = tim->tm_hour;
    this->minutes = tim->tm_min;
    this->seconds = tim->tm_sec;

    delete[] tim;
}

Time::Time(int hour, int minutes, int seconds, bool format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

Time::Time(const Time& obj)
{
    this->format = obj.format;
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
}

Time& Time::operator=(const Time& obj)
{
    this->format = obj.format;
    this->hour = obj.hour;
    this->minutes = obj.minutes;
    this->seconds = obj.seconds;
    return *this;
}

Time::~Time()
{
}

void Time::setHour(int hour)
{
    if (hour >= 0 && hour <= 23)
    {
        this->hour = hour;
    }
}

int Time::getHour() const
{
    return hour;
}

void Time::setMinutes(int minutes)
{
    if (minutes >= 0 && minutes <= 59)
    {
        this->minutes = minutes;
    }
}

int Time::getMinutes() const
{
    return minutes;
}

void Time::setSeconds(int seconds)
{
    if (seconds >= 0 && seconds <= 59)
    {
        this->seconds = seconds;
    }
}

int Time::getSeconds() const
{
    return seconds;
}

void Time::setFormat(bool format)
{
    this->format = format;
}

bool Time::getFormat() const
{
    return format;
}

bool Time::valid() const
{
    if ((hour >= 0 && hour <= 23) && (minutes >= 0 && minutes <= 59) && (seconds >= 0 && seconds <= 59))
    {
        return true;
    }
    return false;
}

void Time::tickTime()
{
    if (seconds == 59 && minutes == 59 && hour == 23)
    {
        seconds = 0;
        minutes = 0;
        hour = 0;
    }
    else if (seconds == 59 && minutes == 59)
    {
        seconds = 0;
        minutes = 0;
        hour++;
    }
    else if (seconds == 59)
    {
        seconds = 0;
        minutes++;
        hour++;
    }
    else
    {
        seconds++;
    }
}

void Time::untickTime()
{
    if (seconds == 0 && minutes == 0 && hour == 0)
    {
        seconds = 59;
        minutes = 59;
        hour = 23;
    }
    else if (seconds == 0 && minutes == 0)
    {
        seconds = 59;
        minutes = 59;
        hour--;
    }
    else if (seconds == 0)
    {
        seconds = 59;
        minutes--;
        hour--;
    }
    else
    {
        seconds--;
    }
}

void Time::showTime() const
{
    if (format)
    {
        cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << endl;
    }
    else
    {
        if (hour <= 12)
        {
            cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << " AM" << endl;
        }
        else
        {
            int hrs = hour - 12;
            cout << hrs / 10 << hrs % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << " PM" << endl;
        }
    }
}

bool Time::operator==(const Time& obj) const&
{
    if ((this->hour == obj.hour) && (this->minutes == obj.minutes) && (this->seconds == obj.seconds))
    {
        return true;
    }
    return false;
}

bool Time::operator!=(const Time& obj) const&
{
    return !(*this == obj);
}

bool Time::operator>(const Time& obj) const&
{
    if (this->hour > obj.hour)
    {
        return true;
    }
    else if (this->hour == obj.hour && this->minutes > obj.minutes)
    {
        return true;
    }
    else if (this->hour == obj.hour && this->minutes == obj.minutes && this->seconds > obj.seconds)
    {
        return true;
    }
    return false;
}

bool Time::operator<(const Time& obj) const&
{
    return !(*this > obj) && *this != obj;
}

bool Time::operator>=(const Time& obj) const&
{
    return (*this > obj) || (*this == obj);
}

bool Time::operator<=(const Time& obj) const&
{
    return (*this < obj) || (*this == obj);
}

Time& Time::operator+=(int s)
{
    for (int i = 0; i < s; i++)
    {
        this->tickTime();
    }
    return*this;
}

Time& Time::operator-=(int s)
{
    for (int i = 0; i < s; i++)
    {
        this->untickTime();
    }
    return*this;
}

Time& Time::operator+=(float m)
{
    this->minutes += m;
    if (minutes > 59)
    {
        do
        {
            if (minutes == 60)
            {
                minutes = 0;
                if (hour != 23)
                {
                    hour++;
                }
                else
                {
                    hour = 0;
                }
                break;
            }
            minutes -= 60;
            if (hour != 23)
            {
                hour++;
            }
            else
            {
                hour = 0;
            }
        } while (minutes > 59);
    }
    return *this;
}

Time& Time::operator-=(float m)
{
    this->minutes -= m;
    if (minutes < 0)
    {
        do
        {
            minutes += 60;
            if (hour != 0)
            {
                hour--;
            }
            else
            {
                hour = 23;
            }
        } while (minutes < 0);
    }
    return *this;
}

Time& Time::operator+=(long h)
{
    this->hour += h;
    if (hour > 23)
    {
        do
        {
            if (hour == 24)
            {
                hour = 0;
                break;
            }
            hour -= 24;
        } while (hour > 23);
    }
    return *this;
}

Time& Time::operator-=(long h)
{
    this->hour -= h;
    if (hour < 0)
    {
        do
        {
            hour += 24;
        } while (hour < 0);
    }
    return *this;
}

Time Time::operator+(int s) const&
{
    Time tmp = *this;
    tmp += s;
    return tmp;
}

Time Time::operator-(int s) const&
{
    Time tmp = *this;
    tmp -= s;
    return tmp;
}

Time Time::operator+(float m) const&
{
    Time tmp = *this;
    tmp += m;
    return tmp;
}

Time Time::operator-(float m) const&
{
    Time tmp = *this;
    tmp -= m;
    return tmp;
}

Time Time::operator+(long h) const&
{
    Time tmp = *this;
    tmp += h;
    return tmp;
}

Time Time::operator-(long h) const&
{
    Time tmp = *this;
    tmp -=h;
    return tmp;
}

Time& Time::operator--()
{
    this->untickTime();
    return *this;
}

Time Time::operator--(int)
{
    Time tmp = *this;
    this->untickTime();
    return tmp;
}

Time& Time::operator++()
{
    this->tickTime();
    return *this;
}

Time Time::operator++(int)
{
    Time tmp = *this;
    this->tickTime();
    return tmp;
}

Time operator+(int n, const Time a)
{
    Time tmp = a + n;
    return tmp;
}

Time operator-(int n, const Time a)
{
    Time tmp = a - n;
    return tmp;
}

ostream& operator<<(ostream& os, const Time& t)
{
    if (t.format)
    {
        os << t.hour / 10 << t.hour % 10 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10;
    }
    else
    {
        if (t.hour <= 12)
        {
            os << t.hour / 10 << t.hour % 10 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10 << " AM";
        }
        else
        {
            int hrs = t.hour - 12;
            os << hrs / 10 << hrs % 10 << ":" << t.minutes / 10 << t.minutes % 10 << ":" << t.seconds / 10 << t.seconds % 10 << " PM";
        }
    }
    return os;
}

istream& operator>>(istream& is, Time& t)
{
    do
    {
        cout << "hh:mm:ss   format(1 - 24h, 0 - 12h)\n";
        is >> t.hour >> t.minutes >> t.seconds >> t.format;
        system("cls");
    } while (!t.valid());
    return is;
}
