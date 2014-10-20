#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "Fecha.h"
#include "Itinerario"

class Usuario
{
private:
//Attributes.
	string sNombre, sUserName, sPassword;
	int iEdad, iIDUsuario;
	Itinerario itAgenda;
	Fecha fLlegada, fRegreso;
public:
//Constructor.
	Usuario();
	Usuario(string sNombre, string sUserName, string sPassword, int iEdad);
//Modif.
	void setNombre(string sNombre);
	void setUserName(string sUserName);
	void setPassword(string sPassword);
	void setEdad(int iEdad);
	void setIDUsuario(int iIDUsuario);
	void setAgenda(Itinerario itAgenda);
	void setLlegada(Fecha fLlegada);
	void setRegreso(Fecha fRegreso);
//Access.
	string getNombre();
	string getUserName();
	string getPassword();
	int getEdad();
	int getIDUsuario();
	Itinerario getAgenda();
	Fecha getLlegada();
	Fecha getRegreso();
};
Usuario::Usuario()
{
	sNombre="";
	sUserName="";
	sPassword="";
	iEdad=0;
	iIDUsuario=0;
}
Usuario::Usuario(string sNombre, string sUserName, string sPassword, int iEdad)
{
	this->sNombre=sNombre;
	this->sUserName=sUserName;
	this->sPassword=sPassword;
	this->iEdad=iEdad;
}
void Usuario::setNombre(string sNombre)
{
	this->sNombre=sNombre;
}
void Usuario::setUserName(string sUserName)
{
	this->sUserName=sUserName;
}
void Usuario::setPassword(string sPassword)
{
	this->sPassword=sPassword;
}
void Usuario::setEdad(int iEdad)
{
	this->iEdad=iEdad;
}
void Usuario::setIDUsuario(int iIDUsuario)
{
	this->iIDUsuario=iIDUsuario;
}
void Usuario::setAgenda(Itinerario itAgenda)
{
	this->itAgenda=itAgenda;
}
void Usuario::setLlegada(Fecha fLlegada)
{
	this->fLlegada=fLlegada;
}
void Usuario::setRegreso(Fecha fRegreso)
{
	this->fRegreso=fRegreso;
}
string Usuario::getNombre()
{
	return sNombre;
}
string Usuario::getUserName()
{
	return sUserName;
}
string Usuario::getPassword()
{
	return sPassword;
}
int Usuario::getEdad()
{
	return iEdad;
}
int Usuario::getIDUsuario()
{
	return iIDUsuario;
}
Itinerario Usuario::getAgenda()
{
	return itAgenda;
}
Fecha Usuario::getLlegada()
{
	return fLlegada;
}
Fecha Usuario::getRegreso()
{
	return fRegreso;
}
#endif // USUARIO_H_INCLUDED