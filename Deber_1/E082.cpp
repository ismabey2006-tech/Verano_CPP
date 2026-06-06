#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream salida("poema.txt");

    salida << "Las rosas son rojas" << endl;
    salida << "El mar es profundo" << endl;
    salida << "El codigo es logica" << endl;
    salida << "C++ es poderoso" << endl;
    salida.close();

    ifstream entrada("poema.txt");
    string linea;
    int numero = 1;

    while(getline(entrada, linea)){
        cout << numero << ": " << linea << endl;
        numero++;
    }

    entrada.close();

    return 0;
}
