#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "User.h"

Itinerary defaultTemplate(string cityName, string cityFile, int days, Date arrival, Date departure) //prints a default template for each city & returns Itinerary
{
    ifstream archEnt;
    int auxInt, numberOfEvents;;
    string auxString;

    //Sets the initial info for the defualt itinerary.
    Itinerary defaultItinerary;
    defaultItinerary.setArrival(arrival);
    defaultItinerary.setDeparture(departure);
    defaultItinerary.setName("Default " + cityName);
    defaultItinerary.setCity(cityName);//Sets the name of the itinerary.
    defaultItinerary.vDays.resize(days);
    Hour auxHour;
    
    switch (days)
    {
        case 2:
        {
            cityFile += "2.txt";//2 day trip.
        }
            break;
/*==========NEEDS ALL THE FILES===================
        case 3:
        {
            cityFile += "3.txt";//3 day trip.
        }
            break;
        case 4:
        {
            cityFile += "4.txt";//4  day trip.
        }
            break;
===============================================*/
    }
    
    archEnt.open(cityFile.c_str()); //c_str() is used so the file can be opened with the given string(Opens file).

//Algorithm for taking the information out of the opened file (Defaults).
//
    for (int i = 0; i < days; i++){

        archEnt >> numberOfEvents;
        defaultItinerary.vDays[i].vEventList.resize(numberOfEvents);

        for (int j = 0; j < numberOfEvents; j++){

            archEnt >> auxHour.hour >> auxHour.minutes;
            //cout << auxHour.hour << " " << auxHour.minutes << endl;
            defaultItinerary.vDays[i].vEventList[j].setStart(auxHour);
            archEnt >> auxHour.hour >> auxHour.minutes;
            defaultItinerary.vDays[i].vEventList[j].setFinish(auxHour);
            archEnt >> auxInt;
            defaultItinerary.vDays[i].vEventList[j].setTime(auxInt);
            archEnt.ignore();
            getline(archEnt, auxString);
            //cout << auxString << endl;
            defaultItinerary.vDays[i].vEventList[j].setName(auxString);
        }
//
//======================================================================
        archEnt.close();//Closes File.
        defaultItinerary.print();//Uses a method from the Itinerary class to print out the Itinerary.
        return defaultItinerary;//Returns and object of type Itinerary.
    }
}


int main(){
    string response, cityName, cityFile;
    int cityNumber, travelDays;
    Date arrival, departure;
    Itinerary itinerario;

    //RF3
    cout << "¿Desea crear un nuevo itinerario (si/no)?\n";
    cin >> response;
//Keeps asking if he wants to create an itinerary(Default until now).
    while(response == "si"  || response == "SI" || response == "Si"){

        //RF4
        cout << "Elija el numero de la ciudad a la que desea viajar:\n1. San Francisco\n2. Kyoto\n3. Las Vegas\n4. London\5. Guadalajara\n";
        cin >> cityNumber;//Asksfor the cirt number(Used in the switch).

        while (cityNumber < 1 || cityNumber > 1){
//        while (cityNumber < 1 || cityNumber > 6){ ///////Until all files are added.
        //Loop to make the user type a valid number.
            cout << "Ese no es un numero valido, vuelva a ingresar un numero: ";
            cin >> cityNumber;
        }

        cout << "Ingrese el numero de dias que estara de visita entre 2 y 4: ";
        cin >> travelDays;

        while (travelDays < 2 || travelDays > 2){
//        while (travelDays < 2 || travelDays > 4){ //////UNTIL all files are added.
        //Loop to make hte user type a valid number.
            cout << "Ese no es un numero válido, ingrese un numero entre 2 y 4: ";
            cin >> travelDays;
        }

        switch (cityNumber)//Usesthe switch to send the right information to the function to create the default itinerary.
        {
                //RF5 & RF6
            case 1:
            {
                cityName = "San Francisco";//City Name.
                cityFile = "SFTemplate";//City File Name(Gets opened).

            }
                break;
/*=======================NEEDS ALL FILES====================================
            case 2:
            {
                cityName = "Kyoto";//City name.
                cityFile = "KYTemplate";//City File Name(Gets opened).
            }
                break;
            case 3:
            {
                cityName = "Las Vegas";//City name.
                cityFile = "LVTemplate";//City File Name(Gets opened).
            }
                break;
            case 4:
            {
                cityName = "London";//City name.
                cityFile = "LDTemplate";//City File Name(Gets opened).
            }
                break;
            case 5:
            {
                cityName = "Guadalajara";//City name.
                cityFile = "GDTemplate";//City File Name(Gets opened).
            }
                break;
==========================================================================*/
        }

        //Asks the user when he willbe arriving.
        cout << "Ingrese el dia de llegada(dd): ";
        cin >> arrival.day;
        cout << "Ingrese el mes de llegada(mm): ";
        cin >> arrival.month;
        cout << "Ingrese el año de llegada(aaaa): ";
        cin >> arrival.year;

        //Sets the date of arrival.
        departure.day = arrival.day + travelDays;
        departure.month = arrival.month;
        departure.year = arrival.year;

        //RF7
        itinerario = defaultTemplate(cityName, cityFile, travelDays, arrival, departure);

        //RF3
        cout << "¿Desea crear un nuevo itinerario (si/no)?\n";
        cin >> response;
    }

    return 0;
}
