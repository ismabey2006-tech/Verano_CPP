#include <iostream>
using namespace std;

void imprimir(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int* original = new int[3]{1, 2, 3};

    cout << "Original (3): ";
    imprimir(original, 3);

    int* ampliado = new int[6];

    for (int i = 0; i < 3; i++) {
        ampliado[i] = original[i];
    }
    for (int i = 3; i < 6; i++) {
        ampliado[i] = i + 1;
    }

    delete[] original;
    original = nullptr;

    cout << "Ampliado (6): ";
    imprimir(ampliado, 6);

    delete[] ampliado;
    ampliado = nullptr;

    cout << "Memoria liberada." << endl;

    return 0;
}
