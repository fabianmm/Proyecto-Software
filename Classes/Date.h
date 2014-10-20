#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
private:
//Attributes.
	int iDay, iMonth, iYear;	
public:
//Constructor.
	Date();
//Modify.
	void setDay(int iDay);
	void setMonth(int iMonth);
	void setYear(int iYear);
//Access.
	int getDay();
	int getMonth();
	int getYear();
};
Date::Date()
{
	iDay=5;
	iMonth=5;
	iYear=2014;
}
void Date::setDay(int iDay)
{
	this->iDay=iDay;
}
void Date::setMonth(int iMonth)
{
	this->iMonth=iMonth;
}
void Date::setYear(int iMonth)
{
	this->iMonth=iMonth;
}
int Date::getDay()
{
	return iDay;
}
int Date::getMonth()
{
	return iMonth;
}
int Date::getYear()
{
	return iYear;
}
#endif // DATE_H_INCLUDED
