#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
    int n;
    string nombres[100];
    double notas[100];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nombres[i];
    }
    for(int i = 0; i < n; i++){
        cin >> notas[i];
    }

    int mejor = 0;
    for(int i = 1; i < n; i++){
        if(notas[i] > notas[mejor]){
            mejor = i;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Mejor estudiante: " << nombres[mejor] << " con nota " << notas[mejor] << endl;

    return 0;
}
