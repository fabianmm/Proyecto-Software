#include "Hour.h"

class Event
{
private:
    string name;
    string day;
    Hour start
    Hour finish;
    int time;
    string code;
public:
    Event();
    Event(string a, string b, Hour c, Hour d, int e);
    void setName(string a);
    string getName();
    void setDay(string a);
    string getDay();
    void setStart(Hour a);
    void setFinish(Hour a);
    void setTime(int a);
    void setCode(string code);
    string getCode();
    int getTime();
    void print();
};
Event()
{
    name = "N/A";
    day = "N/A";
    time = 0;
}
void Event::setName(string a)
{
    name = a;
}
string Event::getName()
{
    return name;
}
void Event::setDay(string a)
{
    day = a;
}
string Event::getDay()
{
    return day;
}
void Event::setStart(Hour a)
{
    start = a;
}
void Event::setFinish(Hour a)
{
    finish = a;
}
void Event::setTime(int a)
{
    time = a;
}
int Event::getTime()
{
    return time;
}
void Event::setCode(string code)
{
    this->code = code;
}
string Event::getCode()
{
    return code;
}
void Event::print()
{
    cout << name << endl;
    //cout << "Day: " << day << endl;
    cout << "Starting time: " << start.hour << ":";
    if (start.minutes == 0)
        cout << "00" << endl;
    else
        cout << start.minutes << endl;
    cout << "Finish time: " << finish.hour << ":";
    if (finish.minutes == 0)
        cout << "00" << endl;
    else
        cout << finish.minutes << endl;
    cout << "Total time: " << time << endl;
}
