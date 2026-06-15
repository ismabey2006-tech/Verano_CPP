#include <iostream>
#include <string>
using namespace std;

/*
RESPUESTA C024 — ANALISIS

a) Todos los atributos deben ser private. nombre, salario y edad deben protegerse
   para validar cambios. contrasena nunca debe quedar expuesta publicamente.
b) El setter original no valida. Si s = -5000, el empleado queda con salario invalido.
c) getSalario debe ser const porque solo lee el salario y no modifica el objeto.
d) contrasena no deberia tener getter, porque no se debe mostrar. Podria tener un
   metodo cambiarContrasena() con validacion, pero no un getter directo.
*/

class Empleado {
private:
    string nombre;
    double salario;
    int edad;
    string contrasena;

public:
    Empleado(string nombre, double salario, int edad, string contrasena)
        : nombre(nombre), salario(0), edad(0), contrasena(contrasena) {
        setSalario(salario);
        setEdad(edad);
    }

    const string& getNombre() const { return nombre; }
    double getSalario() const { return salario; }
    int getEdad() const { return edad; }

    void setSalario(double s) {
        if (s >= 0) salario = s;
        else cout << "Salario invalido." << endl;
    }

    void setEdad(int e) {
        if (e >= 18 && e <= 80) edad = e;
        else cout << "Edad invalida." << endl;
    }

    bool cambiarContrasena(string actual, string nueva) {
        if (actual == contrasena && nueva.length() >= 6) {
            contrasena = nueva;
            return true;
        }
        return false;
    }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << nombre << " | Edad: " << edad << " | Salario: $" << salario << endl;
    }
};

int main() {
    Empleado e("Ana", 1500.0, 30, "clave123");
    e.imprimir();
    e.setSalario(-5000.0);
    e.imprimir();
    return 0;
}
