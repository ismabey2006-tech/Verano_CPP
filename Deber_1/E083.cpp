#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string oracion;

    getline(cin, oracion);

    ofstream archivo("registro.txt", ios::app);
    archivo << oracion << endl;
    archivo.close();

    cout << "Linea agregada a \"registro.txt\"." << endl;

    return 0;
}
