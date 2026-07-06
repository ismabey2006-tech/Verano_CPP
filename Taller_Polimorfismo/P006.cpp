#include <iostream>
using namespace std;

class Instrumento {
public:
    virtual void tocar() const = 0;
    virtual ~Instrumento() {}
};

class Guitarra : public Instrumento {
public:
    void tocar() const override {
        cout << "Tañe las cuerdas" << endl;
    }
};

class Piano : public Instrumento {
public:
    void tocar() const override {
        cout << "Presiona las teclas" << endl;
    }
};

class Bateria : public Instrumento {
public:
    void tocar() const override {
        cout << "Golpea los parches" << endl;
    }
};

void concierto(Instrumento* i) {
    cout << "[puntero]    ";
    if (i != nullptr) {
        i->tocar();
    }
}

void concierto(Instrumento& i) {
    cout << "[referencia] ";
    i.tocar();
}

int main() {
    Instrumento* instrumentos[3];
    instrumentos[0] = new Guitarra();
    instrumentos[1] = new Piano();
    instrumentos[2] = new Bateria();

    for (int i = 0; i < 3; ++i) {
        concierto(instrumentos[i]);
    }

    for (int i = 0; i < 3; ++i) {
        delete instrumentos[i];
        instrumentos[i] = nullptr;
    }

    Guitarra guitarra;
    Piano piano;
    Bateria bateria;

    concierto(guitarra);
    concierto(piano);
    concierto(bateria);

    return 0;
}
