#include <iostream>
#include <iomanip>
using namespace std;

// Retorna memoria dinámica; el caller debe liberar con delete[].
double* crearNotas(int n) {
    double* notas = new double[n];
    for (int i = 0; i < n; i++) {
        notas[i] = 0.0;
    }
    return notas;
}

void llenar(double* notas, int n) {
    for (int i = 0; i < n; i++) {
        cin >> notas[i];
    }
}

double promedio(const double* notas, int n) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }
    return suma / n;
}

void imprimir(const double* notas, int n) {
    cout << "Notas: ";
    for (int i = 0; i < n; i++) {
        cout << notas[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Cantidad invalida" << endl;
        return 1;
    }

    double* notas = crearNotas(n);
    llenar(notas, n);

    cout << fixed << setprecision(2);
    imprimir(notas, n);
    cout << "Promedio: " << promedio(notas, n) << endl;

    delete[] notas;
    notas = nullptr;

    cout << "Memoria liberada." << endl;

    return 0;
}
