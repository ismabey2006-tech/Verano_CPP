#include <iostream>
#include <string>
using namespace std;

/*
P015 | Analisis critico con preguntas guia

a) enviarTodas() NO funciona polimorficamente en el codigo original porque
   Notificacion::enviar() no es virtual. Si la lista contiene Email, SMS y
   Notificacion base, imprimira siempre la version de la base:

   Enviando: [mensaje del primer objeto]
   Enviando: [mensaje del segundo objeto]
   Enviando: [mensaje del tercer objeto]

b) Cambio de una palabra:
   En la clase Notificacion, escribir:
   virtual void enviar()

c) Si se agrega NotificacionPush, no se modifica enviarTodas(), siempre que
   enviar() sea virtual y Push sobrescriba enviar().

d) Si el destructor de Notificacion no es virtual y se hace delete sobre un
   Notificacion* que apunta a NotificacionEmail, solo se ejecutaria
   ~Notificacion(). Si NotificacionEmail tuviera recursos propios, quedarian
   sin liberarse.

e) No ocurre slicing en:
   NotificacionEmail e("Hola", "x@x.com");
   Notificacion* lista[1] = {&e};
   enviarTodas(lista, 1);
   porque se guarda una direccion/puntero al objeto real, no una copia por valor.
*/

class Notificacion {
protected:
    string mensaje;

public:
    Notificacion(string m) : mensaje(m) {}

    virtual void enviar() {
        cout << "Enviando: " << mensaje << endl;
    }

    virtual ~Notificacion() {}
};

class NotificacionEmail : public Notificacion {
private:
    string email;

public:
    NotificacionEmail(string m, string e)
        : Notificacion(m), email(e) {}

    void enviar() override {
        cout << "Email a " << email << ": " << mensaje << endl;
    }
};

class NotificacionSMS : public Notificacion {
private:
    string telefono;

public:
    NotificacionSMS(string m, string t)
        : Notificacion(m), telefono(t) {}

    void enviar() override {
        cout << "SMS a " << telefono << ": " << mensaje << endl;
    }
};

class NotificacionPush : public Notificacion {
private:
    string dispositivo;

public:
    NotificacionPush(string m, string dispositivo)
        : Notificacion(m), dispositivo(dispositivo) {}

    void enviar() override {
        cout << "Push a " << dispositivo << ": " << mensaje << endl;
    }
};

void enviarTodas(Notificacion** lista, int n) {
    for (int i = 0; i < n; ++i) {
        lista[i]->enviar();
    }
}

int main() {
    Notificacion* lista[3];
    lista[0] = new NotificacionEmail("Hola", "x@x.com");
    lista[1] = new NotificacionSMS("Codigo 123", "0999999999");
    lista[2] = new NotificacionPush("Recordatorio", "iPad");

    enviarTodas(lista, 3);

    for (int i = 0; i < 3; ++i) {
        delete lista[i];
        lista[i] = nullptr;
    }

    return 0;
}
