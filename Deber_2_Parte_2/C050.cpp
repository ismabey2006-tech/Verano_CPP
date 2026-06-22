#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int anio;

public:
    Vehiculo(string ma, string mo, int a) : marca(ma), modelo(mo), anio(a) {}
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getAnio() const { return anio; }
    virtual double calcularCosto() const = 0;
    virtual string getTipo() const = 0;
    void imprimir() const {
        cout << fixed << setprecision(2);
        cout << getTipo() << " | " << marca << " " << modelo << " (" << anio
             << ") | Costo: $" << calcularCosto() << endl;
    }
    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    double precioBase;

public:
    Auto(string ma, string mo, int a, double p) : Vehiculo(ma, mo, a), precioBase(p) {}
    double calcularCosto() const override { return anio > 2020 ? precioBase * 1.10 : precioBase; }
    string getTipo() const override { return "Auto"; }
};

class Moto : public Vehiculo {
private:
    double precioBase;

public:
    Moto(string ma, string mo, int a, double p) : Vehiculo(ma, mo, a), precioBase(p) {}
    double calcularCosto() const override { return precioBase * 0.70; }
    string getTipo() const override { return "Moto"; }
};

class Camion : public Vehiculo {
private:
    double precioBase;

public:
    Camion(string ma, string mo, int a, double p) : Vehiculo(ma, mo, a), precioBase(p) {}
    double calcularCosto() const override { return precioBase * 2.50; }
    string getTipo() const override { return "Camion"; }
};

int main() {
    const int N = 6;
    Vehiculo* flota[N] = {
        new Auto("Toyota", "Corolla", 2021, 22000.0),
        new Moto("Yamaha", "MT03", 2023, 6000.0),
        new Camion("Volvo", "FH", 2020, 55000.0),
        new Auto("Kia", "Rio", 2019, 16000.0),
        new Moto("Honda", "CBR", 2022, 9000.0),
        new Camion("Hino", "500", 2022, 42000.0)
    };

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (flota[j]->calcularCosto() < flota[j + 1]->calcularCosto()) {
                Vehiculo* temp = flota[j];
                flota[j] = flota[j + 1];
                flota[j + 1] = temp;
            }
        }
    }

    double total = 0;
    for (int i = 0; i < N; i++) {
        flota[i]->imprimir();
        total += flota[i]->calcularCosto();
    }

    cout << fixed << setprecision(2);
    cout << "Costo total de flota: $" << total << endl;

    for (int i = 0; i < N; i++) {
        delete flota[i];
        flota[i] = nullptr;
    }

    return 0;
}
