#include "Event.h"

class Day
{
public:
    //Consutructors
    Day(string sDName, int iFHours);
    Day();
    //Modify
    void setDayName(string sDName);
    void setFreeHours(int iFHours);
    void setEventList(Event eEvent);
    //Access
    string getDayName();
    int getFreHours();
    Event getEventFromList(int eID);//Returns an specific object of type "Event"(If needed).
    //Attributes
    string sDayName;
    int iFreeHours;
    vector<Event> vEventList;
    
    //Print
    void print();
};
//Constructors
Day::Day(){
    sDayName = "";
    iFreeHours = 0;
}
Day::Day(string sDName, int iFHours){
    sDayName = sDName;
    iFreeHours = iFHours;
}
//Modify
void Day::setDayName(string sDName){
    sDayName = sDName;
}
void Day::setFreeHours(int iFHours){
    iFreeHours = iFHours;
}
void Day::setEventList(Event eEvent){
    vEventList.push_back(eEvent);
}
//Access
string Day::getDayName(){
    return sDayName;
}
int Day::getFreHours(){
    return iFreeHours;
}
Event Day::getEventFromList(int eID){
    return vEventList[eID];
}

void Day::print()
{
    //cout << sDayName << endl;
    for (int i = 0; i < vEventList.size(); i++)
    {
        vEventList[i].print();
        cout << endl;
    }
}
