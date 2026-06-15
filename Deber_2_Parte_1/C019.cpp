#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    double altura;

public:
    Persona(string n, int e, double h) : nombre(n), edad(0), altura(0) {
        setEdad(e);
        setAltura(h);
    }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    double getAltura() const { return altura; }

    void setNombre(string n) { nombre = n; }

    void setEdad(int e) {
        if (e >= 0 && e <= 120) edad = e;
        else cout << "Edad invalida." << endl;
    }

    void setAltura(double h) {
        if (h >= 0.5 && h <= 2.5) altura = h;
        else cout << "Altura invalida." << endl;
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Nombre: " << nombre << ", Edad: " << edad
             << ", Altura: " << altura << "m" << endl;
    }
};

int main() {
    Persona p("Ana", 22, 1.65);
    p.imprimir();
    p.setEdad(-5);
    p.setAltura(3.00);
    p.imprimir();
    return 0;
}
