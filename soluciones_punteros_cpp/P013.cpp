#include <iostream>
using namespace std;

void doblarElementos(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] *= 2;
    }
}

void imprimirArreglo(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Original : ";
    imprimirArreglo(arr, n);

    doblarElementos(arr, n);

    cout << "Doblado  : ";
    imprimirArreglo(arr, n);

    return 0;
}
