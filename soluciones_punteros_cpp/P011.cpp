#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 15, 20};
    int* p = arr;
    int** pp = &p;

    cout << *p << endl;      // 5
    cout << **pp << endl;    // 5
    p++;
    cout << *p << endl;      // 10
    cout << **pp << endl;    // 10
    *pp = arr;               // modifica p: vuelve a arr[0]
    cout << **pp << endl;    // 5
    cout << *(p + 2) << endl;// 15

    return 0;
}
