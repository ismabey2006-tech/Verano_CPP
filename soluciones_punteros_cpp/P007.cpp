#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int* p = arr;
    int n = 5;

    cout << "Acceso con *(p+i):" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    p = arr;
    cout << "Acceso con p++:" << endl;
    for (int i = 0; i < n; i++) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    return 0;
}
