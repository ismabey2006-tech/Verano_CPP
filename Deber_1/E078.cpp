#include <iostream>
#include <string>
using namespace std;

void ordenar(string* arr, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;

    cin >> n;

    string* arr = new string[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    ordenar(arr, n);

    cout << "Ordenado:" << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
