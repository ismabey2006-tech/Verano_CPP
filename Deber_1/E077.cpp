#include <iostream>
using namespace std;

int* buscarDinamico(int* arr, int n, int val){
    for(int i = 0; i < n; i++){
        if(arr[i] == val){
            return &arr[i];
        }
    }
    return nullptr;
}

int main(){
    int n, val;

    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> val;

    int* resultado = buscarDinamico(arr, n, val);

    if(resultado != nullptr){
        cout << "Elemento encontrado: " << *resultado << endl;
    }
    else{
        cout << "Elemento no encontrado." << endl;
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
