struct Hour {
    int hour = 0;
    int minutes = 0;
    void operator=(Hour h);
    int totalMinutes();
    bool operator>(Hour h);
    bool operator<(Hour h);
    Hour operator+(int m);
    bool operator==(Hour h);
};

void Hour::operator=(Hour h){
    this->hour = h.hour;
    this->minutes = h.minutes;
}

int Hour::totalMinutes()
{
    return hour * 60 + minutes;
}

bool Hour::operator>(Hour h){
    int minA, minB;
    minA = this->totalMinutes();
    minB = h.totalMinutes();
    if (minA > minB)
        return true;
    return false;
}

bool Hour::operator<(Hour h){
    int minA, minB;
    minA = this->totalMinutes();
    minB = h.totalMinutes();
    if (minA < minB)
        return true;
    return false;
}

bool Hour::operator==(Hour h)
{
    if (h.hour == this-> hour && h.minutes == this-> minutes)
        return true;
    return false;
}
Hour Hour::operator+(int m){
    Hour r;
    r.hour = (hour+((minutes+m)/60))%24;
    r.minutes =(minutes+m)%60;
    return r;
}