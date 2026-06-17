#include <iostream>
#include <cctype>
using namespace std;

bool esVocal(char c) {
    c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    char palabra[] = "programacion";
    char* p = palabra;
    int longitud = 0;
    int vocales = 0;

    while (*p != '\0') {
        longitud++;
        if (esVocal(*p)) vocales++;
        p++;
    }

    cout << "Longitud  : " << longitud << endl;

    cout << "Mayusculas: ";
    p = palabra;
    while (*p != '\0') {
        cout << static_cast<char>(toupper(static_cast<unsigned char>(*p)));
        p++;
    }
    cout << endl;

    cout << "Vocales   : " << vocales << endl;

    return 0;
}
