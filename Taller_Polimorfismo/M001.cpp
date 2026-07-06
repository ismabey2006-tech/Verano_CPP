#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Sensor {
private:
    double* lecturas;
    int n;

protected:
    int size() const {
        return n;
    }

    void setLecturaBase(int i, double val) {
        if (i >= 0 && i < n) {
            lecturas[i] = val;
        }
    }

    double getLectura(int i) const {
        if (i >= 0 && i < n) {
            return lecturas[i];
        }
        return 0.0;
    }

public:
    Sensor(int n) : lecturas(new double[n]), n(n) {
        for (int i = 0; i < n; ++i) {
            lecturas[i] = 0.0;
        }
    }

    virtual ~Sensor() {
        delete[] lecturas;
        lecturas = nullptr;
        cout << "~Sensor: liberando lecturas" << endl;
    }

    virtual void imprimir() const = 0;
    virtual string tipo() const = 0;
};

class SensorTemperatura : public Sensor {
private:
    string* etiquetas;

public:
    SensorTemperatura(int n) : Sensor(n), etiquetas(new string[n]) {
        for (int i = 0; i < n; ++i) {
            etiquetas[i] = "";
        }
    }

    ~SensorTemperatura() override {
        delete[] etiquetas;
        etiquetas = nullptr;
        cout << "~SensorTemperatura: liberando etiquetas" << endl;
    }

    void setLectura(int i, double val) {
        setLecturaBase(i, val);
    }

    void setEtiqueta(int i, string e) {
        if (i >= 0 && i < size()) {
            etiquetas[i] = e;
        }
    }

    string tipo() const override {
        return "Temperatura";
    }

    void imprimir() const override {
        cout << fixed << setprecision(2);
        for (int i = 0; i < size(); ++i) {
            cout << etiquetas[i] << ": " << getLectura(i) << endl;
        }
    }
};

int main() {
    SensorTemperatura st(3);
    st.setLectura(0, 22.5);
    st.setEtiqueta(0, "Sala");
    st.setLectura(1, 18.0);
    st.setEtiqueta(1, "Cocina");
    st.setLectura(2, 25.3);
    st.setEtiqueta(2, "Patio");

    Sensor* s = &st;
    s->imprimir();
    cout << "Tipo: " << s->tipo() << endl;

    return 0;
}
