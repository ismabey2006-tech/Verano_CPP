#include <iostream>
#include <iomanip>
using namespace std;

int calcularSuma(int* arr, int n){
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma += *(arr + i);
    }
    return suma;
}

double calcularPromedio(int* arr, int n){
    return (double)calcularSuma(arr, n) / n;
}

void invertir(int* arr, int n){
    for(int i = 0; i < n / 2; i++){
        int temp = *(arr + i);
        *(arr + i) = *(arr + n - 1 - i);
        *(arr + n - 1 - i) = temp;
    }
}

int main(){
    int n;
    int arr[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << fixed << setprecision(2);
    cout << "Suma: " << calcularSuma(arr, n) << endl;
    cout << "Promedio: " << calcularPromedio(arr, n) << endl;

    invertir(arr, n);

    cout << "Invertido: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
