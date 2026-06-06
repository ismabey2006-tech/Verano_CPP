#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool esPalindromo(string palabra){
    int izquierda = 0;
    int derecha = palabra.length() - 1;

    while(izquierda < derecha){
        if(tolower(palabra[izquierda]) != tolower(palabra[derecha])){
            return false;
        }
        izquierda++;
        derecha--;
    }

    return true;
}

int main(){
    string palabra;

    cin >> palabra;

    if(esPalindromo(palabra)){
        cout << "\"" << palabra << "\" es palindromo." << endl;
    }
    else{
        cout << "\"" << palabra << "\" no es palindromo." << endl;
    }

    return 0;
}
