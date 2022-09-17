#include "Bus.h"

Bus::Bus(string placa, string modelo, string marca, double costoDelAsiento, int tamano)
{
	this->placa = placa;
	this->modelo = modelo;
	this->marca = marca;
	this->costoDelAsiento = costoDelAsiento;
	this->tamano = tamano;
	vecA = new Asiento*[tamano];
	cantidad = 0;
	for (int i = 0; i < tamano; i++) {
		vecA[i] = NULL;
	}
}

Bus::~Bus()
{
	for (int i = 0; i < tamano; i++) {
		if (vecA[i] != NULL) {
			delete vecA[i];
		}
	}
	delete[] vecA;
}

string Bus::getPlaca()
{
	return placa;
}

string Bus::getModelo()
{
	return modelo;
}

string Bus::getMarca()
{
	return marca;
}

double Bus::getCostoDelAsiento()
{
	return costoDelAsiento;
}

int Bus::getCantidad()
{
	return cantidad;
}

int Bus::getTamano()
{
	return tamano;
}

void Bus::setPlaca(string placa)
{
	this->placa = placa;
}

void Bus::setModelo(string modelo)
{
	this->modelo = modelo;
}

void Bus::setMarca(string marca)
{
	this->marca = marca;
}

void Bus::setCostoDelAsiento(double costoDelAsiento)
{
	this->costoDelAsiento = costoDelAsiento;
}

string Bus::toString()
{
	stringstream ss;
	ss << "Placa: " << placa << endl;
	ss << "Modelo: " << modelo << endl;
	ss << "Marca: " << marca << endl;
	ss << "Costo del asiento: " << costoDelAsiento << endl;
	ss << "Cantidad de asientos: " << cantidad << endl;
	ss << "Tamano del arreglo: " << tamano << endl;
	ss << "Asientos: " << endl;
	for (int i = 0; i < cantidad; i++) {
		ss << vecA[i]->toString() << endl;
	}
	return ss.str();
}

bool Bus::registrarAsiento(Asiento* asiento)
{
	if (cantidad < tamano) {
		vecA[cantidad] = asiento;
		cantidad++;
		return true;
	}
	return false;
}