#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    double altura;

    void imprimir() {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Nombre: " << nombre << ", Edad: " << edad
             << ", Altura: " << altura << "m" << endl;
        cout << "Mayor de edad: " << (esMayorDeEdad() ? "SI" : "NO") << endl;
        cout << saludar() << endl;
    }

    bool esMayorDeEdad() {
        return edad >= 18;
    }

    string saludar() {
        return "Hola, soy " + nombre + " y tengo " + to_string(edad) + " años.";
    }
};

int main() {
    Persona p1;
    p1.nombre = "Ana";
    p1.edad = 22;
    p1.altura = 1.65;

    Persona p2;
    p2.nombre = "Luis";
    p2.edad = 16;
    p2.altura = 1.72;

    Persona p3;
    p3.nombre = "Carla";
    p3.edad = 30;
    p3.altura = 1.60;

    p1.imprimir();
    p2.imprimir();
    p3.imprimir();

    return 0;
}
