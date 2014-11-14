#ifndef ITINERARY_H_INCLUDED
#define ITINERARY_H_INCLUDED

#include <vector>
#include "Date.h"
#include "Day.h"

class Itinerary {
public:
    //Constructor
    Itinerary();
    Itinerary(string name, string city, Date arrival, Date departure);
    //Days attribute is public for easier manipulation
    vector<Day> vDays;
    //Access
    string getName(){return sName;};
    string getCity(){return sCity;};
    Date getArrival(){return dArrival;};
    Date getMiddleDay(){return dMiddleDay;};//Easier access to this day for changesin the itinerary.
    Date getDeparture(){return dDeparture;};
    string getDayOfWeek(Date dDate){return dayOfWeek(dDate);};
    Day getDays(int i){return vDays[i];};
    //Modifiers
    void setName(string name){sName=name;};
    void setCity(string city){sCity=city;};
    void setArrival(Date arrival){dArrival=arrival;};
    void setMiddleDay(Date middleDay){dMiddleDay=middleDay;};//Easier access to this day for changesin the itinerary.
    void setDeparture(Date departure){dDeparture=departure;};
    void setDays(int i, string sDay){vDays[i].setDayName(sDay);};
    //Other
    int totalFreeHours();
    void print();
private:
    //Attributes
    string sName,  sCity;
    Date dArrival, dMiddleDay ,dDeparture;
};

Itinerary::Itinerary(){
    sName = "";
    sCity = "";
}

Itinerary::Itinerary(string name, string city, Date arrival, Date departure){
    sName = name;
    sCity = city;
    dArrival = arrival;
    dMiddleDay = arrival;
    dMiddleDay.day += dMiddleDay.day + 1;
    dDeparture = departure;
}


int Itinerary::totalFreeHours(){
    int hours = 0;
    for (int i = 0; i < vDays.size(); i++){
        hours += vDays[i].getFreeHours();//Como que no existe? ERROR======!!
    }
    return hours;
}

void Itinerary::print(){
    cout << "\"" << sName << "\""
        << "\nCity: " << sCity
    << "\n" << dArrival.month << "/" << dArrival.day << "/" << dArrival.year << " - " << dDeparture.month << "/" << dDeparture.day << "/" << dDeparture.year << endl;
    for (int i = 0; i < vDays.size(); i++){
        vDays[i].print();
    }
    cout << endl;
}
#endif
