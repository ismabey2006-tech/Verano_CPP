#include <iostream>
using namespace std;

int main() {
    int* p = new int;
    *p = 73;

    cout << "Valor en heap: " << *p << endl;

    delete p;
    p = nullptr;

    cout << "Memoria liberada." << endl;
    cout << "Puntero es null: " << (p == nullptr ? "SI" : "NO") << endl;

    return 0;
}
