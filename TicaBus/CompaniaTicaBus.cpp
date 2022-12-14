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
	ss << "Buses: " << endl;
	for (int i = 0; i < cantidad; i++) {
		ss << vecB[i]->toString() << endl;
	}
	return ss.str();
}

bool CompaniaTicaBus::registrarAsiento(string placa, Asiento* asiento)
{
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getPlaca() == placa) {
			return vecB[i]->registrarAsiento(asiento);
		}
	}
	return false;
}

int CompaniaTicaBus::cantidadBusesConLaMitadOMasDeLaMitadDeSuCapacidadOcupada()
{
	int contador = 0;
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getCantidad() >= vecB[i]->getTamano() / 2) {
			contador++;
		}
	}
	return contador;
}

string CompaniaTicaBus::busesConLaMitadOMasDeLaMitadDeSuCapacidadOcupada()
{
	stringstream ss;
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getCantidad() >= vecB[i]->getTamano() / 2) {
			ss << "Bus numero" << i << " " << vecB[i]->toString() << endl;
		}
	}
	return ss.str();
}

double CompaniaTicaBus::totalRecaudadoPorUnBus(string placa)
{
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getPlaca() == placa) {
			return vecB[i]->totalRecaudado();
		}
	}
	return 0;
}

bool CompaniaTicaBus::existeElBus(string placa)
{
/* Checking si existe el bus. */
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getPlaca() == placa) {
			return true;
		}
	}
	return false;
}

int CompaniaTicaBus::cantidadDeAsientosOcupados(string placa) 
{
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getPlaca() == placa) {
			return vecB[i]->getCantidad();
		}
	}
	return 0;
}

int CompaniaTicaBus::cantidadDeAsientosLibres(string placa) 
{
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getPlaca() == placa) {
			return vecB[i]->getTamano() - vecB[i]->getCantidad();
		}
	}
	return 0;
}

string CompaniaTicaBus::mostrarTodasLasCedulasDeUnBus(string placa)
{
	for (int i = 0; i < cantidad; i++) {
		if (vecB[i]->getPlaca() == placa) {
			return vecB[i]->mostrarTodasLasCedulas();
		}
	}
	return "";
}

Bus* CompaniaTicaBus::busQueHaRecaudadoMasDinero() {
	Bus* bus = vecB[0];
	/*el for empieza desde 1 porque al inico el bus que ha recaudado mas dinero es el que esta en la posicion 0 */
	for (int i = 1; i < cantidad; i++) {
		if (vecB[i]->totalRecaudado() > bus->totalRecaudado()) {
			bus = vecB[i];
		}
	}
	return bus;
}

string CompaniaTicaBus::mostrarBusesDescendentementeConBaseEnElModelo() {
	stringstream ss;
	Bus* aux;
/* Ordenando el array orden descente con base en el modelo. */
	for (int i = 0; i < cantidad; i++) {
		for (int j = 0; j < cantidad - 1; j++) {
			if (vecB[j]->getModelo() < vecB[j + 1]->getModelo()) {
				aux = vecB[j];
				vecB[j] = vecB[j + 1];
				vecB[j + 1] = aux;
			}
		}
	}
	for (int i = 0; i < cantidad; i++) {
		ss << vecB[i]->toString() << endl;
	}
	return ss.str();
}