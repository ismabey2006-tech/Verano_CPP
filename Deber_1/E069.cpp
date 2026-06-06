#include <iostream>
using namespace std;

int main(){
    int* p = new int(99);

    cout << "Valor: " << *p << endl;
    cout << "Direccion: " << p << endl;

    delete p;
    p = nullptr;

    cout << "Memoria liberada correctamente." << endl;

    return 0;
}
