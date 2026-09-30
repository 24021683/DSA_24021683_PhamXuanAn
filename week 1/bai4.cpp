#include <iostream>
using namespace std;

long long findGCD(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void simplifyFraction(long long &a, long long &b) {
    long long ucln = findGCD(a, b);
    a = a / ucln;
    b = b / ucln;

    if (b < 0) {
        a = -a;
        b = -b;
    }
}

int main() {
    long long a, b;
    cout << "Nhap tu so a va mau so b: ";
    cin >> a >> b;

    if (b == 0) {
        cout << "Mau so phai khac 0!" << endl;
        return 0;
    }

    simplifyFraction(a, b);

    if (b == 1) {
        cout << "Phan so sau khi rut gon: " << a << endl;
    } else {
        cout << "Phan so sau khi rut gon: " << a << "/" << b << endl;
    }

    return 0;
}