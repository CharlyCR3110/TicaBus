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