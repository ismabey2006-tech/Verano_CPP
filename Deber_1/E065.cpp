#include <iostream>
using namespace std;

void llenarCuadrados(int* arr, int n){
    for(int i = 0; i < n; i++){
        arr[i] = i * i;
    }
}

int main(){
    int n;
    int arr[100];

    cin >> n;
    llenarCuadrados(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
