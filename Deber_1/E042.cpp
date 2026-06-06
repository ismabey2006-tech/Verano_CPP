#include <iostream>
using namespace std;

int buscar(int arr[], int n, int valor){
    for(int i = 0; i < n; i++){
        if(arr[i] == valor){
            return i;
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

    int indice = buscar(arr, n, valor);

    if(indice != -1){
        cout << "Valor " << valor << " encontrado en indice " << indice << "." << endl;
    }
    else{
        cout << "Valor " << valor << " no encontrado." << endl;
    }

    return 0;
}
