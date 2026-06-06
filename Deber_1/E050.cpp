#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string oracion;

    getline(cin, oracion);

    cout << "Longitud: " << oracion.length() << endl;
    cout << "En mayusculas: ";
    for(int i = 0; i < (int)oracion.length(); i++){
        cout << (char)toupper(oracion[i]);
    }
    cout << endl;

    return 0;
}
