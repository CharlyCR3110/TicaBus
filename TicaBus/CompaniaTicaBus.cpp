#include "CompaniaTicaBus.h"

CompaniaTicaBus::CompaniaTicaBus(string nombreCom, string telefono, int tamano)
{
	this->nombreCom = nombreCom;
	this->telefono = telefono;
	this->tamano = tamano;
	vecB = new Bus*[tamano];
	cantidad = 0;
	for (int i = 0; i < tamano; i++) {
		vecB[i] = NULL;
	}
}

CompaniaTicaBus::~CompaniaTicaBus()
{
	for (int i = 0; i < tamano; i++) {
		if (vecB[i] != NULL) {
			delete vecB[i];
		}
	}
	delete[] vecB;
}

string CompaniaTicaBus::getNombreCom()
{
	return nombreCom;
}

string CompaniaTicaBus::getTelefono()
{
	return telefono;
}

Bus** CompaniaTicaBus::getVecB()
{
	return vecB;
}

int CompaniaTicaBus::getCantidad()
{
	return cantidad;
}

int CompaniaTicaBus::getTamano()
{
	return tamano;
}

void CompaniaTicaBus::setNombreCom(string nombreCom)
{
	this->nombreCom = nombreCom;
}

void CompaniaTicaBus::setTelefono(string telefono)
{
	this->telefono = telefono;
}

void CompaniaTicaBus::agregarBus(Bus* b)
{
	if (cantidad < tamano) {
		vecB[cantidad] = b;
		cantidad++;
	}
}

void CompaniaTicaBus::eliminarBus(string placa)
{
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getPlaca() == placa) {
			delete vecB[i];
			vecB[i] = vecB[cantidad - 1];
			vecB[cantidad - 1] = NULL;
			cantidad--;
			break;
		}
	}
}

string CompaniaTicaBus::toString()
{
	stringstream ss;
	ss << "Nombre de la compania: " << nombreCom << endl;
	ss << "Telefono: " << telefono << endl;
	ss << "Cantidad de buses: " << cantidad << endl;
	ss << "Tamano del arreglo: " << tamano << endl << endl;
	ss << " Buses: " << endl;
	for (int i = 0; i < cantidad; i++) {
		ss << vecB[i]->toString() << endl;
	}
	return ss.str();
}
