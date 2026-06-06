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

    ofstream salida("notas.txt");

    for(int i = 0; i < n; i++){
        cin >> nombre >> nota;
        salida << nombre << " " << nota << endl;
    }
    salida.close();

    cout << "Datos guardados en \"notas.txt\"." << endl;

    ifstream entrada("notas.txt");
    double suma = 0;
    int contador = 0;

    while(entrada >> nombre >> nota){
        suma += nota;
        contador++;
    }
    entrada.close();

    double promedio = suma / contador;

    cout << fixed << setprecision(2);
    cout << "Promedio del grupo: " << promedio << endl;

    ofstream append("notas.txt", ios::app);
    append << "Promedio " << promedio << endl;
    append.close();

    cout << "Promedio guardado en el archivo." << endl;

    return 0;
}
