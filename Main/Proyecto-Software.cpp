#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>//stoi (Converts string to int)
using namespace std;
#include "User.h"

//variables globales
vector<Event>SanFrancisco;
vector<Event>Kyoto;
vector<Event>LasVegas;
vector<Event>London;
vector<Event>Guadalajara;
vector<User>Usuarios;


bool eliminarActividad(Itinerary &itinerario)
{
    int auxInt;
    string auxString = "";
    cout << "Que actividad deseas eliminar(ej.'KY0103')? ";
    cin >> auxString;
    
    string auxS = auxString.substr(5, 1);//Stores the Day number in a string var.
    auxInt = atoi(auxS.c_str());
    
    for (int i = 0; i < itinerario.vDays[auxInt - 1].vEventList.size(); ++i)
    {
        //      cout << "TRACE 7." << endl;
        //      cout << "=====" << itinerario.vDays[auxInt - 1].vEventList[i].getCode() << "======";
        
        if (itinerario.vDays[auxInt - 1].vEventList[i].getCode() == auxString)
        {
//           cout << "TRACE 6.";
            itinerario.vDays[auxInt - 1].vEventList.erase(itinerario.vDays[auxInt - 1].vEventList.begin() + i);//Erase event from vDays vector.//Not working???
//            itinerario.print();
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
    defaultItinerary.vDays.resize(days);
    Hour auxHour;
    int auxInt;
    string auxString;
    switch (cityNumber)
    {
        case 1:
        {
            defaultItinerary.setName("Viaje a San Francisco");
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
            defaultItinerary.setName("Viaje a Kyoto");
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
            defaultItinerary.setName("Viaje a Las Vegas");
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
            defaultItinerary.setName("Viaje a Londres");
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
            defaultItinerary.setName("Viaje a Guadalajara");
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
    User auxUser;
    //cout << "Trace 000:";
    //carga San Francisco
    archive.open("SF.txt");
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
        //cout << "Trace 0:";
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
        //cout << "Trace 1:";
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
        //cout << "Trace 2:";
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
        //cout << "Trace 3:";
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
        // cout << "Trace 4:";
    }
    archive.close();
    
    //carga Usuarios
    archive.open("Usuarios.txt");
    while (! archive.eof())
    {
        getline(archive,auxString);
        auxUser.setEmail(auxString);
        getline(archive, auxString);
        auxUser.setPassword(auxString);
        getline(archive, auxString);
        auxUser.setName(auxString);
        Usuarios.push_back(auxUser);
        archive.ignore();
    }
    
    archive.close();
    
}

void menuOpciones() //menu de opciones de actividades
{
    cout << "***Menu de Opciones***\n1. Agregar una actividad.\n2. Eliminar una actividad.\n3. Mover una actividad.\n0. Finalizar y enviar itinerario a correo.\nTeclee el número de la opción deseada: ";
}

void menuSistema() //menu del sistema
{
    //cout<<"BIENVENIDO!"<<endl;
    cout<<"1. LOG IN"<<endl;
    cout<<"2. SIGN UP"<<endl;
    //cout<<"3. LOG OUT"<<endl;
    cout<<"0. Salir"<<endl;
    cout << "Teclee el número de la opción deseada: ";
}
void printEvents(vector<Event> aux)
{
    cout << "#Lista de actividades#\n";
    cout << "Nombre\t Duración\t Código\n";
    for (int i = 0; i < aux.size(); i++)
    {
        
    }
}

//Verificar LOG IN
bool idVer(string mail, string pass, int &iD)
{
    for (int i = 0; i < Usuarios.size(); i++)
    {
        if (Usuarios[i].getEmail() == mail)
        {
            if (Usuarios[i].getPassword() == pass)
            {
                iD = i;
                return true;
            }
        }
    }
    return false;
}
//Verificacion de disponibilidad de Usuario en Sing Up
bool verUsuario(string mail)
{
    for (int i = 0; i < Usuarios.size(); i++)
    {
        if (Usuarios[i].getEmail() == mail)
        {
            return false;
        }
        
    }
    return true;
}

User signIn(){ //LOGIN
    string sId, sPass;
    bool existe = false;
    int iD;
    do {
        cout<<"Username: ";
        cin>>sId;
        cout<<"Password: ";
        cin>>sPass;
        //Verificacion de id y contrasena
        existe = idVer(sId,sPass,iD);
        if (existe==true) {
            cout<<"Bienvenido "<<Usuarios[iD].getName()<<endl;
        }
        else
        {cout<<"Error, favor de ingresar nuevamente los datos."<<endl;}
    }while(existe!=true);
    
    return Usuarios[iD];
}

void signUp(){
    //SIGN UP
    //Verificacion que no exista el ususario
    string sId, sPass, sNombre, vPass;
    bool existeid = false;
    cout<<"Ingrese su Mail(nombre de usuario): ";
    cin>>sId;
    existeid=verUsuario(sId);
    while (!existeid)
    {
        cout<<"Ese usuario ya existe, ingrese otro correo:"<<endl;
        cin >> sId;
        existeid=verUsuario(sId);
    }
    
    cout<<"Ingrese su nombre completo: ";
    cin>>sNombre;
    
    //Verificacion de igualdad de contrasenas
    do{
        //Verificacion de longitud de contrasena
        do{
            cout<<"Ingrese su contraseña(Igual o mayor a 6 caracteres): ";
            cin>>sPass;
            if (sPass.length()<6) {
                cout<<"Favor de ingresar nuevamente la contraseña con una longitud de minimo 6 caracteres."<<endl;
            }
        }while(sPass.length()<6);
        cout<<"Ingrese de nuevo su contraseña: ";
        cin>>vPass;
        if (sPass != vPass)
        {
            cout<<"Error, favor de ingresar nuevamente su contraseña."<<endl;
        }
        
    }while (sPass != vPass);
    User auxUser(sNombre, sId, sPass);
    Usuarios.push_back(auxUser);
}


//Actualiza archivo de usuarios al finalizar la sesion
void pushUsers(vector<User> Usuarios)
{
    ofstream archive;
    archive.open("Usuarios.txt");
    for (int i = 0; i<Usuarios.size(); i++)
    {
        archive << Usuarios[i].getEmail() << endl;
        archive << Usuarios[i].getPassword() << endl;
        archive << Usuarios[i].getName() << endl;
    }
    archive.close();
}

// ============================================================================
//                                  MAIN
int main(){
    Usuarios.resize(0);
    // ===============
    //    VARIABLES
    // ===============
    string response, logOut;
    int cityNumber, travelDays, systemOption, option;
    Date arrival, departure;
    Itinerary itinerario;
    User usuario;
    
    
    
    load(); //cargar archivos de actividades por ciudad en vectores globales de evento
    //cout << Usuarios.size() << endl;
    
    cout<<"BIENVENIDO!"<<endl;
    //######## MENU PRINCIPAL DE SISTEMA ########
    do
    {
        menuSistema();
        cin >> systemOption;
        while (systemOption < 0 || systemOption > 3)
        {
            cout << "Esa no es una opción válida, por favor teclee otro número: ";
            cin >> systemOption;
        }
        
        switch (systemOption)
        {
            case 1: //SIGN IN
            {
                usuario = signIn();
                
                //RF3
                cout << "¿Desea crear un nuevo itinerario (si/no)?\n";
                cin >> response;
                
                while (response == "si" || response == "SI" || response == "Si")
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
                    cout << "Ingrese la cantidad de días a viajar (entre 2 y 5): ";
                    cin >> travelDays;
                    while (travelDays < 2 || travelDays > 5)
                    {
                        cout << "Ese no es un número válido, ingrese un número entre 2 y 5: ";
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
                    
                    do
                    {
                        menuOpciones(); //despliega menu de opciones y pide número de opcion
                        cin >> option;
                        
                        while (option < 0 || option > 3)
                        {
                            cout << "Ese no es un número válido, por favor ingrese otra vez: ";
                            cin >> option;
                        }
                        
                        switch (option)
                        {
                            case 1: //agregar una actividad
                            {
                                //primero se despliegan las actividades de la ciudad
                                break;
                            }
                            case 2://Eliminar actividad.
                            {
                                eliminarActividad(itinerario);
                                break;
                            }
                            case 0:
                            {
                                
                            }
                                
                        }
                    }while (option != 0); //mientras no desee finalizar, se haran modificaciones
                    
                    
                    //Volver a preguntar si se desea crear otro itinerario
                    cout << "¿Desea crear un nuevo itinerario (si/no)?\n";
                    cin >> response;
                    if (!(response == "si" || response == "SI" || response == "Si"))
                    {
                        cout << "¿Desea terminar su sesión? (si/no)?\n";
                        cin >> logOut;
                    }
                    if (logOut == "si" || logOut == "SI" || logOut == "Si")
                    {
                        break;
                    }
                }

                cout << "Adios " << usuario.getName() << endl;
                break;
            }
            case 2: // SIGN UP
            {
                signUp();
                break;
            }
            case 0:
            {
                cout << "Hasta luego.\n";
                pushUsers(Usuarios);
                exit(0);
            }
                
        }
        
        
        
    } while (systemOption != 0);
    
}
