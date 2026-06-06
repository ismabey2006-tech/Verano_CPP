#include <iostream>
using namespace std;

int main(){
    int* a = new int(5);
    int* b = new int[10];

    delete a;
    a = new int(20);

    cout << "Valor final de a: " << *a << endl;

    delete a;
    delete[] b;
    a = nullptr;
    b = nullptr;

    cout << "Memoria liberada correctamente." << endl;

    return 0;
}
