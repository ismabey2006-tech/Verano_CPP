#include <iostream>
using namespace std;

int* buscarPtr(int* arr, int n, int valor){
    for(int i = 0; i < n; i++){
        if(arr[i] == valor){
            return &arr[i];
        }
    }
    return nullptr;
}

int main(){
    int n, valor;
    int arr[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> valor;

    int* resultado = buscarPtr(arr, n, valor);

    if(resultado != nullptr){
        cout << "Valor " << *resultado << " encontrado." << endl;
    }
    else{
        cout << "Valor no encontrado." << endl;
    }

    return 0;
}
