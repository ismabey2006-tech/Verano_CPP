#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    double salario;

public:
    Empleado(string nombre, double salario)
        : nombre(nombre), salario(salario) {}

    string getNombre() const {
        return nombre;
    }

    virtual string tipo() const = 0;
    virtual double calcularPago() const = 0;
    virtual ~Empleado() {}
};

class EmpleadoTC : public Empleado {
public:
    EmpleadoTC(string nombre, double salarioMensual)
        : Empleado(nombre, salarioMensual) {}

    string tipo() const override {
        return "TC";
    }

    double calcularPago() const override {
        return salario;
    }
};

class EmpleadoFL : public Empleado {
private:
    double horas;
    double tarifa;

public:
    EmpleadoFL(string nombre, double horas, double tarifa)
        : Empleado(nombre, 0.0), horas(horas), tarifa(tarifa) {}

    string tipo() const override {
        return "FL";
    }

    double calcularPago() const override {
        return horas * tarifa;
    }
};

void mostrarPago(Empleado* e) {
    if (e == nullptr) return;
    cout << e->getNombre() << " [" << e->tipo() << "]: $"
         << fixed << setprecision(2) << e->calcularPago() << endl;
}

int main() {
    Empleado* e1 = new EmpleadoTC("Ana", 3500.0);
    Empleado* e2 = new EmpleadoFL("Luis", 80.0, 15.0);

    mostrarPago(e1);
    mostrarPago(e2);

    delete e1;
    delete e2;
    e1 = nullptr;
    e2 = nullptr;

    return 0;
}
