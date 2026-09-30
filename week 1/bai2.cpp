#include <iostream>
using namespace std;

void sortArray(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    int a[1000];

    cout << "Nhap N: ";
    cin >> n;

    cout << "Nhap N phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sortArray(a, n);

    cout << "Day sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}