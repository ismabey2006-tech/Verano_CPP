#include <iostream>
using namespace std;

int main(){
    int n, valor;
    int frecuencia[11] = {0};

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> valor;
        frecuencia[valor]++;
    }

    for(int i = 1; i <= 10; i++){
        if(frecuencia[i] > 0){
            cout << "Valor " << i << ": " << frecuencia[i] << " veces" << endl;
        }
    }

    return 0;
}
