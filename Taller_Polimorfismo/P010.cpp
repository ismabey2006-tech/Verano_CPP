#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;

public:
    Empleado(string nombre) : nombre(nombre) {}

    virtual void trabajar() const {
        cout << nombre << " trabaja." << endl;
    }

    virtual ~Empleado() {}
};

class Programador : public Empleado {
private:
    string lenguaje;

public:
    Programador(string nombre, string lenguaje)
        : Empleado(nombre), lenguaje(lenguaje) {}

    void trabajar() const override {
        cout << nombre << " desarrolla software." << endl;
    }

    void escribirCodigo() const {
        cout << nombre << " escribe codigo en " << lenguaje << endl;
    }
};

class Disenador : public Empleado {
private:
    string herramienta;

public:
    Disenador(string nombre, string herramienta)
        : Empleado(nombre), herramienta(herramienta) {}

    void trabajar() const override {
        cout << nombre << " diseña interfaces." << endl;
    }

    void crearMockup() const {
        cout << nombre << " crea mockup en " << herramienta << endl;
    }
};

class Gerente : public Empleado {
private:
    string departamento;

public:
    Gerente(string nombre, string departamento)
        : Empleado(nombre), departamento(departamento) {}

    void trabajar() const override {
        cout << nombre << " gestiona el departamento de " << departamento << endl;
    }
};

void asignarTarea(Empleado* e) {
    if (e == nullptr) return;

    Programador* p = dynamic_cast<Programador*>(e);
    if (p != nullptr) {
        p->escribirCodigo();
        return;
    }

    Disenador* d = dynamic_cast<Disenador*>(e);
    if (d != nullptr) {
        d->crearMockup();
        return;
    }

    cout << "Tarea generica." << endl;
}

int main() {
    Empleado* equipo[3];
    equipo[0] = new Programador("Ana", "C++");
    equipo[1] = new Disenador("Luis", "Figma");
    equipo[2] = new Gerente("Marta", "Tecnologia");

    for (int i = 0; i < 3; ++i) {
        asignarTarea(equipo[i]);
    }

    for (int i = 0; i < 3; ++i) {
        delete equipo[i];
        equipo[i] = nullptr;
    }

    return 0;
}
