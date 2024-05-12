#include <iostream>
using namespace std;

// Use XOR operation to swap two numbers
int main() {
    int a = -2323;
    int b = 10;
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    cout << a << endl;
    cout << b << endl;

    int arr[] = {3, 5};
    swap(arr, 0, 1);
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    swap(arr, 0, 0);
    cout << arr[0] << endl;
}

// This swap works when i != j
// It fails when i == j
// So, while this method is known, it's not recommended
// 因为i和j最好是不一样的内存地址
// 必须保证非0
void swap(int arr[], int i, int j) {
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}
