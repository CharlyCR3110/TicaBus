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
    int cantidadBusesConLaMitadOMasDeLaMitadDeSuCapacidadOcupada();
    string busesConLaMitadOMasDeLaMitadDeSuCapacidadOcupada();
    double totalRecaudadoPorUnBus(string placa);
    bool existeElBus(string placa);
    int cantidadDeAsientosOcupados(string placa);
    int cantidadDeAsientosLibres(string placa);
    string mostrarTodasLasCedulasDeUnBus(string placa);
    Bus* busQueHaRecaudadoMasDinero();
    string mostrarBusesDescendentementeConBaseEnElModelo();
};