#include <iostream>
using namespace std;

// Cấu trúc Node của danh sách liên kết đơn (chỉ có 1 con trỏ next)
struct Node {
    int data;
    Node *next;
};

// Hàm tạo Node mới
Node* taoNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Truy cập phần tử tại vị trí
void truyCap(Node *dau, int viTri) {
    Node *p = dau;
    int i = 0;

    while (p != NULL && i < viTri) {
        p = p->next;
        i++;
    }

    if (p == NULL)
        cout << "Vi tri khong ton tai\n";
    else
        cout << "Gia tri: " << p->data << endl;
}

// Chèn vào đầu
void chenDau(Node *&dau, int x) {
    Node *p = taoNode(x);
    p->next = dau;
    dau = p;
}

// Chèn vào cuối
void chenCuoi(Node *&dau, int x) {
    Node *p = taoNode(x);

    if (dau == NULL) {
        dau = p;
        return;
    }

    Node *q = dau;
    while (q->next != NULL)
        q = q->next;

    q->next = p;
}

// Chèn vào vị trí bất kỳ
void chenViTri(Node *&dau, int viTri, int x) {
    if (viTri == 0) {
        chenDau(dau, x);
        return;
    }

    Node *q = dau;
    int i = 0;

    while (q != NULL && i < viTri - 1) {
        q = q->next;
        i++;
    }

    if (q == NULL) {
        cout << "Vi tri khong hop le\n";
        return;
    }

    Node *p = taoNode(x);
    p->next = q->next;
    q->next = p;
}

// Xóa phần tử đầu
void xoaDau(Node *&dau) {
    if (dau == NULL)
        return;

    Node *p = dau;
    dau = dau->next;
    delete p;
}

// Xóa phần tử cuối
void xoaCuoi(Node *&dau) {
    if (dau == NULL)
        return;

    if (dau->next == NULL) {
        delete dau;
        dau = NULL;
        return;
    }

    Node *p = dau;

    while (p->next->next != NULL)
        p = p->next;

    delete p->next;
    p->next = NULL;
}

// Xóa tại vị trí bất kỳ
void xoaViTri(Node *&dau, int viTri) {
    if (dau == NULL)
        return;

    if (viTri == 0) {
        xoaDau(dau);
        return;
    }

    Node *p = dau;
    int i = 0;

    while (p->next != NULL && i < viTri - 1) {
        p = p->next;
        i++;
    }

    if (p->next == NULL) {
        cout << "Vi tri khong hop le\n";
        return;
    }

    Node *q = p->next;
    p->next = q->next;
    delete q;
}

// Duyệt xuôi từ đầu đến cuối
void duyetXuoi(Node *dau) {
    Node *p = dau;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

// Duyệt ngược (Dùng đệ quy cho danh sách liên kết đơn)
void duyetNguoc(Node *p) {
    if (p == NULL)
        return;

    duyetNguoc(p->next);
    cout << p->data << " ";
}

int main() {
    Node *dau = NULL;

    chenCuoi(dau, 100);
    chenCuoi(dau, 200);
    chenCuoi(dau, 300);
    chenCuoi(dau, 400);

    cout << "Danh sach ban dau: ";
    duyetXuoi(dau);

    cout << "Truy cap vi tri 2: ";
    truyCap(dau, 2);

    chenDau(dau, 50);
    cout << "Chen dau (50): ";
    duyetXuoi(dau);

    chenCuoi(dau, 500);
    cout << "Chen cuoi (500): ";
    duyetXuoi(dau);

    chenViTri(dau, 3, 250);
    cout << "Chen vi tri 3 (250): ";
    duyetXuoi(dau);

    xoaDau(dau);
    cout << "Xoa dau: ";
    duyetXuoi(dau);

    xoaCuoi(dau);
    cout << "Xoa cuoi: ";
    duyetXuoi(dau);

    xoaViTri(dau, 2);
    cout << "Xoa vi tri 2: ";
    duyetXuoi(dau);

    cout << "Duyet xuoi: ";
    duyetXuoi(dau);

    cout << "Duyet nguoc: ";
    duyetNguoc(dau);
    cout << endl;

    return 0;
}
