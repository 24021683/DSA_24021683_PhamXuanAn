#include <iostream>
using namespace std;

void deleteAt(int a[], int &n, int k) {
    if (k < 0 || k >= n) {
        cout << "Vi tri k khong hop le!" << endl;
        return;
    }
    for (int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

void insertAt(int a[], int &n, int y, int m) {
    if (m < 0 || m > n) {
        cout << "Vi tri m khong hop le!" << endl;
        return;
    }
    for (int i = n; i > m; i--) {
        a[i] = a[i - 1];
    }
    a[m] = y;
    n++;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, a[1000];
    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap N phan tu: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cout << "Nhap vi tri k can xoa: ";
    cin >> k;
    deleteAt(a, n, k);
    cout << "Mang sau khi xoa: ";
    printArray(a, n);

    int y, m;
    cout << "Nhap gia tri y va vi tri m can chen: ";
    cin >> y >> m;
    insertAt(a, n, y, m);
    cout << "Mang sau khi chen: ";
    printArray(a, n);

    return 0;
}