#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Estudiante {
    string nombre;
    double nota;
    int edad;
};

void imprimir(const Estudiante* e) {
    if (e == nullptr) return;
    cout << fixed << setprecision(2);
    cout << "Nombre: " << e->nombre << " | Nota: " << e->nota << " | Edad: " << e->edad << endl;
}

void actualizarNota(Estudiante* e, double nuevaNota) {
    if (e != nullptr && nuevaNota >= 0 && nuevaNota <= 100) {
        e->nota = nuevaNota;
    }
}

bool aprobo(const Estudiante* e) {
    return e != nullptr && e->nota >= 60;
}

int main() {
    Estudiante estudiante = {"Ana", 75.0, 20};

    imprimir(&estudiante);
    actualizarNota(&estudiante, 85.0);

    cout << fixed << setprecision(2);
    cout << "Nota actualizada: " << estudiante.nota << endl;
    cout << "Estado: " << (aprobo(&estudiante) ? "APROBADO" : "REPROBADO") << endl;

    return 0;
}
