#include <iostream>
using namespace std;

void imprimir(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ordenarBurbuja(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    int arr[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Arreglo original: ";
    imprimir(arr, n);

    ordenarBurbuja(arr, n);

    cout << "Arreglo ordenado: ";
    imprimir(arr, n);

    return 0;
}
