#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Proyecto final elegido: sistema de e-commerce.
// Jerarquia principal: ElementoSistema -> Producto -> ProductoFisico/Digital/Suscripcion
// Tambien se incluye ElementoSistema -> Usuario -> Cliente/Administrador.

class ElementoSistema {
protected:
    string id;
    string nombre;

public:
    ElementoSistema(string i, string n) : id(i), nombre(n) {}
    string getId() const { return id; }
    string getNombre() const { return nombre; }
    virtual string getTipo() const = 0;
    virtual double calcularImpacto() const = 0;
    virtual void imprimir() const {
        cout << getTipo() << " [" << id << "] " << nombre;
    }
    virtual ~ElementoSistema() {}
};

class Producto : public ElementoSistema {
protected:
    double precioBase;
    int stock;

public:
    Producto(string i, string n, double p, int s) : ElementoSistema(i,n), precioBase(p >= 0 ? p : 0), stock(s >= 0 ? s : 0) {}
    double getPrecioBase() const { return precioBase; }
    int getStock() const { return stock; }
    virtual double precioFinal() const = 0;
    double calcularImpacto() const override { return precioFinal() * stock; }
    void imprimir() const override {
        cout << fixed << setprecision(2);
        ElementoSistema::imprimir();
        cout << " | Precio final: $" << precioFinal() << " | Stock: " << stock
             << " | Valor inventario: $" << calcularImpacto() << endl;
    }
};

class ProductoFisico : public Producto {
private:
    double pesoKg;
public:
    ProductoFisico(string i, string n, double p, int s, double peso) : Producto(i,n,p,s), pesoKg(peso) {}
    string getTipo() const override { return "Producto fisico"; }
    double precioFinal() const override { return precioBase + pesoKg * 1.5; }
};

class ProductoDigital : public Producto {
private:
    double tamanoMB;
public:
    ProductoDigital(string i, string n, double p, int s, double mb) : Producto(i,n,p,s), tamanoMB(mb) {}
    string getTipo() const override { return "Producto digital"; }
    double precioFinal() const override { return precioBase * 0.90; }
    double getTamanoMB() const { return tamanoMB; }
};

class ProductoSuscripcion : public Producto {
private:
    int meses;
public:
    ProductoSuscripcion(string i, string n, double p, int s, int m) : Producto(i,n,p,s), meses(m) {}
    string getTipo() const override { return "Producto suscripcion"; }
    double precioFinal() const override { return precioBase * meses; }
};

class Usuario : public ElementoSistema {
protected:
    string email;
public:
    Usuario(string i, string n, string e) : ElementoSistema(i,n), email(e) {}
    string getEmail() const { return email; }
    void imprimir() const override {
        ElementoSistema::imprimir();
        cout << " | Email: " << email << " | Impacto: " << calcularImpacto() << endl;
    }
};

class Cliente : public Usuario {
private:
    int comprasRealizadas;
public:
    Cliente(string i, string n, string e, int compras) : Usuario(i,n,e), comprasRealizadas(compras) {}
    string getTipo() const override { return "Cliente"; }
    double calcularImpacto() const override { return comprasRealizadas * 10.0; }
    int getComprasRealizadas() const { return comprasRealizadas; }
};

class Administrador : public Usuario {
private:
    int reportesGestionados;
public:
    Administrador(string i, string n, string e, int reportes) : Usuario(i,n,e), reportesGestionados(reportes) {}
    string getTipo() const override { return "Administrador"; }
    double calcularImpacto() const override { return reportesGestionados * 5.0; }
    int getReportesGestionados() const { return reportesGestionados; }
};

class Plataforma {
private:
    ElementoSistema* elementos[100];
    int cantidad;

public:
    Plataforma() : cantidad(0) { for(int i=0;i<100;i++) elementos[i]=nullptr; }
    void agregar(ElementoSistema* e) { if(e && cantidad < 100) elementos[cantidad++] = e; }
    void imprimirTodo() const {
        cout << "=== Plataforma e-commerce ===" << endl;
        for(int i=0;i<cantidad;i++) elementos[i]->imprimir();
    }
    double impactoTotal() const {
        double total = 0;
        for(int i=0;i<cantidad;i++) total += elementos[i]->calcularImpacto();
        return total;
    }
    void imprimirSoloProductos() const {
        cout << "=== Productos detectados por polimorfismo ===" << endl;
        for(int i=0;i<cantidad;i++) {
            Producto* p = dynamic_cast<Producto*>(elementos[i]);
            if(p != nullptr) p->imprimir();
        }
    }
    ~Plataforma() {
        for(int i=0;i<cantidad;i++){ delete elementos[i]; elementos[i]=nullptr; }
    }
};

int main() {
    Plataforma p;
    p.agregar(new ProductoFisico("P001", "Laptop", 1200, 5, 2.5));
    p.agregar(new ProductoDigital("P002", "Curso C++", 80, 20, 1500));
    p.agregar(new ProductoSuscripcion("P003", "Plan Pro", 15, 50, 12));
    p.agregar(new Cliente("U001", "Ana", "ana@mail.com", 8));
    p.agregar(new Administrador("U002", "Luis", "luis@mail.com", 14));

    p.imprimirTodo();
    p.imprimirSoloProductos();
    cout << fixed << setprecision(2) << "Impacto total: " << p.impactoTotal() << endl;

    return 0;
}
