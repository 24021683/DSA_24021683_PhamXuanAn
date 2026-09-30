#include <iostream>
using namespace std;

int main() {
    int n;
    double a[1000];
    double sum = 0;

    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap N so thuc: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum = sum + a[i];
    }

    double avg = sum / n;
    cout << "Gia tri trung binh: " << avg << endl;

    cout << "Cac phan tu >= trung binh: ";
    for (int i = 0; i < n; i++) {
        if (a[i] >= avg) {
            cout << a[i] << " ";
        }
    }
    cout << endl;

    return 0;
}