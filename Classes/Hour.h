struct Hour {
    int hour = 0;
    int minutes = 0;
    void operator=(Hour h);
};

void Hour::operator=(Hour h){
    this->hour = h.hour;
    this->minutes = h.minutes;
}