#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;

public:
    Vehiculo(string marca) : marca(marca) {}

    virtual void describir() const {
        cout << "Vehiculo marca " << marca << endl;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int puertas;

public:
    Auto(string marca, int puertas) : Vehiculo(marca), puertas(puertas) {}

    void describir() const override {
        cout << "Auto " << marca << " de " << puertas << " puertas" << endl;
    }

    void abrirMaletero() const {
        cout << "Abriendo maletero de " << marca << endl;
    }
};

class Camion : public Vehiculo {
private:
    double toneladas;

public:
    Camion(string marca, double toneladas)
        : Vehiculo(marca), toneladas(toneladas) {}

    void describir() const override {
        cout << "Camion " << marca << " de " << toneladas << " toneladas" << endl;
    }

    void cargarMercancia() const {
        cout << "Cargando mercancia en " << marca << endl;
    }
};

int main() {
    // a) Con Auto* puedo acceder a describir() y abrirMaletero().
    Auto* autoPtr = new Auto("Toyota", 4);
    autoPtr->describir();
    autoPtr->abrirMaletero();

    // b) Upcasting: Auto* -> Vehiculo*.
    Vehiculo* vehiculoPtr = autoPtr;
    vehiculoPtr->describir();  // Conserva polimorfismo porque describir() es virtual.

    // Esto NO compila, porque Vehiculo no declara abrirMaletero():
    // vehiculoPtr->abrirMaletero();
    // Mensaje tipico: 'class Vehiculo' has no member named 'abrirMaletero'

    delete autoPtr;
    autoPtr = nullptr;
    vehiculoPtr = nullptr;

    // c) Arreglo polimorfico.
    Vehiculo* flota[2];
    flota[0] = new Auto("Mazda", 2);
    flota[1] = new Camion("Volvo", 12.5);

    for (int i = 0; i < 2; ++i) {
        flota[i]->describir();
    }

    for (int i = 0; i < 2; ++i) {
        delete flota[i];
        flota[i] = nullptr;
    }

    return 0;
}
