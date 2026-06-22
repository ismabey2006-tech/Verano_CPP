#include <iostream>
using namespace std;

int main() {
    cout << "C043 - override y virtual" << endl;
    cout << "a) A y B ejecutan el mismo comportamiento si la firma es correcta, pero B usa override y el compilador verifica que realmente sobrescribe." << endl;
    cout << "b) D da error porque hacerSonidos() no existe en la clase base. override detecta el error tipografico." << endl;
    cout << "c) No es necesario repetir virtual en C. Si el metodo ya era virtual en la base, sigue siendo virtual en la derivada." << endl;
    return 0;
}
