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
    string getName(){return sName;};
    string getCity(){return sCity;};
    Date getArrival(){return dArrival;};
    Date getDeparture(){return dDeparture;};
    //Modifiers
    void setName(string name){sName=name;};
    void setCity(string city){sCity=city;};
    void setArrival(Date arrival){dArrival=arrival;};
    void setDeparture(Date departure){dDeparture=departure;};
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


int Itinerary::totalFreeHours(){
    int hours = 0;
    for (int i = 0; i < vDays.size(); i++){
        hours += vDays[i].iFreeHours;
    }
    return hours;
}

void Itinerary::print(){
    cout << "\"" << sName << "\""
    << "\nCity: " << sCity
    << "\n" << dArrival.month << "/" << dArrival.day << "/" << dArrival.year << " - " << dDeparture.month << "/" << dDeparture.day << "/" << dDeparture.year << endl;
    for (int i = 0; i < vDays.size(); i++){
        cout << "*** Day " << i+1 << " ***" << endl;
        vDays[i].print();
    }
}