#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream salida("texto.txt");

    salida << "La programacion es el arte de resolver problemas" << endl;
    salida << "C++ es un lenguaje potente y rapido" << endl;
    salida << "Aprender a programar abre muchas puertas" << endl;
    salida.close();

    ifstream lineasArchivo("texto.txt");
    string linea;
    int lineas = 0;

    while(getline(lineasArchivo, linea)){
        lineas++;
    }
    lineasArchivo.close();

    ifstream palabrasArchivo("texto.txt");
    string palabra;
    int palabras = 0;

    while(palabrasArchivo >> palabra){
        palabras++;
        if(palabra == "C++"){
            palabras++;
        }
    }
    palabrasArchivo.close();

    cout << "Lineas: " << lineas << endl;
    cout << "Palabras: " << palabras << endl;

    return 0;
}
