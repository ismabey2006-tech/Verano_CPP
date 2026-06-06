#include <iostream>
#include <string>
using namespace std;

int main(){
    string oracion;
    int palabras = 0;

    getline(cin, oracion);

    if(oracion.length() > 0){
        palabras = 1;
    }

    for(int i = 0; i < (int)oracion.length(); i++){
        if(oracion[i] == ' '){
            palabras++;
        }
    }

    cout << "Palabras: " << palabras << endl;

    return 0;
}
