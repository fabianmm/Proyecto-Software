#ifndef HOUR_H_INCLUDED
#define HOUR_H_INCLUDED

class Hour
{
private:
//Attributes.
public:
//Public Attributes.
	int iHour, iMinute;
//Constructor.
	Hour();
	Hour(int iHour, int iMinute);
//Modify.
	void setHour(iHour);
	void setMin(iMinute);
//Access.
	int getHour();
	int getMin();
};
Hour::Hour()
{
	iHour=0;
	iMinute=0;
}
Hour::Hour(int iHour, int iMinute)
{
	this->iHour=iHour;
	this->>iMinute=iMinute;
}
void Hour::setHour(int iHour)
{
	this->iHour=iHour;
}
void Hour::setMin(int iMinute)
{
	this->iMinute=iMinute;
}
int Hour::getHour()
{
	return iHour;
}
int Hour::getMin()
{
	return iMinute;
}
#endif // HOUR_H_INCLUDED
