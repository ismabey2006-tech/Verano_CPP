#include <iostream>
using namespace std;

int main(){
    int a = 42;
    int* b = new int(42);

    cout << "Stack: " << a << "    Heap: " << *b << endl;
    *b = 99;
    cout << "Stack: " << a << "    Heap: " << *b << endl;

    delete b;
    b = nullptr;

    cout << "Heap liberado." << endl;

    return 0;
}
