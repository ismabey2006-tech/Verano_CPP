#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Persona {
protected:
    string nombre, cedula, email, telefono;
public:
    Persona(string n, string c, string e, string t) : nombre(n), cedula(c), email(e), telefono(t) {}
    string getNombre() const { return nombre; }
    string getCedula() const { return cedula; }
    string getEmail() const { return email; }
    string getTelefono() const { return telefono; }
    virtual void imprimir() const {
        cout << nombre << " | CI: " << cedula << " | Email: " << email << " | Tel: " << telefono;
    }
    virtual ~Persona() {}
};

class Estudiante : public Persona {
private:
    string matricula, carrera;
    int semestre;
    double notas[10];
    int numNotas;
public:
    Estudiante(string n, string c, string e, string t, string m, string car, int s)
        : Persona(n,c,e,t), matricula(m), carrera(car), semestre(s), numNotas(0) {}
    void agregarNota(double n) { if(numNotas < 10 && n >= 0 && n <= 100) notas[numNotas++] = n; }
    double calcularPromedio() const { double suma=0; for(int i=0;i<numNotas;i++) suma+=notas[i]; return numNotas==0 ? 0 : suma/numNotas; }
    bool estaEnRiesgo() const { return calcularPromedio() < 70; }
    void imprimir() const override {
        Persona::imprimir();
        cout << " | Matricula: " << matricula << " | Carrera: " << carrera
             << " | Semestre: " << semestre << " | Promedio: " << fixed << setprecision(2) << calcularPromedio() << endl;
    }
};

class Profesor : public Persona {
protected:
    string titulo, departamento;
    double salario;
    string materias[5];
    int numMaterias;
public:
    Profesor(string n, string c, string e, string t, string ti, string dep, double sal)
        : Persona(n,c,e,t), titulo(ti), departamento(dep), salario(sal), numMaterias(0) {}
    void agregarMateria(string m) { if(numMaterias < 5) materias[numMaterias++] = m; }
    virtual double calcularBono() const { return 0; }
    void imprimir() const override {
        Persona::imprimir();
        cout << " | " << titulo << " | Depto: " << departamento
             << " | Salario: $" << fixed << setprecision(2) << salario
             << " | Bono: $" << calcularBono() << endl;
    }
    virtual ~Profesor() {}
};

class ProfesorTitular : public Profesor {
public:
    ProfesorTitular(string n, string c, string e, string t, string ti, string dep, double sal)
        : Profesor(n,c,e,t,ti,dep,sal) {}
    double calcularBono() const override { return salario * 0.15; }
};

class ProfesorContratado : public Profesor {
public:
    ProfesorContratado(string n, string c, string e, string t, string ti, string dep, double sal)
        : Profesor(n,c,e,t,ti,dep,sal) {}
    double calcularBono() const override { return salario * 0.05; }
};

class Universidad {
private:
    Estudiante* estudiantes[500];
    Profesor* profesores[100];
    int numEstudiantes;
    int numProfesores;
public:
    Universidad() : numEstudiantes(0), numProfesores(0) {
        for(int i=0;i<500;i++) estudiantes[i]=nullptr;
        for(int i=0;i<100;i++) profesores[i]=nullptr;
    }
    void matricularEstudiante(Estudiante* e) { if(e && numEstudiantes < 500) estudiantes[numEstudiantes++] = e; }
    void contratarProfesor(Profesor* p) { if(p && numProfesores < 100) profesores[numProfesores++] = p; }
    void listarEstudiantesRiesgo() const {
        cout << "=== Estudiantes en riesgo ===" << endl;
        for(int i=0;i<numEstudiantes;i++) if(estudiantes[i]->estaEnRiesgo()) estudiantes[i]->imprimir();
    }
    void listarProfesoresBono() const {
        cout << "=== Profesores y bonos ===" << endl;
        for(int i=0;i<numProfesores;i++) profesores[i]->imprimir();
    }
    double presupuestoNomina() const { double t=0; for(int i=0;i<numProfesores;i++) t += profesores[i]->calcularBono(); return t; }
    ~Universidad() {
        for(int i=0;i<numEstudiantes;i++){ delete estudiantes[i]; estudiantes[i]=nullptr; }
        for(int i=0;i<numProfesores;i++){ delete profesores[i]; profesores[i]=nullptr; }
    }
};

int main() {
    Universidad u;
    Estudiante* e1 = new Estudiante("Ana", "171", "ana@u.edu", "099", "M001", "MAC", 3);
    e1->agregarNota(95); e1->agregarNota(88);
    Estudiante* e2 = new Estudiante("Luis", "172", "luis@u.edu", "098", "M002", "MAT", 2);
    e2->agregarNota(60); e2->agregarNota(65);
    u.matricularEstudiante(e1);
    u.matricularEstudiante(e2);

    ProfesorTitular* p1 = new ProfesorTitular("Dra. Mora", "091", "mora@u.edu", "222", "PhD", "Computacion", 3000);
    p1->agregarMateria("POO");
    ProfesorContratado* p2 = new ProfesorContratado("Ing. Vera", "092", "vera@u.edu", "333", "MSc", "Matematicas", 1800);
    p2->agregarMateria("Calculo");
    u.contratarProfesor(p1);
    u.contratarProfesor(p2);

    u.listarEstudiantesRiesgo();
    u.listarProfesoresBono();
    cout << fixed << setprecision(2) << "Presupuesto de bonos: $" << u.presupuestoNomina() << endl;
    return 0;
}
