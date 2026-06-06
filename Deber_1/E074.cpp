#include <iostream>
using namespace std;

int main(){
    int filas, columnas;

    cin >> filas >> columnas;

    int** mat = new int*[filas];

    for(int i = 0; i < filas; i++){
        mat[i] = new int[columnas];
    }

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            mat[i][j] = i * j;
        }
    }

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << mat[i][j] << "  ";
        }
        cout << endl;
    }

    for(int i = 0; i < filas; i++){
        delete[] mat[i];
    }
    delete[] mat;
    mat = nullptr;

    return 0;
}
