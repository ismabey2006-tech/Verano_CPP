#include <iostream>
using namespace std;

int* crearArreglo(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

void aplicar(int* arr, int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

void imprimir(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int duplicar(int x) {
    return x * 2;
}

int cuadrado(int x) {
    return x * x;
}

int sumarDiez(int x) {
    return x + 10;
}

int main() {
    int n = 5;
    int* arr = crearArreglo(n);

    cout << "Original  : ";
    imprimir(arr, n);

    aplicar(arr, n, duplicar);
    cout << "Duplicado : ";
    imprimir(arr, n);

    aplicar(arr, n, cuadrado);
    cout << "Cuadrado  : ";
    imprimir(arr, n);

    aplicar(arr, n, sumarDiez);
    cout << "+10       : ";
    imprimir(arr, n);

    delete[] arr;
    arr = nullptr;

    cout << "Memoria liberada." << endl;

    return 0;
}
