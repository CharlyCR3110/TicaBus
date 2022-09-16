#include "Asiento.h"

Asiento::Asiento()
{
	cedula = "";
}

Asiento::Asiento(string cedula)
{
	this->cedula = cedula;
}

Asiento::~Asiento()
{
}

string Asiento::getCedula()
{
	return cedula;
}

void Asiento::setCedula(string cedula)
{
	this->cedula = cedula;
}

string Asiento::toString()
{
	stringstream s;
	s << "Cedula: " << cedula;
	return s.str();
}
