#include "CompaniaTicaBus.h"

int main() {
    cout << "Test" << endl;
    CompaniaTicaBus* compania = new CompaniaTicaBus("TicaBus", "2222-2222", 10);
    Bus* bus1 = new Bus("AAA-111", "2015", "Toyota", 1000, 10);
    Bus* bus2 = new Bus("BBB-222", "2016", "Mazda", 2000, 10);
    Bus* bus3 = new Bus("CCC-333", "2017", "Nissan", 3000, 10);

    compania->agregarBus(bus1);
    compania->agregarBus(bus2);
    compania->agregarBus(bus3);

    cout << compania->toString();
    compania->eliminarBus("AAA-111");

    delete compania;

    return 0;
}