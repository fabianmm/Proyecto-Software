#include "Hour.h"

class Event
{
private:
    string name, day;
    Hour start, finish;
    int time;
public:
    Event()
    {
        name = "N/A";
        day = "N/A";
        start.setHour(0);
        start.setMinute(0);
        finish.setHour(0);
        finish.setMinute(0);
        time = 0;
    }
    Event(string a, string b, Hour c, Hour d, int e)
    {
        name = a;
        day = b;
        start = c;
        finish = d;
        time = e;
    }
    void setName(string a)
    {
        name = a;
    }
    string getName()
    {
        return name;
    }
    void setDay(string a)
    {
        day = a;
    }
    string getDay()
    {
        return day;
    }
    void setStart(Hour a)
    {
        start = a;
    }
    void setFinish(Hour a)
    {
        finish = a;
    }
    void setTime(int a)
    {
        time = a;
    }
    int getTime()
    {
        return time;
    }
    void print()
    {
        cout << "Event Name: " << name << endl;
        cout << "Day: " << day << endl;
        cout << "Starting time: " << start.hour << ":" << start.minute<< endl;
        cout << "Finish time: " << finish.hour << ":" << finish.minute << endl;
        cout << "Total time: " << time << endl;
    }
    
};