#include <iostream>
using namespace std;

int main(){
    int* p = new int(10);

    cout << "Valor antes de delete: " << *p << endl;

    delete p;
    p = nullptr;

    if(p == nullptr){
        cout << "Puntero puesto en nullptr. Acceso bloqueado." << endl;
    }

    return 0;
}
