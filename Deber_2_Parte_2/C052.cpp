#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Figura {
public:
    virtual double area() const = 0;
    virtual string nombre() const = 0;
    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << nombre() << " | Area: " << area() << endl;
    }
    virtual ~Figura() {}
};

class Circulo : public Figura {
private:
    double radio;
    static constexpr double PI = 3.14159;
public:
    Circulo(double r) : radio(r) {}
    double area() const override { return PI * radio * radio; }
    string nombre() const override { return "Circulo"; }
};

class Rectangulo : public Figura {
private:
    double base, altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}
    double area() const override { return base * altura; }
    string nombre() const override { return "Rectangulo"; }
};

class Triangulo : public Figura {
private:
    double base, altura;
public:
    Triangulo(double b, double h) : base(b), altura(h) {}
    double area() const override { return base * altura / 2.0; }
    string nombre() const override { return "Triangulo"; }
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(double lado) : Rectangulo(lado, lado) {}
    string nombre() const override { return "Cuadrado"; }
};

class Rombo : public Figura {
private:
    double d1, d2;
public:
    Rombo(double a, double b) : d1(a), d2(b) {}
    double area() const override { return d1 * d2 / 2.0; }
    string nombre() const override { return "Rombo"; }
};

class Lienzo {
private:
    Figura* figuras[50];
    int cantidad;

public:
    Lienzo() : cantidad(0) {
        for (int i = 0; i < 50; i++) figuras[i] = nullptr;
    }

    void agregar(Figura* f) {
        if (f != nullptr && cantidad < 50) figuras[cantidad++] = f;
    }

    double areaTotalCanvas() const {
        double total = 0;
        for (int i = 0; i < cantidad; i++) total += figuras[i]->area();
        return total;
    }

    double areaPromedio() const {
        return cantidad == 0 ? 0 : areaTotalCanvas() / cantidad;
    }

    Figura* figuraMayor() const {
        if (cantidad == 0) return nullptr;
        int pos = 0;
        for (int i = 1; i < cantidad; i++) {
            if (figuras[i]->area() > figuras[pos]->area()) pos = i;
        }
        return figuras[pos];
    }

    Figura* figurasMenor() const {
        if (cantidad == 0) return nullptr;
        int pos = 0;
        for (int i = 1; i < cantidad; i++) {
            if (figuras[i]->area() < figuras[pos]->area()) pos = i;
        }
        return figuras[pos];
    }

    void imprimirTodas() const {
        cout << "=== Figuras del lienzo ===" << endl;
        for (int i = 0; i < cantidad; i++) figuras[i]->imprimir();
    }

    ~Lienzo() {
        for (int i = 0; i < cantidad; i++) {
            delete figuras[i];
            figuras[i] = nullptr;
        }
    }
};

int main() {
    Lienzo l;
    l.agregar(new Circulo(5));
    l.agregar(new Rectangulo(6, 4));
    l.agregar(new Triangulo(3, 4));
    l.agregar(new Cuadrado(7));
    l.agregar(new Rombo(6, 8));
    l.agregar(new Circulo(2));
    l.agregar(new Rectangulo(10, 3));
    l.agregar(new Triangulo(8, 5));

    l.imprimirTodas();
    cout << fixed << setprecision(2);
    cout << "Area total: " << l.areaTotalCanvas() << endl;
    cout << "Area promedio: " << l.areaPromedio() << endl;

    Figura* mayor = l.figuraMayor();
    Figura* menor = l.figurasMenor();
    if (mayor) cout << "Mayor area: " << mayor->nombre() << " = " << mayor->area() << endl;
    if (menor) cout << "Menor area: " << menor->nombre() << " = " << menor->area() << endl;

    return 0;
}
