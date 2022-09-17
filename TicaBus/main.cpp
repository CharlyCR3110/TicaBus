#include "CompaniaTicaBus.h"
#include "Menu.h"

int main() {
    cout << "Test" << endl;
    //datos necesarios para el asiento
    string cedula;
    Asiento* asiento;
    //datos necesarios para el bus
    string placaBus, modeloBus, marcaBus;
    double costoDelAsientoBus;
    int tamanoBus;
    Bus* bus;
    //datos necesarios para la compañia
    string nombreCom, telefono;
    int tamanoCom;
    CompaniaTicaBus* compania;
    //variables para el menu
    int opcion;

    do {
        cout << menu();
        cin >> opcion;
		//por si alguien ingresa un caracter no valido
        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
        }
    // ss << "1) Ingresar bus nuevo" << endl;
    // ss << "2) Registrar un asiento de un bus, segun la placa" << endl; //buscar el bus por la placa
    // ss << "3) Mostrar cuantos y cuales buses tienen mas de la mitad de su capacidad maxima" << endl;
    // ss << "4) Mostrar el total recaudado por un bus, segun la placa" << endl; //buscar el bus por la placa
	// ss << "5) Cantidad de asientos ocupado y desocupados, segun la placa" << endl; //buscar el bus por la placa
    // ss << "6) Mostrar una lista de cedulas registradas en un bus, segun la placa" << endl; //buscar el bus por la placa
    // ss << "7) Mostrar el bus que ha recaudado mas dinero" << endl;
    // ss << "8) Mostrar buses descendentemente con base en el modelo" << endl;
    // ss << "9) Salir" << endl;
    // ss << "Ingrese una opcion: ";
        switch (opcion) {
        case 1:
            cout << "Ingrese la placa del bus: ";
            cin >> placaBus;
            cout << "Ingrese el modelo del bus: ";
            cin >> modeloBus;
            cout << "Ingrese la marca del bus: ";
            cin >> marcaBus;
            cout << "Ingrese el costo del asiento del bus: ";
            cin >> costoDelAsientoBus;
            cout << "Ingrese el tamano del bus: ";
            cin >> tamanoBus;
            bus = new Bus(placaBus, modeloBus, marcaBus, costoDelAsientoBus, tamanoBus);
            compania->agregarBus(bus);
            break;
        case 2:
            cout << "Ingrese la placa del bus: ";
            cin >> placaBus;
            cout << "Ingrese la cedula del pasajero: ";
            cin >> cedula;
            asiento = new Asiento(cedula);
            compania->registrarAsiento(placaBus, asiento);
            break;
        case 3:
            cout << "Cantidad de buses con la mitad o mas de los asientos ocupados: " 
            << compania->cantidadBusesConLaMitadOMasDeLaMitadDeSuCapacidadOcupada() << endl;
            cout << "Buses con la mitad o mas de los asientos ocupados: " << 
            compania->busesConLaMitadOMasDeLaMitadDeSuCapacidadOcupada() << endl;
            break;
        case 4:
            cout << "Ingrese la placa del bus: ";
            cin >> placaBus;
            cout << "Total recaudado por el bus placa: " << placaBus << " " << compania->totalRecaudadoPorUnBus(placaBus) << endl;
            break;
        default:
            break;
        }
        system("cls");
    } while (opcion != 9);

    return 0;
}
    // CompaniaTicaBus* compania = new CompaniaTicaBus("TicaBus", "2222-2222", 10);
    // Bus* bus1 = new Bus("AAA-111", "2015", "Toyota", 1000, 10);
    // Bus* bus2 = new Bus("BBB-222", "2016", "Mazda", 2000, 10);
    // Bus* bus3 = new Bus("CCC-333", "2017", "Nissan", 3000, 10);

    // compania->agregarBus(bus1);
    // compania->agregarBus(bus2);
    // compania->agregarBus(bus3);