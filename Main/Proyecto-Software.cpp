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
Event findEvent(string auxT, Itinerary &itinerario, int &iPos, int &iPos2)//Return an Event found by "Code".
{
    int auxInt;
    
    string auxS = auxT.substr(5, 1);//Stores the Day number in a string var.
    //auxInt = atoi(auxS.c_str());//For Windows.
    auxInt = stoi(auxT.c_str());//For Mac.
    
    iPos = auxInt - 1;//Position in vDays in which the event is located.
    //cout << "Trace 0001";
    for (int i = 0; i < itinerario.vDays[iPos].vEventList.size(); ++i)//Looks in an specific day given by the code.
    {
        //cout << "Trace 0002";
        if (itinerario.vDays[iPos].vEventList[i].getCode() == auxT)//Looks for the event in the vDays vector.
        {
            //cout << "Trace 0003";
            iPos2 = i;//Position in which the event was found in the vEventList.
            return itinerario.vDays[iPos].vEventList[i];//Returns the Event.
        }
    }
    Event e;
    return e;
}
void moverActividad(Itinerary &itinerario)
{
    Event auxEvent, auxEvent2;
    string auxS, auxS2;
    int iPos, iPos2, auxPos, auxPos2;
    
    cout << "Cual es el codigo de la actividad que desea mover? " << endl;
    cin >> auxS;
    cout << "Por que actividad desea cambiarla(Codigo)? " << endl;
    cin >> auxS2;
    
    auxEvent = findEvent(auxS, itinerario, iPos, iPos2);//Stores the Event 1
    cout << "Trace 0004";
    auxPos = iPos;//Position
    auxPos2 = iPos2;//Position.
    //  auxEvent.print();
    cout << "Trace 0005";
    auxEvent2 = findEvent(auxS2, itinerario, iPos, iPos2);//Stores event 2.
    //  auxEvent2.print();
    
    itinerario.vDays[auxPos].vEventList[auxPos2] = auxEvent2;//Swap. en el 1 queda el 2
    itinerario.vDays[iPos].vEventList[iPos2] = auxEvent;//Swap. en el 2 queda el 1
    
    itinerario.vDays[auxPos].vEventList[auxPos2].setCode(auxS2);
    itinerario.vDays[iPos].vEventList[iPos2].setCode(auxS); //Intercambiar codigos
    
    Hour auxHour = itinerario.vDays[auxPos].vEventList[auxPos2].getStart(); // Hora del 2
    Hour auxHour2 = itinerario.vDays[iPos].vEventList[iPos2].getStart(); //Hora del 1
    
    itinerario.vDays[auxPos].vEventList[auxPos2].setStart(auxHour2);
    itinerario.vDays[auxPos].vEventList[auxPos2].setFinish(auxHour2+auxEvent2.getTime());
    
    itinerario.vDays[iPos].vEventList[iPos2].setStart(auxHour);
    itinerario.vDays[iPos].vEventList[iPos2].setFinish(auxHour+auxEvent.getTime());
    
    //=====================================Verification===================================================
    
    if (!(auxPos2 - 1 < 0) && ((auxPos2 + 1) <= (itinerario.vDays[auxPos].vEventList.size() )))
    {
        if (itinerario.vDays[auxPos].vEventList[auxPos2 - 1].getFinish().hour < itinerario.vDays[auxPos].vEventList[auxPos2].getStart().hour)
        {
            if (itinerario.vDays[auxPos].vEventList[auxPos2 - 1].getFinish().minutes < itinerario.vDays[auxPos].vEventList[auxPos2].getStart().minutes)
            {
                itinerario.vDays[auxPos].vEventList[auxPos2] = auxEvent2;
            }
        }
    }
    if (!(auxPos2 - 1 < 0) && ((iPos2 + 1) <= (itinerario.vDays[iPos].vEventList.size() )))
    {
        if (itinerario.vDays[iPos].vEventList[iPos2 - 1].getFinish().hour < itinerario.vDays[iPos].vEventList[iPos2].getStart().hour)
        {
            if (itinerario.vDays[iPos].vEventList[iPos2 - 1].getFinish().minutes < itinerario.vDays[iPos].vEventList[iPos2].getStart().minutes)
            {
                itinerario.vDays[iPos].vEventList[iPos2] = auxEvent;
            }
        }
    }
    
    itinerario.print();
}
bool eliminarActividad(Itinerary &itinerario)
{
    int auxInt;
    string auxString = "";
    cout << "Que actividad deseas eliminar(ej.'KY0103')? ";
    cin >> auxString;
    
    string auxS = auxString.substr(5, 1);//Stores the Day number in a string var.
    auxInt = stoi(auxS.c_str());
    
    for (int i = 0; i < itinerario.vDays[auxInt - 1].vEventList.size(); ++i)
    {
        //      cout << "TRACE 7." << endl;
        //      cout << "=====" << itinerario.vDays[auxInt - 1].vEventList[i].getCode() << "======";
        
        if (itinerario.vDays[auxInt - 1].vEventList[i].getCode() == auxString)
        {
            //           cout << "TRACE 6.";
            itinerario.vDays[auxInt - 1].vEventList.erase(itinerario.vDays[auxInt - 1].vEventList.begin() + i);//Erase event from vDays vector.//Not working???
            cout << "\n===ITINERARIO ACTUALIZADO===\n";
            itinerario.print();
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
    while (!archive.eof())
    {
        getline(archive,auxString);
        auxUser.setEmail(auxString);
        getline(archive, auxString);
        auxUser.setPassword(auxString);
        getline(archive, auxString);
        auxUser.setName(auxString);
        Usuarios.push_back(auxUser);
        //archive.ignore();
    }
    archive.ignore();
    archive.close();
    
}
void menuOpciones() //menu de opciones de actividades
{
    cout << "***Menu de Opciones***\n1. Agregar una actividad.\n2. Eliminar una actividad.\n3. Intercambiar una actividad.\n0. Finalizar y enviar itinerario a correo.\nTeclee el numero de la opcion deseada: ";
}
void menuSistema() //menu del sistema
{
    //cout<<"BIENVENIDO!"<<endl;
    cout<<"1. LOG IN"<<endl;
    cout<<"2. SIGN UP"<<endl;
    //cout<<"3. LOG OUT"<<endl;
    cout<<"0. Salir"<<endl;
    cout << "Teclee el numero de la opcion deseada: ";
}
void printEvents(vector<Event> aux)
{
    cout << "#Lista de actividades#\n";
    cout << "Nombre\t | Duracion\t | Codigo\n";
    for (int i = 0; i < aux.size(); i++)
    {
        cout << aux[i].getName() << " | " << aux[i].getTime() << " | " << aux[i].getCode() << endl;
    }
}
/*void agregaActividad(Itinerary &itinerario, int cityNumber)
 {
 int auxInt, hrIn, minIn, dia, result;
 string auxString;
 Event elec;
 switch (cityNumber)
 {
 case 1:
 {
 cout << "Actividades disponibles en San Francisco:\n";
 printEvents(SanFrancisco);
 break;
 }
 case 2:
 {
 cout << "Actividades disponibles en Kyoto:\n";
 printEvents(Kyoto);
 break;
 }
 case 3:
 {
 cout << "Actividades disponibles en Las Vegas:\n";
 printEvents(LasVegas);
 break;
 }
 case 4:
 {
 cout << "Actividades disponibles en Londres:\n";
 printEvents(London);
 break;
 }
 case 5:
 {
 cout << "Actividades disponibles en Guadalajara:\n";
 printEvents(Guadalajara);
 break;
 }
 }
 
 
 bool rev=false;
 do
 {
 cout << "Que actividad deseas agregar(ej.'KY0103')? ";
 cin >> auxString;
 for(int i=0; i<SanFrancisco.size();i++)
 {
 if(auxString==SanFrancisco[i].getCode())
 {
 rev=true;
 }
 }
 if(rev==false)
 {
 cout<<"Esa actividad no existe!"<<endl;
 }
 }while(rev!=true);
 
 
 cout << "Que dia desea agregar la actividad? (1, 2, etc.) ";
 cin >> dia;
 
 bool flag = true;
 do
 {
 cout << "A que hora desea realizar la actividad? Separala por un espacio (ej. '9 40') ";
 cin >> hrIn;
 cin >> minIn;
 Hour nuevo;
 nuevo.hour = hrIn;
 nuevo.minutes = minIn;
 result = (hrIn * 60) + minIn;
 
 int j = 0;
 do
 {
 if ((itinerario.vDays[dia-1].vEventList[j].getStart().hour == hrIn && itinerario.vDays[dia-1].vEventList[j].getStart().minutes == minIn) || (nuevo < itinerario.vDays[dia].vEventList[j].getFinish() && nuevo > itinerario.vDays[dia].vEventList[j].getStart()))
 {
 flag == false;
 }
 j++;
 } while(flag == true && j != itinerario.vDays[dia-1].vEventList.size());
 if (flag == false)
 {
 cout << "La actividad se empalma a esa hora, elija otro horario";
 }
 } while (flag == false);
 itinerario.print();
 }*/

void agregaActividad(Itinerary &itinerario, int cityNumber)
{
    int auxInt, hrIn, minIn, dia, result;
    string auxString;
    Event elec;
    bool rev=false;
    Event auxEvento;
    string auxS = "N/A";
    int auxInt2, iPos;
    switch (cityNumber)
    {
        case 1:
        {
            cout << "Actividades disponibles en San Francisco:\n";
            printEvents(SanFrancisco);
            do
            {
                cout << "Que actividad deseas agregar(ej.'KY0103')? ";
                cin >> auxString;
                
                string auxS = auxString.substr(2, 2);//Stores the Day number in a string var.
                auxInt2 = atoi(auxS.c_str());//For Windows.
                //    auxInt2 = stoi(auxT.c_str());//For Mac.
                
                iPos = auxInt2 - 1;//Position in vDays in which the event is located.
                //cout << "Trace 0001";
                for (int i = 0; i < SanFrancisco.size(); ++i)//Looks in an specific day given by the code.
                {
                    //cout << "Trace 0002";
                    if (SanFrancisco[i].getCode() == auxString)//Looks for the event in the vDays vector.
                    {
                        //cout << "Trace 0003";
                        auxEvento = SanFrancisco[i];
                        // auxEvento.print();
                        rev = true;
                    }
                }
                /*
                 for(int i=0; i<SanFrancisco.size();i++)
                 {
                 if(auxString==SanFrancisco[i].getCode())
                 {
                 //auxEvento = findEvent(auxString, itinerario, iPos, iPos2, 2, 2);//Regresa un evento la funcion.
                 //auxEvento.print();
                 rev=true;
                 }
                 }
                 */
                if(rev==false)
                {
                    cout<<"Esa actividad no existe!"<<endl;
                }
            }while(rev!=true);
            break;
        }
        case 2:
        {
            cout << "Actividades disponibles en Kyoto:\n";
            printEvents(Kyoto);
            do
            {
                cout << "Que actividad deseas agregar(ej.'KY0103')? ";
                cin >> auxString;
                
                string auxS = auxString.substr(2, 2);//Stores the Day number in a string var.
                auxInt2 = atoi(auxS.c_str());//For Windows.
                //    auxInt2 = stoi(auxT.c_str());//For Mac.
                
                iPos = auxInt2 - 1;//Position in vDays in which the event is located.
                //cout << "Trace 0001";
                for (int i = 0; i < Kyoto.size(); ++i)//Looks in an specific day given by the code.
                {
                    //cout << "Trace 0002";
                    if (Kyoto[i].getCode() == auxString)//Looks for the event in the vDays vector.
                    {
                        //cout << "Trace 0003";
                        auxEvento = Kyoto[i];
                        // auxEvento.print();
                        rev = true;
                    }
                }
                /*
                 for(int i=0; i<SanFrancisco.size();i++)
                 {
                 if(auxString==SanFrancisco[i].getCode())
                 {
                 //auxEvento = findEvent(auxString, itinerario, iPos, iPos2, 2, 2);//Regresa un evento la funcion.
                 //auxEvento.print();
                 rev=true;
                 }
                 }
                 */
                if(rev==false)
                {
                    cout<<"Esa actividad no existe!"<<endl;
                }
            }while(rev!=true);
            break;
        }
        case 3:
        {
            cout << "Actividades disponibles en Las Vegas:\n";
            printEvents(LasVegas);
            do
            {
                cout << "Que actividad deseas agregar(ej.'KY0103')? ";
                cin >> auxString;
                
                string auxS = auxString.substr(2, 2);//Stores the Day number in a string var.
                auxInt2 = atoi(auxS.c_str());//For Windows.
                //    auxInt2 = stoi(auxT.c_str());//For Mac.
                
                iPos = auxInt2 - 1;//Position in vDays in which the event is located.
                //cout << "Trace 0001";
                for (int i = 0; i < LasVegas.size(); ++i)//Looks in an specific day given by the code.
                {
                    //cout << "Trace 0002";
                    if (LasVegas[i].getCode() == auxString)//Looks for the event in the vDays vector.
                    {
                        //cout << "Trace 0003";
                        auxEvento = LasVegas[i];
                        //auxEvento.print();
                        rev = true;
                    }
                }
                /*
                 for(int i=0; i<SanFrancisco.size();i++)
                 {
                 if(auxString==SanFrancisco[i].getCode())
                 {
                 //auxEvento = findEvent(auxString, itinerario, iPos, iPos2, 2, 2);//Regresa un evento la funcion.
                 //auxEvento.print();
                 rev=true;
                 }
                 }
                 */
                if(rev==false)
                {
                    cout<<"Esa actividad no existe!"<<endl;
                }
            }while(rev!=true);
            break;
        }
        case 4:
        {
            cout << "Actividades disponibles en Londres:\n";
            printEvents(London);
            do
            {
                cout << "Que actividad deseas agregar(ej.'KY0103')? ";
                cin >> auxString;
                
                string auxS = auxString.substr(2, 2);//Stores the Day number in a string var.
                auxInt2 = atoi(auxS.c_str());//For Windows.
                //    auxInt2 = stoi(auxT.c_str());//For Mac.
                
                iPos = auxInt2 - 1;//Position in vDays in which the event is located.
                //cout << "Trace 0001";
                for (int i = 0; i < London.size(); ++i)//Looks in an specific day given by the code.
                {
                    //cout << "Trace 0002";
                    if (London[i].getCode() == auxString)//Looks for the event in the vDays vector.
                    {
                        //cout << "Trace 0003";
                        auxEvento = London[i];
                        //auxEvento.print();
                        rev = true;
                    }
                }
                /*
                 for(int i=0; i<SanFrancisco.size();i++)
                 {
                 if(auxString==SanFrancisco[i].getCode())
                 {
                 //auxEvento = findEvent(auxString, itinerario, iPos, iPos2, 2, 2);//Regresa un evento la funcion.
                 //auxEvento.print();
                 rev=true;
                 }
                 }
                 */
                if(rev==false)
                {
                    cout<<"Esa actividad no existe!"<<endl;
                }
            }while(rev!=true);
            break;
        }
        case 5:
        {
            cout << "Actividades disponibles en Guadalajara:\n";
            printEvents(Guadalajara);
            do
            {
                cout << "Que actividad deseas agregar(ej.'KY0103')? ";
                cin >> auxString;
                
                string auxS = auxString.substr(2, 2);//Stores the Day number in a string var.
                auxInt2 = atoi(auxS.c_str());//For Windows.
                //    auxInt2 = stoi(auxT.c_str());//For Mac.
                
                iPos = auxInt2 - 1;//Position in vDays in which the event is located.
                //cout << "Trace 0001";
                for (int i = 0; i < Guadalajara.size(); ++i)//Looks in an specific day given by the code.
                {
                    //cout << "Trace 0002";
                    if (Guadalajara[i].getCode() == auxString)//Looks for the event in the vDays vector.
                    {
                        //cout << "Trace 0003";
                        auxEvento = Guadalajara[i];
                        //auxEvento.print();
                        rev = true;
                    }
                }
                /*
                 for(int i=0; i<SanFrancisco.size();i++)
                 {
                 if(auxString==SanFrancisco[i].getCode())
                 {
                 //auxEvento = findEvent(auxString, itinerario, iPos, iPos2, 2, 2);//Regresa un evento la funcion.
                 //auxEvento.print();
                 rev=true;
                 }
                 }
                 */
                if(rev==false)
                {
                    cout<<"Esa actividad no existe!"<<endl;
                }
            }while(rev!=true);
            break;
        }
    }
    
    // ESTO SOLO CHECA QUE EL EVENTO EXISTA EN SAN FRANCISCO, HAY QUE METERLO A LOS SWITCHES Y CAMBIAR EL VECTOR, Y FALTA QUE GUARDE EN UNA VARIABLE EVENTO EL EVENTO EN SI
    
    
    
    
    cout << "Que dia desea agregar la actividad? (1, 2, etc.) ";
    cin >> dia;
    auxEvento.print();
    bool flag = true;
    /*
     do
     {
     Hour nuevo;
     int hrIn, minIn;
     
     cout << "A que hora desea realizar la actividad? Separala por un espacio (ej. '9 40') ";
     cin >> hrIn;
     cin >> minIn;
     
     nuevo.hour = hrIn;
     nuevo.minutes = minIn;
     result = (hrIn * 60) + minIn;
     
     int j = 0;
     do
     {
     
     //no entiendo bien aqui
     cout << "Trace 001";
     if (!(j - 1 < 0) && ((j + 1) <= (itinerario.vDays[dia].vEventList.size())))
     {
     cout << "Trace 0004";
     if (itinerario.vDays[dia-1].vEventList[j - 1].getStart().hour < nuevo.hour && nuevo.hour < itinerario.vDays[dia].vEventList[j + 1].getFinish().hour)
     {
     if (itinerario.vDays[dia-1].vEventList[j - 1].getStart().minutes < nuevo.minutes && nuevo.minutes < itinerario.vDays[dia].vEventList[j + 1].getStart().minutes)
     {
     cout << "Trace 002";
     flag == false;
     itinerario.vDays[dia - 1].vEventList.insert(itinerario.vDays[auxInt - 1].vEventList.begin() + j, auxEvento);//ADDS EVENT.
     }
     }
     }
     
     j++;
     
     } while(flag == true && j != itinerario.vDays[dia-1].vEventList.size());
     if (flag == false)
     {
     cout << "Trace 003";
     cout << "La actividad se empalma a esa hora, elija otro horario";
     }
     } while (flag == false);
     
     */
    
    do
    {
        cout << "A que hora desea realizar la actividad? Separala por un espacio (ej. '9 40') ";
        cin >> hrIn;
        cin >> minIn;
        Hour nuevo, nuevoFin;
        nuevo.hour = hrIn;
        nuevo.minutes = minIn;
        result = (hrIn * 60) + minIn;
        nuevoFin = nuevo + auxEvento.getTime();
        
        bool horas[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        
        //arreglo de horas ocupadas del dia a insertar
        for (int i = 0; i < itinerario.vDays[dia-1].vEventList.size(); i++){
            for (int j = 0; j < itinerario.vDays[dia-1].vEventList[i].getTime()/60+1; j++)
            {
                horas[itinerario.vDays[dia-1].vEventList[i].getStart().hour + j] = 1;
            }
        }
        //checar si se empalma el evento
        bool interruptor = false;
        for (int i = nuevo.hour; i <= nuevoFin.hour; i++) //nuevo es la hora a la que empieza el evento, nuevoFin la hora a la que termina
        {
            if (horas[i]){
                interruptor = true;
            }
        }
        vector<Event>::iterator it;
        it = itinerario.vDays[dia-1].vEventList.begin();
        auxEvento.setStart(nuevo);
        auxEvento.setFinish(nuevoFin);
        string code = auxString.substr(0, 5);
        code = code + to_string(dia);
        auxEvento.setCode(code);
        
        if (!interruptor)
        {
            cout << "No se empalma" << endl;
            int i = 0;
            do
            {
                interruptor = false;
                if (nuevo < itinerario.vDays[dia-1].vEventList[i].getStart())
                {
                    itinerario.vDays[dia - 1].vEventList.insert(it+i, auxEvento);
                    interruptor = true;
                }
                i++;
            } while (!interruptor && i < itinerario.vDays[dia-1].vEventList.size());
            if (!interruptor)
            {
                itinerario.vDays[dia - 1].vEventList.push_back(auxEvento);
            }
        }
        else {
            cout << "Si se empalma" << endl;
        }
        /*cout << "trace 001";
         int j = 0;
         do
         {
         cout << "trace 002";
         //no entiendo bien aqui================================================================================
         
         if ( nuevoFin < itinerario.vDays[dia-1].vEventList[j].getStart())
         {
         if (j == 0)
         {
         cout << "trace 003";
         flag = false;
         itinerario.vDays[dia - 1].vEventList.insert(itinerario.vDays[auxInt - 1].vEventList.begin(), auxEvento);
         }
         else
         {
         if (nuevo > itinerario.vDays[dia-1].vEventList[j-1].getFinish())
         {
         cout << "trace 003";
         flag = false;
         itinerario.vDays[dia - 1].vEventList.insert(itinerario.vDays[auxInt - 1].vEventList.begin()+j, auxEvento);
         }
         }
         }
         
         
         /*if ((itinerario.vDays[dia-1].vEventList[j].getStart().hour == hrIn && itinerario.vDays[dia-1].vEventList[j].getStart().minutes == minIn) || (nuevo < itinerario.vDays[dia].vEventList[j].getFinish() && nuevo > itinerario.vDays[dia].vEventList[j].getStart()))
         {
         cout << "trace 003";
         flag = false;
         itinerario.vDays[dia - 1].vEventList.insert(itinerario.vDays[auxInt - 1].vEventList.begin() + j, auxEvento);//ADDS EVENT. //faltaría en insert para el evento
         }
         j++;
         } while(flag == true && j <= itinerario.vDays[dia-1].vEventList.size());
         if (flag == false)
         {
         cout << "La actividad se empalma a esa hora, elija otro horario";
         }*/
    } while (flag == false);
    
    itinerario.print();
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
            cout<<"Ingrese su password(Igual o mayor a 6 caracteres): ";
            cin>>sPass;
            if (sPass.length()<6) {
                cout<<"Favor de ingresar nuevamente la password con una longitud de minimo 6 caracteres."<<endl;
            }
        }while(sPass.length()<6);
        cout<<"Ingrese de nuevo su password: ";
        cin>>vPass;
        if (sPass != vPass)
        {
            cout<<"Error, favor de ingresar nuevamente su password."<<endl;
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
            cout << "Esa no es una opcion valida, por favor teclee otro numero: ";
            cin >> systemOption;
        }
        
        switch (systemOption)
        {
            case 1: //SIGN IN
            {
                usuario = signIn();
                
                //RF3
                cout << "Desea crear un nuevo itinerario (si/no)?\n";
                cin >> response;
                
                while (response == "si" || response == "SI" || response == "Si")
                {
                    //RF4
                    cout << "Elija el numero de la ciudad a la que desea viajar:\n1. San Francisco\n2. Kyoto\n3. Las Vegas\n4. London\n5. Guadalajara\n";
                    cin >> cityNumber;
                    while (cityNumber < 1 || cityNumber > 5)
                    {
                        cout << "Ese no es un numero valido, vuelva a ingresar un numero: ";
                        cin >> cityNumber;
                    }
                    
                    
                    //RF5 & RF6
                    cout << "Ingrese la cantidad de dias a viajar (entre 2 y 5): ";
                    cin >> travelDays;
                    while (travelDays < 2 || travelDays > 5)
                    {
                        cout << "Ese no es un numero valido, ingrese un numero entre 2 y 5: ";
                        cin >> travelDays;
                    }
                    
                    cout << "Ingrese el dia de llegada(dd): ";
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
                            cout << "Ese no es un numero valido, por favor ingrese otra vez: ";
                            cin >> option;
                        }
                        
                        switch (option)
                        {
                            case 1: //agregar una actividad
                            {
                                //primero se despliegan las actividades de la ciudad
                                agregaActividad(itinerario, cityNumber);
                                break;
                            }
                            case 2://Eliminar actividad.
                            {
                                eliminarActividad(itinerario);
                                
                                break;
                            }
                            case 3://Mover una actividad
                            {
                                moverActividad(itinerario);
                                /*Hour auxHour;
                                 int duration;
                                 Event auxEvent;
                                 int dia = 2;
                                 insert(itinerario, auxHour, duration, auxEvent, dia);*/
                                break;
                            }
                                
                            case 0:
                            {
                                cout << "El itinerario " <<  itinerario.getName() << " se enviara al correo " << usuario.getEmail() << endl;
                                cout << "Listo!\n";
                                break;
                            }
                                
                        }
                    }while (option != 0); //mientras no desee finalizar, se haran modificaciones
                    
                    
                    //Volver a preguntar si se desea crear otro itinerario
                    cout << "Desea crear un nuevo itinerario (si/no)?\n";
                    cin >> response;
                    if (!(response == "si" || response == "SI" || response == "Si"))
                    {
                        cout << "Desea terminar su sesion? (si/no)?\n";
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
