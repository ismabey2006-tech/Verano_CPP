#include <iostream>
using namespace std;

class Contador{
private:
    static int total;
    char nombre;

public:
    Contador(char n){
        nombre = n;
        total++;
        cout << "(crear " << nombre << ") Total objetos: " << total << endl;
    }

    ~Contador(){
        total--;
        cout << "(destruir " << nombre << ") Total objetos: " << total << endl;
    }

    static int getTotal(){
        return total;
    }
};

int Contador::total = 0;

int main(){
    cout << "Total objetos: " << Contador::getTotal() << endl;

    {
        Contador a('A');
        Contador b('B');
        Contador c('C');
    }

    return 0;
}
