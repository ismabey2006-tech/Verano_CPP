#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;

public:
    Empleado(string n) : nombre(n) {}
    virtual double calcularSalarioMensual() const = 0;
    virtual double calcularImpuesto() const = 0;
    virtual string getTipo() const = 0;
    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << nombre << " | " << getTipo()
             << " | Bruto: $" << calcularSalarioMensual()
             << " | Impuesto: $" << calcularImpuesto()
             << " | Neto: $" << calcularSalarioMensual() - calcularImpuesto() << endl;
    }
    virtual ~Empleado() {}
};

class EmpleadoFijo : public Empleado {
private:
    double salarioMensual;

public:
    EmpleadoFijo(string n, double s) : Empleado(n), salarioMensual(s >= 0 ? s : 0) {}
    double calcularSalarioMensual() const override { return salarioMensual; }
    double calcularImpuesto() const override { return salarioMensual * (salarioMensual > 2000 ? 0.15 : 0.10); }
    string getTipo() const override { return "Fijo"; }
};

class EmpleadoHora : public Empleado {
private:
    double horasSemanales;
    double tarifaHora;

public:
    EmpleadoHora(string n, double h, double t) : Empleado(n), horasSemanales(h), tarifaHora(t) {}
    double calcularSalarioMensual() const override { return horasSemanales * tarifaHora * 4; }
    double calcularImpuesto() const override { return calcularSalarioMensual() * 0.08; }
    string getTipo() const override { return "Por hora"; }
};

class EmpleadoComision : public Empleado {
private:
    double salarioBase;
    double ventas;
    double pctComision;

public:
    EmpleadoComision(string n, double sb, double v, double pct) : Empleado(n), salarioBase(sb), ventas(v), pctComision(pct) {}
    double calcularSalarioMensual() const override { return salarioBase + ventas * pctComision; }
    double calcularImpuesto() const override { return calcularSalarioMensual() * 0.12; }
    string getTipo() const override { return "Comision"; }
};

class Nomina {
private:
    Empleado* lista[50];
    int cantidad;

public:
    Nomina() : cantidad(0) { for (int i=0;i<50;i++) lista[i]=nullptr; }
    void agregar(Empleado* e) { if (e && cantidad < 50) lista[cantidad++] = e; }
    double totalBruto() const { double t=0; for(int i=0;i<cantidad;i++) t += lista[i]->calcularSalarioMensual(); return t; }
    double totalImpuesto() const { double t=0; for(int i=0;i<cantidad;i++) t += lista[i]->calcularImpuesto(); return t; }
    double totalNeto() const { return totalBruto() - totalImpuesto(); }
    void imprimirNomina() const {
        cout << "=== NOMINA ===" << endl;
        for(int i=0;i<cantidad;i++) lista[i]->imprimir();
        cout << fixed << setprecision(2);
        cout << "Total bruto: $" << totalBruto() << endl;
        cout << "Total impuesto: $" << totalImpuesto() << endl;
        cout << "Total neto: $" << totalNeto() << endl;
    }
    ~Nomina() { for(int i=0;i<cantidad;i++){ delete lista[i]; lista[i]=nullptr; } }
};

int main() {
    Nomina n;
    n.agregar(new EmpleadoFijo("Ana", 2500));
    n.agregar(new EmpleadoFijo("Luis", 1500));
    n.agregar(new EmpleadoHora("Carla", 30, 12));
    n.agregar(new EmpleadoComision("Pedro", 1000, 10000, 0.05));
    n.imprimirNomina();
    return 0;
}
