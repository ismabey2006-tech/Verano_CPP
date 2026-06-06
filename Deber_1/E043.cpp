#include <iostream>
#include <iomanip>
using namespace std;

int maximo(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int minimo(int arr[], int n){
    int min = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

double promedio(int arr[], int n){
    double suma = 0;
    for(int i = 0; i < n; i++){
        suma += arr[i];
    }
    return suma / n;
}

int main(){
    int n;
    int arr[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << fixed << setprecision(2);
    cout << "Maximo: " << maximo(arr, n) << endl;
    cout << "Minimo: " << minimo(arr, n) << endl;
    cout << "Promedio: " << promedio(arr, n) << endl;

    return 0;
}
