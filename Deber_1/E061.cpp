#include <iostream>
using namespace std;

int longitudManual(char palabra[]){
    char* p = palabra;
    int len = 0;

    while(*p != '\0'){
        len++;
        p++;
    }

    return len;
}

int main(){
    char palabra[100];
    cin >> palabra;

    cout << "Palabra: " << palabra << endl;
    cout << "Longitud (manual): " << longitudManual(palabra) << endl;

    return 0;
}
