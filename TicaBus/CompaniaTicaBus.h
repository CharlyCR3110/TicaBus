#include "Bus.h"

class CompaniaTicaBus {
private:
    string nombreCom;
    string telefono;
    Bus** vecB;
    int cantidad;
    int tamano;
public:
    CompaniaTicaBus(string nombreCom = "", string telefono = "", int tamano = 10);
    virtual ~CompaniaTicaBus();
    string getNombreCom();
    string getTelefono();
    Bus** getVecB();
    int getCantidad();
    int getTamano();
    void setNombreCom(string nombreCom);
    void setTelefono(string telefono);
    void agregarBus(Bus* b);
    void eliminarBus(string placa);
    string toString();
    bool registrarAsiento(string placa, Asiento* asiento);
    //saber cuales y cuantos buses tienen mas de la mitad de su capacidad ocupada
    int cantidadBusesConMasDeLaMitadDeSuCapacidadOcupada();
};