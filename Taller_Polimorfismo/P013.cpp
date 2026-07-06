#include <iostream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void log(string mensaje) {
        cout << "[LOG] " << mensaje << endl;
    }

    virtual ~Logger() {}
};

class LoggerFecha : public Logger {
public:
    void log(string mensaje) override {
        Logger::log(mensaje);
        cout << "[FECHA] 2024-01-01" << endl;
    }
};

class LoggerCompleto : public LoggerFecha {
public:
    void log(string mensaje) override {
        LoggerFecha::log(mensaje);
        cout << "[NIVEL] INFO" << endl;
    }
};

int main() {
    Logger base;
    LoggerFecha fecha;
    LoggerCompleto completo;

    cout << "-- Logger base:" << endl;
    base.log("Sistema iniciado");

    cout << "\n-- LoggerFecha:" << endl;
    fecha.log("Sistema iniciado");

    cout << "\n-- LoggerCompleto:" << endl;
    completo.log("Sistema iniciado");

    return 0;
}
