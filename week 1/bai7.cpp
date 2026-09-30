#include <iostream>
using namespace std;

long long sumMatrix(int a[][100], int n, int m) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum = sum + a[i][j];
        }
    }
    return sum;
}

void deleteRow(int a[][100], int &n, int m, int rowDelete) {
    if (rowDelete < 0 || rowDelete >= n) {
        cout << "Dong khong hop le!" << endl;
        return;
    }
    for (int i = rowDelete; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = a[i + 1][j];
        }
    }
    n--;
}

void printMatrix(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    int a[100][100];

    cout << "Nhap N va M: ";
    cin >> n >> m;

    cout << "Nhap ma tran N x M:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Tong cac phan tu trong ma tran: " << sumMatrix(a, n, m) << endl;

    int k;
    cout << "Nhap chi so dong k can xoa (0 den " << n - 1 << "): ";
    cin >> k;

    deleteRow(a, n, m, k);

    cout << "Ma tran sau khi xoa dong " << k << ":\n";
    printMatrix(a, n, m);

    return 0;
}