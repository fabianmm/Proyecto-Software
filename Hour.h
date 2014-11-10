#ifndef HOUR_H_INCLUDED
#define HOUR_H_INCLUDED

struct Hour {
    int hour = 0;
    int minutes = 0;
    void operator=(Hour h);
};

void Hour::operator=(Hour h){
    this->hour = h.hour;
    this->minutes = h.minutes;
}
#endif
