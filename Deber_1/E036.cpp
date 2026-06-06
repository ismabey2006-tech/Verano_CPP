#include <iostream>
#include <string>
using namespace std;

string invertir(string s){
    string invertida = "";

    for(int i = s.length() - 1; i >= 0; i--){
        invertida += s[i];
    }

    return invertida;
}

int main(){
    string palabra;

    cin >> palabra;

    cout << "Original: " << palabra << endl;
    cout << "Invertida: " << invertir(palabra) << endl;

    return 0;
}
