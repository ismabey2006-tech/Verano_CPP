#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int n;

    cin >> n;

    string* nombres = new string[n];
    double* notas = new double[n];

    for(int i = 0; i < n; i++){
        cin >> nombres[i] >> notas[i];
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(notas[j] < notas[j + 1]){
                double tempNota = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = tempNota;

                string tempNombre = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = tempNombre;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "=== Ranking ===" << endl;
    for(int i = 0; i < n; i++){
        cout << i + 1 << ". " << left << setw(6) << nombres[i] << " - " << notas[i] << endl;
    }

    delete[] nombres;
    delete[] notas;
    nombres = nullptr;
    notas = nullptr;

    cout << "Memoria liberada." << endl;

    return 0;
}
