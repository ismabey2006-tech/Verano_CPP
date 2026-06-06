#include <iostream>
using namespace std;

void duplicar(int* p){
    *p = *p * 2;
}

int main(){
    int x;
    cin >> x;

    cout << "Antes: " << x << endl;
    duplicar(&x);
    cout << "Despues: " << x << endl;

    return 0;
}
