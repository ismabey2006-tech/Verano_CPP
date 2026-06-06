#include <iostream>
#include <iomanip>
using namespace std;

class Vector2D{
private:
    double x;
    double y;

public:
    Vector2D(double xValor = 0, double yValor = 0){
        x = xValor;
        y = yValor;
    }

    Vector2D operator+(Vector2D otro){
        return Vector2D(x + otro.x, y + otro.y);
    }

    double operator*(Vector2D otro){
        return x * otro.x + y * otro.y;
    }

    friend ostream& operator<<(ostream& salida, Vector2D v){
        salida << fixed << setprecision(2);
        salida << "(" << v.x << ", " << v.y << ")";
        return salida;
    }
};

int main(){
    double x1, y1, x2, y2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    Vector2D v1(x1, y1);
    Vector2D v2(x2, y2);
    Vector2D suma = v1 + v2;
    double producto = v1 * v2;

    cout << fixed << setprecision(2);
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << suma << endl;
    cout << "v1 · v2 = " << producto << endl;

    return 0;
}
