#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Producto {
private:
    string codigo;
    string nombre;
    double precio;

public:
    Producto(string c, string n, double p) : codigo(c), nombre(n), precio(p >= 0 ? p : 0) {}
    string getCodigo() const { return codigo; }
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    virtual string getCategoria() const = 0;
    virtual double calcularPrecioFinal() const = 0;
    virtual void imprimir() const {
        cout << fixed << setprecision(2);
        cout << getCategoria() << " [" << codigo << "] " << nombre
             << " | Base: $" << precio << " | Final: $" << calcularPrecioFinal() << endl;
    }
    virtual ~Producto() {}
};

class ProductoFisico : public Producto {
private:
    double peso;
    string dimensiones;
public:
    ProductoFisico(string c, string n, double p, double pe, string d) : Producto(c,n,p), peso(pe), dimensiones(d) {}
    string getCategoria() const override { return "Fisico"; }
    double calcularPrecioFinal() const override { return getPrecio() + peso * 2.5; }
    void imprimir() const override { Producto::imprimir(); cout << "  Peso: " << peso << " kg | Dim: " << dimensiones << endl; }
};

class ProductoDigital : public Producto {
private:
    double tamanoMB;
    string plataforma;
public:
    ProductoDigital(string c, string n, double p, double mb, string pl) : Producto(c,n,p), tamanoMB(mb), plataforma(pl) {}
    string getCategoria() const override { return "Digital"; }
    double calcularPrecioFinal() const override { return getPrecio() * 0.85; }
    void imprimir() const override { Producto::imprimir(); cout << "  Tamano: " << tamanoMB << " MB | Plataforma: " << plataforma << endl; }
};

class ProductoSuscripcion : public Producto {
private:
    int periodoMeses;
    bool renovacionAutomatica;
public:
    ProductoSuscripcion(string c, string n, double p, int meses, bool ren) : Producto(c,n,p), periodoMeses(meses), renovacionAutomatica(ren) {}
    string getCategoria() const override { return "Suscripcion"; }
    double calcularPrecioFinal() const override { return getPrecio() * periodoMeses; }
    void imprimir() const override { Producto::imprimir(); cout << "  Meses: " << periodoMeses << " | Renovacion: " << (renovacionAutomatica ? "SI" : "NO") << endl; }
};

class Inventario {
private:
    Producto* productos[100];
    int cantidad;
public:
    Inventario() : cantidad(0) { for(int i=0;i<100;i++) productos[i]=nullptr; }
    void agregar(Producto* p) { if(p && cantidad < 100) productos[cantidad++] = p; }
    Producto* buscar(string codigo) const {
        for(int i=0;i<cantidad;i++) if(productos[i]->getCodigo() == codigo) return productos[i];
        return nullptr;
    }
    void eliminar(string codigo) {
        for(int i=0;i<cantidad;i++) {
            if(productos[i]->getCodigo() == codigo) {
                delete productos[i];
                for(int j=i;j<cantidad-1;j++) productos[j]=productos[j+1];
                productos[cantidad-1]=nullptr;
                cantidad--;
                cout << "Producto eliminado: " << codigo << endl;
                return;
            }
        }
        cout << "Producto no encontrado: " << codigo << endl;
    }
    double valorTotal() const { double t=0; for(int i=0;i<cantidad;i++) t += productos[i]->calcularPrecioFinal(); return t; }
    void listar() const { cout << "=== Inventario ===" << endl; for(int i=0;i<cantidad;i++) productos[i]->imprimir(); }
    ~Inventario() { for(int i=0;i<cantidad;i++){ delete productos[i]; productos[i]=nullptr; } }
};

int main() {
    Inventario inv;
    inv.agregar(new ProductoFisico("F001", "Laptop", 1200, 2.2, "35x25x2"));
    inv.agregar(new ProductoDigital("D001", "Curso C++", 80, 1500, "Web"));
    inv.agregar(new ProductoSuscripcion("S001", "Plan Pro", 15, 12, true));
    inv.listar();
    cout << fixed << setprecision(2) << "Valor total: $" << inv.valorTotal() << endl;
    Producto* p = inv.buscar("D001");
    if (p) { cout << "Encontrado: "; p->imprimir(); }
    inv.eliminar("S001");
    inv.listar();
    return 0;
}
