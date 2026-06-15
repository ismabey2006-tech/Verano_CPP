#include <iostream>
using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x, double y) : x(x), y(y) {}

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }

    void imprimir() const {
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Vector2D original(3.0, 4.0);
    Vector2D copia = original;

    cout << "Original: "; original.imprimir(); cout << endl;
    cout << "Copia:    "; copia.imprimir(); cout << endl;

    copia.setX(10.0);
    copia.setY(20.0);
    cout << "[modificar copia a (10, 20)]" << endl;

    cout << "Original: "; original.imprimir(); cout << "   <- no cambio" << endl;
    cout << "Copia:    "; copia.imprimir(); cout << " <- si cambio" << endl;
    return 0;
}
