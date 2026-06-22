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
    virtual double calcularBono() const { return 0.0; }
    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << nombre << ": $" << salario << " | Bono: $" << calcularBono() << endl;
    }
    virtual ~Empleado() {}
};

class Programador : public Empleado {
private:
    string lenguaje;

public:
    Programador(string n, double s, string l) : Empleado(n, s), lenguaje(l) {}
    double calcularBono() const override { return salario * 0.10; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << nombre << " (Programador/" << lenguaje << "): $" << salario
             << " | Bono: $" << calcularBono() << endl;
    }
};

class Gerente : public Empleado {
protected:
    string departamento;

public:
    Gerente(string n, double s, string d) : Empleado(n, s), departamento(d) {}
    double calcularBono() const override { return salario * 0.20; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << nombre << " (Gerente/" << departamento << "): $" << salario
             << " | Bono: $" << calcularBono() << endl;
    }
};

class Director : public Gerente {
private:
    double presupuesto;

public:
    Director(string n, double s, string d, double p) : Gerente(n, s, d), presupuesto(p) {}
    double calcularBono() const override { return salario * 0.30; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        cout << nombre << " (Directora): $" << salario
             << " | Bono: $" << calcularBono()
             << " | Ppto: $" << presupuesto << endl;
    }
};

int main() {
    Programador p("Ana", 3000.0, "Python");
    Gerente g("Luis", 5000.0, "Sistemas");
    Director d("Carla", 8000.0, "Direccion", 500000.0);

    p.imprimir();
    g.imprimir();
    d.imprimir();

    return 0;
}
