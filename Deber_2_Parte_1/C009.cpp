#include <iostream>
using namespace std;

class Matematica {
public:
    static int maximo(int a, int b) {
        return (a > b) ? a : b;
    }

    static int minimo(int a, int b) {
        return (a < b) ? a : b;
    }

    static bool esPrimo(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    static double potencia(double base, int exp) {
        double resultado = 1.0;
        for (int i = 0; i < exp; i++) resultado *= base;
        return resultado;
    }
};

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << "Maximo(8, 3): " << Matematica::maximo(8, 3) << endl;
    cout << "Minimo(8, 3): " << Matematica::minimo(8, 3) << endl;
    cout << "Es primo 7: " << (Matematica::esPrimo(7) ? "SI" : "NO") << endl;
    cout << "Es primo 9: " << (Matematica::esPrimo(9) ? "SI" : "NO") << endl;
    cout << "2 elevado a 10: " << Matematica::potencia(2, 10) << endl;
    return 0;
}
