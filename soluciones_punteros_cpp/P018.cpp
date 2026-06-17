#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "N invalido" << endl;
        return 1;
    }

    double* valores = new double[n];
    double suma = 0.0;

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
        suma += valores[i];
    }

    cout << fixed << setprecision(2);
    cout << "Valores: ";
    for (int i = 0; i < n; i++) {
        cout << valores[i] << " ";
    }
    cout << endl;

    cout << "Promedio: " << suma / n << endl;

    delete[] valores;
    valores = nullptr;

    cout << "Memoria liberada." << endl;

    return 0;
}
