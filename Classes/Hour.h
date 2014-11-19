struct Hour {
    int hour = 0;
    int minutes = 0;
    void operator=(Hour h);
    int totalMinutes();
    bool operator>(Hour h);
    bool operator<(Hour h);
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