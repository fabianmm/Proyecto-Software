#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "User.h"

Itinerary defaultTemplate(int cityNumber, int days, Date arrival, Date departure) //prints a default template for each city & returns Itinerary
{
    ifstream archEnt;
    Itinerary defaultItinerary;
    defaultItinerary.setArrival(arrival);
    defaultItinerary.setDeparture(departure);
    defaultItinerary.setName("Default SF");
    defaultItinerary.vDays.resize(days);
    Hour auxHour;
    int auxInt;
    string auxString;
    switch (cityNumber)//Para que son tantos switches?
    {
        case 1:
        {
            defaultItinerary.setCity("San Francisco");
            switch (days)
            {
                case 2:
                {
                    archEnt.open("SFTemplate2.txt");

                    int numberOfEvents;

                    for (int i = 0; i < days; i++)
                    {
                        archEnt >> numberOfEvents;
                        defaultItinerary.vDays[i].vEventList.resize(numberOfEvents);
                        for (int j = 0; j < numberOfEvents; j++)
                        {
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
                    }

                    archEnt.close();
                    defaultItinerary.print();
                    return defaultItinerary;
                }
            }
        }



    }
    return defaultItinerary;
}


int main(){
    string response;
    int cityNumber, travelDays;
    Date arrival, departure;
    Itinerary itinerario;
    //RF3
    cout << "¿Desea crear un nuevo itinerario (si/no)?\n";
    cin >> response;

    do
    {
        //RF4
        cout << "Elija el número de la ciudad a la que desea viajar:\n1. San Francisco\n2. Kyoto\n3. Las Vegas\n4. London\5. Guadalajara\n";
        cin >> cityNumber;
        while (cityNumber < 1 || cityNumber > 6)
        {
            cout << "Ese no es un número válido, vuelva a ingresar un número: ";
            cin >> cityNumber;
        }

        switch (cityNumber)//Para que es el switch aqui?
        {
                //RF5 & RF6
            case 1:
            {
                cout << "Ingrese la cantidad de días a viajar (entre 2 y 4): ";
                cin >> travelDays;
                while (travelDays < 2 || travelDays > 4)
                {
                    cout << "Ese no es un número válido, ingrese un número entre 2 y 4: ";
                    cin >> travelDays;
                }

                cout << "Ingrese el día de llegada(dd): ";
                cin >> arrival.day;
                cout << "Ingrese el mes de llegada(mm): ";
                cin >> arrival.month;
                cout << "Ingrese el año de llegada(aaaa): ";
                cin >> arrival.year;
                departure.day = arrival.day + travelDays;
                departure.month = arrival.month;
                departure.year = arrival.year;

                //RF7
                itinerario = defaultTemplate(cityNumber, travelDays, arrival, departure);
            }
                break;

            default:
                cout << "Ese no es un número válido, vuelva a ingresar un número: ";
                cin >> cityNumber;
        }



    }  while (response == "si" || response == "SI");
}
