#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) {
        cout << "Cantidad invalida" << endl;
        return 1;
    }

    string* nombres = new string[n];
    double* notas = new double[n];

    for (int i = 0; i < n; i++) {
        cin >> nombres[i] >> notas[i];
    }

    double suma = 0.0;
    int idxMax = 0;
    int idxMin = 0;

    for (int i = 0; i < n; i++) {
        suma += notas[i];
        if (notas[i] > notas[idxMax]) idxMax = i;
        if (notas[i] < notas[idxMin]) idxMin = i;
    }

    cout << fixed << setprecision(2);
    cout << "=== Reporte ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << nombres[i] << ": " << notas[i] << endl;
    }

    cout << "Promedio: " << suma / n << endl;
    cout << "Maxima : " << notas[idxMax] << " (" << nombres[idxMax] << ")" << endl;
    cout << "Minima : " << notas[idxMin] << " (" << nombres[idxMin] << ")" << endl;

    delete[] nombres;
    delete[] notas;
    nombres = nullptr;
    notas = nullptr;

    cout << "Memoria liberada." << endl;

    return 0;
}
