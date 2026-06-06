#include <iostream>
#include <iomanip>
using namespace std;

int* leerArregloDinamico(int &n){
    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    return arr;
}

void imprimirArreglo(int* arr, int n){
    cout << "Arreglo: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

double promedioArreglo(int* arr, int n){
    double suma = 0;

    for(int i = 0; i < n; i++){
        suma += arr[i];
    }

    return suma / n;
}

void liberarArreglo(int* &arr){
    delete[] arr;
    arr = nullptr;
}

int main(){
    int n;
    int* arr = leerArregloDinamico(n);

    imprimirArreglo(arr, n);

    cout << fixed << setprecision(2);
    cout << "Promedio: " << promedioArreglo(arr, n) << endl;

    liberarArreglo(arr);

    cout << "Memoria liberada." << endl;

    return 0;
}
