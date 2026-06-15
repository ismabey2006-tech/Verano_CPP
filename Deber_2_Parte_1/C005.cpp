#include <iostream>
#include <string>
using namespace std;

class Estudiante {
public:
    string nombre;
    double nota;

    void imprimir() {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << nombre << ": " << nota << endl;
    }

    bool aprobo() {
        return nota >= 60.0;
    }
};

int main() {
    Estudiante estudiantes[4];
    estudiantes[0].nombre = "Ana";    estudiantes[0].nota = 85;
    estudiantes[1].nombre = "Luis";   estudiantes[1].nota = 45;
    estudiantes[2].nombre = "Carla";  estudiantes[2].nota = 92;
    estudiantes[3].nombre = "Pedro";  estudiantes[3].nota = 58;

    cout << "=== Aprobados ===" << endl;
    for (int i = 0; i < 4; i++) {
        if (estudiantes[i].aprobo()) estudiantes[i].imprimir();
    }

    cout << "=== Reprobados ===" << endl;
    for (int i = 0; i < 4; i++) {
        if (!estudiantes[i].aprobo()) estudiantes[i].imprimir();
    }

    return 0;
}
