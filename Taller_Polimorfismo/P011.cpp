#include <iostream>
using namespace std;

/*
P011 | TRAZA — cuando dynamic_cast retorna nullptr

a) Arbol de herencia:

       A
      / \
     B   C
     |
     D

b) Prediccion:
   Caso 1: OK    a1 apunta a un B real.
   Caso 2: null  a2 apunta a un C real, y C no es B.
   Caso 3: OK    a3 apunta a un D real, y D hereda de B.
   Caso 4: OK    a3 apunta exactamente a un D real.
   Caso 5: null  a3 apunta a D, y D no hereda de C.

c) El caso 3 funciona porque D es tambien B. Aunque a3 fue declarado A*,
   el tipo real en memoria es D. dynamic_cast revisa el tipo real mediante RTTI.
*/

class A {
public:
    virtual ~A() {}
};

class B : public A {};
class C : public A {};
class D : public B {};

int main() {
    A* a1 = new B();
    A* a2 = new C();
    A* a3 = new D();

    B* b1 = dynamic_cast<B*>(a1);
    B* b2 = dynamic_cast<B*>(a2);
    B* b3 = dynamic_cast<B*>(a3);
    D* d1 = dynamic_cast<D*>(a3);
    C* c1 = dynamic_cast<C*>(a3);

    cout << (b1 ? "OK" : "null") << endl;
    cout << (b2 ? "OK" : "null") << endl;
    cout << (b3 ? "OK" : "null") << endl;
    cout << (d1 ? "OK" : "null") << endl;
    cout << (c1 ? "OK" : "null") << endl;

    delete a1;
    delete a2;
    delete a3;
    a1 = nullptr;
    a2 = nullptr;
    a3 = nullptr;

    return 0;
}
