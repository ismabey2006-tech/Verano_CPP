#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    string buscado, nombre;
    double nota;
    bool encontrado = false;

    cin >> buscado;

    ifstream archivo("estudiantes.txt");

    if(!archivo.is_open()){
        cout << "Error: no se pudo abrir el archivo." << endl;
        return 1;
    }

    while(archivo >> nombre >> nota){
        if(nombre == buscado){
            encontrado = true;
            cout << fixed << setprecision(2);
            cout << "Estudiante encontrado: " << nombre << " - " << nota << endl;
        }
    }

    archivo.close();

    if(!encontrado){
        cout << "Estudiante no encontrado." << endl;
    }

    return 0;
}
