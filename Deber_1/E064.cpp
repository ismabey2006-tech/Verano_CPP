#include <iostream>
using namespace std;

int main(){
    int x = 100;
    int* p = &x;
    int** pp = &p;

    cout << "x   = " << x << endl;
    cout << "*p  = " << *p << endl;
    cout << "**pp = " << **pp << endl;

    return 0;
}
