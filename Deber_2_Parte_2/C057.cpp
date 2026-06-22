#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Transporte {
protected:
    string origen;
    string destino;
    int capacidadPasajeros;
public:
    Transporte(string o, string d, int c) : origen(o), destino(d), capacidadPasajeros(c) {}
    virtual double calcularTarifa(double distanciaKm) const = 0;
    virtual double tiempoEstimado(double distanciaKm) const = 0;
    virtual string getTipo() const = 0;
    virtual void imprimir() const {
        cout << getTipo() << " | " << origen << " -> " << destino
             << " | Capacidad: " << capacidadPasajeros << endl;
    }
    virtual ~Transporte() {}
};

class TransporteTerrestre : public Transporte {
protected:
    double velocidadPromedio;
    double costoPorKm;
public:
    TransporteTerrestre(string o, string d, int c, double v, double costo) : Transporte(o,d,c), velocidadPromedio(v), costoPorKm(costo) {}
    double tiempoEstimado(double distanciaKm) const override { return distanciaKm / velocidadPromedio; }
};

class TransporteAereo : public Transporte {
protected:
    double costoBase;
    double tasaAeropuerto;
public:
    TransporteAereo(string o, string d, int c, double base, double tasa) : Transporte(o,d,c), costoBase(base), tasaAeropuerto(tasa) {}
};

class Bus : public TransporteTerrestre {
public:
    Bus(string o, string d) : TransporteTerrestre(o,d,40,60,0.20) {}
    double calcularTarifa(double km) const override { return km * costoPorKm; }
    string getTipo() const override { return "Bus"; }
};

class Taxi : public TransporteTerrestre {
public:
    Taxi(string o, string d) : TransporteTerrestre(o,d,4,45,0.80) {}
    double calcularTarifa(double km) const override { return 2.0 + km * costoPorKm; }
    string getTipo() const override { return "Taxi"; }
};

class Avion : public TransporteAereo {
public:
    Avion(string o, string d) : TransporteAereo(o,d,180,80,35) {}
    double calcularTarifa(double km) const override { return costoBase + tasaAeropuerto + km * 0.12; }
    double tiempoEstimado(double km) const override { return km / 750.0; }
    string getTipo() const override { return "Avion"; }
};

class Helicoptero : public TransporteAereo {
public:
    Helicoptero(string o, string d) : TransporteAereo(o,d,6,250,50) {}
    double calcularTarifa(double km) const override { return costoBase + tasaAeropuerto + km * 3.0; }
    double tiempoEstimado(double km) const override { return km / 220.0; }
    string getTipo() const override { return "Helicoptero"; }
};

class Reserva {
private:
    Transporte* transporte;
    string pasajero;
    string fecha;
    double distancia;
public:
    Reserva(Transporte* t, string p, string f, double d) : transporte(t), pasajero(p), fecha(f), distancia(d) {}
    double calcularCosto() const { return transporte ? transporte->calcularTarifa(distancia) : 0; }
    void imprimir() const {
        cout << fixed << setprecision(2);
        cout << pasajero << " | " << fecha << " | ";
        if(transporte) {
            cout << transporte->getTipo() << " | Costo: $" << calcularCosto()
                 << " | Tiempo: " << transporte->tiempoEstimado(distancia) << " h" << endl;
        }
    }
};

class GestorReservas {
private:
    Reserva* reservas[100];
    int cantidad;
public:
    GestorReservas() : cantidad(0) { for(int i=0;i<100;i++) reservas[i]=nullptr; }
    void agregar(Reserva* r) { if(r && cantidad < 100) reservas[cantidad++] = r; }
    void listar() const { cout << "=== Reservas ===" << endl; for(int i=0;i<cantidad;i++) reservas[i]->imprimir(); }
    ~GestorReservas() { for(int i=0;i<cantidad;i++){ delete reservas[i]; reservas[i]=nullptr; } }
};

int main() {
    Transporte* bus = new Bus("Quito", "Otavalo");
    Transporte* taxi = new Taxi("Centro", "Aeropuerto");
    Transporte* avion = new Avion("Quito", "Guayaquil");
    Transporte* heli = new Helicoptero("Quito", "Mindo");

    GestorReservas g;
    g.agregar(new Reserva(bus, "Ana", "2026-07-01", 95));
    g.agregar(new Reserva(taxi, "Luis", "2026-07-02", 40));
    g.agregar(new Reserva(avion, "Carla", "2026-07-03", 280));
    g.agregar(new Reserva(heli, "Pedro", "2026-07-04", 75));
    g.listar();

    delete bus; delete taxi; delete avion; delete heli;
    return 0;
}
