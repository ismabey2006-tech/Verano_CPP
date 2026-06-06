#include <iostream>
using namespace std;

int main(){
    int N;
    int n;
    int menor;
    int mayor;

    cin >> N;

    if(N <= 0){
        cout << "Cantidad invalida" << endl;
        return 0;
    }

    cin >> n;
    mayor = n;
    menor = n;

    for(int i = 1; i < N; i++){
        cin >> n;

        if(n > mayor){
            mayor = n;
        }

        if(n < menor){
            menor = n;
        }
    }

    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;

    return 0;
}
