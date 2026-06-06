#include <iostream>
using namespace std;

int busquedaBinaria(int arr[], int n, int valor){
    int izquierda = 0;
    int derecha = n - 1;

    while(izquierda <= derecha){
        int medio = (izquierda + derecha) / 2;

        if(arr[medio] == valor){
            return medio;
        }
        else if(arr[medio] < valor){
            izquierda = medio + 1;
        }
        else{
            derecha = medio - 1;
        }
    }

    return -1;
}

int main(){
    int n, valor;
    int arr[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> valor;

    int indice = busquedaBinaria(arr, n, valor);

    if(indice != -1){
        cout << "Valor " << valor << " encontrado en indice " << indice << " (busqueda binaria)." << endl;
    }
    else{
        cout << "Valor " << valor << " no encontrado." << endl;
    }

    return 0;
}
