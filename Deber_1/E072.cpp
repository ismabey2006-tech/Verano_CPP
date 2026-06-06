#include <iostream>
using namespace std;

int* crearArreglo(int n, int valorInicial){
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = valorInicial;
    }

    return arr;
}

int main(){
    int n, valorInicial;

    cin >> n;
    cin >> valorInicial;

    int* arr = crearArreglo(n, valorInicial);

    cout << "Arreglo de " << n << " elementos inicializados en " << valorInicial << ":" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}
