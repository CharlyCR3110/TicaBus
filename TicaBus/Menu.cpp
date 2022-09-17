#include "Menu.h"
string menu() {
    system("cls");
    stringstream ss;
    ss << endl;
    ss << "Menu: " << endl;
    ss << "1) Ingresar bus nuevo" << endl;
    ss << "2) Registrar un asiento de un bus, segun la placa" << endl; //buscar el bus por la placa
    ss << "3) Mostrar cuantos y cuales buses tienen mas de la mitad de su capacidad maxima" << endl;
    ss << "4) Mostrar el total recaudado por un bus, segun la placa" << endl; //buscar el bus por la placa
	ss << "5) Cantidad de asientos ocupado y desocupados, segun la placa" << endl; //buscar el bus por la placa
    ss << "6) Mostrar una lista de cedulas registradas en un bus, segun la placa" << endl; //buscar el bus por la placa
    ss << "7) Mostrar el bus que ha recaudado mas dinero" << endl;
    ss << "8) Mostrar buses descendentemente con base en el modelo" << endl;
    ss << "9) Salir" << endl;
    ss << "Ingrese una opcion: ";
    return ss.str();
}