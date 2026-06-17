#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 6, 9, 12, 15};
    int n = 5;

    cout << "arr[i]  : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "*(arr+i): ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    cout << "p++     : ";
    int* p = arr;
    for (int i = 0; i < n; i++) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    return 0;
}
