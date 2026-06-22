#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    double salario;

public:
    Empleado(string n, double s) : nombre(n), salario(s >= 0 ? s : 0) {}
    string getNombre() const { return nombre; }
    double getSalario() const { return salario; }
    virtual double calcularBono() const = 0;
    virtual string getTipo() const = 0;
    void imprimir() const {
        cout << fixed << setprecision(2);
        cout << nombre << " | " << getTipo() << " | $" << salario
             << " | Bono: $" << calcularBono() << endl;
    }
    virtual ~Empleado() {}
};

class Programador : public Empleado {
public:
    Programador(string n, double s) : Empleado(n, s) {}
    double calcularBono() const override { return salario * 0.10; }
    string getTipo() const override { return "Programador"; }
};

class Gerente : public Empleado {
public:
    Gerente(string n, double s) : Empleado(n, s) {}
    double calcularBono() const override { return salario * 0.20; }
    string getTipo() const override { return "Gerente"; }
};

class Director : public Empleado {
public:
    Director(string n, double s) : Empleado(n, s) {}
    double calcularBono() const override { return salario * 0.30; }
    string getTipo() const override { return "Director"; }
};

int main() {
    Empleado* empleados[4] = {
        new Programador("Ana", 3000.0),
        new Gerente("Luis", 5000.0),
        new Director("Carla", 8000.0),
        new Programador("Pedro", 2800.0)
    };

    double totalBonos = 0;
    for (int i = 0; i < 4; i++) {
        empleados[i]->imprimir();
        totalBonos += empleados[i]->calcularBono();
    }

    cout << fixed << setprecision(2);
    cout << "Total bonos: $" << totalBonos << endl;

    for (int i = 0; i < 4; i++) {
        delete empleados[i];
        empleados[i] = nullptr;
    }

    return 0;
}
