#include <iostream>
using namespace std;

bool esPar(int n){
    return n % 2 == 0;
}

void imprimirPares(int inicio, int fin){
    for(int i = inicio; i <= fin; i++){
        if(esPar(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}

int main(){
    int inicio, fin;

    cin >> inicio;
    cin >> fin;

    cout << "Pares entre " << inicio << " y " << fin << ":" << endl;
    imprimirPares(inicio, fin);

    return 0;
}
