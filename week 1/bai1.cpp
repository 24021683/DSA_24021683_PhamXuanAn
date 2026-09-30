#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap N: ";
    cin >> n;

    int a[1000];
    long long sum = 0;

    cout << "Nhap N phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = sum + a[i];
    }

    cout << "Tong cac phan tu: " << sum << endl;
    return 0;
}