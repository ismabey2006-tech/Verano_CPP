#include <iostream>
using namespace std;

int* encontrarMaximo(int arr[], int n){
    int* max = &arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > *max){
            max = &arr[i];
        }
    }

    return max;
}

int main(){
    int n;
    int arr[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int* maximo = encontrarMaximo(arr, n);

    cout << "Maximo encontrado: " << *maximo << endl;
    *maximo = *maximo * 2;

    cout << "Arreglo tras duplicar el maximo: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
