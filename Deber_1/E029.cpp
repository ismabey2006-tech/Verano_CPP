#include <iostream>
using namespace std;

bool esPrimo(int n){
    if(n <= 1){
        return false;
    }

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    cout << "Primos entre 1 y 50:" << endl;

    for(int i = 1; i <= 50; i++){
        if(esPrimo(i)){
            cout << i << " ";
        }
    }

    return 0;
}
