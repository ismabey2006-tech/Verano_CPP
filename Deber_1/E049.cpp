#include <iostream>
using namespace std;

int main(){
    int n;
    int matriz[50][50];
    int suma = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }

    cout << "Diagonal principal: ";
    for(int i = 0; i < n; i++){
        cout << matriz[i][i] << " ";
        suma += matriz[i][i];
    }
    cout << endl;
    cout << "Suma: " << suma << endl;

    return 0;
}
