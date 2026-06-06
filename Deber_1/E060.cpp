#include <iostream>
using namespace std;

void intercambiar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a, b;
    cin >> a;
    cin >> b;

    cout << "Antes:  a=" << a << ", b=" << b << endl;
    intercambiar(&a, &b);
    cout << "Despues: a=" << a << ", b=" << b << endl;

    return 0;
}
