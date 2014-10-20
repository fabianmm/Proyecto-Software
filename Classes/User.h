#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "Itinerary"

class User
{
private:
//Attributes.
	bool bAdmin;
	string sName, sEmail, sPassword;
	Itinerary itLastItinerary;
public:
//Constructor.
	User();
	User(string sName, string sEmail, string sPassword, bool bAdmin);
//Modif.
	void setName(string sName);
	void setEmail(string sEmail);
	void setPassword(string sPassword);
	void setLastItinerary(Itinerary itLastItinerary);
//Access.
	string getName();
	string getEmail();
	string getPassword();
	Itinerary getLastItinerary();
	bool getAdmin();
//Other
	void push();
};
User::User()
{
	sName="";
	sEmail="";
	sPassword="";
	bAdmin=false;
}
User::User(string sName, string sEmail, string sPassword, bAdmin)
{
	this->sName=sName;
	this->sEmail=sEmail;
	this->sPassword=sPassword;
	this->bAdmin=bAdmin;
}
void User::setName(string sName)
{
	this->sName=sName;
}
void User::setEmail(string sEmail)
{
	this->sEmail=sEmail;
}
void User::setPassword(string sPassword)
{
	this->sPassword=sPassword;
}
void User::setLastItinerary(Itinerary itLastItinerary)
{
	this->itLastItinerary=itLastItinerary;
}
string User::getName()
{
	return sName;
}
string User::getEmail()
{
	return sEmail;
}
string User::getPassword()
{
	return sPassword;
}
Itinerary User::getLastItinerary()
{
	return itLastItinerary;
}
bool User::getAdmin()
{
	return bAdmin;
}
void User::push()
{
	//Funcion Push??
}
#endif // USER_H_INCLUDED