#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int* p = arr;

    cout << arr[2] << endl;      // 3
    cout << *(arr + 2) << endl;  // 3
    cout << *(p + 2) << endl;    // 3
    p += 2;
    cout << *p << endl;          // 3
    cout << p[1] << endl;        // 4
    *p = 99;
    cout << arr[2] << endl;      // 99

    return 0;
}
