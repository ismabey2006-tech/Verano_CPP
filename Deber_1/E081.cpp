#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream archivo("saludo.txt");

    archivo << "Linea 1: Hola desde C++" << endl;
    archivo << "Linea 2: Aprendiendo archivos" << endl;
    archivo << "Linea 3: fstream es poderoso" << endl;
    archivo.close();

    cout << "Archivo \"saludo.txt\" creado." << endl;
    cout << "3 lineas escritas." << endl;

    return 0;
}
