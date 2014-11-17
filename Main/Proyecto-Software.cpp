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
    switch (cityNumber)
    {
        case 1:
        {
            defaultItinerary.setCity("San Francisco");
            switch (days)
            {
                case 2:
                    archEnt.open("SFTemplate2.txt");
                    break;
                case 3:
                    archEnt.open("SFTemplate3.txt");
                    break;
                case 4:
                    archEnt.open("SFTemplate4.txt");
                    break;
                case 5:
                    archEnt.open("SFTemplate5.txt");
            }
        }
            
            
            
            
    }
    archEnt.close();
    defaultItinerary.print();
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
        while (cityNumber < 1 || cityNumber > 5)
        {
            cout << "Ese no es un número válido, vuelva a ingresar un número: ";
            cin >> cityNumber;
        }
        //RF5 & RF6
        cout << "Ingrese la cantidad de días a viajar (entre 2 y 4): ";
        cin >> travelDays;
        while (travelDays < 2 || travelDays > 5)
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
        
        //imprime y guarda el itinerario default
        itinerario = defaultTemplate(cityNumber, travelDays, arrival, departure);
        
        
        
        
    }  while (response == "si" || response == "SI");
}