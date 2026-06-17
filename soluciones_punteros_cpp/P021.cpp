#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int filas, columnas;
    cin >> filas >> columnas;

    if (filas <= 0 || columnas <= 0) {
        cout << "Dimensiones invalidas" << endl;
        return 1;
    }

    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j + 1;
        }
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << setw(3) << matriz[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;

    cout << "Memoria liberada." << endl;

    return 0;
}
