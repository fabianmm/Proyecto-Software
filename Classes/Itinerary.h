#include <vector>
#include "Date.h"
#include "Day.h"

class Itinerary {
public:
    //Constructor
    Itinerary();
    Itinerary(string, string, Date, Date);
    //Days attribute is public for easier manipulation
    vector<Day> vDays;
    //Access
    string getName();
    string getCity();
    Date getArrival();
    Date getDeparture();
    //Modifiers
    void setName(string);
    void setCity(string);
    void setArrival(Date);
    void setDeparture(Date);
    //Other
    int totalFreeHours();
    void print();
private:
    //Attributes
    string sName;
    string sCity;
    Date dArrival;
    Date dDeparture;
};

Itinerary::Itinerary(){
    sName = "";
    sCity = "";
}

Itinerary::Itinerary(string name, string city, Date arrival, Date departure){
    sName = name;
    sCity = city;
    dArrival = arrival;
    dDeparture = departure;
}

string Itinerary::getName(){
    return sName;
}

string Itinerary::getCity(){
    return sCity;
}

Date Itinerary::getArrival(){
    return dArrival;
}

Date Itinerary::getDeparture(){
    return dDeparture;
}

void Itinerary::setName(string name){
    sName = name;
}

void Itinerary::setCity(string city){
    sCity = city;
}

void Itinerary::setDeparture(Date departure){
    dDeparture = departure;
}

void Itinerary::setArrival(Date arrival){
    dArrival = arrival;
}

int Itinerary::totalFreeHours(){
    int hours = 0;
    for (int i = 0; i < vDays.size(); i++){
        hours += vDays[i].freeHours();
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