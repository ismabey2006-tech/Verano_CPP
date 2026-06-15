#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;

public:
    Animal(string n) : nombre(n) {}
    virtual ~Animal() {}

    string getNombre() const { return nombre; }

    virtual void hacerSonido() const {
        cout << "..." << endl;
    }

    virtual void imprimir() const {
        cout << nombre << endl;
    }
};

class Perro : public Animal {
private:
    string raza;

public:
    Perro(string n, string r) : Animal(n), raza(r) {}

    void hacerSonido() const override {
        cout << nombre << " (" << raza << ") dice: Guau!" << endl;
    }

    void imprimir() const override {
        cout << nombre << " - Raza: " << raza << endl;
    }
};

class Gato : public Animal {
private:
    bool esCallejero;

public:
    Gato(string n, bool c) : Animal(n), esCallejero(c) {}

    void hacerSonido() const override {
        cout << nombre << " (Callejero: " << (esCallejero ? "Si" : "No") << ") dice: Miau!" << endl;
    }

    void imprimir() const override {
        cout << nombre << " - Callejero: " << (esCallejero ? "Si" : "No") << endl;
    }
};

int main() {
    Perro p("Rex", "Labrador");
    Gato g("Luna", false);
    p.hacerSonido();
    p.imprimir();
    g.hacerSonido();
    g.imprimir();
    return 0;
}
