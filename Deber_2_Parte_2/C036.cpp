#include <iostream>
using namespace std;

class A {
public:
    int x;
    A(int v) : x(v) { cout << "A(" << x << ")" << endl; }
    ~A() { cout << "~A(" << x << ")" << endl; }
};

class B : public A {
public:
    int y;
    B(int v1, int v2) : A(v1), y(v2) { cout << "B(" << x << "," << y << ")" << endl; }
    ~B() { cout << "~B(" << x << "," << y << ")" << endl; }
};

class C : public B {
public:
    int z;
    C(int v1, int v2, int v3) : B(v1, v2), z(v3) {
        cout << "C(" << x << "," << y << "," << z << ")" << endl;
    }
    ~C() { cout << "~C(" << x << "," << y << "," << z << ")" << endl; }
};

int main() {
    C obj(1, 2, 3);
    return 0;
}
