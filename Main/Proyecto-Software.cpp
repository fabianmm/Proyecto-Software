#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>//atoi (Converts string to int)
using namespace std;
#include "User.h"

//variables globales
vector<Event>SanFrancisco;
vector<Event>Kyoto;
vector<Event>LasVegas;
vector<Event>London;
vector<Event>Guadalajara;

bool eliminarActividad(Itinerary &itinerario, int travelDays)
{   
    int auxInt;
    string auxString = "";
    cout << "Que actividad deseas eliminar(ej.'KY0103')? ";
    cin >> auxString;

    auxInt = atoi(auxString[4]);

    for (int i = 0; i < itinerario.vDays[auxInt].vEventList.size(); ++i)
    {
        if (itinerario.vDays[auxInt].vEventList[j] === auxString)
        {
            itinerario.vDays[auxInt].vEventList[j].erase();//Erase event from vDays vector.
            return true;
        }
    }
    return false;
}
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
                    break;
            }
            break;
        }
        case 2:
        {
            defaultItinerary.setCity("Kyoto");
            switch (days)
            {
                case 2:
                    archEnt.open("KYTemplate2.txt");
                    break;
                case 3:
                    archEnt.open("KYTemplate3.txt");
                    break;
                case 4:
                    archEnt.open("KYTemplate4.txt");
                    break;
                case 5:
                    archEnt.open("KYTemplate5.txt");
                    break;
            }
            break;
        }
        case 3:
        {
            defaultItinerary.setCity("Las Vegas");
            switch (days)
            {
                case 2:
                    archEnt.open("LVTemplate2.txt");
                    break;
                case 3:
                    archEnt.open("LVTemplate3.txt");
                    break;
                case 4:
                    archEnt.open("LVTemplate4.txt");
                    break;
                case 5:
                    archEnt.open("LVTemplate5.txt");
                    break;
            }
            break;
        }
        case 4:
        {
            defaultItinerary.setCity("London");
            switch (days)
            {
                case 2:
                    archEnt.open("LDTemplate2.txt");
                    break;
                case 3:
                    archEnt.open("LDTemplate3.txt");
                    break;
                case 4:
                    archEnt.open("LDTemplate4.txt");
                    break;
                case 5:
                    archEnt.open("LDTemplate5.txt");
                    break;
            }
            break;
        }
        case 5:
        {
            defaultItinerary.setCity("Guadalajara");
            switch (days)
            {
                case 2:
                    archEnt.open("GDTemplate2.txt");
                    break;
                case 3:
                    archEnt.open("GDTemplate3.txt");
                    break;
                case 4:
                    archEnt.open("GDTemplate4.txt");
                    break;
                case 5:
                    archEnt.open("GDTemplate5.txt");
                    break;
            }
            break;
        }
            
    }
    
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
            archEnt >> auxString;
            defaultItinerary.vDays[i].vEventList[j].setCode(auxString);
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

void load() //carga archivos de actividades en vectores de Event
{
    ifstream archive;
    string auxString;
    int auxInt;
    Event aux;
    
    //carga San Francisco
    archive.open("SanFrancisco.txt");
    while (!archive.eof())
    {
        getline(archive, auxString);
        aux.setName(auxString);
        archive >> auxInt;
        archive >> auxString;
        archive.ignore();
        aux.setTime(auxInt);
        aux.setCode(auxString);
        SanFrancisco.push_back(aux);
    }
    archive.close();
    
    //carga Kyoto
    archive.open("Kyoto.txt");
    while (!archive.eof())
    {
        getline(archive, auxString);
        aux.setName(auxString);
        archive >> auxInt;
        archive >> auxString;
        archive.ignore();
        aux.setTime(auxInt);
        aux.setCode(auxString);
        Kyoto.push_back(aux);
    }
    archive.close();
    
    //carga Las Vegas
    archive.open("LasVegas.txt");
    while (!archive.eof())
    {
        getline(archive, auxString);
        aux.setName(auxString);
        archive >> auxInt;
        archive >> auxString;
        archive.ignore();
        aux.setTime(auxInt);
        aux.setCode(auxString);
        LasVegas.push_back(aux);
    }
    archive.close();
    
    //carga London
    archive.open("London.txt");
    while (!archive.eof())
    {
        getline(archive, auxString);
        aux.setName(auxString);
        archive >> auxInt;
        archive >> auxString;
        archive.ignore();
        aux.setTime(auxInt);
        aux.setCode(auxString);
        London.push_back(aux);
    }
    archive.close();
    
    //carga Las Vegas
    archive.open("Guadalajara.txt");
    while (!archive.eof())
    {
        getline(archive, auxString);
        aux.setName(auxString);
        archive >> auxInt;
        archive >> auxString;
        archive.ignore();
        aux.setTime(auxInt);
        aux.setCode(auxString);
        Guadalajara.push_back(aux);
    }
    archive.close();
    
}

void menuOpciones() //menu de opciones de actividades
{
    cout << "***Menu de Opciones***\n1. Agregar una actividad.\n2. Eliminar una actividad.\n3. Mover una actividad.\n0. Finalizar y enviar itinerario a correo.\nTeclee el número de la opción deseada: ";
}

void printEvents(vector<Event> aux)
{
    cout << "#Lista de actividades#\n";
    cout << "Nombre\t Duración\t Código\n";
    for (int i = 0; i < aux.size(); i++)
    {
        
    }
}

int main(){
    string response;
    int cityNumber, travelDays, option;
    Date arrival, departure;
    Itinerary itinerario;
    
    load(); //cargar archivos de actividades por ciudad en vectores globales de evento
    
    //RF3
    cout << "¿Desea crear un nuevo itinerario (si/no)?\n";
    cin >> response;
    
    do
    {
        //RF4
        cout << "Elija el número de la ciudad a la que desea viajar:\n1. San Francisco\n2. Kyoto\n3. Las Vegas\n4. London\n5. Guadalajara\n";
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
        
        menuOpciones(); //despliega menu de opciones y pide número de opcion
        cin >> option;
        while (option < 0 || option > 3)
        {
            cout << "Ese no es un número válido, por favor ingrese otra vez: ";
            cin >> option;
        }
        while (option != 0) //mientras no desee finalizar, se haran modificaciones
        {
            switch (option)
            {
                case 1: //agregar una actividad
                {
                    //primero se despliegan las actividades de la ciudad
                    
                }
                case 2://Eliminar actividad.
                    eliminarActividad(itinerario, travelDays);
                    break;
                    
            }
        }
        
        
        
        
        
        
        
        
        //Volver a preguntar si se desea crear otro itinerario
        cout << "¿Desea crear un nuevo itinerario (si/no)?\n";
        cin >> response;
        
    }  while (response == "si" || response == "SI" || response == "Si");
    cout << "Adios.\n";
}