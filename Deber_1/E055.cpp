#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int n;
    string nombres[100];
    double promedios[100];
    double n1, n2, n3;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nombres[i] >> n1 >> n2 >> n3;
        promedios[i] = (n1 + n2 + n3) / 3.0;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(promedios[j] < promedios[j + 1]){
                double tempPromedio = promedios[j];
                promedios[j] = promedios[j + 1];
                promedios[j + 1] = tempPromedio;

                string tempNombre = nombres[j];
                nombres[j] = nombres[j + 1];
                nombres[j + 1] = tempNombre;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "=== Ranking de estudiantes ===" << endl;
    for(int i = 0; i < n; i++){
        cout << i + 1 << ". " << left << setw(6) << nombres[i] << " - Promedio: " << promedios[i] << endl;
    }

    return 0;
}
