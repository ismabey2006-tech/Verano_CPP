#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int n;
    string nombre;
    double nota;

    cin >> n;

    ofstream salida("estudiantes.txt");

    for(int i = 0; i < n; i++){
        cin >> nombre >> nota;
        salida << nombre << " " << nota << endl;
    }
    salida.close();

    cout << "Guardados " << n << " registros en \"estudiantes.txt\"." << endl;
    cout << "Leyendo archivo:" << endl;

    ifstream entrada("estudiantes.txt");

    cout << fixed << setprecision(2);
    while(entrada >> nombre >> nota){
        cout << nombre << " - " << nota << endl;
    }
    entrada.close();

    return 0;
}
