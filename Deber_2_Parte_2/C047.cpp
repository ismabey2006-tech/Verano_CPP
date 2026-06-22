#include <iostream>
using namespace std;

class A {
public:
    virtual void f() { cout << "A::f" << endl; }
    void g() { cout << "A::g" << endl; }
    virtual ~A() {}
};

class B : public A {
public:
    void f() override { cout << "B::f" << endl; }
    void g() { cout << "B::g" << endl; }
};

class C : public B {
public:
    void f() override { cout << "C::f" << endl; }
};

int main() {
    A* p1 = new B();
    A* p2 = new C();
    B* p3 = new C();

    p1->f();
    p1->g();
    p2->f();
    p2->g();
    p3->f();
    p3->g();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
