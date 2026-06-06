#include <iostream>
using namespace std;

int sumar(int a, int b){
    return a + b;
}

int restar(int a, int b){
    return a - b;
}

int multiplicar(int a, int b){
    return a * b;
}

int main(){
    int opcion, a, b;
    int (*op)(int, int) = nullptr;

    cin >> opcion;
    cin >> a >> b;

    if(opcion == 1){
        op = sumar;
    }
    else if(opcion == 2){
        op = restar;
    }
    else if(opcion == 3){
        op = multiplicar;
    }

    if(op != nullptr){
        cout << "Resultado: " << op(a, b) << endl;
    }
    else{
        cout << "Opcion invalida." << endl;
    }

    return 0;
}
