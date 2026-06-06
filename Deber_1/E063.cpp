#include <iostream>
using namespace std;

void triplicarRef(int &n){
    n = n * 3;
}

void triplicarPtr(int* p){
    *p = *p * 3;
}

int main(){
    int x;
    cin >> x;

    cout << "Valor inicial: " << x << endl;
    triplicarRef(x);
    cout << "Despues de triplicarRef: " << x << endl;
    triplicarPtr(&x);
    cout << "Despues de triplicarPtr: " << x << endl;

    return 0;
}
