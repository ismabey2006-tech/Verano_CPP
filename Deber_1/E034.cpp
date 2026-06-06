#include <iostream>
using namespace std;

void imprimirLinea(int n = 20, char c = '-'){
    for(int i = 0; i < n; i++){
        cout << c;
    }
    cout << endl;
}

int main(){
    imprimirLinea();
    imprimirLinea(10);
    imprimirLinea(5, '*');

    return 0;
}
