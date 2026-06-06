#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream entrada("estudiantes.txt");
    ofstream salida("respaldo.txt");
    string linea;
    int lineas = 0;

    if(!entrada.is_open()){
        cout << "Error: no se pudo abrir el archivo." << endl;
        return 1;
    }

    while(getline(entrada, linea)){
        salida << linea << endl;
        lineas++;
    }

    entrada.close();
    salida.close();

    cout << "Copiadas " << lineas << " lineas a \"respaldo.txt\"." << endl;

    return 0;
}
