#include "Asiento.h"

class Bus {
private:
    string placa;
    string modelo;
    string marca;
    double costoDelAsiento;
    Asiento** vecA;
    int cantidad;
    int tamano;
public:
    Bus(string placa = "", string modelo = "", string marca = "", double costoDelAsiento = 0, int tamano = 10);
    virtual ~Bus();
    string getPlaca();
    string getModelo();
    string getMarca();
    double getCostoDelAsiento();
    int getCantidad();
    int getTamano();
    void setPlaca(string placa);
    void setModelo(string modelo);
    void setMarca(string marca);
    void setCostoDelAsiento(double costoDelAsiento);
    string toString();
    bool registrarAsiento(Asiento* asiento);
    double totalRecaudado();
    string mostrarTodasLasCedulas();
};