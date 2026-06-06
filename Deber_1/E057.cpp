#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int* p = &x;

    cout << "Antes: " << *p << endl;
    *p = 99;
    cout << "Despues: " << *p << endl;

    return 0;
}
