#include <vector>
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
	std::vector<Event> vEventList;
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
void setDayName(string sDName){
	sDayName = sDName;
}
void setFreeHours(int iFHours){
	iFreeHours = iFHours;
}
void setEventList(Event eEvent){
	vEventList.PUSH_BACK(eEvent);
}
//Access
string getDayName(){
	return sDayName;
}
int getFreHours(){
	return iFreeHours;
}
Event getEventFromList(int eID){
	return vEventList[eID];
}