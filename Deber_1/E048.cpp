#include <iostream>
using namespace std;

int main(){
    int matriz[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> matriz[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        int suma = 0;
        for(int j = 0; j < 3; j++){
            suma += matriz[i][j];
        }
        cout << "Suma fila " << i + 1 << ": " << suma << endl;
    }

    for(int j = 0; j < 3; j++){
        int suma = 0;
        for(int i = 0; i < 3; i++){
            suma += matriz[i][j];
        }
        cout << "Suma columna " << j + 1 << ": " << suma << endl;
    }

    return 0;
}
