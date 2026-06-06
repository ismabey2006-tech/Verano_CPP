#include <iostream>
using namespace std;

void imprimir(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n, nuevo;

    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> nuevo;

    cout << "Original: ";
    imprimir(arr, n);

    int* extendido = new int[n + 1];

    for(int i = 0; i < n; i++){
        extendido[i] = arr[i];
    }
    extendido[n] = nuevo;

    delete[] arr;
    arr = nullptr;

    cout << "Extendido: ";
    imprimir(extendido, n + 1);

    delete[] extendido;
    extendido = nullptr;

    return 0;
}
